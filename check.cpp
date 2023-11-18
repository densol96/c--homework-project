#include <iostream>
#include <fstream>
#include <string>

void displayCoursesFromFile(const std::string &filename)
{
    std::ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string courseName;
    while (std::getline(inputFile, courseName))
    {
        std::cout << courseName << std::endl;
    }

    inputFile.close();
}

int main()
{
    std::string filename = "kursi.txt"; // Update with your file name
    displayCoursesFromFile(filename);

    return 0;
}