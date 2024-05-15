#if 0
#pragma once

#include "../cutil.h"
/*
	检查以确保两个类型有一致的布局，需要保证每个对应字段都有同样的长度和偏移量
*/

/// 检查两个类型的字段是有拥有同样的大小和偏移量(1字段)
#define cr_layout_assert1(T1, T2, f1) \
	static_assert(cr_same_offset_size(T1, T2, f1), #T1 " & " #T2 " field:" #f1 " not match");

/// 检查两个类型的字段是有拥有同样的大小和偏移量(2字段)
#define cr_layout_assert2(T1, T2, f1, f2) \
	static_assert(cr_same_offset_size(T1, T2, f1), #T1 " & " #T2 " field:" #f1 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f2), #T1 " & " #T2 " field:" #f2 " not match");

/// 检查两个类型的字段是有拥有同样的大小和偏移量(3字段)
#define cr_layout_assert3(T1, T2, f1, f2, f3) \
	static_assert(cr_same_offset_size(T1, T2, f1), #T1 " & " #T2 " field:" #f1 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f2), #T1 " & " #T2 " field:" #f2 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f3), #T1 " & " #T2 " field:" #f3 " not match");

/// 检查两个类型的字段是有拥有同样的大小和偏移量(4字段)
#define cr_layout_assert4(T1, T2, f1, f2, f3, f4) \
	static_assert(cr_same_offset_size(T1, T2, f1), #T1 " & " #T2 " field:" #f1 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f2), #T1 " & " #T2 " field:" #f2 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f3), #T1 " & " #T2 " field:" #f3 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f4), #T1 " & " #T2 " field:" #f4 " not match");

/// 检查两个类型的字段是有拥有同样的大小和偏移量(5字段)
#define cr_layout_assert5(T1, T2, f1, f2, f3, f4, f5) \
	static_assert(cr_same_offset_size(T1, T2, f1), #T1 " & " #T2 " field:" #f1 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f2), #T1 " & " #T2 " field:" #f2 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f3), #T1 " & " #T2 " field:" #f3 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f4), #T1 " & " #T2 " field:" #f4 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f5), #T1 " & " #T2 " field:" #f5 " not match");

/// 检查两个类型的字段是有拥有同样的大小和偏移量(6字段)
#define cr_layout_assert6(T1, T2, f1, f2, f3, f4, f5, f6) \
	static_assert(cr_same_offset_size(T1, T2, f1), #T1 " & " #T2 " field:" #f1 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f2), #T1 " & " #T2 " field:" #f2 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f3), #T1 " & " #T2 " field:" #f3 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f4), #T1 " & " #T2 " field:" #f4 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f5), #T1 " & " #T2 " field:" #f5 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f6), #T1 " & " #T2 " field:" #f6 " not match");

/// 检查两个类型的字段是有拥有同样的大小和偏移量(7字段)
#define cr_layout_assert7(T1, T2, f1, f2, f3, f4, f5, f6, f7) \
	static_assert(cr_same_offset_size(T1, T2, f1), #T1 " & " #T2 " field:" #f1 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f2), #T1 " & " #T2 " field:" #f2 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f3), #T1 " & " #T2 " field:" #f3 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f4), #T1 " & " #T2 " field:" #f4 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f5), #T1 " & " #T2 " field:" #f5 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f6), #T1 " & " #T2 " field:" #f6 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f7), #T1 " & " #T2 " field:" #f7 " not match");

/// 检查两个类型的字段是有拥有同样的大小和偏移量(8字段)
#define cr_layout_assert8(T1, T2, f1, f2, f3, f4, f5, f6, f7, f8) \
	static_assert(cr_same_offset_size(T1, T2, f1), #T1 " & " #T2 " field:" #f1 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f2), #T1 " & " #T2 " field:" #f2 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f3), #T1 " & " #T2 " field:" #f3 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f4), #T1 " & " #T2 " field:" #f4 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f5), #T1 " & " #T2 " field:" #f5 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f6), #T1 " & " #T2 " field:" #f6 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f7), #T1 " & " #T2 " field:" #f7 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f8), #T1 " & " #T2 " field:" #f8 " not match");

/// 检查两个类型的字段是有拥有同样的大小和偏移量(9字段)
#define cr_layout_assert9(T1, T2, f1, f2, f3, f4, f5, f6, f7, f8, f9) \
	static_assert(cr_same_offset_size(T1, T2, f1), #T1 " & " #T2 " field:" #f1 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f2), #T1 " & " #T2 " field:" #f2 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f3), #T1 " & " #T2 " field:" #f3 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f4), #T1 " & " #T2 " field:" #f4 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f5), #T1 " & " #T2 " field:" #f5 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f6), #T1 " & " #T2 " field:" #f6 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f7), #T1 " & " #T2 " field:" #f7 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f8), #T1 " & " #T2 " field:" #f8 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f9), #T1 " & " #T2 " field:" #f9 " not match");

/// 检查两个类型的字段是有拥有同样的大小和偏移量(10字段)
#define cr_layout_assert10(T1, T2, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10) \
	static_assert(cr_same_offset_size(T1, T2, f1), #T1 " & " #T2 " field:" #f1 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f2), #T1 " & " #T2 " field:" #f2 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f3), #T1 " & " #T2 " field:" #f3 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f4), #T1 " & " #T2 " field:" #f4 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f5), #T1 " & " #T2 " field:" #f5 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f6), #T1 " & " #T2 " field:" #f6 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f7), #T1 " & " #T2 " field:" #f7 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f8), #T1 " & " #T2 " field:" #f8 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f9), #T1 " & " #T2 " field:" #f9 " not match"); \
	static_assert(cr_same_offset_size(T1, T2, f10), #T1 " & " #T2 " field:" #f10 " not match");

#endif