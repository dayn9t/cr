#pragma once

namespace cr {
	namespace reflect {

		/// 反射测试
		struct TestOp {
			template<typename T>
			void operator()(T t, string name)
			{
				cout << typeid(t).name() << '\t' << name << ":\t" << t << endl;
			}
		};

		/// 获取行字符
		struct RowStr {
			string s;
			template<typename T>
			void operator()(T t, string name)
			{
				s += '\t' + xtl::str(t);
			}
		};

		
		//获取记录的所有field名称
		class GetNames {
		public:
			vector<string>	names;
			template<typename T>
			void operator()(T, string name)
			{
				names.push_back(name);
				
			}
		};

		//获取记录的所有field值
		class GetValues {
		public:
			vector<string>	values;
			template<typename T>
			void operator()(const T& t, string)
			{
				values.push_back(xtl::str(t));
				
			}
		};

	}

}
