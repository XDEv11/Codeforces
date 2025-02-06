//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	vector<long long> d(n);
	d[0] = v[0];
	for (int i{1}; i < n; ++i) d[i] = v[i] - v[i - 1];

	long long ans{0};
	for (int i{1}; i < n; ++i) {
		if (d[i] >= 0) ans += d[i];
		else ans += -d[i], d[0] += d[i];
	}
	ans += abs(d[0]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
