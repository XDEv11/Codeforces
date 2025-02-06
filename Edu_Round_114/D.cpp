#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <functional>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	for (int i{0}; i < n; ++i) {
		int c;
		cin >> c;
		a[i].resize(c);
		for (auto& x : a[i]) cin >> x;
	}

	set<vector<int>> ban{};
	int m;
	cin >> m;
	while (m--) {
		vector<int> b(n);
		for (auto& x : b) cin >> x, --x;
		ban.emplace(move(b));
	}

	priority_queue<pair<int, vector<int>>> pq{};
	set<vector<int>> vis{};
	{
		int sum{0};
		vector<int> v(n);
		for (int i{0}; i < n; ++i) v[i] = a[i].size() - 1;
		pq.emplace(sum, v), vis.emplace(move(v));
	}

	while (true) {
		auto [sum, v]{pq.top()}; pq.pop();
		if (!ban.count(v)) {
			for (auto& x : v) cout << x + 1 << ' ';
			cout<< '\n';
			return ;
		}
		for (int i{0}; i < n; ++i) {
			if (v[i] == 0) continue;
			sum -= a[i][v[i]], --v[i], sum += a[i][v[i]];
			if (!vis.count(v)) pq.emplace(sum, v), vis.emplace(v);
			sum -= a[i][v[i]], ++v[i], sum += a[i][v[i]];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
