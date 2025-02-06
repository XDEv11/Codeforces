//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

int turn(int x) {
	cout << x << endl;
	int y;
	cin >> y;
	return y;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int i{0};
	while (i < n && v[i] == i) ++i;
	while (i >= 0) {
		int j{turn(i)};
		i = j;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
