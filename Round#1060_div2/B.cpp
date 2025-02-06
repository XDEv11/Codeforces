//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll mx{};
		for (int i{1}; i < n; i += 2) {
			mx = max({mx, v[i - 1], v[i]});
			v[i] = mx;
		}

		ll ans{};
		for (int i{1}; i < n; i += 2) {
			if (v[i - 1] == v[i]) ++ans;
			if (i + 1 < n && v[i] <= v[i + 1]) {
				ans += v[i + 1] - (v[i] - 1);
				v[i + 1] = v[i] - 1;
			}
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
