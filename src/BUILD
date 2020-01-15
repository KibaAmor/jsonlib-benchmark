load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "jsonlib",
    hdrs = glob(["*.h"]),
    srcs = glob(["*.cc"]),
    linkstatic = True,
    includes = ["."],
    deps = [
        "@com_google_googletest//:gtest",
        "@com_github_google_benchmark//:benchmark",
    ],
)
