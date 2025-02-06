#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

static int OR(int i, int j) {
	cout << "or "s << i + 1 << ' ' << j + 1 << endl;
	int res;
	return cin >> res, res;
}

static int AND(int i, int j) {
	cout << "and "s << i + 1 << ' ' << j + 1 << endl;
	int res;
	return cin >> res, res;
}

static void FINISH(int v) {
	cout << "finish "s << v << endl;
}

void solve() {
	int n, k;
	cin >> n >> k, --k;

	vector<int> v(n);
	for (int i{1}; i < n; ++i) v[i] = OR(0, i) + AND(0, i);
	v[0] = (v[1] + v[2] - (OR(1, 2) + AND(1, 2))) / 2;
	for (int i{1}; i < n; ++i) v[i] -= v[0];

	nth_element(v.begin(), next(v.begin(), k), v.end());
	FINISH(v[k]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
