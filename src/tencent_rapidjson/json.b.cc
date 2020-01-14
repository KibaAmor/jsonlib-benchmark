#include "jsonfixture.h"
#include "rapidjson/document.h"

BENCHMARK_DEFINE_F(JsonFixtrue, TencentRapidJson)
(::benchmark::State &state)
{
  using namespace rapidjson;
  if (!IsValid())
  {
    state.SkipWithError("read file failed");
    return;
  }
  for (const auto _ : state)
  {
    for (std::int64_t i = 0; i < state.range(1); ++i)
    {
      state.PauseTiming();
      Document doc;
      state.ResumeTiming();
      doc.Parse(GetData());
    }
  }
}

BENCHMARK_REGISTER_F(JsonFixtrue, TencentRapidJson)->Apply(CustomJsonFixtrueArguments);

BENCHMARK_MAIN();