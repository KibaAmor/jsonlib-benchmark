#!/usr/bin/env python
# coding: utf-8

import os
import re
import json

NUMBER_RE = re.compile(
    r'(-?(?:0|[1-9]\d*))(\.\d+)?([eE][-+]?\d+)?',
    (re.VERBOSE | re.MULTILINE | re.DOTALL))


def state_make_scanner(context):
    parse_object = context.parse_object
    parse_array = context.parse_array
    parse_string = context.parse_string
    match_number = NUMBER_RE.match
    encoding = context.encoding
    strict = context.strict
    parse_float = context.parse_float
    parse_int = context.parse_int
    parse_constant = context.parse_constant
    object_pairs_hook = context.object_pairs_hook

    def _object_hook(pairs):
        context.stat['keyNum'] += len(pairs.keys())
        if context.object_hook is not None:
            return context.object_hook(pairs)
        return pairs

    object_hook = _object_hook

    def _scan_once(string, idx):
        try:
            nextchar = string[idx]
        except IndexError:
            raise StopIteration

        if nextchar == '"':
            context.stat['stringNum'] += 1
            return parse_string(string, idx + 1, encoding, strict)
        elif nextchar == '{':
            context.stat['objectNum'] += 1
            return parse_object((string, idx + 1), encoding, strict,
                                _scan_once, object_hook, object_pairs_hook)
        elif nextchar == '[':
            context.stat['arrayNum'] += 1
            return parse_array((string, idx + 1), _scan_once)
        elif nextchar == 'n' and string[idx:idx + 4] == 'null':
            context.stat['nullNum'] += 1
            return None, idx + 4
        elif nextchar == 't' and string[idx:idx + 4] == 'true':
            context.stat['trueNum'] += 1
            return True, idx + 4
        elif nextchar == 'f' and string[idx:idx + 5] == 'false':
            context.stat['falseNum'] += 1
            return False, idx + 5

        m = match_number(string, idx)
        if m is not None:
            integer, frac, exp = m.groups()
            if frac or exp:
                context.stat['floatNum'] += 1
                res = parse_float(integer + (frac or '') + (exp or ''))
            else:
                context.stat['intNum'] += 1
                res = parse_int(integer)
            return res, m.end()
        elif nextchar == 'N' and string[idx:idx + 3] == 'NaN':
            return parse_constant('NaN'), idx + 3
        elif nextchar == 'I' and string[idx:idx + 8] == 'Infinity':
            return parse_constant('Infinity'), idx + 8
        elif nextchar == '-' and string[idx:idx + 9] == '-Infinity':
            return parse_constant('-Infinity'), idx + 9
        else:
            raise StopIteration

    return _scan_once


class JsonStatDecoder(json.JSONDecoder):
    def __init__(self, stat={}, **kw):
        json.JSONDecoder.__init__(self, **kw)
        self.stat = stat
        self.scan_once = state_make_scanner(self)


def get_script_abspath():
    return os.path.dirname(os.path.abspath(__file__))


def list_json_files(basepath):
    dirlist = os.listdir(basepath)
    files = []
    for filename in dirlist:
        filepath = os.path.join(basepath, filename)
        if not os.path.isfile(filepath):
            continue
        if filepath.endswith('.json'):
            files.append(filepath)
    return files


def get_all_json_files():
    datapath = os.path.join(get_script_abspath(), 'data')
    return list_json_files(datapath) + list_json_files(os.path.join(datapath, 'roundtrip'))


def get_json_stat(filename):
    with open(filename, 'r') as f:
        stat = {
            'filename': filename,
            'nullNum': 0,
            'trueNum': 0,
            'falseNum': 0,
            'intNum': 0,
            'floatNum': 0,
            'stringNum': 0,
            'arrayNum': 0,
            'objectNum': 0,
            'keyNum': 0,
        }
        json.load(f, stat=stat, cls=JsonStatDecoder)
        return stat


def gen_jsoninfo_file():
    filename = os.path.join(get_script_abspath(), 'src/gen_jsoninfo.cc')
    with open(filename, 'w+') as f:
        f.write('''#include "jsoninfo.h"

const std::vector<JsonInfo> &GetAllJsonInfo() noexcept
{
  static const std::vector<JsonInfo> allJsonInfo = {
''')
        for filename in get_all_json_files():
            stat = get_json_stat(filename)
            info = ('    JsonInfo(R\"({filename})\", {nullNum}, ' +
                    '{trueNum}, {falseNum}, {intNum}, {floatNum}, ' +
                    '{stringNum}, {arrayNum}, {objectNum}, {keyNum}),\n').format(**stat)
            f.write(info)
        f.write('''  };
  return allJsonInfo;
}
''')


if __name__ == "__main__":
    gen_jsoninfo_file()
