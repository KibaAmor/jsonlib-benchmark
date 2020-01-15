#include "jsoninfo.h"
#include "jsonfixture.h"
#include "rapidjson/document.h"
#include <iostream>

using namespace rapidjson;

struct StatVisitor
{
  StatVisitor(JsonInfo &ji) : jsonInfo(ji) {}
  JsonInfo &jsonInfo;

  bool Null()
  {
    jsonInfo.nullNum++;
    return true;
  }

  bool Bool(bool b)
  {
    if (b)
      jsonInfo.trueNum++;
    else
      jsonInfo.falseNum++;
    return true;
  }

  bool Int(int i)
  {
    jsonInfo.intNum++;
    return true;
  }

  bool Uint(unsigned i)
  {
    jsonInfo.intNum++;
    return true;
  }

  bool Int64(int64_t i)
  {
    jsonInfo.intNum++;
    return true;
  }

  bool Uint64(uint64_t i)
  {
    jsonInfo.intNum++;
    return true;
  }

  bool Double(double d)
  {
    jsonInfo.floatNum++;
    return true;
  }

  bool RawNumber(const char *str, SizeType length, bool)
  {
    throw "invalid";
    return true;
  }

  bool String(const char *str, SizeType length, bool)
  {
    jsonInfo.stringNum++;
    return true;
  }

  bool StartArray()
  {
    jsonInfo.arrayNum++;
    return true;
  }

  bool EndArray(SizeType)
  {
    return true;
  }

  bool StartObject()
  {
    jsonInfo.objectNum++;
    return true;
  }

  bool Key(const char *str, SizeType length, bool)
  {
    jsonInfo.keyNum++;
    return true;
  }

  bool EndObject(SizeType)
  {
    return true;
  }
};

TEST_F(JsonTestFixtrue, RapidJsonStatTest)
{
  for (std::size_t i = 0, N = GetAllData().size(); i < N; ++i)
  {
    const auto data = GetData(i);
    ASSERT_NE(nullptr, data);

    Document d;
    d.Parse(data->c_str());

    const auto& base = GetAllJsonInfo().at(i);

    JsonInfo parsed;
    StatVisitor vistor(parsed);
    d.Accept(vistor);

    JSONINFO_EXPECT_EQ(base, parsed);
  }
}
