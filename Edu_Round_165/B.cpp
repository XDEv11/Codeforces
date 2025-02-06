//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

static void solve() {
	string s{};
	cin >> s;

	long long ans{};
	int c{};
	for (auto& x : s) {
		if (x == '0') {
			if (c) ans += c + 1;
		} else ++c;
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
