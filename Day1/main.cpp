#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <cassert>
#include <sstream>
#include <unordered_map>


using namespace std;

int main() {
    //PART 1
    std::ifstream ifs(
            "C:\\Users\\Laurens\\Documents\\School\\Jaar 2\\Kwartiel 2\\Datastructures\\AoC2018\\Day1\\puzzleinput.txt");
    std::string content((std::istreambuf_iterator<char>(ifs)),
                        (std::istreambuf_iterator<char>()));

    int sum{0};
    int number;

    std::stringstream inputfile{content};
    while (inputfile >> number) {
        sum = sum + number;
    }
    cout << "Solution of part 1: " << sum << endl;

    //PART 2

    int sum1{0};
    unordered_map<int, bool> frequenties;
    frequenties[sum1] = true;
    while (true)
    {
        stringstream inputfile2{content};
        while (inputfile2 >> number)
        {
            sum1 = sum1 + number;
            if (frequenties[sum1])
            {
                cout << "Solution of part 2: " << sum1 << endl;
                return 0;
            }
            frequenties[sum1] = true;
        }

    }
}