#pragma once
#include <string>
#include <vector>
#include <ostream>

struct JsonInfo {
    std::string filename;
    int nullNum = 0;
    int trueNum = 0;
    int falseNum = 0;
    int intNum = 0;
    int floatNum = 0;
    int stringNum = 0;
    int arrayNum = 0;
    int objectNum = 0;
    int keyNum = 0;
    int binNum = 0;

    JsonInfo() = default;
    JsonInfo(const std::string& filename,
        int nullNum,
        int trueNum,
        int falseNum,
        int intNum,
        int floatNum,
        int stringNum,
        int arrayNum,
        int objectNum,
        int keyNum,
        int binNum)
    {
        this->filename = filename;
        this->nullNum = nullNum;
        this->trueNum = trueNum;
        this->falseNum = falseNum;
        this->intNum = intNum;
        this->floatNum = floatNum;
        this->stringNum = stringNum;
        this->arrayNum = arrayNum;
        this->objectNum = objectNum;
        this->keyNum = keyNum;
        this->binNum = binNum;
    }
};

inline bool operator==(const JsonInfo& a, const JsonInfo& b) noexcept
{
    return a.nullNum == b.nullNum && a.trueNum == b.trueNum && a.falseNum == b.falseNum && a.intNum == b.intNum && a.floatNum == b.floatNum && a.stringNum == b.stringNum && a.arrayNum == b.arrayNum && a.objectNum == b.objectNum && a.keyNum == b.keyNum && a.binNum == b.binNum;
}

inline std::ostream& operator<<(std::ostream& os, const JsonInfo& ji) noexcept
{
    os << "filename:" << ji.filename << std::endl
       << "nullNum:" << ji.nullNum << std::endl
       << "trueNum:" << ji.trueNum << std::endl
       << "falseNum:" << ji.falseNum << std::endl
       << "intNum:" << ji.intNum << std::endl
       << "floatNum:" << ji.floatNum << std::endl
       << "stringNum:" << ji.stringNum << std::endl
       << "arrayNum:" << ji.arrayNum << std::endl
       << "objectNum:" << ji.objectNum << std::endl
       << "keyNum:" << ji.keyNum << std::endl
       << "binNum:" << ji.binNum << std::endl;
    return os;
}

#define JSONINFO_EXPECT_EQ(lhs, rhs)         \
    EXPECT_EQ(lhs, rhs);                     \
    EXPECT_EQ(lhs.nullNum, rhs.nullNum);     \
    EXPECT_EQ(lhs.trueNum, rhs.trueNum);     \
    EXPECT_EQ(lhs.falseNum, rhs.falseNum);   \
    EXPECT_EQ(lhs.intNum, rhs.intNum);       \
    EXPECT_EQ(lhs.floatNum, rhs.floatNum);   \
    EXPECT_EQ(lhs.stringNum, rhs.stringNum); \
    EXPECT_EQ(lhs.arrayNum, rhs.arrayNum);   \
    EXPECT_EQ(lhs.objectNum, rhs.objectNum); \
    EXPECT_EQ(lhs.keyNum, rhs.keyNum);       \
    EXPECT_EQ(lhs.binNum, rhs.binNum)

const std::vector<JsonInfo>& GetAllJsonInfo() noexcept;
