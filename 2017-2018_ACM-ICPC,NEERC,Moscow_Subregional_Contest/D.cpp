//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ull = unsigned long long;

	int n;
	cin >> n;
	vector<ull> v(n);
	for (auto& x : v) cin >> x;

	ull c{}; int s{};
	for (auto& x : v) {
		c += (x & 0x7F) << s;
		if (x & 0x80) s += 7;
		else {
			if (c & 1) cout << '-';
		   	cout << ((c >> 1) + (c & 1)) << '\n';
			c = 0, s = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
