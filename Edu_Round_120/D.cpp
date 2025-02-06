//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

const vector<ll> fac{[] {
	const int maxv{5000};
	vector<ll> v(maxv + 1);
	v[0] = 1;
	for (int i{1}; i <= maxv; ++i) v[i] = MM(v[i - 1], i);
	return v;
}()};

void solve() {
	int n, c;
	cin >> n >> c;
	vector<bool> v(n);
	for (int i{0}; i < n; ++i) {
		char x;
		cin >> x;
		v[i] = (x == '1');
	}
	if (!c) return cout << "1\n", []{}();

	ll ans{1};

	int i{0}, j{0}, k{0};
	while (j < n && !v[j]) ++j;
	int t{c};
	while (k < n && t) t -= v[k++];
	if (t) return cout << "1\n", []{}();
	while (k < n && !v[k]) ++k;

	while (j < k) {
		ll x{MM(MM(fac[k - i], MI(fac[c])), MI(fac[k - i - c]))};
		ll y{MM(MM(fac[k - (j + 1)], MI(fac[c - 1])), MI(fac[k - (j + 1) - (c - 1)]))};
		ans = MA(ans, MS(x, y));

		i = ++j, --c;
		while (j < n && !v[j]) ++j;
		if (k < n) ++k, ++c;
		while (k < n && !v[k]) ++k;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
