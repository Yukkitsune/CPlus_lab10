#include <iostream>
#include "Vector.h"

void print_fout(std::ostream& out, int* mas, int cap) { // Печать массива в файл
    out << "int*: " << "capacity " << cap << " --> ";
    for (int i = 0; i < cap; ++i) {
        out << mas[i] << " ";
    }
    out << "\n";
}
void fill_dynamic_massive(std::ifstream& in, int* mas, int cap) { // Заполнение массива данными из файла
    for (int i = 0; i < cap; ++i) {
        in >> mas[i];
    }
}
void print(int* mas, int cap) { // Печать массива в консоль
    std::cout << "int*: " << "capacity " << cap << " --> ";
    for (int i = 0; i < cap; ++i) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "----------" << std::endl;
}

int main(int argc, const char* argv[])
{
    int enough_arguments = 3;
    if (argc != enough_arguments) { // Проверка на количество аргументов при запуске
        std::cerr << "Not enough arguments :(" << std::endl;
        std::cerr << "Need: " << enough_arguments << " Given: " << argc << std::endl;
        return -1;
    }
    const std::string in = argv[1];
    const std::string out = argv[2];
    std::ifstream fin(in);
    std::ofstream fout(out);
    int cap = 0;
    if (!fin) { // Проверка на наличие файла для чтения
        std::cerr << "File not found :(" << std::endl;
        return -2;
    }
    fin >> cap; // Считываем длину массива
    int* mas1 = new int[cap]; // Задаем динамические массивы
    int* mas2 = new int[cap];
    fill_dynamic_massive(fin, mas1, cap); // Заполняем массивы
    fill_dynamic_massive(fin, mas2, cap);

    std::cout << "Let's xor vector and int*: " << std::endl;
    Vector vec(mas1, cap); // Задаем вектор
    Vector result_vec = vec ^ mas2; // Результат xor
    std::cout << "Vector: "; //Выводим информацию в консоль
    vec.print();
    print(mas2, cap);
    std::cout << "Result vector: ";
    result_vec.print();
    fout << "Let's xor vector and int*: " << "\n"; // Выводим информацию в файл
    fout << "Vector: " << vec;
    print_fout(fout, mas2, cap);
    fout << "Result of xor vector and int*: " << result_vec;

    std::cout << "Let's look at the empty vector: " << std::endl;
    Vector empt; // Задаем пустой вектор
    std::cout << "Empty vector: ";
    empt.print();
    fout << "Let's look at the empty vector: " << "\n";
    fout << "Empty vector: " << empt;

    std::cout << "Let's look at not filled vector: " << std::endl;
    Vector nfilled(5); // Задаем вектор размерности 5
    std::cout << "Not filled vector: ";
    nfilled.print();
    fout << "Let's look at not filled vector: " << "\n";
    fout << "Not filled vector: " << nfilled;

    std::cout << "Let's copy the etalon vector: " << std::endl;
    Vector etalon(mas1, cap); // Вектор эталон
    Vector copied(cap); // Вектор копия
    Vector moved(cap); // Вектор перемещенный
    copied = (Vector&)etalon; // Копируем эталон
    std::cout << "Etalon: ";
    etalon.print();
    std::cout << "Copied: ";
    copied.print();
    fout << "Let's copy the etalon vector: " << "\n";
    fout << "Etalon: " << etalon;
    fout << "Copied: " << copied;

    std::cout << "Let's move the etalon vector:" << std::endl;
    moved = (Vector&&)etalon; // Перемещаем эталон
    std::cout << "Etalon: ";
    etalon.print();
    std::cout << "Moved: ";
    moved.print();
    fout << "Let's move the etalon vector:" << "\n";
    fout << "Etalon: " << etalon;
    fout << "Moved: " << moved;

    if (mas1 != nullptr) delete[] mas1; // Чистим память
    if (mas2 != nullptr) delete[] mas2;

    fin.close(); // Закрываем файлы
    fout.close();
    return 0;
}
