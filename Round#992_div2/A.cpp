//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace {
	void solve() {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		for (int i{0}; i < n; ++i) {
			bool f{true};
			for (int j{0}; j < n; ++j) {
				if (i == j) continue;
				if (abs(v[i] - v[j]) % k) continue;
				f = false;
				break;
			}
			if (f) return cout << "YES\n" << (i + 1) << '\n', []{}();
		}
		cout << "NO\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
