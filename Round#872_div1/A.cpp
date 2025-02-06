//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<bool> ck(m + 1);
	int c1{0}, c2{0};
	for (auto& x : v) {
		if (x > 0) ck[x] = true;
		else if (x == -1) ++c1;
		else if (x == -2) ++c2;
	}
	vector<int> ps(m + 1);
	for (int i{1}; i <= m; ++i) ps[i] = ps[i - 1] + ck[i];

	int ans{min(m, max(c1, c2) + ps[m])};
	for (int i{1}; i <= m; ++i) {
		if (!ck[i]) continue;
		ans = max(ans, min(i - 1, ps[i - 1] + c1) + 1 + min(m - i, (ps[m] - ps[i]) + c2));
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
