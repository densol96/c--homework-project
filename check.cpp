#include <iostream>
#include <string>

using namespace std;

void test(const string &s)
{
    cout << s << endl;
}

int main()
{
    test("Hello");
    return 0;
}
