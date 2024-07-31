
#include "cr/container/vec_op.h"
#include "cr/test.hpp"

TEST(Vec, basic) {
    {
        CrUBytes b1 = cr_vec_new(U8, 10);
                TR(cr_vec_empty(b1));
                EQ(b1.capacity, 10);
                NE(b1.data, nullptr);
        cr_vec_release(b1);
                TR(cr_vec_empty(b1));
                EQ(b1.capacity, 0);
                EQ(b1.data, nullptr);
    }
    {
        CrUBytes b1 = {};
                TR(cr_vec_empty(b1));
                TR(cr_vec_full(b1));
    }
    {
        U8 d1[4] = {};

        CrUBytes b1 = {4, 0, d1};
                TR(cr_vec_empty(b1));
                FA(cr_vec_full(b1));
        cr_vec_push(b1, 1);
                FA(cr_vec_empty(b1));
                EQ(b1.size, 1);
                EQ(cr_vec_first(b1), 1);
                EQ(cr_vec_last(b1), 1);
        cr_vec_push(b1, 2);
                FA(cr_vec_empty(b1));
                EQ(b1.size, 2);
                EQ(cr_vec_first(b1), 1);
                EQ(cr_vec_last(b1), 2);
        cr_vec_push(b1, 3);
        cr_vec_push(b1, 4);
                TR(cr_vec_full(b1));
                EQ(b1.size, 4);
                EQ(cr_vec_first(b1), 1);
                EQ(cr_vec_last(b1), 4);
        cr_vec_pop(b1);
        cr_vec_pop(b1);
                FA(cr_vec_full(b1));
                EQ(b1.size, 2);
                EQ(cr_vec_last(b1), 2);
        cr_vec_clear(b1);
                TR(cr_vec_empty(b1));
                FA(cr_vec_full(b1));

        U8 d2[4] = {};
        cr_vec_put(b1, d2, 4);
                EQ(b1.size, 4);
                EQ(cr_vec_first(b1), 0);
                EQ(cr_vec_last(b1), 0);

        U8 d3[3] = {1, 1, 1};
        cr_vec_get(b1, d3, 3);
                EQ(b1.size, 3);
                EQ(cr_vec_first(b1), 1);
                EQ(cr_vec_last(b1), 1);
        cr_vec_set(b1, 2);
                EQ(b1.size, 3);
                EQ(cr_vec_first(b1), 2);
                EQ(cr_vec_last(b1), 2);

        U8 d4[4] = {};
        CrUBytes b2 = {4, 4, d4};
        cr_vec_copy(b2, b1);
                EQ(b1.size, 4);
                EQ(cr_vec_first(b1), 0);
                EQ(cr_vec_last(b1), 0);
    }
}
