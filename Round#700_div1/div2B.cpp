#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	long long x, y;
	int n;
	cin >> x >> y >> n;
	vector<long long> a(n), b(n);
	for (auto& e : a) cin >> e;
	for (auto& e : b) cin >> e;

	vector<long long> c(n);
	for (int i{0}; i < n; ++i) {
		c[i] = a[i] * ((b[i] + x - 1) / x);
	}

	if (y - (accumulate(c.begin(), c.end(), 0ll) - *max_element(a.begin(), a.end())) >= 1) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
