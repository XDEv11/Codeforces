//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

static void solve() {
	using ll = long long;
	using pll = pair<ll, ll>;

	int n, k;
	cin >> n >> k;
	vector<pll> v(n);
	for (auto& [x, y] : v) cin >> x;
	for (auto& [x, y] : v) cin >> y;

	multiset<pll, greater<pll>> s1{}, s2{};
	for (auto& [x, y] : v) {
		if (x >= y) continue;
		s1.emplace(y, x);
	}

	ll c{};
	auto it{s1.begin()};
	for (int i{0}; i < k && it != s1.end(); ++i) {
		auto ni{next(it)};
		c -= it->se;
		s2.emplace(it->se, 0);
		s1.erase(it), it = ni;
	}
	for (; it != s1.end(); ++it) c += it->fi - it->se;

	ll ans{max(0ll, c)};
	if (k) {
		while (!s1.empty()) {
			c -= s1.begin()->fi;
			s2.emplace(s1.begin()->se, 0);
			s1.erase(s1.begin());

			c += s2.begin()->fi;
			s2.erase(s2.begin());

			ans = max(ans, c);
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
