#include <iostream>
#include <vector>
void main() {
    std::vector<int> vector = {1,2,3,4,5,6,7,8,9}; //создается на стеке, но содержимое созданно на динамической памяти (хип)
    vector.push_back(1); //в конец добавляется элемент путём копирования
    vector.erase(vector.begin()+1); //удаляет элементы в определённом диапозон
    vector.insert(vector.begin() + 4, 11); //вставляет число массива в определённое место
    vector.resize(5); //сохраняет первые 5 элементов
    vector.reserve(16); //отводит место для 16 элементов
    std::cout << "capacity: " << vector.capacity(); //возвращает вместимость вектора 
    for (int i = 0; i < vector.size(); i++) 
    {
        vector[i] += 1; //увеличивает все элементы массива на 1
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
    vector.shrink_to_fit(); //изменяет вместимость под текущее количество элементов
    std::cout << "capacity: " << vector.capacity(); //возвращает вместимость вектора
    vector.clear(); //очищаем вектор
    vector.emplace_back(1);//создает элемент в конце вектора
    for (int i = 0; i < vector.size(); i++) 
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl << std::endl;
}