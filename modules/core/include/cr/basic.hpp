#pragma once

#include <cr/cdd/basic.h>
#include "dbc.hpp"
#include <vector>
#include <array>

namespace cr {
    using std::string;
    using std::vector;
    using std::array;

    using InString = const string&;
    using Strings = vector<string>;

    using InStrings = const Strings&;

    template<typename T> using InVector = const vector<T>&;

    /// 数值向上对齐
    template<typename T>
    T align_up(T size, T align) {
        return (size + align - 1) / align * align;
    }

    /// 数值向下对齐
    template<typename T>
    T align_down(T size, T align) {
        return size / align * align;
    }
}
