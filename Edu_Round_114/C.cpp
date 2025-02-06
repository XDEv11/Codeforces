#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (auto& x : a) cin >> x;
	int m;
	cin >> m;
	vector<pair<long long, long long>> v(m);
	for (auto& [x, y] : v) cin >> x >> y;

	long long s{accumulate(a.begin(), a.end(), 0ll)};
	sort(a.begin(), a.end());
	for (auto& [x, y] : v) {
		auto it{lower_bound(a.begin(), a.end(), x)};
		long long ans{x + y};
		if (it != a.end()) ans = min(ans, max(0ll, y - (s - *it)));
		if (it != a.begin()) ans = min(ans, max(0ll, y - (s - *prev(it))) + x - *prev(it));
		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
