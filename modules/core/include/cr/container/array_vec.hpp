#pragma once

#include "fixed_vec.hpp"

namespace cr {

    /**
    * 用数组实现定容向量.
    *
    * - 避免内存分配
    * - 用内部数组持有数据, 值语义
    * - 容量由模板参数指定 
    */
    template<typename T, size_t C>
    class ArrayVec : public FixedVec<T> {
    public:
        /// 构造 - 空对象
        ArrayVec() {
            *((FixedVec<T> *) this) = FixedVec<T>(array_, C);
        };

        /// 构造 - 复制输入数据
        explicit ArrayVec(const T *data, size_t size = 0) : ArrayVec() {
            cr_ensure(this->capacity() > size);
        }

        /// 构造 - 复制
        ArrayVec(const ArrayVec &other) : ArrayVec() {
            other.copy_to(*this);
        }

        /// 构造 - 复制不同容量
        template<size_t C1>
        ArrayVec(const ArrayVec<T, C1> &other) : ArrayVec() {
            other.copy_to(*this);
        }

    public:
        /// 赋值
        ArrayVec &operator=(const ArrayVec &other) {
            other.copy_to(*this);
            return *this;
        }

        /// 赋值 - 不同容量
        template<size_t C1>
        ArrayVec &operator=(const ArrayVec<T, C1> &other) {
            other.copy_to(*this);
            return *this;
        }

    public:
        /// 交换
        void swap(ArrayVec &other) {
            std::swap(array_, other.array_);
            std::swap(this->size_, other.size_);
        }

    private:
        T array_[C] = {};
    };
}
