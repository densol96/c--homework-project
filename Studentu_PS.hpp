#ifndef STUDENTU_PS_HPP
#define STUDENTU_PS_HPP

#include <vector>
#include <string>
#include "Students.hpp"

class Studentu_PS
{
private:
    vector<Students> students_list;

public:
    Studentu_PS();

    // Searching by id
    bool vai_ir_students(const string &id) const;
    Students &students_pec_id(const string &id);
    const Students &students_pec_id(const string &id) const;

    // Adding a student
    void pievienot_studentu(const Students &jauns_students);
    void pievienot_studentu(const string &id, const string &grupa, const string &vards, int studiju_gads);

    // Displaying info
    void display_students_and_courses() const;
    void display_students_and_grades() const;
    void display_students_full() const;
};
#endif