//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

#include <cstdlib>

using namespace std;

namespace {
	int ask(int a, int b) {
		cout << "? " << a << ' ' << b << endl;
		int r; cin >> r;
		if (r == -1) exit(EXIT_SUCCESS);
		return r;
	}
	void ans(const vector<int>& p) {
		cout << "! ";
		for (int i{1}; i < p.size(); ++i) cout << p[i] << ' ';
		cout << endl;
	}
	void solve() {
		int n;
		cin >> n;

		vector<int> p(n);
		int i{1}, j{2};
		while (j < n && ask(1, j)) ++j;
		p[j] = 1;
		while (j < n) {
			int k{j};
			if (i == 1) i = 2, ++k;
			for (; k < n; ++k) {
				while (i < j && ask(i, k)) ++i;
				if (i == j) break;
				p[k] = i++;
			}
			i = j, j = k;
		}

		ans(p);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
