#pragma once

#include <cr/core_type.hpp>

namespace cr {

	/// 类型名信息
	struct TypeName
	{
		string type;	/// < class/struct/enum
		string name;	/// <类型基本名

		TypeName(InString str);
		string to_string() const;
	};


	/// 获取类型名
	template<typename T>
	string type_name(const T& p)
	{
		return TypeName(typeid(p).name()).name;		
	}
}
