#include <iostream>
#include "IntegerArray.h"
#include "except.h"

int main() {
    setlocale(LC_ALL, "rus");
    // Протестируем работоспособность функций контейнера IntegerArray 
    IntegerArray array(10);
    for (size_t i = 0; i < array.getLength(); i++) {
        array[i] = i + 1;
    }
    try {        
        array.resize(8);
        array.insertBefore(20, 5);
        array.remove(3);
        array.insertAtEnd(30);
        array.insertAtBeginning(40);
        array.showInfo();        
    }
    catch (const bad_range& br) {
        std::cout << br.what() << " Значение, вызвавшее ошибку: " << br.getError_data() << '\n';
    }
    catch (const bad_length& bl) {
        std::cout << bl.what() << " Значение, вызвавшее ошибку: " << bl.getError_data() << '\n';
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }

    // Попробуем отловить исключение bad_length, объявив массив из 0 элементов
    try {        
        IntegerArray array1(0);
    }
    catch (const bad_length& bl) {
        std::cout << bl.what() << " Значение, вызвавшее ошибку: " << bl.getError_data() << '\n';
    }

    // Попробуем отловить исключения bad_range, передав неверные данные в функции
    try {         
        array.insertBefore(333, 11);        
    }
    catch (const bad_range& br) {
        std::cout << br.what() << " Значение, вызвавшее ошибку: " << br.getError_data() << '\n';
    }
    try {        
        array.remove(10);
    }
    catch (const bad_range& br) {
        std::cout << br.what() << " Значение, вызвавшее ошибку: " << br.getError_data() << '\n';
    }
    try {       
        array.getData(-1);
    }
    catch (const bad_range& br) {
        std::cout << br.what() << " Значение, вызвавшее ошибку: " << br.getError_data() << '\n';
    }    
    return 0;
}