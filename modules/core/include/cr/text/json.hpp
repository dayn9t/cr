#pragma once

#define RAPIDJSON_HAS_STDSTRING 1
#include <cr/basic.hpp>
#include <rapidjson/document.h>
#include <cr/reflect/template_struct.hpp>
//#include <cr/system/file.hpp>
#include <cr/system/time.hpp>
//#include <cr/lang/dyn_enum_code.hpp>
//#include <cr/util/guid.hpp>
#include "itranslate.hpp"
#include <array>
#include <set>
#include <map>
#include <type_traits>

namespace cr {

	using std::array;

	using Allocator = rapidjson::Document::AllocatorType;
	using RValue = rapidjson::Document::ValueType;

	extern const Status JsonFormatError;


	/// Jason文档环境
	struct IJsonEnv
		: public ITextTranslate
	{
		virtual ~IJsonEnv()
		{}

		/// 获取分配器
		virtual Allocator& allocator() = 0;
	};

	/// map元素
	template<typename K, typename V>
	struct MapElement
	{
		K key;
		V value;
	};

	/// load MapElement
	template<typename K, typename V, typename A>
	bool load(MapElement<K, V>& elem, A& archive)
	{
		return archive.get_field("key", elem.key)
			   && archive.get_field("value", elem.value);
	}

	/// save MapElement
	template<typename K, typename V, typename A>
	void save(const MapElement<K, V>& elem, A& archive)
	{
		archive.set_field("key", elem.key);
		archive.set_field("value", elem.value);
	}


	/// JSON值对象，引用语义
	class JsonValue
	{
	public:
		JsonValue(RValue& value, IJsonEnv& env)
			: m_ob(value), m_env(env)
		{}

	public:
		/// 布尔型判定
		bool is_bool() const;

		/// 整型判定
		bool is_int() const;

		/// 无符号整型判定
		bool is_uint() const;

		/// 无符号整型判定
		bool is_uint64() const;

		/// 64位型判定
		bool is_int64() const;

		/// 浮点数判定
		bool is_double() const;

		/// 数值判定
		bool is_number() const;

		/// 字符串判定
		bool is_string() const;

		/// 数组判定
		bool is_array() const;

		/// 对象判定
		bool is_object() const;

	public:

		/// 加载布尔值
		bool get(bool& v) const;

		/// 加载整数
		bool get(int& v) const;

		/// 加载64位整数
		bool get(int64_t& v) const;

		/// 加载无符号整数
		bool get(unsigned& v) const;

		/// 加载无符号整数
		bool get(uint64_t& v) const;

		/// 加载无符号整数
		bool get(UByte& v) const;

		/// 加载浮点数
		bool get(float& v) const;

		/// 加载浮点数
		bool get(double& v) const;

		/// 加载字符串
		bool get(string& v) const;

		/// 读取数组
		template<typename T, size_t N>
		bool get(array<T, N>& arr) const
		{
			if (!is_array()) return false;
			if (m_ob.Size() != N) return false;
			for (size_t i = 0; i < N; ++i) {
				T v{};
				if (!load(v, JsonValue(m_ob[i], m_env))) return false;
				arr[i] = v;
			}
			return true;
		}

		/// 读取向量
		template<typename T>
		bool get(vector<T>& array) const
		{
			if (!is_array()) return false;
			for (rapidjson::SizeType i = 0; i < m_ob.Size(); ++i) {
				T v{};
				JsonValue jv(m_ob[i], m_env);
				load(v, jv);
				array.push_back(v);
			}
			return true;
		}

		/// 读取集合
		template<typename T>
		bool get(std::set<T>& array) const
		{
			if (!is_array()) return false;
			for (rapidjson::SizeType i = 0; i < m_ob.Size(); ++i) {
				T v{};
				if (!load(v, JsonValue(m_ob[i], m_env))) return false;
				array.insert(v);
			}
			return true;
		}

		/// 设置字符串
		void set(const char* s);

		/// 设置字符串
		void set(InString s);

		/// 设置基本类型
		template<typename T>
		void set(const T& v)
		{ m_ob = v; }

		/// 保存数组
		template<typename T, size_t N>
		void set(const array<T, N>& arr)
		{
			set_array(arr);
		}

		/// 保存向量
		template<typename T>
		void set(const vector<T>& arr)
		{
			set_array(arr);
		}

		/// 保存集合
		template<typename T>
		void set(const std::set<T>& arr)
		{
			set_array(arr);
		}


		/// 读取向量
		template<typename K, typename V>
		bool get(std::map<K, V>& m) const
		{
			vector<MapElement<K, V>> arr;
			if (!get(arr)) return false;

			for (auto& e : arr) {
				m[e.key] = e.value;
			}
			return true;
		}

