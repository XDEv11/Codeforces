//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	if (k & 1) {
		for (auto& x : v) x = (x == '1' ? '0' : '1');
	}

	vector<int> ans(n, 0);
	for (int i{0}; i < n; ++i) {
		if (v[i] == '1' || k == 0) continue;
		v[i] = '1', ans[i] = 1, --k;
	}
	ans[n - 1] += k;
	if (k & 1) v[n - 1] = '0';

	for (auto& x : v) cout << x;
	cout << '\n';
	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
