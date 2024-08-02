#pragma once

#include "geo.h"

/// 色彩格式定义
typedef enum CrColorFormat_ {
    CR_CF_UNKNOWN,
    CR_CF_RGB,
    CR_CF_BGR,
    CR_CF_RGB_P,
    CR_CF_BGR_P,
    CR_CF_GRAY,
    CR_CF_NV12,
    CR_CF_NV21,
} CrColorFormat;

/// 图像通道
typedef struct CrImageChannel_ {
    /// 图像尺寸
    CrSize size;
    /// 行偏移
    int pitch;
    /// 列步长, 一般: 平面排列为1, 交错排列如RGB为3
    int col_step;
    /// 数据指针
    U8 *data;
} CrImageChannel;

/// 图像
typedef struct CrImageC {
    /// 色彩格式
    CrColorFormat format;
    /// 图像尺寸
    CrSize size;
    /// 图像通道数量
    U32 channel_num;
    /// 图像通道数量
    CrImageChannel channels[8];
} CrImage;
