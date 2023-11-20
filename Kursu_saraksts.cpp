#include "Kursu_saraksts.hpp"
#include "Studiju_kurss.hpp"
#include "My_error.hpp"

#include <iostream>
#include <string>

using namespace std;

Kursu_saraksts::Kursu_saraksts() {}

Kursu_saraksts::Kursu_saraksts(int length)
    : length{length}
{
    if (length < 0)
    {
        string message = "Index cannot be negative, but your provided value is " + to_string(length);
        throw My_error{message};
    }
    else if (length == 0)
    {
        dynamic_array = nullptr;
    }
    else
    {
        dynamic_array = new Studiju_kurss[length];
    }
}

// Kopesanas konstruktors
Kursu_saraksts::Kursu_saraksts(const Kursu_saraksts &orig)
    : Kursu_saraksts{orig.length}
{
    if ((orig.dynamic_array != nullptr) && (this != &orig))
    {
        dynamic_array = new Studiju_kurss[length];
        for (int i{0}; i < length; i++)
        {
            dynamic_array[i] = orig.dynamic_array[i];
        }
    }
    // else the default value of dynamic_array remain nullptr.
}

// Move konstruktors :)
Kursu_saraksts::Kursu_saraksts(Kursu_saraksts &&temp)
{
    length = temp.length;
    dynamic_array = temp.dynamic_array;
    temp.dynamic_array = nullptr;
}

Kursu_saraksts::~Kursu_saraksts()
{
    if (dynamic_array != nullptr)
    {
        delete[] dynamic_array;
    }
}

void Kursu_saraksts::erase()
{
    if (dynamic_array != nullptr)
    {
        delete[] dynamic_array;
        dynamic_array = nullptr;
    }
    length = 0;
}

int Kursu_saraksts::size() const
{
    return length;
}

void Kursu_saraksts::checkIndex(int i) const
{
    if (i >= length)
    {
        string message = "You are out of range. Length of the array - " + to_string(length) + ". Index - " + to_string(i);
        throw My_error{message};
    }
    else if (i < 0)
    {
        throw My_error{"Index cannot be negative!"};
    }
}

Studiju_kurss &Kursu_saraksts::operator[](int i)
{
    // throw an Error if out of range; else return a course
    checkIndex(i);
    return dynamic_array[i];
}

const Studiju_kurss &Kursu_saraksts::operator[](int i) const
{
    checkIndex(i);
    return dynamic_array[i];
}

Kursu_saraksts &Kursu_saraksts::operator=(const Kursu_saraksts &rhs)
{
    // if trying to assign the same object then just return
    if (this == &rhs)
    {
        return *this;
    }
    // else - first take care of memory
    erase();

    if (rhs.dynamic_array != nullptr)
    {
        // if rhs is not empty, then need to set size and copy its elements
        length = rhs.length;
        dynamic_array = new Studiju_kurss[length];

        for (int i{0}; i < length; i++)
        {
            dynamic_array[i] = rhs.dynamic_array[i];
        }
    }
    return *this;
}

void Kursu_saraksts::resize(int new_length)
{
    if (length == new_length)
        return;
    if (new_length < 0)
    {
        string message = "Cannot resize to the provided negative value of " + to_string(new_length);
        throw My_error{message};
    }
    else if (new_length == 0)
    {
        // we already defined a function that can be used if we want to resize to 0
        erase();
    }
    else
    {
        // need a placeholder for the current data
        Studiju_kurss *data = new Studiju_kurss[new_length];
        // if we remove an element, we want to go up to the reduced size, else wana copy all curent content
        int to_be_copied = (new_length < length) ? new_length : length;

        for (int i{0}; i < to_be_copied; i++)
        {
            // copy current data
            data[i] = dynamic_array[i];
        }
        // free the current memory
        delete[] dynamic_array;

        // steal data pointer
        dynamic_array = data;
        data = nullptr;

        // update to new_length
        length = new_length;
    }
}

void Kursu_saraksts::push_back(const Studiju_kurss &kurss)
{
    // resize to size+1
    int new_length = length + 1;
    resize(new_length);
    // add a course at the back (last index = size - 1), using = operator
    dynamic_array[new_length - 1] = kurss;
}

Studiju_kurss Kursu_saraksts::pop_back()
{
    if (length == 0)
    {
        throw My_error{"Cannot pop from an empty array!"};
    }
    int last_index = length - 1;
    Studiju_kurss removed = dynamic_array[last_index];
    resize(last_index);
    return removed;
}
