#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include "My_error.hpp"
#include "Studentu_PS.hpp"
#include "Students.hpp"
#include "testi.hpp"
using namespace std;

void app(Studentu_PS &school_system);
void clear_screen();
void display_main_menu();
void add_student(Studentu_PS &school_system);
void timer_ui(int secs = 3, string text = "Returning to main menu in");
void find_student_menu(Studentu_PS &school_system);
void student_menu(Students &current_student);
void display_student_menu(Students &current_student);
void add_course(Students &current_student);
void display_available_courses();
void provide_course_information(Students &current_student);
void print_text_file(string filename);
void add_change_grade(Students &current_student);

// g++ -g Kursu_saraksts.cpp My_error.cpp Students.cpp Studentu_PS.cpp Studiju_kurss.cpp main.cpp -o main.exe

int main()
{
    // TESTS
    // studiju_kurss_test();
    // testKursuSaraksts();
    // testStudents();

    // Start the app
    // Upon launching the .exe in order to clear previous entries in terminal have to run this twice, but once the app is up, it works properly
    clear_screen();
    clear_screen();
    cout << "===============" << endl;
    cout << "Welcome to our application!" << endl;
    cout << "NAME: 01_projekts" << endl;
    cout << "AUTHORS: Deniss Solovjovs, Edvards Bazbauers." << endl;
    cout << "================" << endl;
    cout << endl;
    cout << "Please press Enter to start this program...... " << endl;
    cin.get();

    // Create the Studentu_PS object
    Studentu_PS school_system;

    // Pass the object by reference and start the app
    app(school_system);

    return 0;
}

void app(Studentu_PS &school_system)
{

    while (true)
    {
        display_main_menu();
        int choice;
        cout << "Please enter your option ===> ";
        cin >> choice;
        if (choice == 1)
        {
            add_student(school_system);
        }
        else if (choice == 2)
        {
            find_student_menu(school_system);
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            clear_screen();
            cout << "WRONG INPUT! TRY AGAIN!" << endl;
            timer_ui();
            continue;
        }
    }
}

void clear_screen()
{
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
}

