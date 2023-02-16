#include <iostream>
#include "IntegerArray.h"
#include "except.h"

int main() {
    setlocale(LC_ALL, "rus");
    // ������������ ����������������� ������� ���������� IntegerArray 
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
        std::cout << br.what() << " ��������, ��������� ������: " << br.getError_data() << '\n';
    }
    catch (const bad_length& bl) {
        std::cout << bl.what() << " ��������, ��������� ������: " << bl.getError_data() << '\n';
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }

    // ��������� �������� ���������� bad_length, ������� ������ �� 0 ���������
    try {        
        IntegerArray array1(0);
    }
    catch (const bad_length& bl) {
        std::cout << bl.what() << " ��������, ��������� ������: " << bl.getError_data() << '\n';
    }

    // ��������� �������� ���������� bad_range, ������� �������� ������ � �������
    try {         
        array.insertBefore(333, 11);        
    }
    catch (const bad_range& br) {
        std::cout << br.what() << " ��������, ��������� ������: " << br.getError_data() << '\n';
    }
    try {        
        array.remove(10);
    }
    catch (const bad_range& br) {
        std::cout << br.what() << " ��������, ��������� ������: " << br.getError_data() << '\n';
    }
    try {       
        array.getData(-1);
    }
    catch (const bad_range& br) {
        std::cout << br.what() << " ��������, ��������� ������: " << br.getError_data() << '\n';
    }    
    return 0;
}