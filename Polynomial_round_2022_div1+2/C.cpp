//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n - 1);
	for (auto& x : v) cin >> x;

	cout << "1 ";
	int c{1};
	for (int i{1}; i < n - 1; ++i) {
		if (v[i] == v[i - 1]) ++c;
		else c = 1;
		cout << i + 2 - c << ' ';
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
