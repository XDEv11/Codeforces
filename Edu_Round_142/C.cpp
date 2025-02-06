//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (auto& x : p) cin >> x, --x;

	vector<int> pos(n);
	for (int i{0}; i < n; ++i) pos[p[i]] = i;

	int ans{n / 2};
	int i{0}, j{1};
	while (i < n) {
		while (j < n && pos[j] > pos[j - 1]) ++j;
		ans = min(ans, max(i, n - j));

		i = j, j = i + 1;
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
