//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> gs(2, vector<int>(n)), gt{gs};
	for (auto& v : gs)
		for (auto& x : v) cin >> x;
	for (auto& v : gt)
		for (auto& x : v) cin >> x;

	if (count(gs[0].begin(), gs[0].end(), 1) + count(gs[1].begin(), gs[1].end(), 1)
		!= count(gt[0].begin(), gt[0].end(), 1) + count(gt[1].begin(), gt[1].end(), 1)) return cout << "-1\n", []{}();

	long long ans{0};
	vector<int> ps(2);
	for (int i{0}; i < n; ++i) {
		ps[0] += gs[0][i] - gt[0][i];
		ps[1] += gs[1][i] - gt[1][i];
		if (ps[0] != 0 && ps[1] != 0 && (ps[0] > 0) != (ps[1] > 0)) {
			if (ps[0] > 0) --ps[0], ++ps[1];
			else ++ps[0], --ps[1];
			++ans;
		}
		ans += abs(ps[0]) + abs(ps[1]);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
