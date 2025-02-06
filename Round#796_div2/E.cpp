//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Ask(const vector<bool>& v) {
	cout << "? ";
	for (int i{0}; i < v.size(); ++i) cout << v[i];
	cout << endl;
	int r;
	return cin >> r, r;
}

void Ans(int c) {
	cout << "! " << c << endl;
}

void solve() {
	int n, m
	cin >> n >> m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
