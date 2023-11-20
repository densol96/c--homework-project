#ifndef STUDENTS_HPP
#define STUDENTS_HPP

#include <iostream>
#include <string>
#include "Kursu_saraksts.hpp"
using namespace std;

class Students
{
private:
    string id{}; // matrikulas numurs
    string grupa{};
    string vards{};
    int studiju_gads{1};            // [1; 4], default - 1
    Kursu_saraksts studiju_kursi{}; // izaicinājums

    void check_gads_range(int gads);
    bool aizvietot_kursu(string id);
    // gan izvada_info, gan  izvada_pilno_info prasa ari katra kursa atzimi, tapec varam refactor code a bit..
    void izvada_kursi_atzimes() const;

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

    // PAPILDINA KURSU SARAKSTU
    void pievienot_kursu(const Studiju_kurss &kurss);
    void pievienot_kursus(const Kursu_saraksts &kursi);

    // VIDEJA UN VIDEJA SVERSTA ATZIMES
    double videja_atzime() const;
    double videja_sversta_atzime() const;

    // IZVADES FUNKCIJAS
    // izvada studenta identifikatoru, vārdu un viņa studiju kursu nosaukumus un atzīmi
    void izvada_info() const;
    // izvada studenta identifikatoru, vārdu un vidējo atzīmi un vidējo svērto atzīmi
    void izvada_info_ar_vid_atzimi() const;
    // izvada pilnu informāciju par studentu, ieskaitot informāciju par studiju kursiem void izvada_info_ar_vid_atzimi();
    void izvada_pilno_info() const;
};

#endif