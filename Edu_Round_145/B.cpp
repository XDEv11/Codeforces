//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	using ll = long long;
	static auto cnt = [](ll sz) {
		if (sz == 0) return 1ll;
		else if (sz % 2 == 0) return 1 + sz / 2 * (8 + 4 * sz) / 2;
		else return (sz + 1) / 2 * (4 + 4 * sz) / 2;
	};

	ll n;
	cin >> n;

	ll l{-1}, r{1000000000};
	while (r - l > 1) {
		ll m{(l + r) / 2};
		if (cnt(m) < n) l = m;
		else r = m;
	}
	cout << r << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
