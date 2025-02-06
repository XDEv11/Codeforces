//#pragma GCC optimize ("O3")
 
#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<char> a(n), b(n);
	for (auto& e : a) cin >> e;
	for (auto& e : b) cin >> e;
 
	int cnt{0};
	for (int i{0}; i < n; ++i) cnt += (a[i] != b[i]);
	if (cnt & 1) return cout << "-1\n", []{}();
	if (cnt == 2) {
		bool flag{false};
		for (int i{0}; i + 1 < n; ++i) flag = flag || (a[i] != b[i] && a[i + 1] != b[i + 1]);
		if (flag) cout << min(x, 2 * y) << '\n';
		else cout << y << '\n';
	} else {
		cout << static_cast<long long>(cnt / 2) * y << '\n';
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}