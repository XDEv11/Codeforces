//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	using ll = long long;
	vector<vector<ll>> ans(n, vector<ll>(m));
	ll k{1};
	while (k < n) k *= 2;
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) ans[i][j] = i + k * j;

	cout << n * m << '\n';
	for (auto& v : ans) {
		for (auto& x : v) cout << x << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
