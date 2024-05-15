#include <iostream>
#include "cr/dbc.hpp"

using namespace std;

CrError catch1() {
    cr_try { cr_ensure(1 == 2)}
    cr_return;
}

CrError catch2() {
    cr_try { throw std::runtime_error("error's position"); }
    cr_return;
}

int main() {

    cout << "\n# errs\n" << endl;

    CrError errs[] = {
            cr_ok(),
            cr_unknown_error(),
            cr_unknown_exception(),
            cr_error_msg(0x101, "a message"),
            cr_error_data(0x102, 5, 10),
            cr_error_all(0x103, 5, 10, "a message"),
    };

    for (auto e: errs)
        cout << cr::to_string(e) << endl;


    cout << "\n# funs\n" << endl;

    function<void()> funs[] = {
            []() { cr_ensure(1 == 2)},
            []() { cr_ensure_or(1 == 2, 0x11)},
            []() { cr_ensure_or_msg(1 == 2, 0x12, "a message")},
            []() { cr_ensure_or_data(1 == 2, 0x13, 11, 12)},
            []() { cr_ensure_or_all(1 == 2, 0x14, 11, 12, "a message")},
            []() { throw std::runtime_error("error's position lost"); },
    };

    for (auto f: funs) {
        auto e = cr::catch_error(f);
        cout << cr::to_string(e) << endl;
    }

    cout << "\n# catches\n" << endl;

    function<CrError()> catches[] = {catch1, catch2};
    for (auto f: catches) {
        auto e = f();
        cout << cr::to_string(e) << endl;
    }

    return 1;
}
