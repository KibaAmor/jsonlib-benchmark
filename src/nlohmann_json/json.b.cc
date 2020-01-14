#include "jsonfixture.h"
#include "nlohmann/json.hpp"

BENCHMARK_DEFINE_F(JsonFixtrue, NlohmannJson)
(::benchmark::State &state)
{
  using json = nlohmann::json;
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
      state.ResumeTiming();
      auto j = std::move(json::parse(GetData()));
      state.PauseTiming();
    }
    state.ResumeTiming();
  }
}

BENCHMARK_REGISTER_F(JsonFixtrue, NlohmannJson)->Apply(CustomJsonFixtrueArguments);

BENCHMARK_MAIN();