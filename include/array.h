#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <stdexcept>

template<typename T>
class Array {
private:
    std::unique_ptr<T[]> data;
    size_t capacity_;
    size_t size_;

    void resize(size_t new_capacity) {
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = std::move(data[i]);
        }
        data = std::move(new_data);
        capacity_ = new_capacity;
    }

public:
    Array(size_t initial_capacity = 10) : capacity_(initial_capacity), size_(0) {
        data = std::make_unique<T[]>(capacity_);
    }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            resize(capacity_ * 2);
        }
        data[size_++] = value;
    }

    void push_back(T&& value) {
        if (size_ == capacity_) {
            resize(capacity_ * 2);
        }
        data[size_++] = std::move(value);
    }

    void erase(size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < size_ - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        --size_;
    }

    T& operator[](size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }

    double total_area() const {
        double total = 0;
        for (size_t i = 0; i < size_; ++i) {
            total += static_cast<double>(*data[i]);
        }
        return total;
    }
};

#endif
