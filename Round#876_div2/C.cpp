//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x;

	if (a[n - 1]) return cout << "NO\n", []{}();

	vector<int> b{};
	for (int i{n - 1}; i >= 0; ) {
		int j{i - 1};
		while (j >= 0 && a[j]) --j;
		for (int k{i - 1}; k > j; --k) b.push_back(0);
		b.push_back(i - 1 - j);
		i = j;
	}

	cout << "YES\n";
	for (auto& x : b) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
