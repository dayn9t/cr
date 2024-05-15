#pragma once

#include "template_io.hpp"
#include "template_equals.hpp"


#define cr_template_reflexible(T1) 


/// 定义结构体模板反射（含1个字段）
#define cr_template_struct_1f(S, f1) \
	cr_template_reflexible(S) \
	cr_template_io_1f(S, f1) \
	cr_template_equals_1f(S, f1)

/// 定义结构体模板反射（含2个字段）
#define cr_template_struct_2f(S, f1, f2) \
	cr_template_reflexible(S) \
	cr_template_io_2f(S, f1, f2) \
	cr_template_equals_2f(S, f1, f2)

/// 定义结构体模板反射（含3个字段）
#define cr_template_struct_3f(S, f1, f2, f3) \
	cr_template_reflexible(S) \
	cr_template_io_3f(S, f1, f2, f3) \
	cr_template_equals_3f(S, f1, f2, f3)

/// 定义结构体模板反射（含4个字段）
#define cr_template_struct_4f(S, f1, f2, f3, f4) \
	cr_template_reflexible(S) \
	cr_template_io_4f(S, f1, f2, f3, f4) \
	cr_template_equals_4f(S, f1, f2, f3, f4)

/// 定义结构体模板反射（含5个字段）
#define cr_template_struct_5f(S, f1, f2, f3, f4, f5) \
	cr_template_reflexible(S) \
	cr_template_io_5f(S, f1, f2, f3, f4, f5) \
	cr_template_equals_5f(S, f1, f2, f3, f4, f5)

/// 定义结构体模板反射（含6个字段）
#define cr_template_struct_6f(S, f1, f2, f3, f4, f5, f6) \
	cr_template_reflexible(S) \
	cr_template_io_6f(S, f1, f2, f3, f4, f5, f6) \
	cr_template_equals_6f(S, f1, f2, f3, f4, f5, f6)

/// 定义结构体模板反射（含7个字段）
#define cr_template_struct_7f(S, f1, f2, f3, f4, f5, f6, f7) \
	cr_template_reflexible(S) \
	cr_template_io_7f(S, f1, f2, f3, f4, f5, f6, f7) \
	cr_template_equals_7f(S, f1, f2, f3, f4, f5, f6, f7)

/// 定义结构体模板反射（含8个字段）
#define cr_template_struct_8f(S, f1, f2, f3, f4, f5, f6, f7, f8) \
	cr_template_reflexible(S) \
	cr_template_io_8f(S, f1, f2, f3, f4, f5, f6, f7, f8) \
	cr_template_equals_8f(S, f1, f2, f3, f4, f5, f6, f7, f8)

/// 定义结构体模板反射（含9个字段）
#define cr_template_struct_9f(S, f1, f2, f3, f4, f5, f6, f7, f8, f9) \
	cr_template_reflexible(S) \
	cr_template_io_9f(S, f1, f2, f3, f4, f5, f6, f7, f8, f9) \
	cr_template_equals_9f(S, f1, f2, f3, f4, f5, f6, f7, f8, f9)

/// 定义结构体模板反射（含10个字段）
#define cr_template_struct_10f(S, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10) \
	cr_template_reflexible(S) \
	cr_template_io_10f(S, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10) \
	cr_template_equals_10f(S, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10)

