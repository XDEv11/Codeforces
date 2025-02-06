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
	auto mx{*max_element(v.begin(), v.end())};
	for (int i{0}; i <= 1; ++i) {
		long long t{0}, c{0};
		for (auto& x : v) {
			auto d{mx + i - x};
			t += d, c += d & 1;
		}

		ans = min(ans, max(t / 3 * 2 + t % 3, c * 2 - 1));
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
