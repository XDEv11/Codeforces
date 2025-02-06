//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		int ans{};
		for (int i{0}; i < n; ++i) {
			for (int k{1}; k <= v[i]; ++k) {
				if (i - k * v[i] < 0) break;
				ans += (v[i - k * v[i]] == k);
			}
			for (int k{1}; k < v[i]; ++k) {
				if (i + k * v[i] >= n) break;
				ans += (v[i + k * v[i]] == k);
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
