#include "cr/container/packet.hpp"
#include <cr/test.hpp>

template<typename T>
void test1() {
    auto v0 = T(0);
    auto v1 = T(1);
    auto v2 = T(2);
    auto const C = sizeof(T) * 3;

    Packet p1(C);
            EQ(p1.size(), 0);
            EQ(p1.capacity(), C);
            EQ(p1.empty(), true);
            EQ(p1.full(), false);
    auto r = p1.pack(v0);
            TR(r);
            EQ(p1.size(), sizeof(T));
            EQ(p1.capacity(), C);
            EQ(p1.empty(), false);
            EQ(p1.full(), false);
            EQ(p1.element<T>(0), v0);
    r = p1.pack(v1);
            TR(r);
    r = p1.pack(v2);
            TR(r);
            EQ(p1.size(), sizeof(T) * 3);
            EQ(p1.capacity(), C);
            EQ(p1.empty(), false);
            EQ(p1.full(), true);
            EQ(p1.element<T>(0), v0);
            EQ(p1.element<T>(1), v1);
            EQ(p1.element<T>(2), v2);
            EQ(p1.elements(), 3);
    r = p1.pack(v2);
            FA(r);
    p1.element<T>(1) = v0;
            EQ(p1.element<T>(1), v0);
    p1.clear();
            EQ(p1.capacity(), C);
            EQ(p1.empty(), true);
            EQ(p1.full(), false);
            EQ(p1.elements(), 0);
    p1.reserve(1);
            EQ(p1.capacity(), C);
    p1.pack(v0);
    p1.pack(v1);
    p1.pack(v2);
    p1.reserve(C * 2);
            EQ(p1.capacity(), C * 2);
            EQ(p1.element<T>(0), v0);
            EQ(p1.element<T>(2), v2);
    Packet p2(C);
    p2.pack(v0);
    p2.pack(v1);
    p2.pack(v2);
            NE(p1.capacity(), p2.capacity());
            EQ(p1, p2);
    Packet p3(C);
    p3 = p2;
            EQ(p3.element<T>(0), v0);
            EQ(p3.element<T>(2), v2);
    Packet p4(p2);
            EQ(p1, p2);
            EQ(p3, p2);
            EQ(p4, p2);
    Packet p5(C);
    T a1[] = {v0, v1, v2};
    p5.pack(a1, 2);
            EQ(p5.elements(), 1);
    auto a2 = p5.element<T[2]>(0);
            EQ(a2[0], v0);
            EQ(a2[1], v1);
    //EQ(p5.element<T>(1), v1);
}


TEST(Packet, basic) {
    test1<int16_t>();
    test1<int>();
    test1<float>();
    test1<double>();
}

