#pragma once

///
/// @brief: CR库基础
///
/// 包含了CR库最基础共性的内容, 包括:
/// - C类型别名, 引入别名是为了统一命名风格, 避免转为Rust类型后会海量警告
/// - 其他待定
///

/// 无符号字节
typedef unsigned char U8;

/// 带符号32位整数
typedef int I32;

/// 无符号32位整数
typedef unsigned int U32;

/// 无符号字节
typedef unsigned char U8;


/// 二进制数值定义
#define KILO				(1<<10)
#define MEGA				(1<<20)
#define GIGA				(1<<30)
#define TERA				(1<<40)
#define PETA				(1<<50)
#define EXA				    (1<<60)

