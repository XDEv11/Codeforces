//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

using ll = long long;
const ll PM{998244353};
ll MC(ll a) { return (a % PM + PM) % PM; }
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

static void solve() {
	auto lowbit{[](int x) {
		int y{1};
		while (!(x & y)) y <<= 1;
		return y;
	}};

	int n; ll k;
	cin >> n >> k;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	for (int i{1}; i <= n; ++i) {
		ll c{1};
		for (int j{i + lowbit(i)}, d{1}; j <= n; j += lowbit(j), ++d) {
			c = MD(MM(c, k + d - 1), d);
			v[j - 1] = MS(v[j - 1], MM(c, v[i - 1]));
		}
	}

	for (auto& x : v) cout << x << ' ';
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
