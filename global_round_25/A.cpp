//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int c{}, k;
	for (int i{0}; i < n; ++i) {
		if (v[i] == '0') continue;
		++c, k = i;
	}
	cout << (c & 1 || (c == 2 && v[k - 1] == '1') ? "NO\n" : "YES\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
