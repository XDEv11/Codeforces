#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;

	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < i; ++j) cout << "()"s;
		for (int j{i}; j < n; ++j) cout << '(';
		for (int j{i}; j < n; ++j) cout << ')';
		cout << '\n';
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
