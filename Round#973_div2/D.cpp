//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll mn{numeric_limits<ll>::max()};
		{
			ll s{};
			for (int i{0}; i < n; ++i) {
				s += v[i];
				mn = min(mn, s / (i + 1));
			}
		}
		ll mx{};
		{
			ll s{};
			for (int i{n - 1}; i >= 0; --i) {
				s += v[i];
				mx = max(mx, (s + n - i - 1) / (n - i));
			}
		}

		cout << mx - mn << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
