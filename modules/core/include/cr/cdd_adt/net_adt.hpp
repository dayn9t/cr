#pragma once

#include "str_adt.hpp"
#include <cr/cdd/net.h>

namespace cr
{
    /// 解析 URL 字符串
    bool parse_url(string_view url_str, CrEndpoint& endpoint, CrAuthInfo& auth, string& path, StrMap& queries);
}
