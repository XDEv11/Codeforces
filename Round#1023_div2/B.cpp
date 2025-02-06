//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n; ll m;
		cin >> n >> m;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll s{accumulate(v.begin(), v.end(), 0ll)};
		auto [mn, mx]{minmax_element(v.begin(), v.end())};
		*mx -= 1, mx = max_element(v.begin(), v.end());

		if (*mx - *mn > m) cout << "Jerry\n";
		else cout << (s & 1 ? "Tom\n" : "Jerry\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
