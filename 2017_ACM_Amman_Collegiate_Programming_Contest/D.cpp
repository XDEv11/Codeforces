//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const ll PM{1000000007};
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
const ll maxval{100000};
const vector<ll> fac{[] {
	vector<ll> v(maxval + 1);
	v[0] = 1;
	for (ll i{1}; i <= maxval; ++i) v[i] = MM(v[i - 1], i);
	return v;
}()};
ll MC(ll m, ll n) { return MD(fac[m], MM(fac[n], fac[m - n])); }

void solve() {
	int a, b;
	cin >> a >> b;

	cout << MM(2, MC(a - 1, b)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
