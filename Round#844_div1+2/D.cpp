//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& e : v) cin >> e;

	vector<ll> pos{};
	for (int i{0}; i < n; ++i)
		for (int j{i + 1}; j < n; ++j) {
			ll t{v[j] - v[i]};
			for (ll f1{1}; f1 * f1 < t; ++f1) {
				if (t % f1) continue;
				ll f2{t / f1};
				if ((f1 & 1) != (f2 & 1)) continue;
				ll m{(f1 + f2) / 2};
				if (m * m >= v[j]) pos.push_back(m * m - v[j]);
			}
		}

	int ans{1};
	for (auto& x : pos) {
		int cnt{0};
		for (auto& e : v) {
			ll t{llround(sqrt(e + x))};
			cnt += (t * t == e + x);
		}
		ans = max(ans, cnt);
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
