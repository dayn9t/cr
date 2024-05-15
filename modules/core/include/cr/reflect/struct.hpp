#pragma once

#include "vector_op.hpp"
#include "equals.hpp"

namespace cr {

	/// 默认is_reflexible模板，必要时导入到特定的名字空间
	template<typename T>
	struct is_reflexible { static const bool value = false; };

}

using cr::is_reflexible;

/// 声明本类型可被反射(特化cr::is_reflexible)
//#define cr_reflexible(T1) template <> struct is_reflexible<T1> { static const bool value = true; };
#define cr_reflexible(T1) 


/// 定义结构体反射（含1字段）
#define cr_struct_1f(T, f1) \
	cr_reflexible(T) \
	cr_io_1f(T, f1) \
	cr_equals_1f(T, f1)

/// 定义结构体反射（含2字段）
#define cr_struct_2f(T, f1, f2) \
	cr_reflexible(T) \
	cr_io_2f(T, f1, f2) \
	cr_equals_2f(T, f1, f2)

/// 定义结构体反射（含3字段）
#define cr_struct_3f(T, f1, f2, f3) \
	cr_reflexible(T) \
	cr_io_3f(T, f1, f2, f3) \
	cr_equals_3f(T, f1, f2, f3)

/// 定义结构体反射（含4字段）
#define cr_struct_4f(T, f1, f2, f3, f4) \
	cr_reflexible(T) \
	cr_io_4f(T, f1, f2, f3, f4) \
	cr_equals_4f(T, f1, f2, f3, f4)

/// 定义结构体反射（含5字段）
#define cr_struct_5f(T, f1, f2, f3, f4, f5) \
	cr_reflexible(T) \
	cr_io_5f(T, f1, f2, f3, f4, f5) \
	cr_equals_5f(T, f1, f2, f3, f4, f5)

/// 定义结构体反射（含6字段）
#define cr_struct_6f(T, f1, f2, f3, f4, f5, f6) \
	cr_reflexible(T) \
	cr_io_6f(T, f1, f2, f3, f4, f5, f6) \
	cr_equals_6f(T, f1, f2, f3, f4, f5, f6)

/// 定义结构体反射（含7字段）
#define cr_struct_7f(T, f1, f2, f3, f4, f5, f6, f7) \
	cr_reflexible(T) \
	cr_io_7f(T, f1, f2, f3, f4, f5, f6, f7) \
	cr_equals_7f(T, f1, f2, f3, f4, f5, f6, f7)

/// 定义结构体反射（含8字段）
#define cr_struct_8f(T, f1, f2, f3, f4, f5, f6, f7, f8) \
	cr_reflexible(T) \
	cr_io_8f(T, f1, f2, f3, f4, f5, f6, f7, f8) \
	cr_equals_8f(T, f1, f2, f3, f4, f5, f6, f7, f8)

/// 定义结构体反射（含9字段）
#define cr_struct_9f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9) \
	cr_reflexible(T) \
	cr_io_9f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9) \
	cr_equals_9f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9)

/// 定义结构体反射（含10字段）
#define cr_struct_10f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10) \
	cr_reflexible(T) \
	cr_io_10f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10) \
	cr_equals_10f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10)

/// 定义结构体反射（含11字段）
#define cr_struct_11f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11) \
	cr_reflexible(T) \
	cr_io_11f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11) \
	cr_equals_11f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11)

/// 定义结构体反射（含12字段）
#define cr_struct_12f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12) \
	cr_reflexible(T) \
	cr_io_12f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12) \
	cr_equals_12f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12)

