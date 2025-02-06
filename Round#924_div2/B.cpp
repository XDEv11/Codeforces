//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int ans{};
	for (int i{0}, j{0}; i < v.size(); ++i) {
		while (j < v.size() && v[j] - v[i] < n) ++j;
		ans = max(ans, j - i);
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
