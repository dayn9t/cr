
#include <cr/container/fixed_vec.hpp>
#include <cr/test.hpp>

// 是否值得?
struct FixedVecProps {
    bool empty;
    bool full;
    size_t capacity;
    size_t size;
    size_t free_space;
    size_t capacity_in_bytes;
    size_t size_in_bytes;
    int *begin;
    int *end;
};

TEST(FixedVec, ctor) {
    {
        FixedVec<int> v1;
                TR(v1.empty());
                TR(v1.full());
                EQ(v1.size(), 0);
                EQ(v1.capacity(), 0);
                EQ(v1.free_space(), 0);
                EQ(v1.begin(), nullptr);
                EQ(v1.end(), nullptr);
    }
    const int C = 4;
    std::array<int, 4> arr{0, 1, 2, 3};
    {
        FixedVec<int> v1(arr);
                TR(v1.empty());
                EQ(v1.size(), 0);
                EQ(v1.capacity(), C);
                EQ(v1.free_space(), C);
                EQ(v1.begin(), &arr[0]);
    }
    {
        FixedVec<int> v1(arr, C);
                TR(v1.full());
                EQ(v1.size(), C);
                EQ(v1.capacity(), C);
                EQ(v1.free_space(), 0);
                EQ(v1.begin(), &arr[0]);
    }

}


TEST(FixedVec, io) {
    const int C = 4;
    int arr[C] = {0, 1, 2, 3};
    FixedVec<int> v1(arr, C);
            TR(v1.empty());
            TR(!v1.full());
            EQ(v1.size(), 0);
            EQ(v1.capacity(), C);
            EQ(v1.capacity_in_bytes(), C * sizeof(int));
            EQ(v1.free_space(), C);
            EQ(v1.begin(), arr);
            EQ(v1.end(), arr);
    v1.push_back(0);
            EQ(v1.front(), 0);
            EQ(v1.back(), 0);
            TR(!v1.empty());
            TR(!v1.full());
            EQ(v1.size(), 1);
    v1.push_back(1);
            EQ(v1.front(), 0);
            EQ(v1.back(), 1);
    v1.push_back(2);
    v1.push_back(3);
            EQ(v1.front(), 0);
            EQ(v1.back(), 3);
            TR(!v1.empty());
            TR(v1.full());
            EQ(v1.size(), C);
            EQ(v1.capacity(), C);
            EQ(v1.size_in_bytes(), C * sizeof(int));
            EQ(v1.free_space(), 0);
            EQ(v1.begin(), arr);
            EQ(v1.end(), arr + C);

    for (int i = 0; i < C; i++) {
                EQ(v1[i], i);
    }

    v1.pop_back();
            EQ(v1.front(), 0);
            EQ(v1.back(), 2);
            EQ(v1.size(), 3);
    v1.pop_back();
            EQ(v1.front(), 0);
            EQ(v1.back(), 1);
            EQ(v1.size(), 2);
    v1.pop_back();
    v1.pop_back();
            EQ(v1.size(), 0);
}


TEST(FixedVec, interact) {
    const int C = 4;
    int a1[C] = {0, 1, 2, 3};
    int a2[C] = {};
    FixedVec<int> v1(a1, C, C);
    FixedVec<int> v2(a2, C);

    v2.push_back(9);
            EQ(v2.front(), 9);
            TR(v2 != v1);
    v1.copy_to(v2);
            TR(v2 == v1);

    vector<int> v3(C + 1);
    int a3[C + 1] = {};
    v1.copy_to(a3);
            EQ(a3[0], 0);
            EQ(a3[3], 3);
            EQ(a3[4], 0);
}
