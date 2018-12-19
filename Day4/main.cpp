
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

class guard {
private:
    int minuteAsleep{0};
    int totalAsleep{0};
    map<int, int> minutesAsleep;

public:
    void sleep(int minute) {
        this->minuteAsleep = minute;
    }

    void awake(int minute) {
        this->totalAsleep += minute - minuteAsleep;
        for (int a = minuteAsleep; a < minute; a++)
            this->minutesAsleep[a]++;
    }

    int getTotalSleepMinutes() const {
        return this->totalAsleep;
    }

    int getMaxMinute() {
        auto x = max_element(this->minutesAsleep.begin(), this->minutesAsleep.end(),
                                  [](const pair<int, int>&p1, const pair<int, int>& p2) {
                                      return p1.second < p2.second; });

        return x->first;
    }

    int getAmountOfAsleepPerMinute(int minute) {
        return this->minutesAsleep[minute];
    }
};

int main() {
    fstream file{"C:\\Users\\Laurens\\Documents\\School\\Jaar 2\\Kwartiel 2\\Datastructures\\AoC2018\\Day4\\input4.txt"};
    string segment;

    vector<string> inputLines;
    while (getline(file, segment))
        inputLines.push_back(segment);

    sort(inputLines.begin(), inputLines.end());

    map<int, guard> guards;
    for (auto& i : inputLines) {
        stringstream sss{i};
        string command;
        int minute, guardId;
        char c;

        sss >> segment >> minute >> c >> minute >> c >> command;
        if (command == "Guard") {
            sss >> c >> guardId;
        } else if (command == "falls") {
            guards[guardId].sleep(minute);
        } else {
            guards[guardId].awake(minute);
        }
    }

    auto x = max_element(guards.begin(), guards.end(),
                              [](const pair<int, guard>& p1, const pair<int, guard>& p2) {
                                  return p1.second.getTotalSleepMinutes() < p2.second.getTotalSleepMinutes();
                              });

    cout << "Solution of part 1: " << x->first * x->second.getMaxMinute() << endl;

    int laziestGuard{0};
    int laziestMinute{0};
    int SleepTimes{0};
    for (int i = 0; i < 59; i++) {
        for (auto& guard : guards) {
            int y = guard.second.getAmountOfAsleepPerMinute(i);
            if (y > SleepTimes) {
                laziestGuard = guard.first;
                laziestMinute = i;
                SleepTimes = y;
            }
        }
    }

    cout << "Solution of part 2: " << laziestGuard * laziestMinute << endl;
}