void timer_ui(int secs, string text)
{
    cout << text << endl;
    for (int i{secs}; i >= 0; i--)
    {
        cout << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\033[F\033[K";
    }
}

void display_main_menu()
{
    clear_screen();
    cout << "===== MAIN MENU =====" << endl;
    cout << "1) Add a new student to the list" << endl;
    cout << "2) Find the student by ID" << endl;
    cout << "3) Exit the program" << endl;
}

void add_student(Studentu_PS &school_system)
{
    clear_screen();
    cout << "===== ADD NEW STUDENT MENU =====" << endl;
    cout << "To add a new student, please, provide following information:" << endl;

    string id, vards, grupa;
    int studiju_gads{};

    cout << "ID ==> ";
    cin >> id;
    cout << "NAME ===> ";
    cin >> vards;
    cout << "GROUP ===> ";
    cin >> grupa;
    cout << "YEAR ===> ";
    cin >> studiju_gads;

    try
    {
        Students new_student{id, vards, grupa, studiju_gads};
        school_system.pievienot_studentu(new_student);
    }
    catch (const My_error &err)
    {
        clear_screen();
        cout << "ERROR: " << err.what() << endl;
        cout << "STUDENT WAS NOT ADDED.." << endl;
        timer_ui(5);
        return;
    }
    clear_screen();
    cout << "STUDENT SUCESSFULLY ADDED!" << endl;
    timer_ui();
}

void find_student_menu(Studentu_PS &school_system)
{
    clear_screen();
    cout << "===== FIND THE STUDENT =====" << endl;
    cout << "ENTER STUDENT'S ID ===> ";
    string id;
    cin >> id;
    if (school_system.vai_ir_students(id))
    {
        Students &current_student = school_system.students_pec_id(id);
        student_menu(current_student);
    }
    else
    {
        clear_screen();
        cout << "STUDENT WITH THIS ID OF " << id << " DOES NOT EXIST!" << endl;
        timer_ui(5);
    }
}

void student_menu(Students &current_student)
{
    while (true)
    {
        clear_screen();
        cout << "===== STUDENT MENU: " << current_student.get_vards() << "( " << current_student.get_id() << " ) =====" << endl;
        cout << "1) Display information" << endl;
        cout << "2) Add new course" << endl;
        cout << "3) Add/change grade" << endl;
        cout << "4) Return to main menu" << endl;
        int choice;
        cout << "Please enter your option ===> ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 1)
        {
            display_student_menu(current_student);
        }
        else if (choice == 2)
        {
            add_course(current_student);
        }
        else if (choice == 3)
        {
            add_change_grade(current_student);
        }
        else if (choice == 4)
        {
            return;
        }
        else
        {
            cout << "INVALID INPUT! Please try again!" << endl;
        }
    }
}

void display_student_menu(Students &current_student)
{
    while (true)
    {
        clear_screen();
        cout << "===== DISPLAY STUDENT INFORMATION MENU: " << current_student.get_vards() << "( " << current_student.get_id() << " ) =====" << endl;
        cout << "1) Display student's courses" << endl;
        cout << "2) Display student's average grades" << endl;
        cout << "3) Display student's full information" << endl;
        cout << "4) Return to student menu" << endl;
        int choice;
        cout << "Please enter your option ===> ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 1)
        {
            clear_screen();
            current_student.izvada_info();
            cout << "Press Enter to return back.." << endl;
            cin.get();
        }
        else if (choice == 2)
        {
            clear_screen();
            current_student.izvada_info_ar_vid_atzimi();
            cout << "Press Enter to return back.." << endl;
            cin.get();
        }
        else if (choice == 3)
        {
            clear_screen();
            current_student.izvada_pilno_info();
            cout << "Press Enter to return back.." << endl;
            cin.get();
        }
        else if (choice == 4)
        {
            return;
        }
        else
        {
            cout << "INVALID INPUT! Please try again!" << endl;
        }
    }
}

void add_course(Students &current_student)
{
    while (true)
    {
        clear_screen();
        cout << "===== ADD NEW COURSE FOR: " << current_student.get_vards() << "( " << current_student.get_id() << " ) =====" << endl;
        cout << "Here is the list of available for adding courses:" << endl;
        print_text_file("kursi.txt");
        cout << endl
             << "Please provide your option for the course you want to add: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            Studiju_kurss temp{"PROG_1", "Programming", 4};
            current_student.pievienot_kursu(temp);
            break;
        }
        else if (choice == 2)
        {
            Studiju_kurss temp{"MATH_2", "Mathematics", 3};
            current_student.pievienot_kursu(temp);
            break;
        }
        else if (choice == 3)
        {
            Studiju_kurss temp{"LAN_3", "Networking", 4};
            current_student.pievienot_kursu(temp);
            break;
        }
        else if (choice == 4)
        {
            Studiju_kurss temp{"ENG_4", "English", 2};
            current_student.pievienot_kursu(temp);
            break;
        }
        else if (choice == 5)
        {
            Studiju_kurss temp{"BUS_5", "Business", 1};
            current_student.pievienot_kursu(temp);
            break;
        }
        else if (choice == 6)
        {
            Studiju_kurss temp{"CHN_6", "Chinese", 1};
            current_student.pievienot_kursu(temp);
            break;
        }
        else if (choice == 7)
        {
            Studiju_kurss temp{"OS_7", "Operational Systems", 4};
            current_student.pievienot_kursu(temp);
            break;
        }
        else if (choice == 8)
        {
            return;
        }
        else
        {
            clear_screen();
            cout << "Wrong input! Please try again! Or go back to the student menu!" << endl;
            timer_ui(5, "Returning to ADD NEW COURSE menu");
        }
    }
    clear_screen();
    cout << "Action completed!" << endl;
    timer_ui(3, "Returning to student menu in..");
    return;
}

void print_text_file(string filename)
{
    ifstream file;
    file.open(filename);
    if (!file.is_open())
    {
        cerr << "Could not open " << filename << endl;
        return;
    }
    string single_line;
    while (getline(file, single_line))
    {
        cout << single_line << endl;
    }
    file.close();
}

void add_change_grade(Students &current_student)
{
    if (current_student.get_studiju_kursi().size() == 0)
    {
        clear_screen();
        cout << "Sorry! Currently student has no any courses added!" << endl;
        timer_ui(3, "Returning to the STUDENT MENU in..");
        return;
    }
    while (true)
    {
        clear_screen();
        cout << "===== ADD/CHANGE GRADE FOR: " << current_student.get_vards() << "( " << current_student.get_id() << " ) =====" << endl;
        current_student.izvada_info();
        cout << endl
             << "Which course to choose for adding/changing grade? Enter id (or enter 'exit' if you changed your mind) --> ";
        string id;
        cin >> id;

        if (tolower(id[0]) == 'e')
            return;

        if (!current_student.vai_ir_kurss(id))
        {
            clear_screen();
            timer_ui(3, "Student does not have a course with such ID! Pleast try again in");
            continue;
        }

        cout << "Enter new grade [1, 10] --> ";
        int new_grade;
        cin >> new_grade;

        try
        {
            current_student.kurss_pec_id(id).set_atzime(new_grade);
        }
        catch (const My_error &err)
        {
            clear_screen();
            cerr << err.what() << endl;
            timer_ui(4, "Please try again in..");
            continue;
        }
        clear_screen();
        cout << "Changes successfully applied!" << endl;
        current_student.kurss_pec_id(id).display_name_grade();
        timer_ui(5, "Returning to the student menu in..");
        return;
    }
}