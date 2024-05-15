#pragma once

#include "layout.hpp"
/*
	实质同一的类型间的转换。可声明于namespace，用于避免名字冲突。
*/

/// 同类型默认转换函数
template<typename T>
T stc(T v) { return v; }


/// 声明两个类型完全一样的枚举类型(1字段)
#define cr_same_enum(T1, T2) \
	static_assert(cr_same_size(T1, T2), "type size is not equal"); \
	inline T1 stc(T2 v) { return T1(v); } \
	inline T2 stc(T1 v) { return T2(v); }


/// 声明两个类型完全一样(1字段)
#define cr_same_struct1(T1, T2, f1) \
	cr_layout_assert1(T1, T2, f1) \
	inline T1 stc(T2 v) { return cr_vv_cast(T1, v); } \
	inline T2 stc(T1 v) { return cr_vv_cast(T2, v); }

/// 声明两个类型完全一样(2字段)
#define cr_same_struct2(T1, T2, f1, f2) \
	cr_layout_assert2(T1, T2, f1, f2) \
	inline T1 stc(T2 v) { return cr_vv_cast(T1, v); } \
	inline T2 stc(T1 v) { return cr_vv_cast(T2, v); }

/// 声明两个类型完全一样(3字段)
#define cr_same_struct3(T1, T2, f1, f2, f3) \
	cr_layout_assert3(T1, T2, f1, f2, f3) \
	inline T1 stc(T2 v) { return cr_vv_cast(T1, v); } \
	inline T2 stc(T1 v) { return cr_vv_cast(T2, v); }

/// 声明两个类型完全一样(4字段)
#define cr_same_struct4(T1, T2, f1, f2, f3, f4) \
	cr_layout_assert4(T1, T2, f1, f2, f3, f4) \
	inline T1 stc(T2 v) { return cr_vv_cast(T1, v); } \
	inline T2 stc(T1 v) { return cr_vv_cast(T2, v); }

/// 声明两个类型完全一样(5字段)
#define cr_same_struct5(T1, T2, f1, f2, f3, f4, f5) \
	cr_layout_assert5(T1, T2, f1, f2, f3, f4, f5) \
	inline T1 stc(T2 v) { return cr_vv_cast(T1, v); } \
	inline T2 stc(T1 v) { return cr_vv_cast(T2, v); }

/// 声明两个类型完全一样(6字段)
#define cr_same_struct6(T1, T2, f1, f2, f3, f4, f5, f6) \
	cr_layout_assert6(T1, T2, f1, f2, f3, f4, f5, f6) \
	inline T1 stc(T2 v) { return cr_vv_cast(T1, v); } \
	inline T2 stc(T1 v) { return cr_vv_cast(T2, v); }

/// 声明两个类型完全一样(7字段)
#define cr_same_struct7(T1, T2, f1, f2, f3, f4, f5, f6, f7) \
	cr_layout_assert7(T1, T2, f1, f2, f3, f4, f5, f6, f7) \
	inline T1 stc(T2 v) { return cr_vv_cast(T1, v); } \
	inline T2 stc(T1 v) { return cr_vv_cast(T2, v); }

/// 声明两个类型完全一样(8字段)
#define cr_same_struct8(T1, T2, f1, f2, f3, f4, f5, f6, f7, f8) \
	cr_layout_assert8(T1, T2, f1, f2, f3, f4, f5, f6, f7, f8) \
	inline T1 stc(T2 v) { return cr_vv_cast(T1, v); } \
	inline T2 stc(T1 v) { return cr_vv_cast(T2, v); }

/// 声明两个类型完全一样(9字段)
#define cr_same_struct9(T1, T2, f1, f2, f3, f4, f5, f6, f7, f8, f9) \
	cr_layout_assert9(T1, T2, f1, f2, f3, f4, f5, f6, f7, f8, f9) \
	inline T1 stc(T2 v) { return cr_vv_cast(T1, v); } \
	inline T2 stc(T1 v) { return cr_vv_cast(T2, v); }

/// 声明两个类型完全一样(10字段)
#define cr_same_struct10(T1, T2, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10) \
	cr_layout_assert10(T1, T2, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10) \
	inline T1 stc(T2 v) { return cr_vv_cast(T1, v); } \
	inline T2 stc(T1 v) { return cr_vv_cast(T2, v); }


#if 0
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