		/// map
		template<typename K, typename V>
		void set(const std::map<K, V>& m)
		{
			vector<MapElement<K, V>> arr;
			for (auto& p : m) {
				MapElement<K, V> e{p.first, p.second};
				arr.push_back(e);
			}

			set_array(arr);
		}

	public:
		/// 判断是否含有指定的成员
		bool has_member(const char* key) const;

		/// 获取字段
		template<typename T>
		bool get_field(const char* key, T& value) const
		{
			key = m_env.translate(key);
            cr_ensure(is_object());
			if (!has_member(key)) return false;
			JsonValue jv(m_ob[key], m_env);
			load(value, jv);
			return true;
		}

		/// 获取字段
		template<typename T>
		T get_field(const char* key) const
		{
			T v{};
			get(key, v);
			return v;
		}

		/// 获取字段，失败则返回指定缺省值
		template<typename T>
		T get_field_or(const char* key, T default_value = T{}) const
		{
			get(key, default_value);
			return default_value;
		}

		/// 设置字段
		template<typename T>
		void set_field(const char* key, const T& value)
		{
			key = m_env.translate(key);
			bool is_class = std::is_class<T>::value;
			RValue v;
			if (is_class) v.SetObject();
			JsonValue o(v, m_env);
			save(value, o);

			if (!m_ob.IsObject()) m_ob.SetObject();

			if (has_member(key)) {
				m_ob[key] = v;
			} else {
				m_ob.AddMember(RValue::StringRefType(key), v, m_env.allocator());
			}
		}

	public:
		RValue& get() const
		{ return m_ob; }

		IJsonEnv& env() const
		{ return m_env; }

	private:
		//保存数组
		template<typename Array>
		void set_array(const Array& arr)
		{
			bool is_class = std::is_class<typename Array::value_type>::value;
			m_ob.SetArray();
			for (auto& elem : arr) {
				RValue v;
				if (is_class) v.SetObject();
				JsonValue jv(v, m_env);
				save(elem, jv);
				m_ob.PushBack(v, m_env.allocator());
			}
		}

	private:
		RValue& m_ob;
		IJsonEnv& m_env;
	};


	/// 加载用基本类型表示的特殊类型
	template<typename Basic, typename T>
	bool imp_load_b2t(T& v, const JsonValue& o)
	{
		Basic s;
		if (!o.get(s)) return false;
		v = T(s);
		return true;
	}


	/// 保存数值型值
	template<typename T>
	typename std::enable_if<std::is_arithmetic<T>::value>::type save(const T& v, JsonValue& o)
	{ o.set(v); }

	/// 加载数值型值
	template<typename T>
	typename std::enable_if<std::is_arithmetic<T>::value, bool>::type load(T& v, const JsonValue& o)
	{ return o.get(v); }

	/// 保存字符串
	inline void save(const char* v, JsonValue& o)
	{ o.set(v); }

	/// 保存字符串
	inline void save(InString v, JsonValue& o)
	{ o.set(v); }

	/// 加载字符串
	inline bool load(string& v, const JsonValue& o)
	{ return o.get(v); }

#if 0
	/// 保存路径
	inline void save(const Path& v, JsonValue& o)
	{ o.set(v.string()); }

	/// 加载路径
	inline bool load(Path& v, const JsonValue& o)
	{ return imp_load_b2t<string>(v, o); }
#endif
	/// 保存时间点
	inline void save(const TimePoint& v, JsonValue& o)
	{ o.set(to_string(v)); }

	/// 加载时间点
	inline bool load(TimePoint& v, const JsonValue& o)
	{
		string s;
		if (!o.get(s)) return false;
		return parse(s, v);
	}

	/// 保存时间长度
	inline void save(const Duration& v, JsonValue& o)
	{
		//o.set(1.0 * v.count() * Duration::period::num / Duration::period::den);
		o.set(v.count() * Duration::period::num / Duration::period::den);    //TODO:兼容api
	}

	/// 加载长度
	inline bool load(Duration& v, const JsonValue& o)
	{
		double s = 0;
		if (!load(s, o)) return false;
		v = Duration(int64_t(s * Duration::period::den / Duration::period::num));
		return true;
	}


	/// 保存时钟时间
	inline void save(const ClockTime& v, JsonValue& o)
	{ o.set(v.to_string()); }

	/// 加载时钟时间
	inline bool load(ClockTime& v, const JsonValue& o)
	{ return imp_load_b2t<string>(v, o); }

	/// 保存DynEnumCode
	inline void save(const DynEnumCode& v, JsonValue& o)
	{ o.set(v.as_int()); }

