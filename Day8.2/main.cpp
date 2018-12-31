#include <iostream>
#include <vector>
using namespace std;

int valueOf(){
    vector<int> sonsValues(1, 0);
    int N, M, consume, value = 0;
    cin >> N >> M;
    while(N--) { sonsValues.push_back(valueOf()); }

    if(sonsValues.size() == 1)	while(M--)	{ cin >> consume; value+=consume; }
    else	while(M--){	cin >> consume;	value += (consume > 0 && consume < (int) sonsValues.size()) ? sonsValues[consume] : 0;	}

    return value;
}

int main(){
    freopen("C:\\Users\\Laurens\\Documents\\School\\Jaar 2\\Kwartiel 2\\Datastructures\\AoC2018\\Day8\\input8.txt", "r", stdin);
    cout << valueOf();
    return 0;
}