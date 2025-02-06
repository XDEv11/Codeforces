//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <queue>

using namespace std;

void solve() {
	using ll = long long;

	ll n, k;
	cin >> n >> k;
	vector<pair<ll, ll>> v(n);
	for (auto& [h, p] : v) cin >> h;
	for (auto& [h, p] : v) cin >> p;

	priority_queue<pair<ll, ll>> pq{};
	for (auto& [h, p] : v) pq.emplace(-p, h);

	ll c{0};
	bool flag = false;
	while (!pq.empty()) {
		auto [p, h]{pq.top()}; p *= -1, pq.pop();
		h -= c;
		if (h <= 0) continue;
		if (flag) k -= p, flag = false;
		h -= k, c += k;
		if (h <= 0) {
			flag = true;
			continue;
		}
		if (!(k > p)) return cout << "NO\n", []{}();

		ll l{1}, r{(k + p - 1) / p + 1};
		while (r - l > 1) {
			ll m{(l + r) / 2};
			ll x{((k - p) + (k - (m - 1) * p)) * (m - 1) / 2};
			if (h <= x) r = m;
			else l = m;
		}
		ll x{((k - p) + (k - l * p)) * l / 2};
		if (!(h <= x)) return cout << "NO\n", []{}();
		c += x, k -= (l + 1) * p;
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
