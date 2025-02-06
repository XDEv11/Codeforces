//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k, --k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int j{0};
	while (v[j] < v[k]) ++j;

	int ans{};
	swap(v[0], v[k]);
	for (int i{1}; i < n; ++i) {
		if (v[0] > v[i]) ++ans;
		else break;
	}
	swap(v[0], v[k]);

	if (j && j < k) {
		int ans2{1};
		swap(v[j], v[k]);
		for (int i{j + 1}; i < n; ++i) {
			if (v[j] > v[i]) ++ans2;
			else break;
		}
		swap(v[j], v[k]);
		ans = max(ans, ans2);
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
