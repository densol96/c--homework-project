#ifndef STUDIJU_KURSS_HPP
#define STUDIJU_KURSS_HPP
#include <iostream>
#include <string>

using namespace std;

class Studiju_kurss
{
private:
    string id{};
    string nosaukums{};
    int kp{0};      // >= 0
    int atzime{-1}; // [-1; 10]
public:
    Studiju_kurss(); // "", "", 0, -1
    Studiju_kurss(const string &id, const string &nosaukums, int kp);

    // Could also define copy constructor but since we do not work with pointers in this class, default copy cosntructor will be just fine

    // ""Nepareizu vērtību gadījumā - izsviests izņēmums.""
    void check_kp(int kp_val);

    void set_id(const string &id_value);
    void set_nosaukums(const string &nosaukums_value);
    void set_kp(int kp_value);
    void set_atzime(int atzime_value);

    string get_id() const;
    string get_nosaukums() const;
    int get_kp() const;
    int get_atzime() const;

    // izvada pilnu informāciju par studiju kursu, ieskaitot atzīmi;
    void display_full() const;

    // izvada informāciju par studiju kursu bez atzīmes
    friend ostream &operator<<(ostream &os, const Studiju_kurss &src);

    // Papild izvade: Nosaukums un atzime
    void display_name_grade() const;
};

#endif