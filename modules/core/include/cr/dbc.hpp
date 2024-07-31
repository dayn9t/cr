#pragma once

#include <cr/cdd/error.h>
#include <string>
#include <functional>

#pragma region 错误构造

/// 创建出错信息CrError
#define cr_error(code) cr::error((code), __LINE__, __FILE__)

/// 创建CrError的正确状态
#define cr_ok() cr_error(CRC_OK)

/// 创建CrError - 未知错误
#define cr_unknown_error() cr_error(CRC_UNKNOWN_ERR)

/// 创建CrError - 未知异常
#define cr_unknown_exception() cr_error(CRC_UNKNOWN_EXCEPTION)

/// 创建出错信息 - 附带描述信息
#define cr_error_msg(code, msg) cr::error((code), __LINE__, __FILE__, 0, 0, (msg))

/// 创建出错信息 - 从std::exception, TODO: e.what() 可能不是静态生存周期
#define cr_std_exception(e) cr::error(CRC_STD_EXCEPTION, __LINE__, __FILE__, 0, 0, (e).what())

/// 创建出错信息 - 附带数据
#define cr_error_data(code, data1, data2) cr::error((code), __LINE__, __FILE__, (data1), (data2))

/// 创建出错信息 - 附带全部数据
#define cr_error_all(code, data1, data2, msg) cr::error((code), __LINE__,__FILE__,(data1), (data2), (msg))

#pragma endregion
#pragma region 错误抛出

/// 确保条件成功，否则抛出 CrError(CX_UNKNOWN_ERR)
#define cr_ensure(cond) while(!(cond)) { throw cr_error_msg(CRC_DBC_ERR, #cond); }

/// 确保条件成功，否则抛出 CrError(code)
#define cr_ensure_or(cond, code) while(!(cond)) { throw cr_error_msg(code, #cond); }

/// 确保条件成功，否则抛出 CrError(code, msg)
#define cr_ensure_or_msg(cond, code, msg) while(!(cond)) { throw cr_error_msg(code, msg); }

/// 确保条件成功，否则抛出 CrError(code, data1)
#define cr_ensure_or_data1(cond, code, data1) while(!(cond)) { throw cr_error_data(code, data1, 0); }
/// 确保条件成功，否则抛出 CrError(code, data1, data2)
#define cr_ensure_or_data2(cond, code, data1, data2) while(!(cond)) { throw cr_error_data(code, data1, data2); }


/// 确保条件成功，否则抛出 CrError(code, data1, data2, msg)
#define cr_ensure_or_all(cond, code, data1, data2, msg) while(!(cond)) { throw cr_error_all(code, data1, data2, msg); }

/// 确保 CrError 无错，否则抛出 CrError
#define cr_ensure_ret(err) while(err.code != CRC_OK) { throw err; }


#ifdef CRC_DBC_NO_PREFIX
#define ensure(cond) cr_ensure(cond)
#define ensure_or(cond, code) cr_ensure_or(cond, code)
#define ensure_or_msg(cond, code, msg) cr_ensure_or_msg(cond, code, msg)
#define ensure_or_data1(cond, code, data1) cr_ensure_or_data1(cond, code, data1)
#define ensure_or_data2(cond, code, data1, data2) cr_ensure_or_data2(cond, code, data1, data2)
#define ensure_or_all(cond, data1, data2, msg) cr_ensure_or_all(cond, data1, data2, msg)
#endif

#pragma endregion
#pragma region 捕获异常/错误

/// 开始捕获错误/异常
#define cr_try CrError __err = cr_ok(); try

/// 结束捕获错误/异常, 并返回结果
#define cr_return catch (const std::exception& e) { \
        __err = cr_std_exception(e); \
    } \
    catch (const CrError& e) { \
        __err = e; \
    } \
    catch (...) { \
        __err = cr_unknown_exception(); \
    } \
    return __err

#pragma endregion


#ifndef CRC_FILEPATH_CUT_N
/// 文件路径截调前N段, 避免路径过长, 减少信息泄漏
#define CRC_FILEPATH_CUT_N 3
#endif


/// 无错误
#define CRE_OK  CrError{}


namespace cr {

    /// 从文件路径中截取前n段
    const char* cut_path(const char* filename, int n);

    /// 生成错误信息
    inline CrError error(uint32_t code, uint32_t line, const char *file, int data1=0, int data2=0, const char *message= nullptr) {
        static_assert(sizeof(CrError) == 32);
        CrError e = {code, line, {data1, data2}, cut_path(file, CRC_FILEPATH_CUT_N), message};
        return e;
    }

    /// 判定CrError包含正常状态
    inline bool is_ok(const CrError& err) {
        return err.code == CRC_OK;
    }

    /// 生成错误信息的字符串表示
    std::string to_string(const CrError& err);

    /// 捕获异常/错误
    CrError catch_error(std::function<void()> fun);


}
