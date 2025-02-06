//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(2 * n);
	for (auto& x : v) cin >> x;

	int ans{1};
	for (int i{0}; i + 1 < 2 * n; ++i) {
		if (v[i] == '(' && v[i + 1] == '(') ++ans;
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
