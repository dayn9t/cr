#pragma once

#include <cr/basic.hpp>

namespace cr {

	/// Jason字段翻译接口
	struct ITextTranslate
	{
		virtual ~ITextTranslate() {}

		/// 翻译字段名称
		virtual const char* translate(const char* field_name) const = 0;
	};
}
