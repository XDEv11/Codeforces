#include <iostream>
#include <vector>
#include <queue>

#define Unreachable 1000000000000000000

using namespace std;

void Dijkstra(vector<pair<int, int>> adjList[], int n, int v) {
	bool found[n];
	for (int i = 0; i < n; ++i) found[i] = false;
	found[v] = true;
	long long distance[n];
	for (int i = 0; i < n; ++i) distance[i] = Unreachable;
	distance[v] = 0;
	priority_queue<pair<long long, int>> mypq;
	for (vector<pair<int, int>>::iterator it = adjList[v].begin(); it != adjList[v].end(); ++it) {
		mypq.emplace(-1 * it -> second, it -> first);
		distance[it -> first] = it -> second;
	}
	for (int i = 1; i <= n - 1; ++i) {
		int u;
		do {
			u = mypq.top().second;
			mypq.pop();
		} while(found[u]);
		found[u] = true;
		for (vector<pair<int, int>>::iterator it = adjList[u].begin(); it != adjList[u].end(); ++it) {
			int w = it -> first;
			if (distance[w] > distance[u] + it -> second) {
				distance[w] = distance[u] + it -> second;
				mypq.emplace(-1 * distance[w], w);
			}
		}
	}
	for (int i = 0; i < n; ++i) cout << distance[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, e;
	cin >> n >> e;
	vector<pair<int, int>> adjList[n];
	while(e--) {//read edges
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		adjList[v1].emplace_back(v2, c);
		adjList[v2].emplace_back(v1, c);
	}
	Dijkstra(adjList, n, 0);
	return 0;
}
