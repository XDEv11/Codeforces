#include <iostream>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	auto ans = [&](int l1, int r1, int l2, int r2) {
		cout << l1 + 1 << ' ' << r1 + 1 << ' ' << l2 + 1 << ' ' << r2 + 1 << '\n';
	};

	for (int i{0}; i < (n + 1) / 2; ++i)
		if (s[i] == '0') return ans(i, n - 1, i + 1, n - 1);
	for (int i{(n + 1) / 2 - 1}; i < n; ++i)
		if (s[i] == '0') return ans(0, i, 0, i - 1);
	ans(0, n - 2, 1, n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
