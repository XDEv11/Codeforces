//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	vector<char> ans(n - 1, '+');
	int cnt{v[0] == '1'};
	for (int i{1}; i < n; ++i) {
		if (v[i] == '0') continue;
		if (cnt > 0) ans[i - 1] = '-', --cnt;
		else ans[i - 1] = '+', ++cnt;
	}

	for (auto& x : ans) cout << x;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
