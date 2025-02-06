//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<char> s(n), t(m);
	for (auto& x : s) cin >> x;
	for (auto& x : t) cin >> x;

	vector<char> v{s};
	for (int i{m - 1}; i >= 0; --i) v.push_back(t[i]);

	int c{0};
	for (int i{0}; i + 1 < n + m; ++i) {
		if (v[i] == v[i + 1]) ++c;
		if (c >= 2) return cout << "NO\n", []{}();
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
