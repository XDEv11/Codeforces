#include <iostream>
#include <vector>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<vector<int>> p(n, vector<int>(n));
	for (auto& v : p)
		for (auto& x : v) cin >> x;

	long long cnt{};
	vector<int> ans(n, -1);
	for (int i{n - 1}; i >= 1; --i) {
		int mx{0}, j;
		for (int k{0}; k < i; ++k) {
			if (p[i][k] > mx) mx = p[i][k], j = k;
		}
		cnt += mx, ans[i] = j;
		for (int k{0}; k < i; ++k) {
			if (k == j) continue;
			p[k][j] = p[j][k] = max(p[j][k], p[i][k]);
		}
	}

	cout << cnt << '\n';
	for (int i{n - 1}; i >= 1; --i) cout << (ans[i] + 1) << ' ' << (i + 1) << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
