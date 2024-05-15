#pragma once

/// 定义结构体相等函数（含1字段）
#define cr_equals_1f(T, f1) \
	inline bool operator==(const T& t1, const T& t2) { \
		return t1.f1 == t2.f1; \
	} \
	inline bool operator!=(const T& t1, const T& t2) { return !(t1 == t2); }

/// 定义结构体相等函数（含2字段）
#define cr_equals_2f(T, f1, f2) \
	inline bool operator==(const T& t1, const T& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2; \
	} \
	inline bool operator!=(const T& t1, const T& t2) { return !(t1 == t2); }

/// 定义结构体相等函数（含3字段）
#define cr_equals_3f(T, f1, f2, f3) \
	inline bool operator==(const T& t1, const T& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3; \
	} \
	inline bool operator!=(const T& t1, const T& t2) { return !(t1 == t2); }

/// 定义结构体相等函数（含4字段）
#define cr_equals_4f(T, f1, f2, f3, f4) \
	inline bool operator==(const T& t1, const T& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4; \
	} \
	inline bool operator!=(const T& t1, const T& t2) { return !(t1 == t2); }

/// 定义结构体相等函数（含5字段）
#define cr_equals_5f(T, f1, f2, f3, f4, f5) \
	inline bool operator==(const T& t1, const T& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4 \
			&& t1.f5 == t2.f5; \
	} \
	inline bool operator!=(const T& t1, const T& t2) { return !(t1 == t2); }

/// 定义结构体相等函数（含6字段）
#define cr_equals_6f(T, f1, f2, f3, f4, f5, f6) \
	inline bool operator==(const T& t1, const T& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4 \
			&& t1.f5 == t2.f5 \
			&& t1.f6 == t2.f6; \
	} \
	inline bool operator!=(const T& t1, const T& t2) { return !(t1 == t2); }

/// 定义结构体相等函数（含7字段）
#define cr_equals_7f(T, f1, f2, f3, f4, f5, f6, f7) \
	inline bool operator==(const T& t1, const T& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4 \
			&& t1.f5 == t2.f5 \
			&& t1.f6 == t2.f6 \
			&& t1.f7 == t2.f7; \
	} \
	inline bool operator!=(const T& t1, const T& t2) { return !(t1 == t2); }


/// 定义结构体相等函数（含8字段）
#define cr_equals_8f(T, f1, f2, f3, f4, f5, f6, f7, f8) \
	inline bool operator==(const T& t1, const T& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4 \
			&& t1.f5 == t2.f5 \
			&& t1.f6 == t2.f6 \
			&& t1.f7 == t2.f7 \
			&& t1.f8 == t2.f8; \
	} \
	inline bool operator!=(const T& t1, const T& t2) { return !(t1 == t2); }


/// 定义结构体相等函数（含9字段）
#define cr_equals_9f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9) \
	inline bool operator==(const T& t1, const T& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4 \
			&& t1.f5 == t2.f5 \
			&& t1.f6 == t2.f6 \
			&& t1.f7 == t2.f7 \
			&& t1.f8 == t2.f8 \
			&& t1.f9 == t2.f9; \
	} \
	inline bool operator!=(const T& t1, const T& t2) { return !(t1 == t2); }


/// 定义结构体相等函数（含10字段）
#define cr_equals_10f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10) \
	inline bool operator==(const T& t1, const T& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4 \
			&& t1.f5 == t2.f5 \
			&& t1.f6 == t2.f6 \
			&& t1.f7 == t2.f7 \
			&& t1.f8 == t2.f8 \
			&& t1.f9 == t2.f9 \
			&& t1.f10 == t2.f10; \
		} \
	inline bool operator!=(const T& t1, const T& t2) { return !(t1 == t2); }


/// 定义结构体相等函数（含11字段）
#define cr_equals_11f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11) \
	inline bool operator==(const T& t1, const T& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4 \
			&& t1.f5 == t2.f5 \
			&& t1.f6 == t2.f6 \
			&& t1.f7 == t2.f7 \
			&& t1.f8 == t2.f8 \
			&& t1.f9 == t2.f9 \
			&& t1.f10 == t2.f10 \
			&& t1.f11 == t2.f11; \
		} \
	inline bool operator!=(const T& t1, const T& t2) { return !(t1 == t2); }


/// 定义结构体相等函数（含12字段）
#define cr_equals_12f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12) \
	inline bool operator==(const T& t1, const T& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4 \
			&& t1.f5 == t2.f5 \
			&& t1.f6 == t2.f6 \
			&& t1.f7 == t2.f7 \
			&& t1.f8 == t2.f8 \
			&& t1.f9 == t2.f9 \
			&& t1.f10 == t2.f10 \
			&& t1.f11 == t2.f11 \
			&& t1.f12 == t2.f12; \
		} \
	inline bool operator!=(const T& t1, const T& t2) { return !(t1 == t2); }
