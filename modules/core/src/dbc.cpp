#include <cr/dbc.hpp>
#include <cstring>

using namespace std;

namespace cr {

    const char *cut_path(const char *path, int n) {
        auto p = path;
        for (int i = 0; i < n; i++) {
            p = strchr(p + 1, '/');
            if (p == nullptr) return path;
        }
        return p;
    }

    string to_string(const CrError &err) {
        char buffer[256] = {};
        int n = sprintf(buffer, "CrError(%05x, %s[%d]", err.code, err.file, err.line);
        if (err.data[0] || err.data[1])
            n += sprintf(buffer + n, ", [%d %d]", err.data[0], err.data[1]);
        if (err.message)
            n += sprintf(buffer + n, ", '%s'", err.message);
        n += sprintf(buffer + n, ")");
        return buffer;
    }

    CrError catch_error(std::function<void()> fun) {
        CrError err = cr_ok();
        try {
            fun();
        }
        catch (const std::exception &e) {
            err = cr_std_exception(e);
        }
        catch (const CrError &e) {
            err = e;
        }
        catch (...) {
            err = cr_unknown_exception();
        }
        return err;
    }
}
