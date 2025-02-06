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
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<ll> a(n), b(m);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		vector<ll> sa{}, sb{};
		for (int i{0}; i < n - 1 - i; ++i) sa.push_back(a[n - 1 - i] - a[i]);
		for (int i{0}; i < m - 1 - i; ++i) sb.push_back(b[m - 1 - i] - b[i]);

		vector<ll> t{};
		ll ans{};
		for (int k{1}, i{0}, j{0}; k <= n && k <= m && k <= n - k + m - k; ++k) {
			if (2 * i + j == n) ans -= sa[--i], ans += sb[j++];
			else if (2 * j + i == m) ans -= sb[--j], ans += sa[i++];

			if (i == n / 2 || 2 * i + j + 1 == n) ans += sb[j++];
			else if (j == m / 2 || 2 * j + i + 1 == m) ans += sa[i++];
			else {
				if (sa[i] >= sb[j]) ans += sa[i++];
				else ans += sb[j++];
			}
			t.push_back(ans);
		}

		cout << t.size() << '\n';
		for (auto& x : t) cout << x << ' ';
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
