
#include <cr/cdd_adt.hpp>
#include <cr/test.hpp>

TEST(Geo, all) {
    CrPoint p0 = {1, 1};
    auto q0 = get_point(p0);
    p0 = to_c(q0);

    auto r1 = 1.0;
            EQ(r1, 1.0);


}
