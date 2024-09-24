#ifndef EPC_VECTOR_H
#define EPC_VECTOR_H

#include <cstdlib>

namespace epc
{
    template <typename T>
    class vector
    {
    public:
        vector() noexcept { }        

        vector(const vector&) { }
        vector& operator=(const vector&) { }

        ~vector() { }

        T* data() { }
        const T* data() const { }

        T& operator[](size_t) { }
        const T& operator[](size_t) const { }

        void push_back(const T&) { }
        void pop_back() { }

        void reserve(size_t) { }

        size_t capacity() const { }
        size_t size() const { }

        void swap(vector&) noexcept { }
    };
}

#endif
