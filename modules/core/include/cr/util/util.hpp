#pragma once

//#include <cx/status/status.hpp>
#include <cr/basic.hpp>

namespace cr {

	/// 模仿动态语言的or
	template<typename T>
	T select_or(const T& v1, const T& v2)
	{
		return v1 ? v1 : v2;
	}

	/// 模仿动态语言的and
	template<typename T>
	T select_and(const T& v1, const T& v2)
	{
		return v1 ? v2 : v1;
	}

	/// 如果v1假，则被v2替代
	template<typename T>
	void or_set(T& v1, const T& v2)
	{
		if (!v1) v1 = v2;
	}

	/// 如果v1真，则被v2替代
	template<typename T>
	void and_set(T& v1, const T& v2)
	{
		if (v1) v1 = v2;
	}


	/// 如果值等于old_val，则用new_val替换
	template<typename T>
	void set_if_equal(T& v, const T& old_val, const T& new_val)
	{
		if (v == old_val) v = new_val;
	}

	/// 如果目标为空，则用new_val替换
	template<typename T>
	void set_if_empty(T& val, const T& new_val)
	{
		if (val.empty()) val = new_val;
	}

	/// 如果值等于缺省值，则设置为新值
	template<typename T1, typename T2>
	void set_if_default(T1& val, const T2& new_val)
	{
		if (val == T1{}) val = new_val;
	}

#if 0
	/// 转换为指定类型
	template<typename T1, typename T2>
	T1 convert_to(const T2& v)
	{
		T1 v1{};
		Status s = convert(v, v1);
		s.ensure_ok();
		return v1;
	}
#endif

	/// POD类型强制转换为布局一致的另一个POD
	template<typename T1, typename T2>
	T1 pod_cast(const T2& src)
	{
		static_assert(sizeof(T1) == sizeof(T2), "pod_cast size dismatch");
		return *(T1*)(&src);
	}

	/// 类型直接复制
	template<typename T1, typename T2>
	void pod_copy(const T1& src, T2& dst)
	{
		static_assert(sizeof(T1) == sizeof(T2), "pod_copy size dismatch");
		*(T1*)(&dst) = src;
	}


	/// 类型T2变量当作T1变量
	template<typename T1, typename T2>
	T1& pod_as(T2& v)
	{
		return *reinterpret_cast<T1*>(&v);
	}


	/// 类型作为ubytes
	template<typename T>
	char* as_chars(T& v)
	{
		return reinterpret_cast<char*>(&v);
	}


	/// 类型作为ubytes
	template<typename T>
	U8* as_ubytes(T& v)
	{
		return reinterpret_cast<U8*>(&v);
	}
}