#ifndef STUDENTS_HPP
#define STUDENTS_HPP

#include <iostream>
#include <string>
#include "Kursu_saraksts.hpp"
using namespace std;

class Students
{
private:
    string id{};    // matrokulas numurs
    string grupa{}; // ITB vs. IZB
    string vards{};
    int studiju_gads{1}; // [1; 4]
    Kursu_saraksts studiju_kursi{};

    void check_gads_range(int gads);

public:
    // Konstruktori
    Students();
    Students(const string &id, const string &vards, const string &grupa, int gads, const Kursu_saraksts &studiju_kursi);
    Students(const string &id, const string &vards, const string &grupa, int gads);

    // Seti
    void set_id(string id);
    void set_grupa(string grupa);
    void set_vards(string vards);
    void set_studiju_gads(int studiju_gads);
    void set_studiju_kursi(Kursu_saraksts studiju_kursi);

    // Geti
    const string &get_id() const;
    const string &get_grupa() const;
    const string &get_vards() const;
    int get_studiju_gads() const;
    const Kursu_saraksts &get_studiju_kursi() const;

    // KUSRU MEKLESANA
    bool vai_ir_kurss(const string &kursa_id) const;

    // KURSU MEKLESANA AR ATSAUCI
    Studiju_kurss &kurss_pec_id(const string &id);
    const Studiju_kurss &kurss_pec_id(const string &id) const;

    // [] operators
    Studiju_kurss &operator[](int i);
    const Studiju_kurss &operator[](int i) const;
};

#endif