	/// 加载DynEnumCode
	inline bool load(DynEnumCode& v, const JsonValue& o)
	{ return imp_load_b2t<int>(v, o); }


	/// 保存Guid
	inline void save(const Guid& v, JsonValue& o)
	{ o.set(cx::to_string(v)); }

	/// 加载Guid
	inline bool load(Guid& v, const JsonValue& o)
	{
		string s;
		if (!o.get(s)) return false;
		return parse(s, v);
	}


	/// 保存向量
	template<typename T, size_t N>
	void save(const array<T, N>& v, JsonValue& o)
	{ o.set(v); }

	/// 加载向量
	template<typename T, size_t N>
	bool load(array<T, N>& v, const JsonValue& o)
	{ return o.get(v); }


	/// 保存向量
	template<typename T>
	void save(const vector<T>& v, JsonValue& o)
	{ o.set(v); }

	/// 加载向量
	template<typename T>
	bool load(vector<T>& v, const JsonValue& o)
	{ return o.get(v); }


	/// 保存集合
	template<typename T>
	void save(const std::set<T>& v, JsonValue& o)
	{ o.set(v); }

	/// 加载集合
	template<typename T>
	bool load(std::set<T>& v, const JsonValue& o)
	{ return o.get(v); }


	/// 保存映射
	template<typename K, typename V>
	void save(const std::map<K, V>& v, JsonValue& o)
	{ o.set(v); }

	/// 加载映射
	template<typename K, typename V>
	bool load(std::map<K, V>& v, const JsonValue& o)
	{ return o.get(v); }


	/// 保存枚举型值
	template<typename T>
	typename std::enable_if<std::is_enum<T>::value>::type save(const T& v, JsonValue& o)
	{ o.set(int(v)); }

	/// 加载枚举型值
	template<typename T>
	typename std::enable_if<std::is_enum<T>::value, bool>::type load(T& v, const JsonValue& o)
	{
		int t{};
		if (!o.get(t)) return false;
		v = T(t);
		return true;
	}


	/// JSON文档对象
	/// 大量inline实现代码，不易直接引入
	class JsonDocument
		: public IJsonEnv
	{
	public:
		/// 创建空文档
		JsonDocument(ITextTranslate* transtlater = nullptr);

		/// 解析文档
		JsonDocument(std::string text, ITextTranslate* transtlater = nullptr);

		~JsonDocument();

	public:
		/// 获取文档根对象
		JsonValue root();

		/// 获取字符串
		string to_string(bool pretty = false);

	public:
		/// 获取分配器
		Allocator& allocator() override;

		/// 翻译字段名称
		const char* translate(const char* field_name) const override;

	private:
		rapidjson::Document m_doc;
		ITextTranslate* m_transtlater = nullptr;
	};


	/// 对象序列化为JSON字符串
	template<typename T>
	string to_json(const T& v, ITextTranslate* transtlater = nullptr, bool pretty = false)
	{
		JsonDocument doc(transtlater);
		auto r = doc.root();
		save(v, r);
		return doc.to_string(pretty);
	}

	/// 对象序列化为JSON字符串
	template<typename T>
	string to_json(const T& v, bool pretty)
	{
		JsonDocument doc(nullptr);
		auto r = doc.root();
		save(v, r);
		return doc.to_string(pretty);
	}

	/// 对象从JSON字符串反序列化
	template<typename T>
	Result<T> from_json(InString json, ITextTranslate* transtlater = nullptr)
	{
		T v{};
		Status s = catch_error([&]() {
			JsonDocument doc(json, transtlater);
			auto r = doc.root();
			load(v, r);
		});
		return {s, v};
	}


	/// 从文件读取json对象
	template<typename T>
	Status save_json_file(const T& v, Path json_file, ITextTranslate* transtlater = nullptr, bool pretty = true)
	{
		return save_text_file(to_json(v, transtlater, pretty), json_file);
	}

	/// 对象从JSON字符串反序列化
	template<typename T>
	Result<T> load_json_file(Path json_file, ITextTranslate* transtlater = nullptr)
	{
		return load_text_file(json_file)
			.and_then<T>([&](InString str) { return from_json<T>(str, transtlater); });
	}


	/// 向上搜索并加载JSON对象
	template<typename T>
	Status load_upward(Path file_or_dir, InString file_name, T& info)
	{
		Path file = find_file_upward(file_or_dir, file_name);
		if (file.empty()) return cx_error(CX_NOT_FOUND);
		auto r = load_json_file<T>(file);
		if (!r.ok()) return cx_error(CX_FORMAT_ERR);
		info = r;
		return {};
	}
}
