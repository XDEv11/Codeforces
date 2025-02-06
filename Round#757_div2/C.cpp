#include <iostream>
#include <vector>
#include <tuple>

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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<tuple<ll, int, int>> v(m);
	for (auto& [x, l, r] : v) cin >> l >> r >> x, --l, --r;
	
	ll t{};
	for (auto& [x, l, r] : v) t |= x;

	cout << MM(t, MP(2, n - 1)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
