#include <fstream>
#include <algorithm>

class Vector {
private:
    int* p = nullptr;
    int cap = 0;
public:
    Vector(int* p, int cap);
    Vector(int cap);
    Vector();
    Vector(const Vector& Vec);
    Vector(Vector&& Vec) noexcept;
    void print();
    int& operator [](int index);
    Vector& operator = (const Vector& v2);
    Vector& operator = (Vector&& v2) noexcept;
    ~Vector();
    friend Vector operator ^ (const Vector& v1, int* v2);
    friend std::istream& operator >> (std::istream& in, Vector& vec);
    friend std::ostream& operator << (std::ostream& out, Vector& vec);
};
