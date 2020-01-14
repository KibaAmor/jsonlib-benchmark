#pragma once
#include "benchmark/benchmark.h"
#include <vector>
#include <string>


class JsonFixtrue : public ::benchmark::Fixture
{
public:
  void SetUp(const ::benchmark::State &state) override;
  void TearDown(const ::benchmark::State &state) override;

  bool IsValid() const noexcept { return _valid; }
  const std::string &GetFileName() const noexcept { return _filename; }
  const char *GetData() const noexcept { return _data.data(); }

private:
  bool _valid = false;
  std::string _filename;
  std::vector<char> _data;
};

const std::vector<std::string> &GetTestJsonFileNames() noexcept;
void CustomJsonFixtrueArguments(::benchmark::internal::Benchmark *b) noexcept;
