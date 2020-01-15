# CPP JSON Library benchmark

## JSON data

[data/sample.json](https://github.com/KibaAmor/jsonlib-benchmark/blob/master/data/sample.json) from [json-test-suite](https://code.google.com/p/json-test-suite/downloads/list)

[others](https://github.com/KibaAmor/jsonlib-benchmark/tree/master/data) from [nativejson-benchmark](https://github.com/miloyip/nativejson-benchmark)

## Libraries

Library | Version | Notes
--------|---------|------
[json](https://github.com/nlohmann/json) | 3.7.3
[rapidjson](https://github.com/Tencent/rapidjson) | 1.1.0

## How to benchmark

### Install python and bazel

### Generate file

```shell
python ./init.py
```

### Test And Benchmark

```shell
bazel test -c opt //...
```
check benchmark data at bazel-testlogs/src/*/benchmark/test.log

```shell 
cat bazel-testlogs/src/*/benchmark/test.log
```
