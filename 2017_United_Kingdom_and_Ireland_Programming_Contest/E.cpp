//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;

bool solve() {
	int n, m;
	if (!(cin >> n >> m)) return false;
	vector<array<int, 2>> s(n);
	vector<array<int, 3>> p(m);
	for (int i{0}; i < n; ++i) cin >> s[i][0], s[i][1] = i;
	for (int i{0}; i < m; ++i) cin >> p[i][0], p[i][2] = i;
	for (int i{0}; i < m; ++i) cin >> p[i][1];

	sort(s.rbegin(), s.rend());
	sort(p.rbegin(), p.rend());

	vector<int> ans(n);
	priority_queue<array<int, 2>> pq{};
	for (int i{0}, j{0}; i < n; ++i) {
		while (j < m && p[j][0] >= s[i][0]) {
			pq.push({-p[j][1], p[j][2]}), ++j;
		}
		if (pq.empty()) return cout << "impossible\n", true;
		auto [x, y]{pq.top()}; pq.pop();
		ans[s[i][1]] = y;
	}

	for (auto& x : ans) cout << x + 1 << ' ';
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
