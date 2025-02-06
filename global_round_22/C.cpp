//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int co{}, ce{};
	for (auto& x : v) x & 1 ? ++co : ++ce;

	if (n & 1) {
		if (co & 1) {
			if (((co - 1) / 2) & 1) cout << "Alice\n";
			else cout << "Bob\n";
		} else {
			if ((co / 2) & 1) cout << "Bob\n";
			else cout << "Alice\n";
		}
	} else {
		if (co & 1) {
			if (((co - 1) / 2) & 1) cout << "Alice\n";
			else cout << "Alice\n";
		} else {
			if ((co / 2) & 1) cout << "Bob\n";
			else cout << "Alice\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
