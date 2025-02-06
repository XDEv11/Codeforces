//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k, m;
	cin >> n >> k >> m;
	vector<int> v(m);
	for (auto& x : v) cin >> x, --x;
	if ((n - m) % (k - 1)) return cout << "NO\n", []{}();

	for (int i{0}; i < m; ++i) {
		int l{v[i] - i}, r{(n - v[i]) - (m - i)};
		if (l >= k / 2 && r >= k / 2) return cout << "YES\n", []{}();
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
