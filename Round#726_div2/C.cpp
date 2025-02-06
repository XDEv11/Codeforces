#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	if (n == 2) return cout << v[0] << ' ' << v[1] << '\n', []{}();

	int mn{numeric_limits<int>::max()}, idx;
	for (int i{0}; i + 1 < n; ++i)
		if (v[i + 1] - v[i] < mn) mn = v[i + 1] - v[i], idx = i;

	int i{(idx + 1) % n};
	while (i != idx) {
		cout << v[i] << ' ';
		i = (i + 1) % n;
	}
	cout << v[idx] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
