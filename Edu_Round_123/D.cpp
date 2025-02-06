//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second

using namespace std;

const long long mod{998244353};

void solve() {
	int n, m, k, q;
	cin >> n >> m >> k >> q;

	vector<pair<int, int>> v(q);
	for (auto& [x, y] : v) cin >> x >> y, --x, --y;

	long long ans{1};
	vector<bool> cx(n, false), cy(m, false);
	int rx{n}, ry{m};
	for (int i{q - 1}; i >= 0; --i) {
		if ((!cx[v[i].fi] && ry) || (!cy[v[i].se] && rx)) ans = ans * k % mod;
		if (!cx[v[i].fi]) cx[v[i].fi] = true, --rx;
		if (!cy[v[i].se]) cy[v[i].se] = true, --ry;
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
