//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n, b, r;
	cin >> n >> r >> b;

	int q{r / (b + 1)}, rm{r % (b + 1)};
	for (int j{0}; j < q; ++j) cout << 'R';
	if (rm) cout << 'R';
	for (int i{1}; i <= b; ++i) {
		cout << 'B'; 
		for (int j{0}; j < q; ++j) cout << 'R';
		if (i < rm) cout << 'R';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
