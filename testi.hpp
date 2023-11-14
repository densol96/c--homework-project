#ifndef TESTI_HPP
#define TESTI_HPP

#include <iostream>
#include "Studiju_kurss.hpp"
#include "My_error.hpp"
#include "Kursu_saraksts.hpp"
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

#endif