//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll s{}; int c{};
	for (int i{0}; i < n; ++i) {
		s += v[i], c += (v[i] & 1);
		if (i) cout << (s - c / 3 - (c % 3 == 1));
		else cout << s;
		cout << " \n"[i == n - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
