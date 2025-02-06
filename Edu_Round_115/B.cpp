#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<array<int, 5>> v(n);
	for (auto& a : v)
		for (auto& x : a) cin >> x;

	for (int j{0}; j < 5; ++j)
		for (int k{j + 1}; k < 5; ++k) {
			int cnt{0}, cnt1{0}, cnt2{0};
			for (int i{0}; i < n; ++i)
				if (v[i][j] && v[i][k]) ++cnt;
				else if (v[i][j]) ++cnt1;
				else if (v[i][k]) ++cnt2;
			if (cnt + cnt1 + cnt2 == n && cnt1 <= n / 2 && cnt2 <= n / 2) return cout << "YES\n"s, []{}();
		}
	cout << "NO\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
