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

	int cnt{0};
	for (auto& x : v) cnt += x & 1;
	if (!(cnt & 1)) return cout << "0\n", []{}();

	int ans{32};
	for (auto& x : v) {
		int a{0};
		if (x & 1) {
			while (x & 1) {
				x /= 2;
				++a;
			}
		} else {
			while (!(x & 1)) {
				x /= 2;
				++a;
			}
		}
		ans = min(ans, a);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
