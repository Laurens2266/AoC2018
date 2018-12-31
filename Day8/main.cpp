#include <iostream>
using namespace std;
int ans = 0;

void foo(){
    int N, M, consume;
    cin >> N >> M;
    while(N--)	foo();
    while(M--) { cin >> consume; ans += consume; }
}

int main(){
    freopen("C:\\Users\\Laurens\\Documents\\School\\Jaar 2\\Kwartiel 2\\Datastructures\\AoC2018\\Day8\\input8.txt", "r", stdin);
    foo();
    cout << ans;
    return 0;
}