#include <iostream>
#include <vector>

using namespace std;

int ask(int i) {
	cout << "? " << i << endl;
	int res;
	cin >> res;
	return res;
}

void ans(int k) {
	cout << "! " << k << endl;
}

void solve() {
	int n;
	cin >> n;

	int l{1}, r{n};
	while (l < r) {
		int m{(l + r) / 2};
		int x{ask(m)}, y{ask(m + 1)};
		if (x < y) r = m;
		else l = m + 1;
	}

	ans(l);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
