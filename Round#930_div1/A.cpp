//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	auto ask{[](int a, int b, int c, int d) {
		cout << "? " << a << " " << b << " " << c << " " << d << endl;
		char r;
		return cin >> r, r;
	}};
	auto ans{[](int i, int j) {
		cout << "! " << i << " " << j << endl;
	}};

	int n;
	cin >> n;

	int pn{0};
	for (int i{1}; i < n; ++i) { // n - 1
		if (ask(pn, pn, i, i) == '<') pn = i;
	}

	vector<int> c{pn};
	for (int i{0}; i < n; ++i) { // n - 1
		if (i == pn) continue;
		char r{ask(pn, c.back(), pn, i)};
		if (r == '<') c.clear();
		if (r == '=' || r == '<') c.push_back(i);
	}

	int a{c[0]};
	for (int k{1}; k < c.size(); ++k) { // at most n - 1
		if (ask(a, a, c[k], c[k]) == '>') a = c[k];
	}

	ans(pn, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
