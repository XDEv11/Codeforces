//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> x(k + 1), c(k + 1);
	for (int i{1}; i <= k; ++i) cin >> x[i];
	for (int i{1}; i <= k; ++i) cin >> c[i];

	vector<char> ans(n);
	char abc{'a'};
	ans[0] = 'a', ans[1] = 'b', ans[2] = 'c';
	x[0] = 3, c[0] = 3;

	for (int i{1}; i <= k; ++i) {
		if (x[i] - x[i - 1] < c[i] - c[i - 1]) return cout << "NO\n", []{}();
		int i2{x[i - 1] + c[i] - c[i - 1]};
		for (int j{x[i - 1]}; j < i2; ++j) ans[j] = 'c' + i;
		for (int j{i2}; j < x[i]; ++j) ans[j] = abc, abc = (abc == 'c' ? 'a' : abc + 1);
	}

	cout << "YES\n";
	for (int i{0}; i < n; ++i) cout << ans[i];
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
