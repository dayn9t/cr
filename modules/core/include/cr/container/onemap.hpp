#pragma once

#include <initializer_list>
#include <cr/basic.hpp>

namespace cr {

	///OneMap无效key异常
	template<typename T>
	struct OneMapInvalidKey
	{
		T key;
	};

	/** 一一映射.
	 *  两个类型T1和T2是一一对应关系，可通过一个查询另一个。
	 */
	template<typename T1, typename T2, typename E1 = OneMapInvalidKey<T1>, typename E2 = OneMapInvalidKey<T2>>
	class OneMap
	{
	public:
		typedef std::pair<T1, T2> Element;
		OneMap(std::initializer_list<Element> list)
			: map_(list.begin(), list.end())
		{
		}
	public:
		///根据T1值获取对应T2类型的值，如key无效则返回T2的第一个值
		T2 operator[](T1 key) const
		{
			auto p = find(key);
			assert(!map_.empty());
			return p ? *p : map_[0].second;
		}
		
		
		///根据T2值获取对应T1类型的值，如key无效则返回T1的第一个值
		T1 operator[](T2 key) const
		{
			auto p = find(key);
			assert(!map_.empty());
			return p ? *p : map_[0].first;
		}
		
	public:
		///根据T1值获取对应T2类型的值，如key无效则抛出E1异常
		T2 at(T1 key) const
		{
			auto p = find(key);
            cr_ensure(p);
			return *p;
		}
		
		
		///根据T2值获取对应T1类型的值，如key无效则抛出E2异常
		T1 at(T2 key) const
		{
			auto p = find(key);
            cr_ensure(p);
			return *p;
		}
	public:
		///根据T1值获取对应T2类型的值，如key无效则抛出E1异常
		T2 get(T1 key, T2 default_value) const
		{
			auto p = find(key);
			return p ? *p : default_value;
		}


		///根据T2值获取对应T1类型的值，如key无效则抛出E2异常
		T1 get(T2 key, T1 default_value) const
		{
			auto p = find(key);
			return p ? *p : default_value;
		}
	public:
		//是否包含指定的值
		bool contains(T1 key) const 
		{
			return !!find(key);
		}


		//是否包含指定的值
		bool contains(T2 key) const
		{
			return !!find(key);
		}

	public:
		///根据key查找对应值的指针
		const T2* find(T1 key) const
		{
			for (auto& e : map_) {
				if (e.first == key) { return &e.second; }
			}
			return nullptr;
		}


		///根据key查找对应值的指针
		const T1* find(T2 key) const
		{
			for (auto& e : map_) {
				if (e.second == key) { return &e.first; }
			}
			return nullptr;
		}
	private:
		vector<Element> map_;
	};
}

