#pragma once
#include <cr/cdd/basic.h>
#include <utility>
#include <vector>

namespace cr {

    /// C数组通过映射函数构建Vector
    template<typename D, typename S>
    vector<D> map_to_vec(S *arr, size_t size, std::function<D(S)> fun) {
        vector<D> v;
        v.reserve(size);
        for (size_t i = 0; i < size; ++i) {
            v.push_back(fun(arr[i]));
        }
        return v;
    }
}
