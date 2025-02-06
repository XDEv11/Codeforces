//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	using ll = long long;

	int n, q;
	cin >> n >> q;
	vector<ll> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	for (int i{1}; i <= n; ++i) v[i] = (v[i] > 1 ? v[i] - 1 : -1);
	for (int i{1}; i <= n; ++i) v[i] += v[i - 1];

	while (q--) {
		int l, r;
		cin >> l >> r;

		cout << (l < r && v[r] - v[l - 1] >= 0 ? "YES\n" : "NO\n");
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
