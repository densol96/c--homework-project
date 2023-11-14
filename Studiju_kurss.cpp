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
        throw My_error{"Kreditpunktu skaits nevar but negativs skaitlis, bet Jusu vertiba ir "};
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
        string message = "Kreditpunktu skaits nevar but negativs skaitlis, bet Jusu vertiba ir " + to_string(kp_value);
        throw My_error{message};
    }
    kp = kp_value;
}

void Studiju_kurss::set_atzime(int atzime_value)
{
    if (atzime_value < -1 || atzime_value > 10)
    {
        string message = "Atzimes vertibas var but no -1 lidz 10, bet Jusu vertiba ir " + to_string(atzime_value);
        throw My_error{message};
    }
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

int Studiju_kurss::set_atzime() const
{
    return atzime;
}

// izvada pilnu informāciju par studiju kursu, ieskaitot atzīmi;
void Studiju_kurss::display_full() const
{
    cout << "------ Pilns kursa apraksts ------" << endl;
    cout << "ID --> " << id << endl;
    cout << "Nosaukums --> " << nosaukums << endl;
    cout << "Kredit Punkti --> " << kp << endl;
    cout << "Atzime --> " << atzime << endl;
    cout << "----------------------------" << endl;
}

// izvada informāciju par studiju kursu bez atzīmes
ostream &operator<<(ostream &os, const Studiju_kurss &src)
{
    os << src.nosaukums << " ( " << src.id << " ), " << src.kp << " KP.";
    return os;
}