//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

#include <cmath>

using namespace std;

static void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll mx{}, mn{};
	for (auto& x : v) {
		if (x >= 0) {
			mx += x, mn += x;
		} else {
			mn += x, mx = max(mx + x, abs(mn));
		}
	}

	cout << mx << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
