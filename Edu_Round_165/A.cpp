//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

static void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	for (int i{0}; i < n; ++i) {
		if (v[v[i]] == i) return cout << "2\n", []{}();
	}
	cout << "3\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
