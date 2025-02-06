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

		ll ns{};
		for (auto& x : v) {
			if (x < 0) ns -= x;
		}
		ll ans{ns}, ps{};
		for (auto& x : v) {
			if (x > 0) ps += x;
			else ns += x;
			ans = max(ans, ps + ns);
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
