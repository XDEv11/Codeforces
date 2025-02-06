//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	string s{};
	cin >> s;

	int ans{};
	int c0{count(s.begin(), s.end(), '0')}, c1{s.size() - c0};
	const int d0{c0}, d1{c1};
	for (int i{s.size() - 1}; i >= 0; --i) {
		if (c0 <= d1 && c1 <= d0) break;
		--(s[i] == '0' ? c0 : c1), ++ans;
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
