#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct rectangle {
    int x{0};
    int y{0};
    int w{0};
    int h{0};
};

int main() {
    fstream file{"C:\\Users\\Laurens\\Documents\\School\\Jaar 2\\Kwartiel 2\\Datastructures\\AoC2018\\Day3\\input3.txt"};
    vector<rectangle> rects;
    string segment, str;
    int count{0};
    rectangle rect;

    map<int, map<int, int>> claims;

    while (getline(file, segment)) {
        stringstream sss{segment};
        char char0;

        sss >> str >> char0 >> rect.x >> char0 >> rect.y >> char0 >> rect.w >> char0 >> rect.h;
        for (int a = rect.x; a < rect.x + rect.w; a++)
        {
            for (int b = rect.y; b < rect.y + rect.h; b++)
            {
                if (claims[a][b]++ == 1)
                {
                    count++;
                }
            }
        }
        rects.push_back(rect);
    }

    cout << "Solution part 1: " << count << endl;

    int id{1};

    for (auto rect2 : rects)
    {
        bool hasFound{true};

        for (int a = rect2.x; a < rect2.x + rect2.w; a++)
        {
            for (int b = rect2.y; b < rect2.y + rect2.h; b++)
            {
                if (claims[a][b] > 1)
                {
                    hasFound = false;
                }
            }
        }

        if (hasFound)
        {
            cout << "Solution part 2: " << id << endl;
        }
        id++;
    }
}