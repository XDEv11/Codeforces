//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	priority_queue<int, vector<int>, greater<int>> pq{};
	for (auto& x : v) pq.push(x);

	int cnt{0}, mx{0};
	while (!pq.empty()) {
		auto x{pq.top()}; pq.pop();
		if (m >= x) m -= x, ++cnt, mx = x;
		else break;
	}

	if (cnt == n) cout << "1\n";
	else if (m + mx - v[cnt] >= 0) cout << n - cnt << '\n';
	else cout << n - cnt + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
