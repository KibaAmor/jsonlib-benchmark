#!/usr/bin/env python
#coding: utf-8

import os

def gen_projpath_file():
  abspath = os.path.abspath(__file__)
  dirname = os.path.dirname(abspath)
  with open(os.path.join(dirname, 'src/gen_projpath.h'), 'w+') as f:
    f.write('#pragma once\n\n')
    f.write('#define PROJECT_ROOT_PATH R"(' + dirname + ')"\n')

if __name__ == "__main__":
  gen_projpath_file()