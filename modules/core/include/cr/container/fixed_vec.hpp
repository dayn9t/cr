#pragma once

#include <cr/basic.hpp>
#include <algorithm>
#include <array>

namespace cr {

    /**
    * 固定容量向量.
    *
    * 固定容量, 避免内存分配。
    * - 不持有数据, 引用语义
    * - 时刻注意数据的生命周期!
    */
    template<typename T>
    class FixedVec {
    public:
        /// 构造 - 空对象
        FixedVec() = default;

        /// 构造
        FixedVec(T *data, size_t capacity, size_t size = 0)
                : capacity_(capacity), size_(size), data_(data) {
            cr_ensure(capacity_ > 0 && capacity_ >= size_);
        }

        /// 构造
        template<size_t C>
        explicit FixedVec(std::array<T, C> &arr, size_t size = 0)
                : FixedVec(arr.begin(), C, size) {}

    public:
        /// 获取尺寸
        size_t size() const { return size_; }

        /// 获取容量
        size_t capacity() const { return capacity_; }

        /// 剩余容量 - 不重新分配情况下
        size_t free_space() const { return capacity_ - size_; }

        /// 判断是否为空
        bool empty() const { return size() == 0; }

        /// 判断是否为满
        bool full() const { return size() >= capacity(); }

        /// 数据占据的字节数
        size_t size_in_bytes() const { return size() * sizeof(T); }

        /// 总容量占据的字节数
        size_t capacity_in_bytes() const { return capacity() * sizeof(T); }

        /// 访问元素
        T &operator[](size_t i) { return data_[i]; }

        /// 访问元素
        const T &operator[](size_t i) const { return data_[i]; }

        /// 访问元素
        T &at(size_t i) {
            cr_ensure(i < size());
            return data_[i];
        }

        /// 访问元素
        const T &at(size_t i) const {
            cr_ensure(i < size());
            return data_[i];
        }

    public:
        /// 获取首迭代器
        T *begin() { return data_; }

        /// 获取首迭代器 - 只读
        const T *begin() const { return data_; }

        /// 获取尾迭代器
        T *end() { return begin() + size(); }

        /// 获取尾迭代器 - 只读
        const T *end() const { return begin() + size(); }

        /// 首元素
        T &front() {
            cr_ensure(!empty());
            return *begin();
        }

        /// 首元素
        const T &front() const {
            cr_ensure(!empty());
            return *begin();
        }

        /// 尾元素
        T &back() {
            cr_ensure(!empty());
            return end()[-1];
        }

        /// 尾元素
        const T &back() const {
            cr_ensure(!empty());
            return end()[-1];
        }

    public:
        /// 等值判断
        bool operator==(const FixedVec &other) {
            if (other.size() != size()) return false;
            return std::equal(begin(), end(), other.begin());
        }

        /// 不等值判断
        bool operator!=(const FixedVec &other) {
            return !(*this == other);
        }

    public:
        /// 添加数据
        void push_back(const T &v) {
            cr_ensure(!full());
            *end() = v;
            size_++;
        }

        /// 弹出数据
        void pop_back() {
            cr_ensure(!empty());
            size_--;
        }

        /// 清空数据
        void clear() { size_ = 0; }

        /// 交换
        void swap(FixedVec &other) {
            std::swap(capacity_, other.capacity_);
            std::swap(size_, other.size_);
            std::swap(data_, other.data_);
        }

        /// 数据复制到目标迭代器
        void copy_to(T *other_begin) const {
            std::copy(begin(), end(), other_begin);
        }

        /// 数据复制到目标 FixedVec
        void copy_to(FixedVec &other) const {
            cr_ensure(other.capacity() >= size());
            copy_to(other.begin());
            other.size_ = size();
        }

    protected:
        size_t capacity_{};
        size_t size_{};
        T *data_{};
    };
}
