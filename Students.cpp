#include <iostream>
#include <string>
#include <cmath>
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
        string message = "Year range is [1; 4], but your provided value is " + to_string(gads);
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
    throw My_error{"Student does not have a course with such id!"};
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
    throw My_error{"Student does not have a course with such id!"};
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

// PAPILDINA KURSU SARAKSTU
bool Students::aizvietot_kursu(string id)
{
    while (true)
    {
        cout << "Student already has the course with the id of --> " << id << "" << endl;
        cout << "Therefore you have 2 options:" << endl;
        cout << "1) Replace the existing course." << endl;
        cout << "2) Keep the old course." << endl;
        cout << "Your option (1 vai 2) ---- > ";
        int choice;
        cin >> choice;
        if (choice == 1)
            return true;
        else if (choice == 2)
        {
            return false;
        }
        else
        {
            cout << "Nepareizs inputs! Jums ir tikai 2 opcijas! Pameginiet velreiz!" << endl
                 << endl;
        }
    }
}

void Students::pievienot_kursu(const Studiju_kurss &kurss)
{
    for (int i{0}, length = studiju_kursi.size(); i < length; i++)
    {
        if (studiju_kursi[i].get_id() == kurss.get_id())
        {
            if (aizvietot_kursu(kurss.get_id()))
            {
                // Studiju_kurss klasse nesatur pointerus, tapec default copy assignment operator will be just fine
                studiju_kursi[i] = kurss;
                return;
            }
            else
            {
                return;
            }
        }
    }
    // Ja kurss neatkartojas, vienkarshi pievienojam kursu saraksta beigas
    studiju_kursi.push_back(kurss);
}

void Students::pievienot_kursus(const Kursu_saraksts &kursi)
{
    for (int i{0}, length = kursi.size(); i < length; i++)
    {
        pievienot_kursu(kursi[i]);
    }
}

// VIDEJA UN VIDEJA SVERTA ATZIMES
double Students::videja_atzime() const
{
    int total{0};
    int active_grades{0};
    bool vismaz_viena_atzime{false};

    for (int i{0}, length = studiju_kursi.size(); i < length; i++)
    {
        int kursa_atzime = studiju_kursi[i].get_atzime();
        if (kursa_atzime != -1)
        {
            vismaz_viena_atzime = true;
            total += kursa_atzime;
            active_grades++;
        }
    }

    if (!vismaz_viena_atzime)
    {
        return -1;
    }
    return static_cast<double>(total) / active_grades;
}

double Students::videja_sversta_atzime() const
{
    int total{0};
    int total_kp{0};
    bool vismaz_viena_atzime{false};

    for (int i{0}, length = studiju_kursi.size(); i < length; i++)
    {
        int kursa_atzime = studiju_kursi[i].get_atzime();
        int kursa_kp = studiju_kursi[i].get_kp();

        if (kursa_atzime != -1)
        {
            vismaz_viena_atzime = true;
            total += kursa_atzime * kursa_kp;
            total_kp += kursa_kp;
        }
    }

    if (!vismaz_viena_atzime)
    {
        return -1;
    }
    else if (total == 0)
    {
        return 0;
    }
    return static_cast<double>(total) / total_kp;
}

void Students::izvada_kursi_atzimes() const
{
    if (studiju_kursi.size() == 0)
    {
        cout << "CURRENTLY NO COURSES ADDED FOR THIS STUDENT!" << endl;
    }
    for (int i{0}, length = studiju_kursi.size(); i < length; i++)
    {
        studiju_kursi[i].display_name_grade();
    }
}

void Students::izvada_info() const
{
    cout << "ID: " << id << endl;
    cout << "Vards: " << vards << endl;
    cout << "Studenta kursi un atzimes par tiem:" << endl;
    izvada_kursi_atzimes();
}

void Students::izvada_info_ar_vid_atzimi() const
{
    cout << "ID: " << id << endl;
    cout << "Vards: " << vards << endl;
    cout << "Videja atzime: " << round(videja_atzime() * 100) / 100 << endl;
    cout << "Videja sversta atzime: " << round(videja_sversta_atzime() * 100) / 100 << endl;
}

void Students::izvada_pilno_info() const
{
    izvada_info_ar_vid_atzimi();
    cout << "Studenta kursi un atzimes par tiem:" << endl;
    izvada_kursi_atzimes();
}