//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<vector<int>> cnt(n + 1);
	for (int i{0}; i < n; ++i) cnt[v[i]].push_back(i);

	int mx{0};
	for (auto& v : cnt) mx = max(mx, int(v.size()));
	vector<vector<int>> cs{mx};
	int i{0};
	for (auto& v : cnt) {
		for (auto& x : v) {
			cs[i].push_back(x);
			i = (i + 1) % mx;
		}
	}

	for (auto& c : cs) {
		for (int i{0}; i + 1 < c.size(); ++i) swap(v[c[i]], v[c[i + 1]]);
	}

	for (auto& x : v) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
