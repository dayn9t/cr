#include <cr/cdd_adt/str_adt.hpp>
#include <iostream>
#include <cstring>

using namespace std;

namespace cr
{
    /*
    StrX& StrX::operator=(const char* p)
    {
        size_t len = std::strlen(p);
        if (len >= m_capacity)
        {
            len = m_capacity - 1;
        }
        std::strncpy(m_ptr, p, len);
        m_ptr[len] = '\0';
        return *this;
    }*/

    /// 用零结尾字符串赋值
    StrX& StrX::operator=(const string_view& s)
    {
        size_t len = s.size();
        if (len >= m_capacity)
        {
            len = m_capacity - 1;
        }
        std::strncpy(m_ptr, s.data(), len);
        m_ptr[len] = '\0';
        return *this;
    }

}
