//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
	using ll = long long;

	int n, m;
	cin >> n >> m, --m;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	int ans{0};
	ll ps{0};
	priority_queue<ll> pq1{};
	for (int i{m}; i >= 1; --i) {
		ps += v[i];
		pq1.push(v[i]);
		while (ps > 0) {
			auto mx{pq1.top()}; pq1.pop();
			ps -= 2 * mx, ++ans;
		}
	}

	ps = 0;
	priority_queue<ll, vector<ll>, greater<ll>> pq2{};
	for (int i{m + 1}; i < n; ++i) {
		ps += v[i];
		pq2.push(v[i]);
		while (ps < 0) {
			auto mn{pq2.top()}; pq2.pop();
			ps -= 2 * mn, ++ans;
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
