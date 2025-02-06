//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	using ll = long long;

	int n; ll k;
	cin >> n >> k;
	vector<array<ll, 2>> v(n);
	for (auto& [l, r] : v) cin >> l;
	for (auto& [l, r] : v) cin >> r;

	ll ans{numeric_limits<ll>::max()};
	multiset<ll> ms{};
	ll cnt{0}, sc{0};
	for (int i{0}; i < n; ++i) {
		ll gap{v[i][0] - 1 - (i - 1 >= 0 ? v[i - 1][1] : 0)}, len{v[i][1] - v[i][0] + 1};
		if (k <= len) {
			ll cnt2{cnt};
			cnt2 += 2;
			cnt2 += gap + max(0ll, k);
			cnt2 -= min(sc, len - max(0ll, k));
			ans = min(ans, cnt2);
		}
		cnt += gap + len;
		ms.insert(len), k -= len, cnt += 2, sc += (len == 1);
		while (k + *ms.begin() <= 0) sc -= (*ms.begin() == 1), cnt -= 2, k += *ms.begin(), ms.erase(ms.begin());
	}
	if (ans == numeric_limits<ll>::max()) ans = -1;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
