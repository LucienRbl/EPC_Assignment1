#ifndef EPC_VECTOR_H
#define EPC_VECTOR_H

#include <cstdlib>

namespace epc
{
    template <typename T>
    class vector
    {
    public:
        static const int GROW_FACTOR = 2;
        size_t capacity_;
        size_t size_;
        T* data_;

        vector() noexcept {
            capacity_ = 0;
            size_ = 0;
            data_ = nullptr;
         }        

        vector(const vector& other) 
            :capacity_(other.capacity_), size_(other.size_)
        {
            size_ == 0 ? data_ = nullptr : data_ = new T[capacity_];
            try {
                std::copy(other.data_, other.data_ + size_, data_);
            }
            catch(...) {
                delete[] data_;
                throw;
            }
        }
        
        vector& operator=(const vector& other) { 
            if(this == &other ) {
                return *this;
            }

            T* new_data;
            other.size_ == 0 ? new_data = nullptr : new_data = new T[other.capacity_];

            try {
                std::copy(other.data_, other.data_ + other.size_, new_data);
            }
            catch(...) {
                delete[] new_data;
                throw;
            }

            delete[] data_; 

            data_ = new_data;
            capacity_ = other.capacity_;
            size_ = other.size_;

            return *this;
        }

        ~vector() {
            delete[] data_;
         }

        T* data() { return data_; }
        const T* data() const { return data_;} 

        T& operator[](size_t index) { 
            return data_[index];
         }
        const T& operator[](size_t index) const {
            return data_[index];
        }

        void push_back(const T& value) { 
            if(size_ < capacity_){
                data_[size_] = value;
                size_++;
            }
            else {
                this->reserve(capacity_ == 0 ? 1 : capacity_ * GROW_FACTOR);
                this->push_back(value);
            }
        }
        void pop_back() { 
            size_--;
        }

        void reserve(size_t capacity) { 
            if (capacity <= capacity_) {
                return;
            }
        
            T* new_data = new T[capacity];

            try {
                std::copy(data_, data_ + size_, new_data);
            }
            catch(...) {
                delete[] new_data;
                throw;
            }

            delete[] data_;
           
            data_ = new_data;
            capacity_ = capacity;            
        }

        size_t capacity() const { return capacity_; }
        size_t size() const { return size_; }

        void swap(vector& other) noexcept {
            std::swap(capacity_,other.capacity_);
            std::swap(size_,other.size_);
            std::swap(data_,other.data_);
        }
    };
}

#endif
