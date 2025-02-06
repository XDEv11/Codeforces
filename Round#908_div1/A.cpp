//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<bool> ck(n);
	for (int i{n - 1}; k--; i = (i - v[i] + n) % n) {
		if (clamp(v[i], 1, n) != v[i]) return cout << "No\n", []{}();
		if (ck[i]) break;
		ck[i] = true;
	}
	cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
