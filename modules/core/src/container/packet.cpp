#include "cr/container/packet.hpp"
#include <memory.h>
#include <cassert>

namespace cr {

    Packet::Packet(size_t capacity) {
        data_ = new UByte[capacity];
        capacity_ = capacity;
    }

    Packet::Packet(const Packet &p)
            : Packet(p.capacity()) {
        p.fill(*this);
    }

    Packet::~Packet() {
        delete[] data_;
        data_ = nullptr;
        clear();
    }

    void *Packet::alloc_void(size_t n, bool clear) {
        if (n < 1 || n > free_space()) return nullptr;
        auto p = end();
        if (clear) memset(p, 0, n);
        size_ += n;
        lens_.push_back(n);
        return p;
    }

    bool Packet::pack_void(const void *p, size_t n) {
        auto dst = alloc_void(n);
        if (dst == nullptr) return false;
        memcpy(dst, p, n);
        return true;
    }

    size_t Packet::copy_to(void *p, size_t capacity) const {
        auto n = std::min(capacity, size());
        memcpy(p, begin(), n);
        return n;
    }

    bool Packet::operator==(const Packet &pack) const {
        if (size() != pack.size()) return false;
        return memcmp(this->data_, pack.data_, size()) == 0;
    }

    Packet &Packet::operator=(const Packet &p) {
        if (capacity() >= p.size()) {
            auto r = p.fill(*this);
            assert(r);
        } else {
            Packet p1(p);
            p1.swap(*this);
        }
        return *this;
    }

    bool Packet::fill(Packet &p) const {
        if (p.capacity() < size()) return false;

        auto r = copy_to(p.begin(), size());
        assert(r == size());
        p.size_ = size_;
        p.lens_ = lens_;
        return true;
    }

    void Packet::swap(Packet &pack) {
        std::swap(data_, pack.data_);
        std::swap(capacity_, pack.capacity_);
        std::swap(size_, pack.size_);
        std::swap(lens_, pack.lens_);
    }

    void Packet::reserve(size_t n) {
        if (n <= capacity()) return;
        Packet p1(n);
        p1 = *this;
        p1.swap(*this);
    }

    void Packet::clear() {
        size_ = 0;
        lens_.clear();
    }
}
