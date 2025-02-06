//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{};
	int k{n};
	while (k >= 2) {
		bool f{true};
		for (int i{0}; i < n; ++i) {
			if (v[i] ^ v[(i + k / 2) % n]) {
				f = false;
				break;
			}
		}
		if (!f) {
			vector<int> t(n);
			for (int i{0}; i < n; ++i) t[i] = v[i] ^ v[(i + k / 2) % n];
			v = t;
			ans += k / 2;
		}
		k /= 2;
	}
	for (int i{0}; i < n; ++i) {
		if (v[i]) {
			ans += 1;
			break;
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
