//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

bool solve() {
	using ll = long long;

	int n;
	if (!(cin >> n)) return false;
	vector<ll> v(n);
	for (int i{0}; i < n; ++i) cin >> v[i];
	for (int i{0}; i < n; ++i) {
		ll x;
		cin >> x;
		v[i] -= x;
	}
	vector<pair<int, ll>> u(n);
	for (int i{1}; i < n; ++i) cin >> u[i].fi >> u[i].se, --u[i].fi;

	for (int i{n - 1}; i >= 1; --i) {
		if (v[i] < 0) {
			if (double(v[i]) * u[i].se < -1e17) return cout << "NO\n", true;
			v[u[i].fi] += v[i] * u[i].se;
			if (v[u[i].fi] < -1e17) return cout << "NO\n", true;
		} else v[u[i].fi] += v[i];
	}

	return cout << (v[0] >= 0 ? "YES\n" : "NO\n"), true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
