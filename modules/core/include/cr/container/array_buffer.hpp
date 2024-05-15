#pragma once

/** @file
@brief buffer管理工具

*/
#include <cr/basic.hpp>
#include <algorithm>

void *memcpy(void *dest, const void *src, size_t count);
int memcmp(const void *buf1, const void *buf2, size_t count);

namespace cr {
	
	/**
	* 数组缓冲区.
	*
	* 数组缓冲区，按需改变容量。
	* - 作为vector低开销的替代。
	* - 改变尺寸时不保证保留原有数据，如果需要，则应在改变之前读出
	*/
	template<typename T>
	class FixedVec
	{
	public:
		/// 构造 - 空对象
		FixedVec()= default;

		/// 构造 - 预先分配空间
		FixedVec(size_t capacity)
			: FixedVec(nullptr, 0, capacity)
		{}

		/// 构造 - 复制
		FixedVec(const FixedVec& buffer, size_t capacity = 0)
			: FixedVec(buffer.data_, buffer.size_, capacity)
		{}

		/// 构造 - 转移
		FixedVec(FixedVec&& buffer)
			: FixedVec()
		{
			this->swap(buffer);
		}

		/// 构建 - 复制输入数据
		FixedVec(const T* data, size_t size, size_t capacity = 0)
			: capacity_(std::max(capacity, size)), size_(size), data_()
		{
			if (capacity_ > 0) {
                data_ = new T[capacity_];
				if(data) ::memcpy(begin(), data, size_in_bytes());
			}
		}

		/// 销毁
		~FixedVec() { release(); }
	public:
		/// 获取尺寸
		size_t size() const { return size_; }
		
		/// 获取容量
		size_t capacity() const { return capacity_; }
		
		/// 判断是否为空
		bool empty() const { return size() == 0; }
		
		/// 数据占据的字节数
		size_t size_in_bytes() const { return size() * sizeof(T); }
		
		/// 访问元素
		T& operator[](size_t i) { return data_[i]; }
		
		/// 访问元素
		const T& operator[](size_t i) const { return data_[i]; }
		
		/// 访问元素
		T& at(size_t i) { ensure(i >= 0 && i < size()); return data_[i]; }
		
		/// 访问元素
		const T& at(size_t i) const { ensure(i >= 0 && i < size()); return data_[i]; }
	public:
		/// 获取首迭代器
		T* begin() { return data_; }

		/// 获取首迭代器 - 只读
		const T* begin() const { return data_; }

		/// 获取尾迭代器
		T* end() { return begin() + size(); }

		/// 获取尾迭代器 - 只读
		const T* end() const { return begin() + size(); }
	public:
		/// 清空数据
		void clear() { size_ = 0; }

		/// 改变尺寸，扩展部分值未定义
		void resize(size_t size) 
		{
			reserve(size);
            size_ = size;
		}

		/// 释放空间
		void release() 
		{
			delete[] data_;
            capacity_ = 0;
            size_ = 0;
            data_ = nullptr;
		}

		/// 预留容量
		void reserve(size_t capacity)
		{
			if(this->capacity() < capacity) {
				*this = FixedVec(*this, capacity);	//move assign
			}
		}

		/// 交换
		void swap(FixedVec& buffer)
		{
			std::swap(capacity_, buffer.capacity_);
			std::swap(size_, buffer.size_);
			std::swap(data_, buffer.data_);
		}		
	public:
		/// 赋值
		FixedVec& operator=(const FixedVec& buffer)
		{
			return assign(buffer.begin(), buffer.size());
		}

		/// 赋值 - 转移
		FixedVec& operator=(FixedVec&& buffer)
		{
			this->swap(buffer);
			return *this;
		}

		/// 设置数据
		FixedVec& assign(const T* data, size_t size)
		{
			if (size > capacity()) {
				*this = FixedVec(data, size);			//move assign
			}
			else if (data != data_) {
                size_ = size;
				::memcpy(data_, data, size_in_bytes());
			}
			return *this;
		}
	public:
		/// 等值判断
		bool operator==(const FixedVec& buffer)
		{
			if(buffer.size() != size()) return false;
			int n = ::memcmp(begin(), buffer.begin(), size_in_bytes());
			return n == 0;
		}
	private:
		size_t capacity_{};
		size_t size_{};
		T* data_{};
	};


	using ArrayBuffer = FixedVec<UByte>;


	/** BufferSegment.
	 *  
	 *  缓冲区片段，用于分段访问同一个缓冲区。
	 */
	template<typename T>
	class BufferSegment
	{
	public:
		/// 创建片段
		BufferSegment(T* buffer = nullptr) { attach(buffer); }

		void attach(T* buffer)
		{
			m_offset = 0;
			m_buffer = buffer; 
		}
	public:
		/// 获取数据尺寸
		int size() const { return m_buffer->size() - m_offset; }			
		/// 获取数据起点
		UByte* begin() { return m_buffer->begin() + m_offset; }
		/// 判断是否村存在数据
		bool empty() { return size() == 0; }

		/// 弹出起始数据
		void pop_front(int size) { m_offset += size; }
	private:
		T* m_buffer{};
		int m_offset{};
	};

}


