//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<pair<int, int>> op(m);
	for (auto &x : a) cin >> x;
	for (auto &[p, v] : op) cin >> p >> v, --p;

	vector<int> t(n + m + 1, -1), c(n + m + 1, 0);
	for (int i{0}; i < n; ++i) t[a[i]] = 0;
	for (int i{0}; i < m; ++i) {
		auto &[p, v]{op[i]};
		if (a[p] == v) continue;
		c[a[p]] += i + 1 - t[a[p]];
		t[a[p]] = -1;
		t[v] = i + 1;
		a[p] = v;
	}
	for (int i{1}; i <= n + m; ++i) {
		if (t[i] == -1) continue;
		c[i] += m + 1 - t[i];
	}

	using ll = long long;
	ll ans{0};
	for (int i{1}; i <= n + m; ++i) {
		ans += static_cast<ll>(c[i]) * (c[i] - 1) / 2;
		ans += static_cast<ll>(c[i]) * (m + 1 - c[i]);
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
