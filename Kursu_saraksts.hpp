#ifndef KURSU_SARAKSTS_HPP
#define KURSU_SARAKSTS_HPP

#include "Studiju_kurss.hpp"

using namespace std;

class Kursu_saraksts
{
private:
    int length{0};
    Studiju_kurss *dynamic_array{nullptr};
    void checkIndex(int i) const;
    void resize(int new_length);

public:
    // Inic. konstruktori
    Kursu_saraksts();
    Kursu_saraksts(int length);

    // Kopesanas konstruktors
    Kursu_saraksts(const Kursu_saraksts &orig);

    // Move konstruktors :)
    Kursu_saraksts(Kursu_saraksts &&temp);

    ~Kursu_saraksts();

    void erase();

    Studiju_kurss &operator[](int i);
    const Studiju_kurss &operator[](int i) const;

    int size() const;

    // Parslogo <<
    Kursu_saraksts &operator=(const Kursu_saraksts &rhs);

    void push_back(const Studiju_kurss &kurss);
    Studiju_kurss pop_back();
};

#endif