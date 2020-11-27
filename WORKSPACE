workspace(name = "com_github_kibaamor_jsonlibbenchmark")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "rules_cc",
  strip_prefix = "rules_cc-master",
  urls = ["https://github.com/bazelbuild/rules_cc/archive/master.zip"],
)

http_archive(
  name = "com_google_googletest",
  strip_prefix = "googletest-release-1.10.0",
  urls = ["https://github.com/google/googletest/archive/release-1.10.0.tar.gz"],
  sha256 = "9dc9157a9a1551ec7a7e43daea9a694a0bb5fb8bec81235d8a1e6ef64c716dcb",
)

http_archive(
  name = "com_github_google_benchmark",
  strip_prefix = "benchmark-1.5.2",
  urls = ["https://github.com/google/benchmark/archive/v1.5.2.tar.gz"],
  sha256 = "dccbdab796baa1043f04982147e67bb6e118fe610da2c65f88912d73987e700c",
)

## https://github.com/nlohmann/json
http_archive(
  name = "com_github_nlohmann_json",
  urls = ["https://github.com/nlohmann/json/releases/download/v3.9.1/include.zip"],
  build_file = "nlohmann_json.BUILD",
  sha256 = "6bea5877b1541d353bd77bdfbdb2696333ae5ed8f9e8cc22df657192218cad91",
)

## https://github.com/Tencent/rapidjson/
http_archive(
  name = "com_github_tencent_rapidjson",
  strip_prefix = "rapidjson-1.1.0",
  urls = ["https://github.com/Tencent/rapidjson/archive/v1.1.0.tar.gz"],
  build_file = "tencent_rapidjson.BUILD",
  sha256 = "bf7ced29704a1e696fbccf2a2b4ea068e7774fa37f6d7dd4039d0787f8bed98e"
)
