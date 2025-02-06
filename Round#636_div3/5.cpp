#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int Unreachable = 10e6;
int[] Dijkstra(vector<pair<int, int>> adjList[], int n, int v, int dest) {
	bool found[n];
	int path[n];
	path[v] = -1;
	for (int i = 0; i < n; ++i) found[i] = false;
	found[v] = true;
	int distance[n];
	for (int i = 0; i < n; ++i) distance[i] = Unreachable;
	distance[v] = 0;
	priority_queue<pair<int, int>> mypq;
	for (auto it = adjList[v].begin(); it != adjList[v].end(); ++it) {
		mypq.emplace(-1 * it -> second, it -> first);
		path[it -> first] = v;
		distance[it -> first] = it -> second;
	}
	for (int i = 1; i <= n - 1; ++i) {
		int u;
		do {
			u = mypq.top().second;
			mypq.pop();
		} while(found[u]);
		found[u] = true;
		for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it) {
			int w = it -> first;
			if (distance[w] > distance[u] + it -> second) {
				path[w] = u;
				distance[w] = distance[u] + it -> second;
				mypq.emplace(-1 * distance[w], w);
			}
		}
	}
	return path;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, m, a, b, c;
		cin >> n >> m >> a >> b >> c;
		--a; --b; --c;
		priority_queue<int> weights;
		for (int i = 0; i < m; ++i) {
			int w;
			cin >> w;
			weights.push(-w);
		}
		vector<pair<int, int>> adjList[n];
		for (int i = 0; i < m; ++i) {
			int v1, v2;
			cin >> v1 >> v2;
			--v1; --v2;
			adjList[v1].emplace_back(v2, 1);
			adjList[v2].emplace_back(v1, 1);
		}
		int num = Dijkstra(adjList, n, a, b);
		cout << a << " -> " << b << " : " << num << endl;
		num += Dijkstra(adjList, n, b, c);
		cout << b << " -> " << c << " : " << num << endl;
		int ans = 0;
		while(num--) {
			ans += weights.top();
			weights.pop();
		}
		cout << -1 * ans << endl;
	}
	return 0;
}
