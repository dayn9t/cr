#include <cr/cdd_adt/str_adt.hpp>
#include <cr/test.hpp>


TEST(Str, all)
{
    char s1[8] = "jiang";

    StrX s2(s1);
    EQ(s2.data(), s1);

    s2 = "wang";
    EQ(s1, string("wang"));

    s2 = string("jiang");
    EQ(s1, string("jiang"));
}
