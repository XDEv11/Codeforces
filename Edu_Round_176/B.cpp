//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n, k;
		cin >> n >> k;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll ans{};
		multiset<ll, greater<ll>> s1{}, s2{};
		for (int i{0}; i < n; ++i) s2.insert(v[i]);
		for (int i{0}; i < n; ++i) {
			s2.erase(s2.find(v[i]));

			ll c{v[i]};
			if (i == 0) {
				auto it{s2.begin()};
				for (int _{0}; _ < k; ++_, ++it) c += *it;
			} else if (i == n - 1) {
				auto it{s1.begin()};
				for (int _{0}; _ < k; ++_, ++it) c += *it;

			} else if (k > 1) {
				auto it1{s1.begin()};
				auto it2{s2.begin()};
				c += *it1, ++it1;
				c += *it2, ++it2;
				for (int _{0}; _ < k - 2; ++_) {
					if (it2 == s2.end() || (it1 != s1.end() && *it1 >= *it2)) c += *it1, ++it1;
					else c += *it2, ++it2;
				}
			} else c = 0;
			ans = max(ans, c);

			s1.insert(v[i]);
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
