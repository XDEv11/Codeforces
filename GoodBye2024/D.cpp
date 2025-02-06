//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
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
	void solve() {
		int n, q;
		cin >> n >> q;
		vector<pair<int, int>> a(n), b(n);
		for (int i{0}; i < n; ++i) cin >> a[i].fi, a[i].se = i;
		for (int i{0}; i < n; ++i) cin >> b[i].fi, b[i].se = i;

		sort(a.begin(), a.end()), sort(b.begin(), b.end());
		vector<int> ai(n), bi(n);
		for (int i{0}; i < n; ++i) ai[a[i].se] = i, bi[b[i].se] = i;

		ll ans{1};
		for (int i{0}; i < n; ++i) ans = MM(ans, min(a[i].fi, b[i].fi));
		cout << ans << ' ';

		while (q--) {
			ll k, i;
			cin >> k >> i, --i;
			if (k == 1) {
				int j{ai[i]};
				int l{j}, r{n};
				while (r - l > 1) {
					int m{(l + r) / 2};
					(a[m].fi == a[j].fi ? l : r) = m;
				}
				swap(a[j].se, a[l].se);
				ai[a[j].se] = j, ai[a[l].se] = l;

				ans = MD(ans, min(a[l].fi, b[l].fi));
				a[l].fi += 1;
				ans = MM(ans, min(a[l].fi, b[l].fi));
			} else if (k == 2) {
				int j{bi[i]};
				int l{j}, r{n};
				while (r - l > 1) {
					int m{(l + r) / 2};
					(b[m].fi == b[j].fi ? l : r) = m;
				}
				swap(b[j].se, b[l].se);
				bi[b[j].se] = j, bi[b[l].se] = l;

				ans = MD(ans, min(a[l].fi, b[l].fi));
				b[l].fi += 1;
				ans = MM(ans, min(a[l].fi, b[l].fi));
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
