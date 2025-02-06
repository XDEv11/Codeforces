//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int m;
	cin >> m;
	vector<pair<ll, ll>> v(m);
	vector<vector<ll>> a(m), c(m);
	for (int i{0}; i < m; ++i) {
		int n;
		cin >> n >> v[i].fi >> v[i].se;
		a[i].resize(n), c[i].resize(n);
		for (auto& x : a[i]) cin >> x;
		for (auto& x : c[i]) cin >> x;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
