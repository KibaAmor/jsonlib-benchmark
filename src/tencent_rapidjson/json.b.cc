#include "jsoninfo.h"
#include "jsonfixture.h"
#include "rapidjson/document.h"

BENCHMARK_DEFINE_F(JsonBenchmarkFixtrue, TencentRapidJson)
(::benchmark::State &state)
{
  using namespace rapidjson;

  const auto index = state.range(0);
  const auto data = GetData(index);
  ASSERT_NE(nullptr, data);
  for (const auto _ : state)
  {
    const auto &ji = GetAllJsonInfo().at(index);
    const auto count = state.range(1);
    state.SetLabel(std::string("File:") + ji.filename + ", Count: " + std::to_string(count));
    state.PauseTiming();
    for (std::int64_t i = 0; i < count; ++i)
    {
      Document doc;
      state.ResumeTiming();
      doc.Parse(data->c_str());
      state.PauseTiming();
    }
    state.ResumeTiming();
  }
}

BENCHMARK_REGISTER_F(JsonBenchmarkFixtrue, TencentRapidJson)->Apply(CustomJsonFixtrueArguments);
