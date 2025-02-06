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
	
	int i{0};
	while (i < n && v[i] == i + 1) ++i;
	if (i < n) {
		int j{i};
		while (v[j] != i + 1) ++j;
		reverse(v.begin() + i, v.begin() + j + 1);
	}

	for (auto& x : v) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
