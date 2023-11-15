#ifndef TESTI_HPP
#define TESTI_HPP

#include <iostream>
#include "Studiju_kurss.hpp"
#include "My_error.hpp"
#include "Kursu_saraksts.hpp"
#include "Students.hpp"

using namespace std;

void studiju_kurss_test()
{
    Studiju_kurss k1;
    cout << "Studiju_kurss k1 ---> " << k1 << endl;

    Studiju_kurss k2{"CS_50", "Comp Sci", 4};
    cout << "Studiju_kurss k2{ CS_50 , Comp Sci, 4} --> " << k2 << endl;
    k2.display_full();

    try
    {
        Studiju_kurss k3{"ERR", "Error_expected", -10};
    }
    catch (const My_error &err)
    {
        cout << "Exception caught: " << endl;
        cerr << err.what() << endl;
    }

    try
    {
        k2.set_atzime(-15);
    }
    catch (const My_error &err)
    {
        cout << "Exception caught: " << endl;
        cerr << err.what() << endl;
    }
}

void testKursuSaraksts()
{
    Studiju_kurss k1{"CS_50", "Comp Sci", 4};
    Studiju_kurss k2{"Bio_1", "Biology", 3};
    Studiju_kurss k3{"Eng_1", "English", 2};

    Kursu_saraksts list;

    cout << "Adding courses to the dynamic array, testing [] operator" << endl;
    list.push_back(k1);
    list.push_back(k2);
    list.push_back(k3);

    for (int i{0}, length = list.size(); i < length; i++)
    {
        cout << list[i] << endl;
    }

    cout << "Testing popping off:" << endl;
    cout << list.pop_back() << endl;
    for (int i{0}, length = list.size(); i < length; i++)
    {
        cout << list[i] << endl;
    }
}

void testStudents()
{
    Studiju_kurss k1{"CS_50", "Comp Sci", 4};
    Studiju_kurss k2{"Bio_1", "Biology", 3};
    Studiju_kurss k3{"Eng_1", "English", 2};
    k1.set_atzime(5);
    k2.set_atzime(6);
    k3.set_atzime(7);

    Kursu_saraksts list;
    list.push_back(k1);
    list.push_back(k2);
    list.push_back(k3);

    Studiju_kurss k4{"RUS1", "Russian", 4};
    Studiju_kurss k5{"LV2", "Latvian", 4};
    Studiju_kurss k6{"Eng_1", "English", 2};
    k4.set_atzime(5);
    k5.set_atzime(6);
    k6.set_atzime(7);

    Kursu_saraksts new_list;
    list.push_back(k4);
    list.push_back(k5);
    list.push_back(k6);
    ////////////////////////////////

    Students s1;
    Students s2{"s22solodeni", "Deniss", "2ITB1", 2};

    // Checking the wrong year
    cout << "ERROR EXPECTED:" << endl;
    try
    {
        Students s3{"Err", "err", "err", 10};
    }
    catch (const My_error &err)
    {
        cerr << err.what() << endl;
    }
    cout << " ==== " << endl
         << endl;

    Students s3{"s00fakeuser", "Faker", "FAKE_55", 1, list};

    cout << "STUDENTS CREATED: " << endl;
    cout << " ==== STUDENT 1 (empty values expected)  ====" << endl;
    s1.izvada_info();
    cout << " ==== STUDENT 2 (-1 for atzimes expected)  ====" << endl;
    s2.izvada_info_ar_vid_atzimi();
    cout << " ==== STUDENT 3 (vid atzime 6 expected)  ====" << endl;
    s3.izvada_pilno_info();
    cout << "END" << endl;

    // SETTERI GETTERI
    cout << endl
         << "SETS AND GETS" << endl;
    cout << s3.get_vards() << endl;
    cout << s3.get_studiju_kursi()[0] << endl;
    s3.set_vards("Janis");
    cout << s3.get_vards() << endl;

    // SEARCHING THE COURSE
    cout << boolalpha << endl;
    cout << "Searcing the valid course - expect true" << endl;
    cout << s3.vai_ir_kurss("CS_50") << endl;
    cout << "Searcing the invalid course - expect false" << endl;
    cout << s3.vai_ir_kurss("CS_540") << endl;

    cout << "Searching and returning a reference, changing the grade on the reference and checking if changes were applied in Student using [] operator" << endl;
    Studiju_kurss &ref = s3.kurss_pec_id("CS_50");
    cout << "Grade on a referenced course  --- > " << ref.get_atzime() << endl;
    ref.set_atzime(7);
    cout << "Updated ref in Student class " << s3[0].get_atzime() << endl;

    cout << "Adding a new course:" << endl;
    Studiju_kurss new_course{"BS12", "Business", 2};
    new_course.set_atzime(10);

    s3.pievienot_kursu(new_course);
    s3.izvada_info();
    cout << "CHECKING if i can ADD THE SAME COURSE" << endl;
    s3.pievienot_kursu(new_course);

    cout << "ADDING MANY COURSES" << endl;
    s3.pievienot_kursus(new_list);
    s3.izvada_info();
}

#endif