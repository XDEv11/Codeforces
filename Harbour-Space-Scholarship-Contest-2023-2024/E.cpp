//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

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

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	ll ans{};
	for (auto& x : v) {
		int c{};
		for (int b{0}; (1 << b) <= x; ++b) c += (x >> b) & 1;
		int j{distance(v.begin(), lower_bound(v.begin(), v.end(), x))};
		int k{distance(v.begin(), upper_bound(v.begin(), v.end(), x))};
		ans = MA(ans, MM(k - j, c + 1));
		int b{0};
		while ((1 << b) <= x) {
			while (!((1 << b) & x)) ++b;
			int m{(1 << b) - 1};
			int nj{distance(v.begin(), lower_bound(v.begin(), v.end(), x & ~m))};
			int nk{distance(v.begin(), upper_bound(v.begin(), v.end(), x | m))};
			ans = MA(ans, MM(j - nj, c + 1));
			ans = MA(ans, MM(nk - k, c + 2));

			j = nj, k = nk, ++b, --c;
		}
		ans = MA(ans, MM(j, 2));
		ans = MA(ans, n - k);
	}
	ans = MD(ans, MM(n, n));

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();
}
