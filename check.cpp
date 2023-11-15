#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

string OS;

void clear_screen()
{
#ifdef __linux__
    system("clear");
#elif __APPLE__
// Add any MacOS-specific clear screen code if needed
#elif _WIN32
    system("cls");
#endif
}

void flash_screen(int choice)
{
    (void)(OS == "linux" ? system("clear") : system("cls"));
}

int main()
{
    getOS();
    cout << OS << endl;
    return 0;
}
