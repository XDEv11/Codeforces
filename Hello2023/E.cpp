//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Ask(int k, const vector<int>& v) {
	cout << "? " << k + 1 << ' ';
	for (auto& x : v) cout << x;
	cout << endl;
	int r;
	return cin >> r, r;
}

void Ans(const vector<int>& v) {
	cout << "! ";
	for (auto& x : v) cout << x;
	cout << endl;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
