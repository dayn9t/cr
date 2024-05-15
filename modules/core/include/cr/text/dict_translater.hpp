#pragma once

#include "itranslate.hpp"
#include <map>

namespace cr {

	/// 基于字典的命名互译
	class DictTranslater
		: public ITextTranslate
	{
	public:
		DictTranslater() {}
	public:
		/// 加入一对互译值
		bool put(string s1, string s2)
		{
			m_map[s1] = s2;
			m_map[s2] = s1;
			return true;
		}

		/// 加入一组互译值
		void puts(const std::map<string, string>& dict)
		{
			for (auto& p : dict) {
				put(p.first, p.second);
			}
		}

		/// 翻译
		const char* translate(const char* str) const override
		{
			auto p = m_map.find(str);
			if (p == m_map.end()) return str;
			return p->second.c_str();
		}
	public:
	private:
		std::map<string, string> m_map;
	};
}
