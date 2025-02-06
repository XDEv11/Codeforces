//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	string s(m, 'B');
	for (auto& x : v) {
		int i{x}, j{m - 1 - x};
		if (j < i) swap(i, j);
		if (s[i] != 'A') s[i] = 'A';
		else s[j] = 'A';
	}
	cout << s << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
