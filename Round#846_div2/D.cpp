//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Sub(int x) {
	cout << "- " << x << endl;
	int c;
	return cin >> c, c;
}

void Ans(int n) {
	cout << "! " << n << endl;
}

void solve() {
	int c;
	cin >> c;

	int ans{0}, aux{0};
	for (int i{0}; i < 30; ++i) {
		int nc{Sub((1 << i) + aux)};
		if (nc < c) {
			ans += (1 << i);
			aux = 0;
		} else {
			ans += (1 << (i + 1));
			aux = (1 << i);
			nc -= 1;
		}
		c = nc;
		if (!nc) break;
	}

	Ans(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
