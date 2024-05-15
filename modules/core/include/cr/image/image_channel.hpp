#pragma once

#include <cr/geo.hpp>
#include <cr/container/array_vec.hpp>

namespace cr {

    /// 图像通道
    class ImageChannel {
    public:
        ImageChannel() = default;

        /// 构造图像通道-从数据成员
        ImageChannel(Size size, UByte *data, int pitch = 0, UByte default_color = 0, int col_step = 1)
                : size_(size), pitch_(pitch ? pitch : size.width), col_step_(col_step), data_(data),
                  default_color_(default_color) {}

    public:
        /// 获取尺寸
        Size size() const { return size_; }

        /// 获取宽度
        int width() const { return size().width; }

        /// 获取高度
        int height() const { return size().height; }

        /// 获取尺寸
        int pitch() const { return pitch_; }

        /// 获取尺寸
        int col_step() const { return col_step_; }

        /// 获取尺寸
        UByte *data() const { return data_; }

        /// 获取简要信息
        string brief() const;

        /// 获取平面对齐后的面积
        size_t pitch_area() const { return pitch_ * size_.height; }

        /// 获取平面内指定行指针
        UByte *row(int i) const { return data_ + pitch_ * i; }

    public:
        /// 数据设置成指定值
        void set_to(UByte value);

        /// 图像像素设置为默认值
        void clear() { set_to(default_color_); }

    private:
        Size size_{};
        int pitch_{};
        int col_step_{};
        UByte *data_{};
        UByte default_color_{};
    };

    /// 图像通道集合
    using ImageChannels = ArrayVec<ImageChannel, 4>;

    /// 获取2D尺寸 - ImageChannel
    inline Size get_size(const ImageChannel &c) { return c.size(); }
}
