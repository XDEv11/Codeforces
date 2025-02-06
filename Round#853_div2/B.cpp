//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int cnt{0};
	for (int i{0}; i < n / 2; ++i) {
		int j{n - 1 - i};
		if (v[i] != v[j] && (i == 0 || v[i - 1] == v[j + 1])) ++cnt;
	}

	cout << (cnt >= 2 ? "No\n" : "Yes\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
