//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const ll PM{1000000007};
ll MN(ll a) { return (a % PM + PM) % PM; }
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

vector<ll> MF{[] {
	ll maxval{200000};
	vector<ll> v(maxval + 1);
	v[0] = 1;
	for (ll i{1}; i <= maxval; ++i) v[i] = MM(v[i - 1], i);
	return v;
}()};
ll MC(ll n, ll m) { return MD(MF[n], MM(MF[m], MF[n - m])); }

void solve() {
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	vector<int> p(m1), s(m2);
	for (auto& x : p) cin >> x, --x;
	for (auto& x : s) cin >> x, --x;
	if (p.front() != 0 || s.back() != n - 1 || p.back() != s.front()) return cout << "0\n", []{}();

	vector<bool> ck(n);
	for (auto& x : p) ck[x] = true;
	for (auto& x : s) ck[x] = true;

	ll ans{MC(n - 1, s[0])};
	for (int i{s[0] - 1}; i >= 0; --i) {
		if (ck[i]) continue;
		ans = MM(ans, i);
	}
	for (int i{s[0] + 1}; i < n; ++i) {
		if (ck[i]) continue;
		ans = MM(ans, n - 1 - i);
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
