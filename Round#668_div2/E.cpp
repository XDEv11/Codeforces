#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> vec(n);
	for (int i{0}; i < n; ++i) {
		cin >> vec[i];
		vec[i] = i + 1 - vec[i];
	}
	vector<int> f(n);
	f[0] = (vec[0] == 0);
	for (int i{1}; i < n; ++i) {
		f[i] = f[i - 1];
		if (vec[i] >= 0 && vec[i] <= f[i - 1]) ++f[i];
	}

	for (auto& e : vec) cout << setw(2) << e << " ";
	cout << endl;

	while (q--) {
		int a, b;
		cin >> a >> b;

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
