//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		sort(v.begin(), v.end());

		vector<ll> ve{}, vo{};
		for (auto& x : v) {
			if (x & 1) vo.push_back(x);
			else ve.push_back(x);
		}
		if (ve.empty() || vo.empty()) return cout << "0\n", []{}();

		ll ans{}, mx{vo.back()};
		for (auto& x : ve) {
			if (mx < x) {
				ll t{(x - mx + ve.back() - 1) / ve.back()};
				mx += t * ve.back(), ans += t;
			}
			mx += x, ++ans;
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
