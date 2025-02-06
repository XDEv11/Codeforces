//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n; ll k;
	cin >> n >> k;
	vector<pair<ll, ll>> v(n);
	for (auto& [b, a] : v) cin >> a >> b;

	sort(v.begin(), v.end());

	int ans{};
	for (int i{0}; i < n; ++i) {
		ll r{k};
		priority_queue<ll> pq{};
		for (int j{i}; j < n; ++j) {
			if (j > i) r -= v[j].fi - v[j - 1].fi;
			pq.push(v[j].se), r -= v[j].se;
			while (r < 0 && !pq.empty()) {
				auto x{pq.top()};
				pq.pop(), r += x;
			}
			if (r < 0) break;
			ans = max(ans, int(pq.size()));
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
