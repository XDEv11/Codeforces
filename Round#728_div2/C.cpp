#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> d(n);
	for (auto& x : d) cin >> x;

	sort(d.begin(), d.end());

	long long ans{0}, t{0};
	for (int i{1}; i < n; ++i) {
		ans += (d[i] - d[i - 1]);
		ans -= (d[i] * i - t);
		t += d[i];
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
