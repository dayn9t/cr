#pragma once

/** @file
@brief IO

*/

#include <cr/basic.hpp>
#include <cx/container/array_buffer.hpp>
#include "fs.hpp"
#include <stdio.h>

namespace cr {

	///载入文本文件
	Result<string> load_text_file(Path file);

	///保存文本文件
	Status save_text_file(InString text, Path file);	//TODO:错误处理

	///加载文件到字节缓冲区
	Status load_bytes(Path file, ArrayBuffer& buffer);

	///保存字节缓冲区到文件
	Status save_bytes(const ArrayBuffer& buffer, Path file);

	///加载文件到字节缓冲区
	Result<ArrayBuffer> load_bytes(Path file);

	/**
	* 文件.
	*
	* FILE的封装。
	*/
	class File
	{
	public:
		//读取文件头
		template<typename T>
		static T header(InString file_name)
		{
			T t;
			File file(file_name, "rb");
			file >> t;
			return t;
		}

	public:
		///构造
		File(Path path, InString flag);
		~File();
	public:
		///获取文件打开状态
		explicit operator bool() const { return !!m_fp; }

		///获取文件路径
		Path path() const { return m_path; }

		///获取文件长度
		size_t size();

		///获取文件指针偏移量
		size_t offset();

		///获取内部文件句柄
		FILE* get() { return m_fp; }
	public:
		///读取数据
		template<typename T>
		bool read(T& t)
		{
			size_t size = fread(&t, sizeof(T), 1, m_fp);
			return size == 1;
		}

		///读取多个数据
		template<typename T>
		bool read(T* t, size_t count)
		{
			size_t size = fread(t, sizeof(T), count, m_fp);
			return size == count;
		}

		///读入一部分数据到buffer，不会改变其容量
		bool read(ArrayBuffer& buffer);

		///写入数据
		template<typename T>
		bool write(const T& t)
		{
			size_t size = fwrite(&t, sizeof(T), 1, m_fp);
			return size == 1;
		}

		///写入多个数据
		template<typename T>
		bool write(const T* t, size_t count)
		{
			size_t n = fwrite(t, sizeof(T), count, m_fp);
			return n == count;
		}

		///读取数据
		template<typename T>
		File& operator >> (T& t)
		{
			ensure(read(t));
			return *this;
		}

		///写入数据
		template<typename T>
		File& operator<<(const T& t)
		{
			ensure(write(t));
			return *this;
		}
	public:
		///定位
		bool seek(size_t offset);
		///刷新
		void flush();
	public:
		///写入格式化字符串
		//void printf(InString fmt, int i);
	private:
		const Path m_path;
		FILE* m_fp{};
	};
}
