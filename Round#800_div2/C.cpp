//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	long long c{0};
	bool f{false};
	for (int i{n - 1}; i >= 0; --i) {
		if (f && c == 0) return cout << "No\n", []{}();
		if (v[i] > 0) {
			if (v[i] > c) return cout << "No\n", []{}();
			c -= v[i];
		} else if (v[i] < 0) {
			c += -v[i];
			f = true;
		}
	}
	if (c) cout << "No\n";
	else cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
