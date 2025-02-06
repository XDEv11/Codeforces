//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>

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

const ll maxv{300000};
vector<bool> pm{[] {
	vector<bool> v(maxv + 1, true);
	for (ll i{2}; i <= maxv; ++i) {
		if (!v[i]) continue;
		for (ll j{i * i}; j <= maxv; j += i) v[j] = false;
	}
	return v;
}()};

void solve() {
	ll n, m;
	cin >> n >> m;

	ll ans{0};
	ll cnt1{1}, cnt2{1}, x{1};
	for (int i{1}; i <= n; ++i) {
		if (x <= m && pm[i]) x *= i;
		cnt1 = MM(cnt1, m / x % PM);
		cnt2 = MM(cnt2, m % PM);
		ans = MS(MA(ans, cnt2), cnt1);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
