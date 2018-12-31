#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
#define INPUT_SIZE 101

struct nodo{ vector<char> out; vector<char> in; bool visited = false; bool inqueue = false; };
unordered_map<char, nodo> adj;

bool checkNode(char c){
    if(adj[c].visited)
        return false;
    for(auto x : adj[c].in)
        if(!adj[x].visited)
            return false;
    return true;
}

int main(){
    freopen("C:\\Users\\Laurens\\Documents\\School\\Jaar 2\\Kwartiel 2\\Datastructures\\AoC2018\\Day7\\input7.txt", "r", stdin);
    for(int i = 0; i < INPUT_SIZE; i++){
        char da, a;
        scanf("Step %c must be finished before step %c can begin.\n", &da, &a);
        adj[da].out.push_back(a);
        adj[a].in.push_back(da);
    }

    string ans = "";

    while(ans.size() != adj.size()){
        char next = ('Z'+1);
        for(auto x : adj){
            if(checkNode(x.first))
                next = min(next, x.first);
        }
        ans += next;
        adj[next].visited = true;
    }
    cout << ans << endl;
    return 0;
}