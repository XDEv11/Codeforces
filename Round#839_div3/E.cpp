//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int cf{0}, cs{0}, ce{0};
	for (int i{0}; i < n; ++i) {
		cf += (v[i] != i + 1);
		cs += (v[i] != n - i);
		ce += (v[i] != i + 1) && (v[i] != n - i);
	}
	cf -= ce, cs -= ce;

	if (cf + ce <= cs) cout << "First\n";
	else if (cs + ce < cf) cout << "Second\n";
	else cout << "Tie\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
