//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<array<int, 3>> a{};
	for (int i{0}; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (x > y) continue;
		a.push_back({x, y, i});
	}
	n = a.size();
	int m;
	cin >> m;
	vector<array<int, 2>> b(m);
	for (int i{0}; i < m; ++i) cin >> b[i][0], b[i][1] = i;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<vector<int>> ans(m);
	priority_queue<pair<int, vector<int>>> pq1{};
	for (int i{0}; i < m; ++i) pq1.emplace(0, vector<int>{});
	priority_queue<array<int, 3>> pq2{};
	int j{0}, k{0};
	while (!pq1.empty()) {
		auto [z, r]{pq1.top()}; pq1.pop();
		if (b[j][0] <= -z) {
			ans[b[j++][1]] = r;
			continue;
		}
		while (k < n && a[k][0] <= -z) pq2.push({-a[k][1], a[k][0], a[k][2]}), ++k;
		if (pq2.empty()) return cout << "impossible\n", true;
		auto [x, y, i]{pq2.top()}; pq2.pop();
		z = x, r.push_back(i);
		pq1.emplace(z, r);
	}

	for (auto& v : ans) {
		for (auto& x : v) cout << x + 1 << ' ';
		cout << '\n';
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
