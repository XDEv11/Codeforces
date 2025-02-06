//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

void solve() {
	int n; long long k;
	cin >> n >> k;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long ans{numeric_limits<long long>::max()};
	sort(v.rbegin(), v.rend());
	long long s{accumulate(v.begin(), v.end(), 0LL)};
	for (int i{0}; i < n; ++i) {
		ans = min(ans, i + (max(0LL, s - k) + i) / (i + 1));
		s = s - v[i] + v.back();
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
