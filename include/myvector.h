#pragma once
#include "mycontainer.h"

template <typename T>
class myvector : public mycontainer<T> {
private:
    T* data_;
    size_t size_;
    size_t capacity_;
    
    void resize(size_t new_capacity){
        
        if (new_capacity == 0) {
            // Освобождаем память если новая емкость 0
            delete[] data_;
            data_ = nullptr;
            capacity_ = 0;
            return;
        }
        
        if (new_capacity <= capacity_) {
            return; // Не нужно уменьшать емкость
        }
        
        T* new_data = new T[new_capacity];
            
        // Копируем существующие элементы
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }
    
public:
    myvector() : data_(nullptr), size_(0), capacity_(0) {} 
    
    myvector(size_t initial_capacity) : capacity_(initial_capacity) {
        if (initial_capacity > 0) {
            data_ = new T[initial_capacity];
        }
    }

    ~myvector() override {
        delete[] data_;
    }
    
    // mycontainer interface
    void push_back(const T& value) override {
        if (size_ >= capacity_) {
            resize(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = value;
    }

    void insert(size_t index, const T& value) override {
        if (size_ >= capacity_) {
            resize(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        // Сдвигаем элементы вправо
        for (size_t i = size_; i > index; --i) {
            data_[i] = data_[i - 1];
        }
        
        data_[index] = value;
        ++size_;
    }

    void erase(size_t index) override {
        // Сдвигаем элементы влево
        for (size_t i = index; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    size_t size() const override {
        return size_;
    }
    
    T& operator[](size_t index) override {
        return data_[index];
    }

    const T& operator[](size_t index) const override {
        return data_[index];
    }

    bool empty() const override {
        return size_ == 0;
    }

    void clear() override {
        size_ = 0;
    }
};
