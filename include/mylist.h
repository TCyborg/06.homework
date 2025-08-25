#pragma once
#include "mycontainer.h"

template <typename T>
class mylist : public mycontainer<T> {
private:
    struct Node {
        T data;        // Храним данные напрямую, а не через указатель
        Node* next;
        Node* prev;
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    size_t size_ = 0;

    Node* get_node(size_t index) const {
        Node* current = head_;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current;
    }
    
public:
    mylist() : head_(nullptr), tail_(nullptr), size_(0) {}
    
    ~mylist() override {
        clear();
    }
    
    // mycontainer interface
    void push_back(const T& value) override {
        Node* new_node = new Node{value, nullptr, nullptr};
        
        if (tail_) {
            tail_->next = new_node;
            new_node->prev = tail_;
            tail_ = new_node;
        } else {
            head_ = tail_ = new_node;
        }
        
        ++size_;
    }
    
    void insert(size_t index, const T& value) override {
        if (index == size_) {
            push_back(value);
            return;
        }
        
        Node* new_node = new Node{value, nullptr, nullptr};
        
        if (index == 0) {
            new_node->next = head_;
            if (head_) {
                head_->prev = new_node;
            }
            head_ = new_node;
            if (!tail_) {
                tail_ = new_node;
            }
        } else {
            Node* current = get_node(index);
            new_node->prev = current->prev;
            new_node->next = current;
            current->prev->next = new_node;
            current->prev = new_node;
        }
        
        ++size_;
    }
    
    void erase(size_t index) override {
        Node* to_delete = get_node(index);
        
        if (to_delete->prev) {
            to_delete->prev->next = to_delete->next;
        } else {
            head_ = to_delete->next;
        }
        
        if (to_delete->next) {
            to_delete->next->prev = to_delete->prev;
        } else {
            tail_ = to_delete->prev;
        }
        
        delete to_delete;
        --size_;
    }
    
    size_t size() const override {
        return size_;
    }
    
    T& operator[](size_t index) override {
        return get_node(index)->data;
    }
    
    const T& operator[](size_t index) const override {
        return get_node(index)->data;
    }
    
    bool empty() const override { 
        return size_ == 0;
    }
    
    void clear() override {
        Node* current = head_;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head_ = tail_ = nullptr;
        size_ = 0;
    }
};
