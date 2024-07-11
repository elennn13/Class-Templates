#include <iostream>


template <typename ANY>//шаблонный класс
class Array {

private:
    size_t size;
    ANY* data;//указательн на динам память

public:
    Array() : size(0NULL), data(nullptr) {}//констурктор по умолчанию
    Array(size_t size) : size(size) { //принимает массив 
        if (size == 0) {
            data = nullptr;
            return;
        }
        data = new ANY[size]{};
    }


    Array(const std::initializer_list<ANY>& list) { // 
        size = list.size();
        data = new ANY[size];
        size_t i = 0;
        for (auto& p : list)
            data[i++] = p;
    }


    Array(const Array& other) : size(other.size) { //коснтр копирования
        if (size == 0) {
            data = nullptr;
            return;
        }
        data = new ANY[size];
        for (size_t i{}; i < size; ++i)
            data[i] = other[i];
    }


    Array(Array&& other) : Array() {//констурктор перемещения+ конструктор по умолчанию
        std::swap(size, other.size);
        std::swap(data, other.data);
    }
    ~Array() { delete[] data; }

    void print() {//вывод
        for (size_t i{}; i < size; ++i)
            std::cout << data[i] << ' ';
        std::cout << std::endl;
    }

    size_t length() { return size; }
    

    ANY& operator[](size_t index) { //оператор квадратных скобок
        return *(data + index);
    }
    ANY operator[](size_t index) const { //оператор квадратных скобок
        return *(data + index);
    }

};

template <typename ANY, size_t size> // size - non type параметр шаблона (не типовой)

class Tuple {
private:
    ANY data[size] {};

public:

    size_t length() { return size; }
    
    ANY& operator[](size_t index) {
            return *(data + index);
}
    ANY operator[](size_t index) const {
           return *(data + index);
}

};

int sum(int counter, int first, ...) { //функция считает сумму
    int result = 0;
    int* firstp = &first;
    //for (size_t i{}; i < counter * 2; i += 2) // 1вариант
       // result += *(firstp + i);
        
    
    
    while (counter--) { // 2 вариант
        result += *(firstp++);
        ++firstp;
    }

    return result;
        
}


int main(){
    setlocale(LC_ALL, "ru");
    int n;

    Array<int> arr1(5);//создание объекта шаблонного класса
    for (size_t i = arr1.length(); i > 0; --i)
        arr1[arr1.length() - i] = i;
    arr1.print();


    Tuple<double, 5> arr2;
    arr2[1] = 7.2;
    std::cout << "arr2[1] = " << arr2[1] << std::endl;

    std::cout << sum(3, 10, 15, 8) << std::endl;
    std::cout << sum(6, 5, 7, 9, 1, 1, 1) << std::endl;

    Array<int> arr3 { 7, 15, 105, 42 };

    arr3.print();




    return 0;
}
