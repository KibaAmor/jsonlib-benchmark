#pragma once
#include "gtest/gtest.h"
#include "benchmark/benchmark.h"
#include <vector>
#include <string>
#include <memory>

class JsonFixtrue {
public:
    std::shared_ptr<std::string> GetData(std::int64_t i) const noexcept;
    const std::vector<std::shared_ptr<std::string>>& GetAllData() const noexcept { return _data; }

protected:
    void Load();
    void Unload();

private:
    std::vector<std::shared_ptr<std::string>> _data;
};

class JsonTestFixtrue
    : public JsonFixtrue,
      public ::testing::Test {
public:
    void SetUp() override { Load(); }
    void TearDown() override { Unload(); }
};

class JsonBenchmarkFixtrue
    : public JsonFixtrue,
      public ::benchmark::Fixture {
public:
    void SetUp(::benchmark::State&) override { Load(); }
    void TearDown(::benchmark::State&) override { Unload(); }
};

std::shared_ptr<std::string> ReadFileData(const std::string& filename) noexcept;
void CustomJsonFixtrueArguments(::benchmark::internal::Benchmark* b) noexcept;
