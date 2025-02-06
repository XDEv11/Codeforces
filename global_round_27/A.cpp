//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		ll n, m, r, c;
		cin >> n >> m >> r >> c;

		ll ans{(n - r) * (2 * m - 1) + (m - c)};

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
