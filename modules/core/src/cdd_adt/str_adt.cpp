#include <cr/cdd_adt/str_adt.hpp>
#include <iostream>
#include <cstring>

using namespace std;

namespace cr
{
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
    }
}
