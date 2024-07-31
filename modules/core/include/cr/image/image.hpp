#pragma once

#include "image_channel.hpp"
#include <cr/cdd/image.h>
#include <utility>

namespace cr {

    /// 色彩格式定义
    enum ColorFormat : int {
        UNKNOW = CR_CF_UNKNOWN,
        RGB = CR_CF_RGB,
        BGR = CR_CF_BGR,
        RGB_P = CR_CF_RGB_P,
        BGR_P = CR_CF_BGR_P,
        //GRAY = CR_CF_GRAY,
        NV12 = CR_CF_NV12,
        NV21 = CR_CF_NV21,
    };


    /// 图像内部数据布局
    class ImageLayout {
    public:
        ImageLayout(CrColorFormat format, Size size, size_t pitch);

    public:
        /// 获取总长度
        size_t total_len() const { return total_len_; }

    public:
        /// 连续放置通道
        ImageChannels lay_channels(U8 *data) const;

    private:
        // 行距
        size_t pitch_;
        // 数据总长度
        size_t total_len_;
        // 各通道尺寸
        vector<Size> sizes_;
        // 各通道偏移量
        vector<size_t> offsets_;
        // 各通道默认颜色
        vector<U8> colors_;
    };


    /// 颜色格式元数据
    struct ImageMeta {
        /// 通道数量
        size_t channel_num;
        /// 通道尺寸系数
        SizeD size_factors[4];
        /// 通道默认颜色
        U8 default_colors[4];

        /// 获取图像通道数据长度
        size_t channel_len(size_t i, size_t max_channel_len) const;

        /// 获取通道尺寸
        Size channel_size(size_t i, Size size) const;
    };

    /// 查找格式的元数据
    const ImageMeta &format_meta(CrColorFormat format);

    /// 图像
    class Image {
    public:
        /// 构建图像 - 空
        Image() = default;

        /// 构建图像
        Image(CrColorFormat format, Size size, U8 *data, size_t pitch = 0);

        /// 构建图像
        Image(CrColorFormat format, Size size, const ImageChannels& channels)
                : format_(format), size_(size), channels_(channels) {}

    public:
        /// 获取图像色彩格式
        CrColorFormat format() const { return format_; }

        /// 获取图像尺寸
        Size size() const { return size_; }

        /// 获取宽度
        int width() const { return size().width; }

        /// 获取高度
        int height() const { return size().height; }

        /// 判定图像是否为空
        bool empty() const { return size_.empty(); }

        /// 获取数据指针
        U8 *data() { return (*this)[0].data(); }

        /// 获取数据指针
        const U8 *data() const { return (*this)[0].data(); }

        /// 获取指定通道
        ImageChannel operator[](size_t i) {
            cr_ensure(i < channels_.size());
            return channels_[i];
        }

        /// 获取指定通道
        const ImageChannel operator[](size_t i) const {
            cr_ensure(i < channels_.size());
            return channels_[i];
        }

        /// 获取图像的所有通道
        ImageChannels &channels() { return channels_; }

        /// 获取图像的所有通道
        const ImageChannels &channels() const { return channels_; }

        /// 获取简要信息
        string brief() const;
    public:
        /// 图像像素设置为默认值
        void clear();

    private:
        // 色彩格式
        CrColorFormat format_ = CR_CF_UNKNOWN;
        // 图像尺寸
        Size size_{};
        // 图像通道
        ImageChannels channels_;
    };

    /// 获取2D尺寸 - Image
    inline Size get_size(const Image &c) { return c.size(); }
}
