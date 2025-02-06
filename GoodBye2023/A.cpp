//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{2023};
	for (auto& x : v) {
		if (ans % x) return cout << "NO\n", []{}();
		ans /= x;
	}
	cout << "YES\n";
	for (int i{0}; i < k - 1; ++i) cout << "1 ";
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
