//#pragma GCC optimize ("O3")

#include <iostream>

#include <cstdlib>

using namespace std;

namespace {
	int ask(int i, int j) {
		cout << "? " << i << ' ' << j << endl;
		cin >> i;
		if (i == -1) exit(EXIT_SUCCESS);
		return i;
	}
	void solve() {
		int n;
		cin >> n;

		for (int i{3}; i <= n * 2; i += 2) {
			if (ask(i, i + 1)) return void(cout << "! " << i << endl);
		}
		if (ask(1, 3)) return void(cout << "! 1" << endl);
		if (ask(1, 4)) return void(cout << "! 1" << endl);
		cout << "! 2" << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
