
#include <cr/container/array_vec.hpp>
#include <cr/test.hpp>

TEST(ArrayVec, copy) {
    const int C = 4;
    {
        ArrayVec<int, C> v;
                TR(v.empty());
                EQ(v.capacity(), C);
    }
    {
        int a1[C] = {0, 1, 2, 3};
        FixedVec<int> v1(a1, C, C);

        ArrayVec<int, C> v2;
                TR(v1 != v2);
        v1.copy_to(v2);
                TR(v1 == v2);

        ArrayVec<int, C> v3;
                TR(v2 != v3);
        v2.copy_to(v3);
                TR(v2 == v3);
    }
    {
        ArrayVec<int, C> v1;
        v1.push_back(1);
        ArrayVec<int, C> v2(v1);
                EQ(v2.size(), 1);
                EQ(v2.front(), 1);
        v2[0] = 0;
                EQ(v1[0], 1); // 内部指针测试

        ArrayVec<int, C> v3;
        v3 = v1;
                EQ(v3.size(), 1);
                EQ(v3.front(), 1);
        v3[0] = 0;
                EQ(v1[0], 1); // 内部指针测试
    }
}

TEST(ArrayVec, swap) {
    const int C = 4;
    {
        ArrayVec<int, C> v1;
        v1.push_back(1);

        ArrayVec<int, C> v2;
        v2.push_back(2);
        v2.push_back(2);

        //std::swap(v1, v2); // TODO: 坑! 内部指针也交换了
        v1.swap(v2);
                EQ(v1.size(), 2);
                EQ(v2.size(), 1);
                EQ(v1[1], 2);
                EQ(v2[0], 1);
    }
}
