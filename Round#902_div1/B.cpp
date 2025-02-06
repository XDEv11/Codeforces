//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

using ll = long long;
const ll PM{998244353};
ll MA(ll a, ll b) { return (a + b) % PM; }
ll MS(ll a, ll b) { return (a - b + PM) % PM; }
ll MM(ll a, ll b) { return (a * b) % PM; }
ll MP(ll a, ll b) {
    ll res{1};
    do {
        if (b & 1) res = MM(res, a);
    } while (a = MM(a, a), b >>= 1);
    return res;
}
ll MI(ll a) { return MP(a, PM - 2); }
ll MD(ll a, ll b) { return MM(a, MI(b)); }

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<pair<int, int>> t(n);
	for (int i{0}; i < n; ++i) t[i] = {v[i], i + 1};
	sort(t.rbegin(), t.rend());

	ll ans{};
	int cnt{n};
	vector<bool> ck(n, true);
	for (int i{0}; i < n; ++i) {
		int c{};
		for (int j{1}; j * j <= t[i].se; ++j) {
			if (t[i].se % j) continue;
			int k{t[i].se / j};
			if (ck[j - 1]) ck[j - 1] = false, ++c;
			if (ck[k - 1]) ck[k - 1] = false, ++c;
		}
		ans = MA(ans, MM(MS(MP(2, cnt), MP(2, cnt - c)), t[i].fi)), cnt -= c;
	}

	cout << ans << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
