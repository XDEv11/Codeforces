//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n, m; ll k;
		cin >> n >> m >> k;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		vector<ll> a(n + 1);
		{
			ll s{};
			for (int i{0}; i < n; ++i) {
				s += v[i];
				if (s >= k) s = 0, a[i + 1] = a[i] + 1, s = 0;
				else a[i + 1] = a[i];
			}
		}

		ll ans{-1}, A{};
		ll s{}; int c{};
		for (int i{n - 1}, j{n}; i >= 0; --i) {
			while (j - 1 >= 0 && a[j - 1] + c >= m) A += v[--j];
			if (j <= i + 1 && a[j] + c >= m) ans = max(ans, A);

			A -= v[i], s += v[i];
			if (s >= k) ++c, s = 0;
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
