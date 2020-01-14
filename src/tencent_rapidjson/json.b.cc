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
    state.PauseTiming();
    for (std::int64_t i = 0; i < state.range(1); ++i)
    {
      Document doc;
      state.ResumeTiming();
      doc.Parse(GetData());
      state.PauseTiming();
    }
    state.ResumeTiming();
  }
}

BENCHMARK_REGISTER_F(JsonFixtrue, TencentRapidJson)->Apply(CustomJsonFixtrueArguments);

BENCHMARK_MAIN();