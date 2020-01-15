load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "test",
    srcs = glob(["*.t.cc"]),
    deps = [
        "@com_google_googletest//:gtest_main",
        "@com_github_nlohmann_json//:json",
        "//src:jsonlib",
    ],
)

cc_test(
    name = "benchmark",
    srcs = glob(["*.b.cc"]),
    deps = [
        "@com_github_google_benchmark//:benchmark_main",
        "@com_github_nlohmann_json//:json",
        "//src:jsonlib",
    ],
)