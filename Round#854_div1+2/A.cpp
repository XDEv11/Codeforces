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

	vector<int> ans{};
	vector<bool> ck(m);
	for (int i{0}; i < m; ++i) {
		if (ck[v[i] - n]) continue;
		ck[v[i] - n] = true;
		if (ans.size() < n) ans.push_back(i + 1);
	}
	while (ans.size() < n) ans.push_back(-1);
	reverse(ans.begin(), ans.end());

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
