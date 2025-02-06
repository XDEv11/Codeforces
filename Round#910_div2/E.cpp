//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<char> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	array<queue<int>, 26> q{};
	for (int i{0}; i < n; ++i) q[a[i] - 'a'].push(i);
	for (int j{0}; j < m; ++j) {
		if (q[b[j] - 'a'].empty()) return cout << "NO\n", []{}();
		auto idx{q[b[j] - 'a'].front()}; q[b[j] - 'a'].pop();
		for (int k{0}; k < b[j] - 'a'; ++k) {
			while (!q[k].empty() && q[k].front() < idx) q[k].pop();
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
