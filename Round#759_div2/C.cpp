//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<long long> pos{0}, neg{0};
	for (int i{0}; i < n; ++i) {
		long long x;
		cin >> x;
		if (!x) continue;
		x > 0 ? (pos.push_back(x)) : (neg.push_back(x));
	}
	sort(pos.rbegin(), pos.rend());
	sort(neg.begin(), neg.end());

	long long ans{0};
	for (int i{0}; i < pos.size(); i += k) ans += 2 * pos[i];
	for (int i{0}; i < neg.size(); i += k) ans += -2 * neg[i];
	ans -= max(pos[0], -1 * neg[0]);

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
