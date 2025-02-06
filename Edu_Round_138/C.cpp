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

	sort(v.begin(), v.end());

	for (int ans{(n + 1) / 2}; ans >= 1; --ans) {
		bool f{true};
		for (int i{1}; i <= ans; ++i) {
			if (v[ans - 1 + i - 1] > i) {
				f = false;
				break;
			}
		}
		if (f) return cout << ans << '\n', []{}();
	}
	cout << "0\n"; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
