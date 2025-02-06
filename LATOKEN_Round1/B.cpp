#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n + 2);
	v[0] = v[n + 1] = 0;
	for (int i{1}; i <= n; ++i) cin >> v[i];

	long long ans{0};
	for (int i{1}; i <= n; ++i) {
		if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
			ans += v[i] - max(v[i - 1], v[i + 1]);
			v[i] = max(v[i - 1], v[i + 1]);
		}
	}
	for (int i{0}; i <= n; ++i) ans += abs(v[i] - v[i + 1]);

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
