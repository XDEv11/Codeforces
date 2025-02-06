//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll ans{accumulate(v.begin(), v.end(), 0ll)};
		while (v.size() > 1) {
			vector<ll> t{};
			ll s{};
			for (int i{0}; i + 1 < v.size(); ++i) t.push_back(v[i + 1] - v[i]), s += t[i];
			ans = max(ans, abs(s));
			v = t;
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
