//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (auto& x : v) cin >> x, --x;

	vector<int> seg{};
	sort(v.begin(), v.end());
	for (int i{0}; i + 1 < m; ++i)
		if (v[i + 1] - v[i] + 1 > 0) seg.push_back(v[i + 1] - v[i] - 1);
	seg.push_back(n - v[m - 1] - 1 + v[0]);

	sort(seg.rbegin(), seg.rend());
	int ans{0}, d{0};
	for (int i{0}; i < seg.size(); ++i) {
		seg[i] -= 2 * d;
		if (seg[i] > 2) ans += max(0, seg[i] - 1), d += 2;
		else if (seg[i] > 0) ans += 1, d += 1;
	}

	cout << n - ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
