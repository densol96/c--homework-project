#include "Studentu_PS.hpp"
#include "My_error.hpp"

Studentu_PS::Studentu_PS() {}

bool Studentu_PS::vai_ir_students(const string &id) const
{
    for (const Students &student : students_list)
    {
        if (student.get_id() == id)
        {
            return true;
        }
    }
    return false;
}

Students &Studentu_PS::students_pec_id(const string &id)
{
    for (Students &student : students_list)
    {
        if (student.get_id() == id)
        {
            return student;
        }
    }
    string message = "Unable to find the stuent with the ID of: " + id;
    throw My_error{message};
}

const Students &Studentu_PS::students_pec_id(const string &id) const
{
    for (const Students &student : students_list)
    {
        if (student.get_id() == id)
        {
            return student;
        }
    }
    string message = "Unable to find the stuent with the ID of: " + id;
    throw My_error{message};
}

void Studentu_PS::pievienot_studentu(const Students &jauns_students)
{
    if (!vai_ir_students(jauns_students.get_id()))
    {
        students_list.push_back(jauns_students);
        return;
    }
    cout << "The student with such id is already present in the list! Student not added again!" << endl;
}

void Studentu_PS::pievienot_studentu(const string &id, const string &grupa, const string &vards, int studiju_gads)
{
    if (!vai_ir_students(id))
    {
        students_list.push_back(Students{id, vards, grupa, studiju_gads});
        return;
    }
    cout << "The student with such id is already present in the list! Student not added again!" << endl;
}

void Studentu_PS::display_students_and_courses() const
{
    for (const Students &student : students_list)
    {
        cout << "========" << endl;
        student.izvada_info();
        cout << "=========" << endl;
    }
}

void Studentu_PS::display_students_and_grades() const
{
    for (const Students &student : students_list)
    {
        cout << "========" << endl;
        student.izvada_info_ar_vid_atzimi();
        cout << "=========" << endl;
    }
}

void Studentu_PS::display_students_full() const
{
    for (const Students &student : students_list)
    {
        cout << "========" << endl;
        student.izvada_pilno_info();
        cout << "=========" << endl;
    }
}