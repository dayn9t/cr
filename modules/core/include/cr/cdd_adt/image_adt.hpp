#pragma once

#include <cr/cdd/image.h>
#include <cr/image/image.hpp>

namespace cr
{
    /// 从C类型构造 - ImageChannel
    ImageChannel from_c(CrImageChannel& channel);

    /// ImageChannel 转化为C类型
    CrImageChannel to_c(ImageChannel& channel);

    /// 从C类型构造 -Image
    Image from_c(CrImage& image);

    /// 转化为C类型
    CrImage to_c(Image& channel);
}
