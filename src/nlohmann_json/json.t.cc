#include "jsoninfo.h"
#include "jsonfixture.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct StatVisitor
{
  using number_integer_t = typename json::number_integer_t;
  using number_unsigned_t = typename json::number_unsigned_t;
  using number_float_t = typename json::number_float_t;
  using string_t = typename json::string_t;

  StatVisitor(JsonInfo &ji) : jsonInfo(ji) {}
  JsonInfo &jsonInfo;

  bool null()
  {
    jsonInfo.nullNum++;
    return true;
  }

  bool boolean(bool b)
  {
    if (b)
      jsonInfo.trueNum++;
    else
      jsonInfo.falseNum++;
    return true;
  }

  bool number_integer(number_integer_t val)
  {
    jsonInfo.intNum++;
    return true;
  }

  bool number_unsigned(number_unsigned_t val)
  {
    jsonInfo.intNum++;
    return true;
  }

  bool number_float(number_float_t val, const string_t &s)
  {
    jsonInfo.floatNum++;
    return true;
  }

  bool string(string_t &val)
  {
    jsonInfo.stringNum++;
    return true;
  }

  bool start_object(std::size_t elements)
  {
    jsonInfo.objectNum++;
    return true;
  }

  bool key(string_t &val)
  {

    jsonInfo.keyNum++;
    return true;
  }

  bool end_object()
  {
    return true;
  }

  bool start_array(std::size_t elements)
  {

    jsonInfo.arrayNum++;
    return true;
  }

  bool end_array()
  {
    return true;
  }

  bool parse_error(std::size_t position,
                   const std::string &last_token,
                   const nlohmann::detail::exception &ex)
  {
    throw ex;
    return false;
  }
};

TEST_F(JsonTestFixtrue, JsonStatTest)
{
  for (std::size_t i = 0, N = GetAllData().size(); i < N; ++i)
  {
    const auto data = GetData(i);
    ASSERT_NE(nullptr, data);

    const auto& base = GetAllJsonInfo().at(i);

    JsonInfo parsed;
    StatVisitor vistor(parsed);
    ASSERT_TRUE(json::sax_parse(*data, &vistor));

    JSONINFO_EXPECT_EQ(base, parsed);
  }
}
