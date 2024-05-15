#pragma once

#include <cr/container/onemap.hpp>
#include <type_traits>

namespace cr {

	/// 获取E类型的值对应的字符串
	template<typename E>
	std::enable_if_t<std::is_enum<E>::value, string> to_string(E value)
	{
		return enum_map(E()).at(value);	//Koenig Lookup
	}


	/// 获取E类型的值对应的字符串
	template<typename E>
	std::enable_if_t<std::is_enum<E>::value, string> to_string(E value, InString default_value)
	{
		return enum_map(E()).get(value, default_value);	//Koenig Lookup
	}


	/// 获取字符串对应的E类型的值
	template<typename E>
	std::enable_if_t<std::is_enum<E>::value, E> to_value(InString str)
	{
		return enum_map(E()).at(str);
	}


	/// 获取字符串对应的E类型的值
	template<typename E>
	std::enable_if_t<std::is_enum<E>::value, E> to_value(InString str, E default_value)
	{
		return enum_map(E()).get(str, default_value);
	}
}

/// 声明一个包含1个值的枚举
#define cr_enum_1v(E, v1) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
	}; \
	return m; \
}


/// 声明一个包含2个值的枚举
#define cr_enum_2v(E, v1, v2) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
	}; \
	return m; \
}


/// 声明一个包含3个值的枚举
#define cr_enum_3v(E, v1, v2, v3) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
	}; \
	return m; \
}


/// 声明一个包含4个值的枚举
#define cr_enum_4v(E, v1, v2, v3, v4) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
	}; \
	return m; \
}


/// 声明一个包含5个值的枚举
#define cr_enum_5v(E, v1, v2, v3, v4, v5) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
	}; \
	return m; \
}


/// 声明一个包含6个值的枚举
#define cr_enum_6v(E, v1, v2, v3, v4, v5, v6) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
	}; \
	return m; \
}


/// 声明一个包含7个值的枚举
#define cr_enum_7v(E, v1, v2, v3, v4, v5, v6, v7) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
	}; \
	return m; \
}


/// 声明一个包含8个值的枚举
#define cr_enum_8v(E, v1, v2, v3, v4, v5, v6, v7, v8) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
	}; \
	return m; \
}


/// 声明一个包含9个值的枚举
#define cr_enum_9v(E, v1, v2, v3, v4, v5, v6, v7, v8, v9) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
		{ E::v9, #v9 }, \
	}; \
	return m; \
}


/// 声明一个包含10个值的枚举
#define cr_enum_10v(E, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
		{ E::v9, #v9 }, \
		{ E::v10, #v10 }, \
	}; \
	return m; \
}


/// 声明一个包含11个值的枚举
#define cr_enum_11v(E, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
		{ E::v9, #v9 }, \
		{ E::v10, #v10 }, \
		{ E::v11, #v11 }, \
	}; \
	return m; \
}


/// 声明一个包含12个值的枚举
#define cr_enum_12v(E, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
		{ E::v9, #v9 }, \
		{ E::v10, #v10 }, \
		{ E::v11, #v11 }, \
		{ E::v12, #v12 }, \
	}; \
	return m; \
}


/// 声明一个包含13个值的枚举
#define cr_enum_13v(E, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
		{ E::v9, #v9 }, \
		{ E::v10, #v10 }, \
		{ E::v11, #v11 }, \
		{ E::v12, #v12 }, \
		{ E::v13, #v13 }, \
	}; \
	return m; \
}


/// 声明一个包含14个值的枚举
#define cr_enum_14v(E, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
		{ E::v9, #v9 }, \
		{ E::v10, #v10 }, \
		{ E::v11, #v11 }, \
		{ E::v12, #v12 }, \
		{ E::v13, #v13 }, \
		{ E::v14, #v14 }, \
	}; \
	return m; \
}


/// 声明一个包含15个值的枚举
#define cr_enum_15v(E, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
		{ E::v9, #v9 }, \
		{ E::v10, #v10 }, \
		{ E::v11, #v11 }, \
		{ E::v12, #v12 }, \
		{ E::v13, #v13 }, \
		{ E::v14, #v14 }, \
		{ E::v15, #v15 }, \
	}; \
	return m; \
}


/// 声明一个包含16个值的枚举
#define cr_enum_16v(E, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
		{ E::v9, #v9 }, \
		{ E::v10, #v10 }, \
		{ E::v11, #v11 }, \
		{ E::v12, #v12 }, \
		{ E::v13, #v13 }, \
		{ E::v14, #v14 }, \
		{ E::v15, #v15 }, \
		{ E::v16, #v16 }, \
	}; \
	return m; \
}


/// 声明一个包含17个值的枚举
#define cr_enum_17v(E, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
		{ E::v9, #v9 }, \
		{ E::v10, #v10 }, \
		{ E::v11, #v11 }, \
		{ E::v12, #v12 }, \
		{ E::v13, #v13 }, \
		{ E::v14, #v14 }, \
		{ E::v15, #v15 }, \
		{ E::v16, #v16 }, \
		{ E::v17, #v17 }, \
	}; \
	return m; \
}


/// 声明一个包含18个值的枚举
#define cr_enum_18v(E, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
		{ E::v9, #v9 }, \
		{ E::v10, #v10 }, \
		{ E::v11, #v11 }, \
		{ E::v12, #v12 }, \
		{ E::v13, #v13 }, \
		{ E::v14, #v14 }, \
		{ E::v15, #v15 }, \
		{ E::v16, #v16 }, \
		{ E::v17, #v17 }, \
		{ E::v18, #v18 }, \
	}; \
	return m; \
}


/// 声明一个包含19个值的枚举
#define cr_enum_19v(E, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
		{ E::v9, #v9 }, \
		{ E::v10, #v10 }, \
		{ E::v11, #v11 }, \
		{ E::v12, #v12 }, \
		{ E::v13, #v13 }, \
		{ E::v14, #v14 }, \
		{ E::v15, #v15 }, \
		{ E::v16, #v16 }, \
		{ E::v17, #v17 }, \
		{ E::v18, #v18 }, \
		{ E::v19, #v19 }, \
	}; \
	return m; \
}


/// 声明一个包含20个值的枚举
#define cr_enum_20v(E, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20) \
inline const cr::OneMap<E, string>& enum_map(E) { \
	static const cr::OneMap<E, string> m{ \
		{ E::v1, #v1 }, \
		{ E::v2, #v2 }, \
		{ E::v3, #v3 }, \
		{ E::v4, #v4 }, \
		{ E::v5, #v5 }, \
		{ E::v6, #v6 }, \
		{ E::v7, #v7 }, \
		{ E::v8, #v8 }, \
		{ E::v9, #v9 }, \
		{ E::v10, #v10 }, \
		{ E::v11, #v11 }, \
		{ E::v12, #v12 }, \
		{ E::v13, #v13 }, \
		{ E::v14, #v14 }, \
		{ E::v15, #v15 }, \
		{ E::v16, #v16 }, \
		{ E::v17, #v17 }, \
		{ E::v18, #v18 }, \
		{ E::v19, #v19 }, \
		{ E::v20, #v20 }, \
	}; \
	return m; \
}
