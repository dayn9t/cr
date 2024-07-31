#include <cr/media/img_proc.hpp>
#include "cr/dbc.hpp"
#include <cr/geo.hpp>

namespace cr {
    inline void yuv2rgb_1_b(U8 y, U8 u, U8 v, U8 *r, U8 *g, U8 *b) {
        auto r1 = int(1.164 * (y - 16) + 1.596 * (v - 128));
        *r = r1 < 0 ? 0 : (r1 > 255 ? 255 : r1);
        auto g1 = int(1.164 * (y - 16) - 0.392 * (u - 128) - 0.813 * (v - 128));
        *g = g1 < 0 ? 0 : (g1 > 255 ? 255 : g1);
        auto b1 = int(1.164 * (y - 16) + 2.017 * (u - 128));
        *b = b1 < 0 ? 0 : (b1 > 255 ? 255 : b1);
    }

    // YUV=>RGB 1次
    inline void yuv2rgb_1(float y, float u, float v, float *r, float *g, float *b) {
        *r = 1.164 * (y - 16) + 1.596 * (v - 128);
        *g = 1.164 * (y - 16) - 0.392 * (u - 128) - 0.813 * (v - 128);
        *b = 1.164 * (y - 16) + 2.017 * (u - 128);
    }

    void yuv420_rgb_p3(const ImageChannel &plane_y, const ImageChannel &plane_uv,
                       ImageChannel &plane_r, ImageChannel &plane_g, ImageChannel &plane_b) {
        auto size = plane_y.size();
        cr_ensure(same_size(plane_r, plane_g));//, plane_b));

        for (int y = 0; y < size.height; y++) {
            auto row_y = plane_y.row(y);
            auto row_uv = plane_uv.row(y / 2);
            auto row_r = plane_r.row(y);
            auto row_g = plane_g.row(y);
            auto row_b = plane_b.row(y);
            for (int x = 0; x < size.width; x++) {
                auto uv = row_uv + x / 2 * 2;
                //yuv2rgb_1_b(row_y[x], uv[0], uv[1], row_b + x, row_g + x, row_r + x);
                float r, g, b;
                float m1 = 0;
                float m2 = 255.0;

                yuv2rgb_1(row_y[x], uv[0], uv[1], &r, &g, &b);
                row_b[x] = std::max(std::min(r, m2), m1);
                row_g[x] = std::max(std::min(g, m2), m1);
                row_r[x] = std::max(std::min(b, m2), m1);
            }
        }
    }




    // float=>ubyte 16次
    inline void float2byte_16(float *src, U8 *dst) {
        for (int i = 0; i < 16; i++) {
            dst[i] = src[i] < 0 ? 0 : U8(src[i] > 255 ? 255 : src[i]);
        }
    }

    // YUV=>RGB 16次
    inline void yuv2rgb_16(U8 *y, float *u16, float *v16, U8 *r, U8 *g, U8 *b) {
        float y16[16];
        float r16[16];
        float g16[16];
        float b16[16];
        for (int i = 0; i < 16; i++) {
            y16[i] = y[i];
        }

        for (int i = 0; i < 16; i++) {
            yuv2rgb_1(y16[i], u16[i], v16[i], r16 + i, g16 + i, b16 + i);
        }
        float2byte_16(r16, r);
        float2byte_16(g16, g);
        float2byte_16(b16, b);
    }

#if 0
    /// YV12 => RGB3p, 初级SIMD化版本, TODO: YV21, yuv420sp_rgb3p
    void yuv420sp_rgb3p(const Frame &src, Frame &dst) {

        cr_ensure(src.width() % 16 == 0);
        cr_ensure(src.height() % 2 == 0);

        auto plan_y = src.plane(0);
        auto plan_uv = src.plane(1);
        auto plan_r = dst.plane(0);
        auto plan_g = dst.plane(1);
        auto plan_b = dst.plane(2);

        for (int y = 0; y < src.height(); y += 2) {
            auto row_uv = plan_uv.row(y / 2);
            auto row_y0 = plan_y.row(y);
            auto row_y1 = plan_y.row(y + 1);

            auto row_r0 = plan_r.row(y);
            auto row_r1 = plan_r.row(y + 1);
            auto row_g0 = plan_g.row(y);
            auto row_g1 = plan_g.row(y + 1);
            auto row_b0 = plan_b.row(y);
            auto row_b1 = plan_b.row(y + 1);

            for (int x = 0; x < src.width(); x += 16) {
                float u16[16];
                float v16[16];
                for (int i = 0; i < 16; i += 2) {
                    u16[i] = u16[i + 1] = row_uv[i];
                    v16[i] = v16[i + 1] = row_uv[i + 1];
                }
                yuv2rgb_16(row_y0 + x, u16 + x, v16 + x, row_r0 + x, row_g0 + x, row_b0 + x);
                yuv2rgb_16(row_y1 + x, u16 + x, v16 + x, row_r1 + x, row_g1 + x, row_b1 + x);
            }
        }
    }
#endif
}
