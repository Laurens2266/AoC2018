#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>

using namespace std;

int main() {
    //PART 1
    std::string strings[250];
    int index{0};
    ifstream ifs(
            "C:\\Users\\Laurens\\Documents\\School\\Jaar 2\\Kwartiel 2\\Datastructures\\AoC2018\\Day2\\inputfileday2.txt");
    string content((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));
    stringstream inputfile{content};

    string line;
    int dupes{0};
    int triples{0};
    int ans1{0};
    while (getline(inputfile, line)) {
        map<char, int> m;
        for (auto it = line.begin(); it != line.end(); ++it) {
            if (m.find(*it) == m.end())
                m.insert(make_pair(*it, 1));
            else
                m[*it] += 1;
        }
        bool HasDupes = false;
        bool HasTriples = false;
        for (auto it = m.begin(); it != m.end(); ++it) {
            switch (it->second) {
                case (2): {
                    HasDupes = true;
                    break;
                }
                case (3): {
                    HasTriples = true;
                    break;
                }
            }
        }
        if (HasDupes) {
            dupes++;
        }
        if (HasTriples) {
            triples++;
        }
        strings[index++] = line;
    }
    ans1 = dupes * triples;
    cout << "answer of part 1: " << ans1 << endl;

    //PART 2

    for (auto string1 : strings) {
        for (const auto& string2 : strings) {
            const char *string3 = string2.c_str();

            char val1, val2;
            int amountOfDifferences{0};

            stringstream output{""};

            for (auto c : string1) {
                if (c != *string3++) {
                    amountOfDifferences++;
                } else {
                    output << c;
                }
            }

            if (amountOfDifferences == 1) {
                std::cout << "Solution of part 2: " << output.str() << std::endl;
                exit(0);
            }
        }
    }


    return 0;
}




