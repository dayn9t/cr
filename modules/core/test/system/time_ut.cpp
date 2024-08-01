#include <cr/system/time.hpp>
#include <cr/test.hpp>


TEST(DatetimeMember, parse)
{
    {
        auto cstr = "2024-01-02T03:04:05";
        DatetimeMember dm = {};
        TR(parse(cstr, dm));

        EQ(dm.year, 2024);
        EQ(dm.month, 1);
        EQ(dm.day, 2);
        EQ(dm.hour, 3);
        EQ(dm.minute, 4);
        EQ(dm.second, 5);
    }

    {
        string str("2024-01-02T03:04:05");
        DatetimeMember dm = {};
        TR(parse(str, dm));

        EQ(dm.year, 2024);
        EQ(dm.month, 1);
        EQ(dm.day, 2);
        EQ(dm.hour, 3);
        EQ(dm.minute, 4);
        EQ(dm.second, 5);
    }
}
