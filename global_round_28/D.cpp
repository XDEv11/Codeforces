//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		sort(a.begin() + 1, a.end());
		sort(b.begin(), b.end());

		int i{0};
		while (i < m && b[i] <= a[0]) ++i;

		for (int k{1}; k <= m; ++k) {
			if (i + m % k >= m) cout << (m / k) << ' ';
			else {
				long long ans{m / k};
				for (int j{i + m % k}; j < m; j += k) {
					ans += distance(lower_bound(a.begin() + 1, a.end(), b[j]), a.end());
				}
				cout << ans << ' ';
			}
		}
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
