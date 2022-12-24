#include <iostream>
#include <vector>
void main() {
    std::vector<int> vector = {1,2,3,4,5,6,7,8,9}; //��������� �� �����, �� ���������� �������� �� ������������ ������ (���)
    vector.push_back(1); //� ����� ����������� ������� ���� �����������
    vector.erase(vector.begin()+1); //������� �������� � ����������� ��������
    vector.insert(vector.begin() + 4, 11); //��������� ����� ������� � ����������� �����
    vector.resize(5); //��������� ������ 5 ���������
    vector.reserve(16); //������� ����� ��� 16 ���������
    std::cout << "capacity: " << vector.capacity(); //���������� ����������� ������� 
    for (int i = 0; i < vector.size(); i++) 
    {
        vector[i] += 1; //����������� ��� �������� ������� �� 1
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
    vector.shrink_to_fit(); //�������� ����������� ��� ������� ���������� ���������
    std::cout << "capacity: " << vector.capacity(); //���������� ����������� �������
    vector.clear(); //������� ������
    vector.emplace_back(1);//������� ������� � ����� �������
    for (int i = 0; i < vector.size(); i++) 
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl << std::endl;
}