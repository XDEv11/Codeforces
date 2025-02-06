//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	int n, K;
	cin >> n >> K;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int tot{numeric_limits<int>::max()};
	for (int k = 1; k <= K; ++k) {
	vector<pair<int, int>> t{};
	sort(v.rbegin(), v.rend());
	int kk{k};
	for (int i{1}; i < n; ++i) {
		while (kk > 1 && v[i] / (kk - 1) <= v[0] / k) --kk;
		t.emplace_back(v[i] / kk, kk == 1 ? v[i] / kk : v[i] / (kk - 1));
	}

	sort(t.begin(), t.end());
	int mx{v[0] / k}, mn{v[0] / k}, ans{numeric_limits<int>::max()};
	for (int i{0}; i < t.size(); ++i) {
		ans = min(ans, mx - min(mn, t[i].fi));
		mx = max(mx, t[i].se);
		mn = min(mn, t[i].se);
	}
	ans = min(ans, mx - mn);
	tot = min(tot, ans);
	}
	cout << tot << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
