#pragma once
#include <map>
#include <string_view>
#include <string>

namespace cr
{
    using std::string;
    using std::string_view;

    /// 字符串映射
    using StrMap = std::map<string, string>;


    class StrX
    {
    public:
        template <size_t N>
        explicit StrX(char (&char_array)[N])
            : m_ptr(char_array), m_capacity(N)
        {
        }

    public:
        /// 转化字符串
        string to_string() const
        {
            return string(m_ptr);
        }

        /// 获取数据
        char* data()
        {
            return m_ptr;
        }

    public:
        /// 用零结尾字符串赋值
        StrX& operator=(const char* p);

    private:
        char* m_ptr;
        size_t m_capacity;
    };

    //strncpy(d.serial_number, info.serial_number.c_str(), CR_SN_MAX_LEN);
}
