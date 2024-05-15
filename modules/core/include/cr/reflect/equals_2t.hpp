#pragma once

/// 声明两个类型相等判断函数，类型有1个字段
#define cr_equals1f(T1, T2, f1) \
	bool equals(const T1& t1, const T2& t2) { \
		return t1.f1 == t2.f1; \
	}

/// 声明两个类型相等判断函数，类型有2个字段
#define cr_equals_2f(T1, T2, f1, f2) \
	bool operator==(const T1& t1, const T2& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2; \
	} \
	bool operator!=(const T1& t1, const T2& t2) { return !(t1 == t2); }

