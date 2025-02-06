//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	for (auto& x : p) cin >> x;
	for (auto& x : q) cin >> x;

	using ll = long long;

	vector<ll> idxp(n + 1), idxq(n + 1);
	for (int i{0}; i < n; ++i) idxp[p[i]] = i;
	for (int i{0}; i < n; ++i) idxq[q[i]] = i;

	ll l{min(idxp[1], idxq[1])}, r{max(idxp[1], idxq[1])};
	ll ans{l * (l + 1) / 2 + (r - l - 1) * (r - l) / 2 + (n - r - 1) * (n - r) / 2};
	for (int i{2}; i <= n; ++i) {
		ll idx1{idxp[i]}, idx2{idxq[i]};
		if (idx1 > idx2) swap(idx1, idx2);
		if (idx1 < l && idx2 < l) ans += (l - idx2) * (n - r);
		if (idx1 < l && r < idx2) ans += (l - idx1) * (idx2 - r);
		if (r < idx1 && r < idx2) ans += (l + 1) * (idx1 - r);
		l = min(l, idx1), r = max(r, idx2);
	}
	ans += 1;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
