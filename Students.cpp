#include <iostream>
#include <string>
#include "Students.hpp"
#include "My_error.hpp"

// CONSTRUCTORS
Students::Students() {}

Students::Students(const string &id, const string &vards, const string &grupa, int gads, const Kursu_saraksts &studiju_kursi)
    : id{id}, vards{vards}, grupa{grupa}, studiju_gads{gads}, studiju_kursi{studiju_kursi}
{
    check_gads_range(gads);
} // Musu veidotam konteinerim ir implements copy constructor

// Delegating to the constructor above, and just additionaly to given args also provide a default dynamic Array Kursu saraksts
Students::Students(const string &id, const string &vards, const string &grupa, int gads)
    : Students{id, vards, grupa, gads, Kursu_saraksts{}}
{
}

// CHECKER
void Students::check_gads_range(int gads)
{
    if (gads < 1 || gads > 4)
    {
        string message = "Studiju gada nosacijumi:  pieļaujamās vērtības: [1; 4], bet Jusu vertiba ir " + to_string(gads);
        throw My_error{message};
    }
}

// SETERI
void Students::set_id(string id)
{
    this->id = id;
}

void Students::set_grupa(string grupa)
{
    this->grupa = grupa;
}

void Students::set_vards(string vards)
{
    this->vards = vards;
}

void Students::set_studiju_gads(int studiju_gads)
{
    check_gads_range(studiju_gads);
    this->studiju_gads = studiju_gads;
}

void Students::set_studiju_kursi(Kursu_saraksts studiju_kursi)
{
    this->studiju_kursi = studiju_kursi;
}

// GETERI
const string &Students::get_id() const
{
    return id;
}

const string &Students::get_grupa() const
{
    return grupa;
}

const string &Students::get_vards() const
{
    return vards;
}

int Students::get_studiju_gads() const
{
    return studiju_gads;
}

const Kursu_saraksts &Students::get_studiju_kursi() const
{
    return studiju_kursi;
}

// KURSU MEKLESANA
bool Students::vai_ir_kurss(const string &kursa_id) const
{
    for (int i{0}, length = studiju_kursi.size(); i < length; i++)
    {
        if (studiju_kursi[i].get_id() == kursa_id)
        {
            return true;
        }
    }
    return false;
}

// KURSU MEKLESANA AR ATSAUCI
Studiju_kurss &Students::kurss_pec_id(const string &id)
{
    for (int i{0}, length = studiju_kursi.size(); i < length; i++)
    {
        if (studiju_kursi[i].get_id() == id)
        {
            return studiju_kursi[i];
        }
    }
    throw My_error{"Tada kursa studentam nav! Funkcija nevar neko atgriezt!"};
}

const Studiju_kurss &Students::kurss_pec_id(const string &id) const
{
    for (int i{0}, length = studiju_kursi.size(); i < length; i++)
    {
        if (studiju_kursi[i].get_id() == id)
        {
            return studiju_kursi[i];
        }
    }
    throw My_error{"Tada kursa studentam nav! Funkcija nevar neko atgriezt!"};
}

// Opertor [] - jau implementejam din. massivaa, tapec seit bus pavisam isi
Studiju_kurss &Students::operator[](int i)
{
    return studiju_kursi[i];
}

const Studiju_kurss &Students::operator[](int i) const
{
    return studiju_kursi[i];
}
