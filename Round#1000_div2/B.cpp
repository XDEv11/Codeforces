//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n, l, r;
		cin >> n >> l >> r, --l;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll ans;
		{
			vector<ll> t{};
			for (int i{0}; i < r; ++i) t.push_back(v[i]);
			sort(t.begin(), t.end());
			ans = accumulate(t.begin(), t.begin() + (r - l), 0ll);
		}
		{
			vector<ll> t{};
			for (int i{l}; i < n; ++i) t.push_back(v[i]);
			sort(t.begin(), t.end());
			ans = min(ans, accumulate(t.begin(), t.begin() + (r - l), 0ll));
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
