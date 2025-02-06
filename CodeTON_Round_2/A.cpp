//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<char> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	for (int i{1}; i < m; ++i)
		if (a[n - (m - i)] != b[i]) return cout << "NO\n", []{}();
	for (int i{0}; i <= n - m; ++i)
		if (a[i] == b[0]) return cout << "YES\n", []{}();
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
