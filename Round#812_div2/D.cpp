//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int ask(int a, int b) {
	cout << "? " << a << " " << b << endl;
	int r;
	return cin >> r, r;
}

void ans(int a) {
	cout << "! " << a << endl;
}

void solve() {
	int n;
	cin >> n;

	vector<int> p(1 << n); iota(p.begin(), p.end(), 1);
	while (n > 1) {
		--n;
		vector<int> p2(1 << n);
		for (int i{0}; i < (1 << n); i += 2) {
			int a{i}, c{(1 << n) + i};
			int r{ask(p[a], p[c])};
			if (r == 0) p2[a >> 1] = p[a + 1], p2[c >> 1] = p[c + 1];
			else if (r == 1) p2[a >> 1] = p[a], p2[c >> 1] = p[c + 1];
			else if (r == 2) p2[a >> 1] = p[a + 1], p2[c >> 1] = p[c];
		}
		p = move(p2);
	}

	if (ask(p[0], p[1]) == 1) ans(p[0]);
	else ans(p[1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
