#include "jsonfixture.h"
#include "gen_projpath.h"
#include <cstdint>
#include <fstream>


void JsonFixtrue::SetUp(const ::benchmark::State &state)
{
  using namespace std;

  _filename = GetTestJsonFileNames().at(state.range(0));
  std::ifstream ifs(_filename, ios::binary);
  if (!ifs)
    return;
  ifs.unsetf(ios::skipws);

  ifs.seekg(0, ios::end);
  const size_t size = ifs.tellg();
  ifs.seekg(0);

  _data.resize(size + 1);
  ifs.read(&_data[0], size);
  _data[size] = 0;
  _valid = true;
}

void JsonFixtrue::TearDown(const ::benchmark::State &state)
{
  _valid = false;
  _filename.clear();
  _data.clear();
}

const std::vector<std::string> &GetTestJsonFileNames() noexcept
{
  static const std::vector<std::string> filenames = {
      PROJECT_ROOT_PATH "/data/canada.json",
      PROJECT_ROOT_PATH "/data/citm_catalog.json",
      PROJECT_ROOT_PATH "/data/twitter.json",
  };
  return filenames;
}

void CustomJsonFixtrueArguments(::benchmark::internal::Benchmark *b) noexcept
{
  const auto &filenames = GetTestJsonFileNames();
  for (std::int64_t i = 0; i < std::int64_t(filenames.size()); ++i)
  {
    for (std::int64_t j = 1; j <= 512; j *= 2)
      b->Args({i, j});
  }
  b->Unit(::benchmark::kMillisecond);
}
