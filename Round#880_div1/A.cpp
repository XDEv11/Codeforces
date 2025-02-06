//#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	auto min_val{[](int d) {
		ll mn{1};
		for (int i{1}; i < d; ++i) mn *= 10;
		return mn;
	}};
	auto max_val{[](int d) {
		ll mx{};
		for (int i{0}; i < d; ++i) mx = (mx * 10) + 9;
		return mx;
	}};

	int a, b, c; ll k;
	cin >> a >> b >> c >> k;

	ll mna{min_val(a)}, mnb{min_val(b)}, mnc{min_val(c)};
	ll mxa{max_val(a)}, mxb{max_val(b)}, mxc{max_val(c)};
	for (ll i{max(mna, mnc - mxb)}; i <= min(mxa, mxc - mnb); ++i) {
		ll mn{max(mnb, mnc - i)}, mx{min(mxb, mxc - i)};
		if (k <= mx - mn + 1) {
			cout << i << " + " << mn + k - 1 << " = " << (i + mn + k - 1) << '\n';
			return ;
		} else k -= mx - mn + 1;
	}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
