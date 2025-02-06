//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	vector<int> ans(n), last(n, -1);
	for (int i{0}; i < n; ++i) {
		if (last[v[i]] == -1 || (i - last[v[i]] - 1) % 2 == 0) ++ans[v[i]];
		last[v[i]] = i;
	}

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
