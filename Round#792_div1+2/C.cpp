//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (auto& v : g)
		for (auto& x : v) cin >> x;
	
	int ans1{-1}, ans2;
	for (auto& v : g) {
		auto t{v};
		sort(t.begin(), t.end());
		int d1{-1}, d2{-1};
		for (int j{0}; j < m; ++j) {
			if (v[j] == t[j]) continue;
			if (d1 == -1) d1 = j;
			else if (d2 == -1) d2 = j;
			else return cout << "-1\n", []{}();
		}
		if (ans1 == -1) ans1 = d1, ans2 = d2;
		else if (d1 != -1 && ans1 != d1 && ans2 != d2) return cout << "-1\n", []{}();
	}
	
	if (ans1 != -1) {
		for (auto& v : g) {
			swap(v[ans1], v[ans2]);
			if (!is_sorted(v.begin(), v.end())) return cout << "-1\n", []{}();
		}
		cout << ans1 + 1 << ' ' << ans2 + 1 << '\n';
	} else cout << "1 1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
