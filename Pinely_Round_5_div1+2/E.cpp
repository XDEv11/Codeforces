//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

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

vector<ll> MF{[]() {
	int n{100000};
	vector<ll> a(n + 1);
	a[0] = 1;
	for (int i{1}; i <= n; ++i) a[i] = MM(a[i - 1], i);
	return a;
}()};
ll MH(ll n, ll m) { return MD(MF[n + m], MM(MF[n], MF[m])); }

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		for (auto& x : v) {
			char t;
			cin >> t;
			x = (t != '?' ? t == '1' : -1);
		}

		vector<int> p{v};
		for (int i{n - 1}; i - (m - 1) >= 0; --i) {
			int j{i - (m - 1)};
			if (p[i] == -2) p[j] = -2;
			else if (p[i] != -1) p[j] = (p[j] == (p[i] ^ 1) ? -2 : p[i]);
		}

		ll ans{};
		for (int b{0}; b <= 1; ++b) {
			int d{b ^ 1};
			if (v[0] == d) continue;

			int cb{}, cd{}, ce{};
			for (int i{1}, j{i}; ; ++i) {
				for (; j < n && j - i < m - 1; ++j) {
					if (p[j] == b) ++cb;
					else if (p[j] == d) ++cd;
					else if (p[j] == -2) ++ce;
				}

				if (i + m <= n) {
					if (p[i] == b) --cb;
					else if (p[i] == d) --cd;
					else if (p[i] == -2) --ce;

					if (v[i] == d || v[i] == -1) {
						if ((p[i + m - 1] == d || p[i + m - 1] == -1) && cb <= m / 2 && cd + 1 <= m / 2 && !ce) {
							ans = MA(ans, MH(m / 2 - cb, m / 2 - (cd + 1)));
						}
						if (v[i] == d) break;
					}
				} else {
					for (int c{cd}; c <= m / 2 && cb + c <= m - 1; ++c) {
						ans = MA(ans, MH(c - cd, m - 1 - (cb + c)));
					}
					break;
				}
			}
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
