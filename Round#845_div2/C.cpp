//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	int ans{numeric_limits<int>::max()};
	int cnt{0}, j{-1};
	vector<int> ck(m + 1);
	for (int i{0}; i < n; ++i) {
		while (cnt < m) {
			++j;
			if (j == n) break;
			for (int f{1}; f <= m && f * f <= v[j]; ++f) {
				if (v[j] % f) continue;
				cnt += !(ck[f]++);
				if (v[j] / f <= m) cnt += !(ck[v[j] / f]++);
			}
		}
		if (j == n) break;
		ans = min(ans, v[j] - v[i]);

		for (int f{1}; f <= m && f * f <= v[i]; ++f) {
			if (v[i] % f) continue;
			cnt -= !(--ck[f]);
			if (v[i] / f <= m) cnt -= !(--ck[v[i] / f]);
		}
	}

	if (ans == numeric_limits<int>::max()) cout << "-1\n";
	else cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
