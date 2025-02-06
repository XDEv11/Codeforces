//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		ll x;
		cin >> x;

		vector<ll> ans{};
		for (int b{59}; b >= 0; --b) {
			ll y{1ll << b};
			if (!(x & y)) continue;
			if (x != y) ans.push_back(x ^ y);
		}
		ans.push_back(x);

		cout << ans.size() << '\n';
		for (auto& e : ans) cout << e << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
