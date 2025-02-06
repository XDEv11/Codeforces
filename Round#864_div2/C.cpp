//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ask(int r, int c) {
	cout << "? " << r + 1 << ' ' << c + 1 << endl;
	int ret; return cin >> ret, ret;
}

void ans(int r, int c) {
	cout << "! " << r + 1 << ' ' << c + 1 << endl;
}

void solve() {
	int n, m;
	cin >> n >> m;

	int r1{ask(0, 0)}, r2{ask(n - 1, 0)};
	if (r1 == n - 1 - r2) ans(r1, ask(r1, 0));
	else if (r1 == r2) ans(ask(0, r1), r1);
	else if (r1 < r2) ans(n - 1 - r2, r1);
	else ans(r1, r2);
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
