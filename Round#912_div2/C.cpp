//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	bool f{false};
	ll ans{}, s{}, c{};
	for (int i{n - 1}; i >= 0; --i) {
		c += v[i];
		if (!i || s + c >= 0) ans += (s += c), c = 0;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
