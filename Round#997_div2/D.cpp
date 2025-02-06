//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		ll ans{ll(n + 1) * n / 2};
		for (int m{1}; m <= 10; ++m) {
			vector<int> ps(n + 1), cnt(2 * n + 1);
			ps[0] = n;
			for (int i{0}, j{0}; i < n; ++i) {
				if (v[i] == m) {
					while (j <= i) ++cnt[ps[j++]];
				}
				ans -= cnt[ps[i + 1] = ps[i] + (v[i] <= m ? -1 : 1)];
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
