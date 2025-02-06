//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long ans{numeric_limits<long long>::max()};
	for (int i{0}; i < n; ++i) {
		long long cnt{0};
		vector<long long> t(n);
		for (int j{i - 1}; j >= 0; --j) {
			v[j] *= -1;
			auto k{(t[j + 1] + 1 + v[j] - 1) / v[j]};
			t[j] = v[j] * k;
			cnt += k;
			v[j] *= -1;
		}
		for (int j{i + 1}; j < n; ++j) {
			auto k{(t[j - 1] + 1 + v[j] - 1) / v[j]};
			t[j] = v[j] * k;
			cnt += k;
		}
		ans = min(ans, cnt);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();
}
