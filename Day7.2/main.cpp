#include <bits/stdc++.h>
using namespace std;
#define INPUT_SIZE 101

struct nodo{ vector<char> out; vector<char> in; bool visited = false; bool workingon = false; };
unordered_map<char, nodo> adj;

bool checkNode(char c){
	if(adj[c].visited || adj[c].workingon)
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

	vector<pair<int, char>> worker;

	for(auto &x : adj)
		if((int)x.second.in.size() == 0 && (int)worker.size() < 5){
			worker.push_back({60 + (int)(x.first - 'A'+1), x.first});
			x.second.workingon = true;
		}

	while((int) worker.size() < 5)
		worker.push_back({0, '.'});

/*	for(auto x : worker)
		cout << x.first << " ";
	cout << "\n";
*/
	int ans = 0;

	bool flag = true;

	while(flag){
		int gap = 1e9;
		for(auto x : worker)
			if(x.second != '.')
				gap = min(gap, x.first);

		ans += gap;

		for(auto &x : worker)
			if(x.second != '.'){
				x.first -= gap;
				if(x.first == 0){
					adj[x.second].visited = true;
					//cout << "Finished: " << x.second << "\n";
					x.second = '.';
				}
			}

		priority_queue<char, vector<char>, greater<char>> nexts;
		for(auto x : adj){
			if(checkNode(x.first))
				nexts.push(x.first);
		}

		for(auto &x : worker){
			if(nexts.empty())	break;
			if(x.second == '.'){
				x.first = 60 + (int)nexts.top() - 'A' +1;
				x.second = nexts.top();
				adj[nexts.top()].workingon = true;
				//cout << "Started: " << nexts.top() << "\n";
				nexts.pop();
			}
		}

		flag = false;
		for(auto x : worker)
			if(x.second != '.'){ flag = true; break; }

	}
	cout << ans;
	return 0;
}