#include <iostream>
#include <vector>

using namespace std;

static void op(int t, int i, int j) {
	cout << t << ' ' << i + 1 << ' ' << j + 1 << '\n';
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	cout << n / 2 * 6 << '\n';
	for (int i{0}; i < n; i += 2) {
		op(1, i, i + 1);
		op(2, i, i + 1);
		op(2, i, i + 1);
		op(1, i, i + 1);
		op(2, i, i + 1);
		op(2, i, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
