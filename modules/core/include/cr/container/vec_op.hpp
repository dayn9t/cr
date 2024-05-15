#pragma once

///
/// @brief: C语言向量操作
///
/// 用泛型操作
///

#include <cr/cdd/vec.h>
#include <vector>

namespace cr {

    /// vector 转码 CVec
    template<typename T, typename CVec>
    CVec as_vec(std::vector<T> &v) {
        return CVec{};
    }


    /// C向量外包类
    template<typename T>
    class CVector {
    public:
    public:
    private:
    };

}