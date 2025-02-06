//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace {
	using ll = long long;
	const ll PM{998244353};
	ll MA(ll& a, ll b) { return a = (a + b) % PM; }
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		map<int, ll> dp0{}, dp1{};
		dp0[0] = 1;
		for (int i{0}; i < n; ++i) {
			map<int, ll> nx0{}, nx1{};
			for (auto& [b, c] : dp0) { // last honest
				if (b == v[i]) MA(nx0[v[i]], c); // honest
				MA(nx1[b + 1], c); // liar
			}
			for (auto& [b, c] : dp1) { // last liar
				if (b == v[i]) MA(nx0[v[i]], c); // honest
			}
			dp0 = nx0, dp1 = nx1;
		}

		ll ans{};
		for (auto& [b, c] : dp0) MA(ans, c);
		for (auto& [b, c] : dp1) MA(ans, c);

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
