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
  strip_prefix = "benchmark-1.5.0",
  urls = ["https://github.com/google/benchmark/archive/v1.5.0.tar.gz"],
  sha256 = "3c6a165b6ecc948967a1ead710d4a181d7b0fbcaa183ef7ea84604994966221a",
)

# Group the sources of the library so that CMake rule have access to it
all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

http_archive(
   name = "rules_foreign_cc",
   strip_prefix = "rules_foreign_cc-master",
   url = "https://github.com/bazelbuild/rules_foreign_cc/archive/master.zip",
)

## https://github.com/nlohmann/json
http_archive(
  name = "com_github_nlohmann_json",
  urls = ["https://github.com/nlohmann/json/releases/download/v3.7.3/include.zip"],
  build_file = "nlohmann_json.BUILD",
  sha256 = "87b5884741427220d3a33df1363ae0e8b898099fbc59f1c451113f6732891014",
)

## https://github.com/Tencent/rapidjson/
http_archive(
  name = "com_github_tencent_rapidjson",
  strip_prefix = "rapidjson-1.1.0",
  urls = ["https://github.com/Tencent/rapidjson/archive/v1.1.0.tar.gz"],
  build_file = "tencent_rapidjson.BUILD",
  sha256 = "bf7ced29704a1e696fbccf2a2b4ea068e7774fa37f6d7dd4039d0787f8bed98e"
)