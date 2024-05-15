#pragma once

/// 定义结构体模板相等函数（含1字段）
#define cr_template_equals_1f(S, f1) \
	template<typename T> \
	inline bool operator==(const S<T>& t1, const S<T>& t2) { \
		return t1.f1 == t2.f1; \
	} \
	template<typename T> \
	inline bool operator!=(const S<T>& t1, const S<T>& t2) { return !(t1 == t2); }

/// 定义结构体模板相等函数（含2字段）
#define cr_template_equals_2f(S, f1, f2) \
	template<typename T> \
	inline bool operator==(const S<T>& t1, const S<T>& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2; \
	} \
	template<typename T> \
	inline bool operator!=(const S<T>& t1, const S<T>& t2) { return !(t1 == t2); }

/// 定义结构体模板相等函数（含3字段）
#define cr_template_equals_3f(S, f1, f2, f3) \
	template<typename T> \
	inline bool operator==(const S<T>& t1, const S<T>& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3; \
	} \
	template<typename T> \
	inline bool operator!=(const S<T>& t1, const S<T>& t2) { return !(t1 == t2); }

/// 定义结构体模板相等函数（含4字段）
#define cr_template_equals_4f(S, f1, f2, f3, f4) \
	template<typename T> \
	inline bool operator==(const S<T>& t1, const S<T>& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4; \
	} \
	template<typename T> \
	inline bool operator!=(const S<T>& t1, const S<T>& t2) { return !(t1 == t2); }

/// 定义结构体模板相等函数（含5字段）
#define cr_template_equals_5f(S, f1, f2, f3, f4, f5) \
	template<typename T> \
	inline bool operator==(const S<T>& t1, const S<T>& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4 \
			&& t1.f5 == t2.f5; \
	} \
	template<typename T> \
	inline bool operator!=(const S<T>& t1, const S<T>& t2) { return !(t1 == t2); }

/// 定义结构体模板相等函数（含6字段）
#define cr_template_equals_6f(S, f1, f2, f3, f4, f5, f6) \
	template<typename T> \
	inline bool operator==(const S<T>& t1, const S<T>& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4 \
			&& t1.f5 == t2.f5 \
			&& t1.f6 == t2.f6; \
	} \
	template<typename T> \
	inline bool operator!=(const S<T>& t1, const S<T>& t2) { return !(t1 == t2); }

/// 定义结构体模板相等函数（含7字段）
#define cr_template_equals_7f(S, f1, f2, f3, f4, f5, f6, f7) \
	template<typename T> \
	inline bool operator==(const S<T>& t1, const S<T>& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4 \
			&& t1.f5 == t2.f5 \
			&& t1.f6 == t2.f6 \
			&& t1.f7 == t2.f7; \
	} \
	template<typename T> \
	inline bool operator!=(const S<T>& t1, const S<T>& t2) { return !(t1 == t2); }


/// 定义结构体模板相等函数（含8字段）
#define cr_template_equals_8f(S, f1, f2, f3, f4, f5, f6, f7, f8) \
	template<typename T> \
	inline bool operator==(const S<T>& t1, const S<T>& t2) { \
		return t1.f1 == t2.f1 \
			&& t1.f2 == t2.f2 \
			&& t1.f3 == t2.f3 \
			&& t1.f4 == t2.f4 \
			&& t1.f5 == t2.f5 \
			&& t1.f6 == t2.f6 \
			&& t1.f7 == t2.f7 \
			&& t1.f8 == t2.f8; \
	} \
	template<typename T> \
	inline bool operator!=(const S<T>& t1, const S<T>& t2) { return !(t1 == t2); }


/// 定义结构体模板相等函数（含9字段）
#define cr_template_equals_9f(S, f1, f2, f3, f4, f5, f6, f7, f8, f9) \
	template<typename T> \
	inline bool operator==(const S<T>& t1, const S<T>& t2) { \
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
	template<typename T> \
	inline bool operator!=(const S<T>& t1, const S<T>& t2) { return !(t1 == t2); }


/// 定义结构体模板相等函数（含10字段）
#define cr_template_equals_10f(S, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10) \
	template<typename T> \
	inline bool operator==(const S<T>& t1, const S<T>& t2) { \
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
	template<typename T> \
	inline bool operator!=(const S<T>& t1, const S<T>& t2) { return !(t1 == t2); }

