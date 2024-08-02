#pragma once

#include "cr/dbc.hpp"
#include "cr/cdd/vec.h"
#include <cstddef>
#include <vector>

namespace cr
{
    /**
         数据包.

        用于不同POD类型包在一起, 包的拼装可以用字节或强类型方式完成.
        类似的, 包的拆解也有两种访问方式:
        - 基于字节方式的拆解
        - 用强类型方式的拆解出元素, 如elements()/elements(i)函数
        包不会自动分配内存, 需要事先确定最大容量.
     */
    class Packet
    {
    public:
        /// 构造，指定队列容量
        explicit Packet(size_t capacity = 0);

        /// 复制构造
        Packet(const Packet& p);

        ~Packet();

    public:
        /** @name 访问.
            @{
        */

        /// 从包里分配 - 空间
        void* alloc_void(size_t n, bool clear = true);

        /// 从包中分配 - 类型
        template <typename T>
        T* alloc(size_t n = 1, bool clear = true)
        {
            return (T*)alloc_void(sizeof(T) * n, clear);
        }

        /// 打包数据 - 空间
        bool pack_void(const void* p, size_t n);

        /// 打包n个T类型数据
        template <typename T>
        bool pack(const T* p, size_t n = 1)
        {
            return pack_void((const void*)p, n * sizeof(T));
        }

        /// 打包T类型数据
        template <typename T>
        bool pack(const T& t) { return pack(&t, 1); }

        /// 复制最多capacity个byte到缓冲区, 返回已经复制字节数量
        size_t copy_to(void* p, size_t capacity) const;
        //@}
    public:
        /** @name 获取状态.
            @{
        */

        /// 获取包元素的数量
        size_t elements() { return lens_.size(); }

        /// 获取指定元素字节长度
        size_t element_len(size_t index)
        {
            cr_ensure(index < lens_.size());
            return lens_[index];
        }

        /// 获取包中指定索引的元素的指针
        template <typename T>
        U8* element_ptr(size_t index)
        {
            return begin() + offset_(index);
        }

        /// 获取包中指定索引的元素的指针, TODO: 应该用buffer
        const U8* element_ptr(size_t index) const
        {
            return begin() + offset_(index);
        }

        /// 获取包中指定索引的元素
        template <typename T>
        T& element(size_t index)
        {
            auto offset = type_offset_<T>(index);
            auto p = begin() + offset;
            return *(T*)p;
        }

        /// 获取包中指定索引的元素
        template <typename T>
        const T& element(size_t index) const
        {
            auto offset = type_offset_<T>(index);
            auto p = begin() + offset;
            return *(const T*)p;
        }

        /// 数据头指针
        U8* begin() { return data_; }

        /// 数据头指针
        const U8* begin() const { return data_; }

        /// 数据尾指针
        U8* end() { return data_ + size_; }

        /// 数据尾指针
        const U8* end() const { return data_ + size_; }

        /// 返回容器尺寸
        size_t size() const { return size_; }

        /// 获取队列的最大容量
        size_t capacity() const { return capacity_; }

        /// 队列是否空
        bool empty() const { return size_ == 0; }

        /// 队列是否满
        bool full() const { return size_ == capacity_; }

        /// 剩余空间
        size_t free_space() const { return capacity_ - size_; }

        /// 剩余空间缓冲区
        CrBytes free_buffer() { return {static_cast<U32>(free_space()), 0, end()}; }

        /// 相等判断
        bool operator==(const Packet& p) const;

        /// 不相等判断
        bool operator!=(const Packet& p) const { return !(*this == p); }
        //@}
    public:
        /** @name 改变状态.
            @{
        */
        /// 赋值
        Packet& operator=(const Packet& p);

        /// 用自身数据填充目标包, 如果目标包容来不足, 则失败
        bool fill(Packet& p) const;

        /// 交换
        void swap(Packet& p);

        /// 预留容量
        void reserve(size_t capacity);

        /// 清除所有元素
        void clear();
        //@}
    private:
        // 获取元素的偏移量, 并检查类型长度
        template <typename T>
        size_t type_offset_(size_t index) const
        {
            cr_ensure(sizeof(T) == lens_[index])
            return offset_(index);
        }

        // 获取元素的偏移量
        size_t offset_(size_t index) const
        {
            cr_ensure(index < lens_.size())
            size_t offset = 0;
            for (size_t i = 0; i < index; ++i)
            {
                offset += lens_[i];
            }
            return offset;
        }

    private:
        U8* data_ = nullptr; // 数据指针
        size_t capacity_ = 0; // 最大容量
        size_t size_ = 0; // 数据长度
        std::vector<size_t> lens_; // 各个元素长度
    };
}
