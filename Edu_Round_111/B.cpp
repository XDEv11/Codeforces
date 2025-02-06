#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<char> v(n);
	for (auto& x : v) cin >> x;
	v.push_back('$');

	int cnt{1}, ans{0}, f{0};
	for (int i{1}; i <= n; ++i) {
		if (v[i] == v[i - 1]) ++cnt;
		else {
			ans += cnt * a;
			if (b < 0) ans += b;
			else ans += cnt * b;

			++f, cnt = 1;
		}
	}
	if (b < 0) ans -= (f - 1) / 2 * b;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
