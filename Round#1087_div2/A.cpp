//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n; ll c, k;
		cin >> n >> c >> k;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		sort(v.begin(), v.end());
		for (auto& x : v) {
			if (x > c) break;
			auto t{min(k, c - x)};
			k -= t, c += x + t;
		}

		cout << c << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
