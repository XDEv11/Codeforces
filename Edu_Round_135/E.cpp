//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void solve() {
	int n;
	cin >> n;
	vector<pll> v(n);
	for (auto& [a, b] : v) cin >> a >> b;

	sort(v.begin(), v.end(), [](const pll& x, const pll& y) { return x.fi - x.se > y.fi - y.se; });

	vector<ll> ans(n + 1);
	ll tmp{0};
	for (auto& [a, b] : v) tmp += b;
	for (int i{0}; ; ++i) {
		ans[i] = tmp;
		if (i == n) break;
		tmp -= v[i].se;
		tmp += v[i].fi;
	}

	int m;
	cin >> m;
	vector<pll> s(m);
	for (auto& [x, y] : s) cin >> x >> y;

	for (auto& [x, y] : s) {


	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
