//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int dfs(int g, int n, int m = 0, int u = 0) {
	if (g == 1) return m;
	if (m > n) return numeric_limits<int>::max();
	int mn{numeric_limits<int>::max()};
	for (int i{1}; i <= n; ++i) {
		if (u & (1 << i)) continue;
		mn = min(mn, dfs(gcd(g, i), n, m + (n - i + 1), u | (1 << i)));
	}
	return mn;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int g{0};
	for (auto& x : v) g = gcd(g, x);
	if (g == 1) return cout << "0\n", []{}();

	cout << dfs(g, n) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
