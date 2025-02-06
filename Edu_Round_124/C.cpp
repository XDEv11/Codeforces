//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <limits>
#include <cmath>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	array<long long, 4> mn; mn.fill(numeric_limits<int>::max());
	for (auto& x : b) {
		mn[0] = min(mn[0], abs(a[0] - x));
		mn[1] = min(mn[1], abs(a[n - 1] - x));
	}
	for (auto& x : a) {
		mn[2] = min(mn[2], abs(b[0] - x));
		mn[3] = min(mn[3], abs(b[n - 1] - x));
	}
	long long ans{accumulate(mn.begin(), mn.end(), 0LL)};
	ans = min(ans, abs(a[0] - b[0]) + mn[1] + mn[3]);
	ans = min(ans, abs(a[0] - b[n - 1]) + mn[1] + mn[2]);
	ans = min(ans, abs(a[n - 1] - b[0]) + mn[0] + mn[3]);
	ans = min(ans, abs(a[n - 1] - b[n - 1]) + mn[0] + mn[2]);
	ans = min(ans, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
	ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
