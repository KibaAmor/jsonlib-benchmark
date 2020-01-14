# CPP JSON Library benchmark

## JSON data

copy from [nativejson-benchmark](https://github.com/miloyip/nativejson-benchmark)

## Libraries

Library | Version | Notes
--------|---------|------
[json](https://github.com/nlohmann/json) | 3.7.3
[rapidjson](https://github.com/Tencent/rapidjson) | 1.1.0

## How to build

### Install bazel

### Build

```shell
bazel build -c opt //...
```

### Test

```shell
bazel test -c opt //...
```

### Benchmark

```shell
bazel run -c opt //src/nlohmann_json:benchmark
bazel run -c opt //src/tencent_rapidjson:benchmark
```