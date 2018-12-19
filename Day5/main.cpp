#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int parse(string data, int rem = 0)
{
    if (rem)
    {
        data.erase(rem(data.begin(), data.end(), rem), data.end());
        data.erase(rem(data.begin(), data.end(), rem + 'A' - 'a'), data.end());
    }

    bool found{true};
    while (found)
    {
        found = false;

        for (unsigned int a{0}; a < data.length() - 1; a++)
        {
            char current = data[a];
            char next = data[a + 1];

            if (current == next + 'A' - 'a' || current + 'A' - 'a' == next)
            {
                data.erase(a, 2);
                found = true;
            }
        }
    }

    return data.length();
}

int main()
{
    ifstream inputFile{"../input5.txt"};
    string input;

    getline(inputFile, input);
    cout << "Solution of part 1: " << parse(input) << endl;

    int Minimumlength{INT_MAX};
    for (int i = 'a'; i <= 'z'; i++)
    {
        Minimumlength = min(Minimumlength, parse(input, i));
    }
    cout << "Solution of part 2: " << Minimumlength << endl;
}