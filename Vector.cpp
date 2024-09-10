#include <iostream>
#include "Vector.h"

Vector::Vector(int* p, int cap) { // Конструктор на входе массив, задающий вектор
    this->cap = cap;
    this->p = new int[cap];
    for (int i = 0; i < cap;++i) {
        this->p[i] = p[i];
    }
    std::cout << "Vector(int* p, int cap) " << std::endl;
}
Vector::Vector(int cap) :cap(cap) { // Конструктор - выделяем память без инициализации
    p = new int[cap] {};
    std::cout << "Vector(int cap)" << std::endl;
}
Vector::Vector() { // Конструктор пустого вектора
    p = nullptr;
    cap = 0;
    std::cout << "Vector()" << std::endl;
}
Vector::Vector(const Vector& Vec) { // Конструктор копирования
    cap = Vec.cap;
    p = new int[cap];
    for (int i = 0; i < cap; ++i) {
        p[i] = Vec.p[i];
    }
    std::cout << "Vector(const Vector& Vec) cap = " << cap << std::endl;
}
Vector::Vector(Vector&& Vec) noexcept { // Конструктор перемещения
    std::swap(p, Vec.p);
    std::swap(cap, Vec.cap);
    std::cout << "Vector(Vector&& Vec)" << std::endl;
}
void Vector::print() { // Печать вектора
    std::cout << "capacity " << cap << " --> ";
    for (int i = 0; i < cap; ++i) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "----------" << std::endl;
}
int& Vector::operator [](int index) { // Перегрузка оператора []
    return p[index];
}
Vector& Vector::operator = (const Vector& v2) { // Перегрузка оператора = обычной ссылкой
    if (this != &v2) {
        cap = v2.cap;
        if (p != nullptr) delete[] p;
        p = new int[cap];
        for (int i = 0; i < cap; ++i) p[i] = v2.p[i];
    }
    std::cout << "Vector& operator = (const Vector& v2) " << std::endl;
    return *this;
}
Vector& Vector::operator = (Vector&& v2) noexcept { // Перегрузка оператора = с rvalue ссылкой
    if (this != &v2) {
        std::swap(p, v2.p);
        std::swap(cap, v2.cap);
    }
    std::cout << "Vector& operator = (Vector&& v2) " << std::endl;
    return *this;
}
Vector::~Vector() { // Деструктор
    std::cout << "~Vector() cap = " << cap << std::endl;
    if (p != nullptr) delete[] p;
}
Vector operator ^(const Vector& v1, int* v2) { // Перегрузка операции ^
    Vector Vec(v1.cap);
    for (int i = 0; i < v1.cap; ++i) Vec.p[i] = v1.p[i] ^ v2[i];
    return Vec;
}
std::istream& operator >> (std::istream& in, Vector& vec) { // Перегрузка операции >>
    if (vec.p != nullptr) { vec.cap = 0; delete[] vec.p; }
    int len_temp;
    in >> len_temp;
    int* p_temp = new int[len_temp];
    for (int i = 0; i < len_temp; ++i) {
        in >> p_temp[i];
    }
    Vector vec_in(p_temp, len_temp);
    len_temp = 0;
    delete[] p_temp;
    return in;
}
std::ostream& operator << (std::ostream& out, Vector& vec) { //Перегрузка операции <<
    out << "capacity " << vec.cap << " --> ";
    for (int i = 0; i < vec.cap; ++i) {
        out << vec.p[i] << " ";
    }
    out << "\n";
    return out;
}

