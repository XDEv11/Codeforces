//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <numeric>

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

	vector<ll> MF{[] {
		vector<ll> f(51);
		f[0] = 1;
		for (int i{1}; i <= 50; ++i) f[i] = MM(f[i - 1], i);
		return f;
	}()};
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n + 1);
		for (auto& x : v) cin >> x;

		int s{accumulate(v.begin(), v.end(), 0)};
		int q{s / n}, r{s % n}, c{};
		for (int i{1}; i <= n; ++i) {
			if (v[i] > q + 1) return void(cout << "0\n");
			else if (v[i] == q + 1) ++c;
		}
		if (c > r) return void(cout << "0\n");

		ll ans{MM(MD(MF[r], MF[r - c]), MF[n - c])};

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
