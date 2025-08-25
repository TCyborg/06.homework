#include <iostream>
#include "myvector.h"

// Функция для вывода содержимого контейнера
template<typename Container>
void print_container(const Container& container) {
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i];
        if (i < container.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Функция для демонстрации работы с контейнером
template<typename Container>
void demonstrate_container() {
    
    // 1. Создание объекта контейнера для хранения объектов типа int
    Container container;
    // 2. Добавление в контейнер десяти элементов (0, 1 … 9)
    for (int i = 0; i < 10; ++i) {
        container.push_back(i);
    }
    // 3. Вывод содержимого контейнера на экран
    print_container(container);
    // 4. Вывод размера контейнера на экран
    std::cout << container.size() << std::endl;
    // 5. Удаление третьего (по счёту), пятого и седьмого элементов
    container.erase(6);
    container.erase(4);
    container.erase(2);
    // 6. Вывод содержимого контейнера на экран
    print_container(container);
    // 7. Добавление элемента 10 в начало контейнера
    container.insert(0, 10);
    // 8. Вывод содержимого контейнера на экран
    print_container(container);
    // 9. Добавление элемента 20 в середину контейнера
    size_t middle_index = container.size() / 2;
    container.insert(middle_index, 20);
    // 10. Вывод содержимого контейнера на экран
    print_container(container);
    // 11. Добавление элемента 30 в конец контейнера
    container.push_back(30);
    // 12. Вывод содержимого контейнера на экран
    print_container(container);
}

int main() {
    // Демонстрация работы с myvector
    demonstrate_container<myvector<int>>();
    
    return 0;
}