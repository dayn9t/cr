#pragma once

#include <string>
#include <sstream>

namespace cr {

    ///一维数据统计信息
    template<typename T, typename S = T>
    struct Stat1DInfo {
        int count;
        T min;
        T max;
        S average;
    };

    /// 一维数据统计
    template<typename T, typename S = T>
    class Stat1D {
    public:
        ///获取元素数量
        int count() const { return count_; }

        ///获取元素总和
        S sum() const { return sum_; }

        ///获取元素平方和
        S sum2() const { return sum2_; }

        ///获取元素最小值
        T min() const { return min_; }

        ///获取元素最大值
        T max() const { return max_; }

        ///获取元素平均值
        T average() const { return count_ ? sum_ / count_ : 0; }

        ///获取统计信息
        Stat1DInfo<T, S> info() const {
            return {count(), min(), max(), average()};
        }

        /// 获取描述字符串
        std::string to_string() const {
            std::ostringstream ss;
            ss << "Stat1D(count=" << count_
               << ", [" << min_
               << ", " << max_
               << "], avg=" << average()
               << ")";
        }

    public:
        ///统计新元素
        Stat1D &operator<<(const T &v) {
            if (count_) {
                if (v < min_) min_ = v;
                else if (v > max_) max_ = v;
            } else {
                min_ = v;
                max_ = v;
            }
            count_++;
            sum_ += v;
            sum2_ += v * v;
            return *this;
        }

        ///清除统计结果
        void clear() {
            count_ = 0;
            sum_ = 0;
            min_ = 0;
            max_ = 0;
        }

    private:
        int count_ = 0;
        S sum_ = 0;
        S sum2_ = 0;
        T min_ = 0;
        T max_ = 0;
    };

}

