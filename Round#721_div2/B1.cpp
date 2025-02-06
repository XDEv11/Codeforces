#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int cnt{count(v.begin(), v.end(), '0')}, A{0}, B{0};

	if (cnt & 1) {
		++A, --cnt;
		if (cnt) cnt -= 2, B += 2;
		B += cnt / 2;
		A += cnt / 2;
	} else {
		if (cnt) cnt -= 2, A += 2;
		A += cnt / 2;
		B += cnt / 2;
	}

	// cout << "A=" << A << ", B=" << B << endl; //
	if (A < B) cout << "ALICE\n";
	else if (B < A) cout << "BOB\n";
	else cout << "DRAW\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
