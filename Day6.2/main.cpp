#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void expandmapa(vector<vector<int>> &mapa, const int x, const int y)
{
	if (mapa.empty())
	{
		for (int i = 0; i < y; ++i)
		{
			vector<int> temp;

			for (int j = 0; j < x; ++j)
			{
				temp.push_back(0);
			}
			mapa.push_back(temp);
		}
	}

	else
	{
		for (int i = 0; i < mapa.size(); ++i)
		{
			for (int j = mapa[i].size(); j < x; ++j)
			{
				mapa[i].push_back(0);
			}
		}

		for (int i = mapa.size(); i < y; ++i)
		{
			vector<int> temp;

			for (int j = 0; j < x; ++j)
			{
				temp.push_back(0);
			}
			mapa.push_back(temp);
		}
	}
}

void buildmapa(vector<vector<int>> &mapa, const int id, const int x, const int y)
{
	expandmapa(mapa, x + 1, y + 1);
	mapa[y][x] = id;
}

struct Info
{
	int x;
	int y;
	int id;
};

int distance(const int x1, const int y1, const int x2, const int y2)
{
	return abs(x2 - x1) + abs(y2 - y1);
}

void buildCloser(vector<vector<int>> &mapa, const vector<Info> &informations, const int x, const int y)
{
	int total_distance = 0;

	for (int i = 0; i < informations.size(); ++i)
		total_distance += distance(x, y, informations[i].x, informations[i].y);

	if (total_distance < 10000)
		mapa[y][x] = -1;
}

int buildSize(const vector<vector<int>> &mapa, const int id)
{
	int res = 0;

	for (int i = 0; i < mapa.size(); ++i)
	{
		for (int j = 0; j < mapa[i].size(); ++j)
		{
			if (mapa[i][j] == -id || mapa[i][j] == id)
			{
				if (i == 0 || i == mapa.size() - 1 || j == 0 || j == mapa[i].size() - 1)
				{
					return 0;
				}
				else
				{
					res++;
				}
			}
		}
	}
	return res;
}

int main()
{
	vector<vector<int>> mapa;
	vector<vector<int>> distances;
	vector<Info> informations;
	int id = 1;
	Info information;
	string line;

    ifstream input("C:\\Users\\Laurens\\Documents\\School\\Jaar 2\\Kwartiel 2\\Datastructures\\AoC2018\\Day6\\input6.txt");

	while (!input.eof())
	{
		information.id = id;

		getline(input, line, ',');
		information.x = stoi(line);

		input.ignore();
		getline(input, line);
		information.y = stoi(line);

		informations.push_back(information);
		buildmapa(mapa, id, information.x, information.y);
		++id;
	}

	input.close();

	for (int i = 0; i < mapa.size(); ++i)
		for (int j = 0; j < mapa[i].size(); ++j)
			buildCloser(mapa, informations, j, i);

	int size = 0;

	for (int i = 0; i < mapa.size(); ++i)
		for (int j = 0; j < mapa[i].size(); ++j)
			size += mapa[i][j] == -1 ? 1 : 0;

	cout << "Solution of part 2: " << size;

	return 0;
}