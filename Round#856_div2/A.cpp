//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string a{}, b{};
	for (int i{0}; i < 2 * (n - 1); ++i) {
		string t{};
		cin >> t;
		if (t.size() == n - 1) swap(a, b), a = move(t);
	}

	bool f{true};
	for (int i{1}; i + 1 < n; ++i) {
		if (a[i] != b[i - 1]) f = false;
	}
	if (!f) swap(a, b);
	a += b[n - 2];

	for (int i{0}; i < n - 1 - i; ++i) {
		if (a[i] != a[n - 1 - i]) return cout << "NO\n", []{}();
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
