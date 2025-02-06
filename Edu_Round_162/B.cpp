//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
	using ll = long long;

	int n; ll k;
	cin >> n >> k;
	vector<ll> h(n);
	vector<int> p(n);
	for (auto& x : h) cin >> x;
	for (auto& x : p) cin >> x;

	vector<int> cnt(n + 1);
	for (int i{0}; i < n; ++i) cnt[abs(p[i])] += h[i];

	ll d{};
	for (int i{1}; i <= n; ++i) {
		d += k - cnt[i];
		if (d < 0) return cout << "NO\n", []{}();
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
