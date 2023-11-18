#include "Studiju_kurss.hpp"
#include "My_error.hpp"
#include <iostream>
#include <string>
using namespace std;

Studiju_kurss::Studiju_kurss() {}

Studiju_kurss::Studiju_kurss(const string &id, const string &nosaukums, int kp)
    : id{id}, nosaukums{nosaukums}, kp{kp}
{
    if (kp < 0)
    {
        string message = "KP value cannot be negative, but your provided value is " + to_string(kp);
        throw My_error{message};
    }
}

// Nepareizu vērtību gadījumā - izsviests izņēmums.
void Studiju_kurss::set_id(const string &id_value)
{
    id = id_value;
}

void Studiju_kurss::set_nosaukums(const string &nosaukums_value)
{
    nosaukums = nosaukums_value;
}

void Studiju_kurss::set_kp(int kp_value)
{
    if (kp_value < 0)
    {
        string message = "KP value cannot be negative, but your provided value is " + to_string(kp_value);
        throw My_error{message};
    }
    kp = kp_value;
}

void Studiju_kurss::set_atzime(int atzime_value)
{
    if (atzime_value < -1 || atzime_value > 10)
    {
        string message = "Grade's range can be  [-1; 10 ], but your value is " + to_string(atzime_value);
        throw My_error{message};
    }
    atzime = atzime_value;
}

string Studiju_kurss::get_id() const
{
    return id;
}

string Studiju_kurss::get_nosaukums() const
{
    return nosaukums;
}

int Studiju_kurss::get_kp() const
{
    return kp;
}

int Studiju_kurss::get_atzime() const
{
    return atzime;
}

// izvada pilnu informāciju par studiju kursu, ieskaitot atzīmi;
void Studiju_kurss::display_full() const
{
    cout << "------ FULL COURSE INFO ------" << endl;
    cout << "ID --> " << id << endl;
    cout << "COURSE NAME --> " << nosaukums << endl;
    cout << "KP --> " << kp << endl;
    cout << "GRADE --> " << atzime << endl;
    cout << "----------------------------" << endl;
}

// izvada informāciju par studiju kursu bez atzīmes
ostream &operator<<(ostream &os, const Studiju_kurss &src)
{
    os << src.nosaukums << " ( " << src.id << " ), " << src.kp << " KP.";
    return os;
}

// Nosaukums - atzime
void Studiju_kurss::display_name_grade() const
{
    cout << id << " - " << nosaukums << " - " << atzime << endl;
}