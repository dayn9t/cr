#pragma once

#include <cr/util/util.hpp>

/// 声明类型补全函数，类型有1个字段
#define cr_complete_1f(T, f1) \
	inline void complete(T& t1, const T& t2) { \
		cr::or_set(t1.f1, t2.f1); \
	}

/// 声明类型补全函数，类型有2个字段
#define cr_complete_2f(T, f1, f2) \
	inline void complete(T& t1, const T& t2) { \
		cr::or_set(t1.f1, t2.f1); \
		cr::or_set(t1.f2, t2.f2); \
	}

/// 声明类型补全函数，类型有3个字段
#define cr_complete_3f(T, f1, f2, f3) \
	inline void complete(T& t1, const T& t2) { \
		cr::or_set(t1.f1, t2.f1); \
		cr::or_set(t1.f2, t2.f2); \
		cr::or_set(t1.f3, t2.f3); \
	}
	

/// 声明类型补全函数，类型有4个字段
#define cr_complete_4f(T, f1, f2, f3, f4) \
	inline void complete(T& t1, const T& t2) { \
		cr::or_set(t1.f1, t2.f1); \
		cr::or_set(t1.f2, t2.f2); \
		cr::or_set(t1.f3, t2.f3); \
		cr::or_set(t1.f4, t2.f4); \
	}
	

/// 声明类型补全函数，类型有5个字段
#define cr_complete_5f(T, f1, f2, f3, f4, f5) \
	inline void complete(T& t1, const T& t2) { \
		cr::or_set(t1.f1, t2.f1); \
		cr::or_set(t1.f2, t2.f2); \
		cr::or_set(t1.f3, t2.f3); \
		cr::or_set(t1.f4, t2.f4); \
		cr::or_set(t1.f5, t2.f5); \
	}
	

/// 声明类型补全函数，类型有6个字段
#define cr_complete_6f(T, f1, f2, f3, f4, f5, f6) \
	inline void complete(T& t1, const T& t2) { \
		cr::or_set(t1.f1, t2.f1); \
		cr::or_set(t1.f2, t2.f2); \
		cr::or_set(t1.f3, t2.f3); \
		cr::or_set(t1.f4, t2.f4); \
		cr::or_set(t1.f5, t2.f5); \
		cr::or_set(t1.f6, t2.f6); \
	}
	

/// 声明类型补全函数，类型有7个字段
#define cr_complete_7f(T, f1, f2, f3, f4, f5, f6, f7) \
	inline void complete(T& t1, const T& t2) { \
		cr::or_set(t1.f1, t2.f1); \
		cr::or_set(t1.f2, t2.f2); \
		cr::or_set(t1.f3, t2.f3); \
		cr::or_set(t1.f4, t2.f4); \
		cr::or_set(t1.f5, t2.f5); \
		cr::or_set(t1.f6, t2.f6); \
		cr::or_set(t1.f7, t2.f7); \
	}
	


/// 声明类型补全函数，类型有8个字段
#define cr_complete_8f(T, f1, f2, f3, f4, f5, f6, f7, f8) \
	inline void complete(T& t1, const T& t2) { \
		cr::or_set(t1.f1, t2.f1); \
		cr::or_set(t1.f2, t2.f2); \
		cr::or_set(t1.f3, t2.f3); \
		cr::or_set(t1.f4, t2.f4); \
		cr::or_set(t1.f5, t2.f5); \
		cr::or_set(t1.f6, t2.f6); \
		cr::or_set(t1.f7, t2.f7); \
		cr::or_set(t1.f8, t2.f8); \
	}
	


/// 声明类型补全函数，类型有9个字段
#define cr_complete_9f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9) \
	inline void complete(T& t1, const T& t2) { \
		cr::or_set(t1.f1, t2.f1); \
		cr::or_set(t1.f2, t2.f2); \
		cr::or_set(t1.f3, t2.f3); \
		cr::or_set(t1.f4, t2.f4); \
		cr::or_set(t1.f5, t2.f5); \
		cr::or_set(t1.f6, t2.f6); \
		cr::or_set(t1.f7, t2.f7); \
		cr::or_set(t1.f8, t2.f8); \
		cr::or_set(t1.f9, t2.f9); \
	}
	


/// 声明类型补全函数，类型有10个字段
#define cr_complete_10f(T, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10) \
	inline void complete(T& t1, const T& t2) { \
		cr::or_set(t1.f1, t2.f1); \
		cr::or_set(t1.f2, t2.f2); \
		cr::or_set(t1.f3, t2.f3); \
		cr::or_set(t1.f4, t2.f4); \
		cr::or_set(t1.f5, t2.f5); \
		cr::or_set(t1.f6, t2.f6); \
		cr::or_set(t1.f7, t2.f7); \
		cr::or_set(t1.f8, t2.f8); \
		cr::or_set(t1.f9, t2.f9); \
		cr::or_set(t1.f10, t2.f10; \
	}
	

