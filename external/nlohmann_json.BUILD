load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
  name = "json",
  hdrs = glob([
    "include/**/*.h",
    "include/**/*.hpp",
    ]),
  strip_include_prefix = "include",
)
