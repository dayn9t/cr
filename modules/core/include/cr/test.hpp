#pragma once

#include <gtest/gtest.h>

using namespace std;

#define TR            ASSERT_TRUE
#define FA            ASSERT_FALSE
#define EQ            ASSERT_EQ
#define NE            ASSERT_NE
#define LT            ASSERT_LT
#define LE            ASSERT_LE
#define GT            ASSERT_GT
#define GE            ASSERT_GE
#define FEQ            ASSERT_FLOAT_EQ
#define DEQ            ASSERT_DOUBLE_EQ
#define SEQ            ASSERT_STREQ
#define SNE            ASSERT_STRNE

/// 检查数组相等
#define test_vector_eq(v1, v2) { \
            EQ(v1.size(), v2.size()); \
    for (size_t i = 0; i < v1.size(); ++i) { \
                EQ(v1[i], v2[i]); \
    } \
};

/// 检查数组相等
#define test_vector_eq2(v1, v2) { \
            EQ(v1.size(), v2.size()); \
    for (size_t i = 0; i < v1.size(); ++i) { \
                TR(v1[i] == v2[i]); \
    } \
};

namespace cr {

    /// 检查数组相等
    template<typename T>
    void test_vector_eq1(const std::vector<T> &v1, const std::vector<T> &v2) {
                EQ(v1.size(), v2.size());
        for (size_t i = 0; i < v1.size(); ++i) {
                    TR(v1[i] == v2[i]);
        }
    };

    /// 检查映射
    template<typename K, typename V, typename Fun>
    void test_map(const std::map<K, V> &map, Fun fun) {
        for (auto &p: map) {
            auto v = fun(p.first);
                    TR(p.second == v);
        }
    };

/*
/// 检查映射（Result）
template<typename K, typename V, typename Fun>
void test_map_result(const std::map<K, V>& map, Fun fun)
{
    for (auto& p : map) {
        cx::Result<V> r = fun(p.first);
                TR(r.ok() && p.second == r.unwrap());
    }
};
*/

    /// 检查反向映射
    template<typename K, typename V, typename Fun>
    void test_reverse_map(const std::map<K, V> &map, Fun fun) {
        for (auto &p: map) {
            auto v = fun(p.second);
                    TR(p.first == v);
        }
    };

    /// 检查to_string映射
    template<typename V>
    void test_map_to_string(const std::map<string, V> &map) {
        for (auto &p: map) {
                    EQ(p.first, p.second.to_string());
        }
    };

/*
///检查映射表相等
template<typename T1, typename T2, typename Fun>
void test_map(InVector<T1> v1 , InVector<T2> v2, Fun fun)
{
            TR(v1.size() == v2.size());
    for(size_t i = 0; i < v1.size(); ++i) {
                TR(v2[i] == fun(v1[i]));
    }
};
 */
}
using namespace cr;
