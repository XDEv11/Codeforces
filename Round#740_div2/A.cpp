#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{0};
	while (!is_sorted(v.begin(), v.end())) {
		for (int i{ans++ & 1}; i + 1 < n; i += 2)
			if (v[i] > v[i + 1]) swap(v[i], v[i + 1]);
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
