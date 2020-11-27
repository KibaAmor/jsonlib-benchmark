# CPP JSON Library benchmark

## JSON data

[data/sample.json](https://github.com/KibaAmor/jsonlib-benchmark/blob/master/data/sample.json) from [json-test-suite](https://code.google.com/p/json-test-suite/downloads/list)

[others](https://github.com/KibaAmor/jsonlib-benchmark/tree/master/data) from [nativejson-benchmark](https://github.com/miloyip/nativejson-benchmark)

## Libraries

Library | Version | Notes
--------|---------|------
[json](https://github.com/nlohmann/json) | 3.9.1
[rapidjson](https://github.com/Tencent/rapidjson) | 1.1.0

## How to benchmark

### Install python3 and bazel

### Generate file

```bash
python3 ./init.py
```

### Test And Benchmark

```bash
bazel test -c opt //...
```
check benchmark data at bazel-testlogs/src/*/benchmark/test.log

```bash
cat bazel-testlogs/src/*/benchmark/test.log
```
