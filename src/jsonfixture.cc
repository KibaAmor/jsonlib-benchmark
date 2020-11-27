#include "jsonfixture.h"
#include "jsoninfo.h"
#include <cstdint>
#include <fstream>
#include <iostream>

void JsonFixtrue::Load()
{
    if (!_data.empty())
        return;

    for (const auto& ji : GetAllJsonInfo())
        _data.push_back(ReadFileData(ji.filename));
}

void JsonFixtrue::Unload()
{
}

std::shared_ptr<std::string> JsonFixtrue::GetData(std::int64_t i) const noexcept
{
    return (i >= 0 && i < std::int64_t(_data.size())) ? _data[i] : nullptr;
}

std::shared_ptr<std::string> ReadFileData(const std::string& filename) noexcept
{
    using namespace std;
    std::ifstream ifs(filename, ios::binary);
    if (!ifs)
        return nullptr;
    ifs.unsetf(ios::skipws);

    ifs.seekg(0, ios::end);
    const size_t size = ifs.tellg();
    ifs.seekg(0);

    auto str = std::make_shared<std::string>(size, '\0');
    ifs.read(&((*str)[0]), size);
    return str;
}

void CustomJsonFixtrueArguments(::benchmark::internal::Benchmark* b) noexcept
{
    for (std::int64_t i = 0; i < std::int64_t(GetAllJsonInfo().size()); ++i)
        b->Args({ i, 1 });
    b->Unit(::benchmark::kMillisecond);
}
