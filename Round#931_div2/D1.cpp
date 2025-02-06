//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	ll n, m;
	cin >> n >> m;

	vector<ll> ans{n};

	int i{62};
	while (!(n & (1ll << i))) --i;
	if (m & (1ll << i)) {
		ans.push_back(m);
	} else {
		n ^= (1ll << i);
		bool f{false};
		for (int j{i - 1}; j >= 0; --j) {
			if (f) n |= (1ll << j);
			else if (n & (1ll << j)) f = true;
		}
		if (n < m) return cout << "-1\n", []{}();
		ans.push_back(n);
		if (n > m) ans.push_back(m);
	}

	cout << (ans.size() - 1) << '\n';
	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
