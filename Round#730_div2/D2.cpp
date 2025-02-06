#include <iostream>
#include <vector>
#include <cstdlib> // exit()

using namespace std;

static bool guess(int y) {
	cout << y << endl;
	int r;
	cin >> r;
	if (r == -1) exit(EXIT_FAILURE);
	return r == 1;
}

void solve() {
	int n, k;
	cin >> n >> k;

	int m{1}, tmp{k}; // m bits
	while (tmp < n) ++m, tmp *= k;

	vector<int> c(m, 0), d(m);
	for (int i{0}; i < n; ++i) {

		int D{i};
		for (int j{0}; j < m; ++j) d[j] = D % k, D /= k;
		for (int j{0}; j < m; ++j) d[j] = (((c[j] + (i & 1 ? -d[j] : d[j])) % k) + k) % k;

		D = 0;
		for (int j{m - 1}; j >= 0; --j) D = (D * k) + d[j];
		if (guess(D)) return ;

		for (int j{0}; j < m; ++j) c[j] = ((-c[j] + d[j]) % k + k) % k;
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
