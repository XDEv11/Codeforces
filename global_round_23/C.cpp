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
	for (auto& x : p) cin >> x;

	vector<int> idx(n + 1);
	for (int i{0}; i < n; ++i) idx[p[i]] = i + 1;

	for (int i{1}; i <= n; ++i) cout << min(n, idx[i] + 1) << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
