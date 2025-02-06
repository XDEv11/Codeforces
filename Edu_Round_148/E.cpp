//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
static const ll PM{998244353};
static inline ll MA(ll a, ll b) { return (a + b) % PM; }
static inline ll MS(ll a, ll b) { return (a - b + PM) % PM; }
static inline ll MM(ll a, ll b) { return (a * b) % PM; }
static inline ll MP(ll a, ll b) {
    ll res{1};
    do {
        if (b & 1) res = MM(res, a);
    } while (a = MM(a, a), b >>= 1);
    return res;
}
static inline ll MI(ll a) { return MP(a, PM - 2); }
static inline ll MD(ll a, ll b) { return MM(a, MI(b)); }

void solve() {
	int n;
	cin >> n;
	vector<ll> v(n); ll x, y, m, k;
	cin >> v[0] >> x >> y >> m >> k;
	for (int i{1}; i < n; ++i) v[i] = MA(MM(v[i - 1], x), y);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
