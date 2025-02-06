//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXL{2000};

int Ask(int w) {
	cout << "? " << w << endl;
	int r;
	if (!(cin >> r)) exit(EXIT_FAILURE);
	return r;
}

int Ans(int a) {
	cout << "! " << a << endl;
}

void solve() {
	int n;
	cin >> n;

	int l{0}, r{n * MAXL + n};
	while (r - l > 1) {
		int m{(l + r) / 2};
		if (Ask(m) == 1) r = m;
		else l = m;
	}

	int ans{r};
	for (int i{2}; i <= n; ++i) {
		auto j{Ask(r / i)};
		if (!j) break;
		if (j == i) ans = min(ans, r / i * i);
	}

	Ans(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
