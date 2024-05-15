#if 0
#pragma once

#include <cr/basic.hpp>
#include "struct.hpp"
//#include <enab>

namespace cr {

#pragma region 类型信息

	struct FieldInfo;
	
	/// 字段信息集合
	typedef vector<FieldInfo> FieldInfos;

	/// 类型的信息
	struct TypeInfo
	{
		string name;				/// <类型名
		FieldInfos fields;			/// <类型字段信息集合

		bool is_class() const { return true; }
	};
	cr_struct_2f(TypeInfo, name, fields);


	/// 获取类型的类型信息
	template<typename T>
	TypeInfo type_of() { return TypeInfo{ typeid(T).name(), fields_of<T>() }; }

	/// 获取对象的类型信息
	template<typename T>
	TypeInfo type_of(T) { return type_of<T>(); }

#pragma endregion
#pragma region 字段信息


	/// 类型的字段信息
	struct FieldInfo
	{
		TypeInfo	type;
		string		name;
	};
	cr_struct_2f(FieldInfo, type, name);

	/// 用于保存FieldInfos的文档对象
	class FieldInfosArchive
	{
	public:
		FieldInfosArchive(FieldInfos& infos) : m_infos(infos) {}
	public:
		template<typename T>
		void set(string name, T) { m_infos.push_back({ type_of<T>(), name }); }
	private:
		FieldInfos& m_infos;
	};

	/// 获取类型的字段信息(默认无字段)
	template<typename T>
	typename enable_if<!is_reflexible<T>::value, FieldInfos>::type
	fields_of() { return FieldInfos{}; }

	/// 获取对象的字段信息
	template<typename T>
	FieldInfos fields_of(T) { return fields_of<T>(); }

	/// 获取可反射类型的字段信息
	template<typename T>
	typename enable_if<is_reflexible<T>::value, FieldInfos>::type
	fields_of()
	{
		FieldInfos infos{};
		FieldInfosArchive a(infos);
		T v{};
		save(v, a);
		return infos;
	}

#pragma endregion

}

#endif