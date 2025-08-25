#pragma once

template <typename T>
class mycontainer {
public:
    virtual ~mycontainer() = default;
    
    // Добавление элементов
    virtual void push_back(const T& value) = 0;
    
    // Вставка элементов
    virtual void insert(size_t index, const T& value) = 0;
    
    // Удаление элементов
    virtual void erase(size_t index) = 0;
    
    // Размер контейнера
    virtual size_t size() const = 0;
    
    // Доступ по индексу
    virtual T& operator[](size_t index) = 0;
    virtual const T& operator[](size_t index) const = 0;
    
    // Вспомогательные методы
    virtual bool empty() const = 0;
    virtual void clear() = 0;
};