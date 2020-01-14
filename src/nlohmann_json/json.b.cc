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
    for (std::int64_t i = 0; i < state.range(1); ++i)
      json::parse(GetData());
  }
}

BENCHMARK_REGISTER_F(JsonFixtrue, NlohmannJson)->Apply(CustomJsonFixtrueArguments);

BENCHMARK_MAIN();