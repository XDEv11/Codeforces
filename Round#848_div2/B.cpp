//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m, d;
	cin >> n >> m >> d;
	vector<int> p(n), v(m);
	for (auto& x : p) cin >> x, --x;
	for (auto& x : v) cin >> x, --x;

	vector<int> idx(n);
	for (int i{0}; i < n; ++i) idx[p[i]] = i;

	bool flag{true};
	for (int i{0}; i + 1 < m; ++i) {
		if (!(idx[v[i]] < idx[v[i + 1]] && idx[v[i + 1]] <= idx[v[i]] + d)) {
			flag = false;
			break;
		}
	}
	if (!flag) return cout << "0\n", []{}();

	int ans{n};
	for (int i{0}; i + 1 < m; ++i) {
		ans = min(ans, idx[v[i + 1]] - idx[v[i]]);
		if (d + 1 < n) ans = min(ans, idx[v[i]] + d + 1 - idx[v[i + 1]]);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
