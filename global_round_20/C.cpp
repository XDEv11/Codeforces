//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int c{0};
	for (int i{0}; i + 1 < n; ++i)
		if (v[i] == v[i + 1]) ++c;
	if (c <= 1) return cout << "0\n", []{}();

	int f{-1}, l;
	for (int i{0}; i + 1 < n; ++i)
		if (v[i] == v[i + 1]) {
			if (f == -1) f = i;
			l = i;
		}
	cout << max(1, l - f - 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
