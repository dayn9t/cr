#pragma once

#include <cr/basic.hpp>
//#include <type_traits>

namespace cr {

	
	/// 判断对象是否等于其缺省（构造的）值
	template<typename T> bool is_default(const T& v) { return v == T{}; }
	
	template<> inline bool is_default(InString v) { return v.empty(); }
	
	template<typename T> bool is_default(InVector<T> v) { return v.empty(); }
}


