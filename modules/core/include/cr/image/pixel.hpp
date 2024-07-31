#pragma once

#include <cr/basic.hpp>
#include <cr/reflect/struct.hpp>


namespace cr {

	///三通道数据
	struct U3C
	{
		U8 c[3];

		///判断各通道值是否一致
		bool same_value() const 
		{
			return c[0] == c[1] && c[0] == c[2];
		}
	};
	static_assert(sizeof(U3C) == 3, "U3C != 3");
	//cx_struct_1f(U3C, c);


	///四通道数据
	struct U4C
	{
		U8 c[4];
	};
	static_assert(sizeof(U4C) == 4, "U4C != 4");
	//cx_struct_1f(U4C, c);


	/// 类型转字节
	template<typename T>
	U8 to_ubyte(T v)
	{
		if (v > 255) v = 255;
		if (v < 0) v = 0;
		return (U8)v;
	}
}
