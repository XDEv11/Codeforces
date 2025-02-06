#include <iostream>
#include <vector>
#include <array>
#include <limits>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<array<int, 5>> k(n);
	for (auto& e : k)
		for (auto& x : e) cin >> x;

	bool lf{true}; int la{0}, lb{m};
	bool rf{true}; int ra{0}, rb{m};
	vector<bool> lr(n), rr(n);
	for (int i{n - 1}; i >= 0 && (lf || rf); --i) {
		bool tmp{lf && la <= k[i][0] && k[i][0] <= lb};
		if (rf && ra <= k[i][0] && k[i][0] <= rb) lr[i] = lf = true, la = 0, lb = m;
		if (tmp) rr[i] = rf = true, ra = 0, rb = m;

		if (!(k[i][1] <= k[i][0] && k[i][0] <= k[i][2])) lf = false;
		la = max(la, k[i][3]), lb = min(lb, k[i][4]);
		if (!(k[i][3] <= k[i][0] && k[i][0] <= k[i][4])) rf = false;
		ra = max(ra, k[i][1]), rb = min(rb, k[i][2]);
	}

	if (lf && la == 0) {
		cout << "Yes\n";
		for (int i{0}; i < n; ++i) {
			cout << !lf << " \n"[i == n - 1];
			if ((lf && lr[i]) || (!lf && rr[i])) lf = !lf;
		}
	} else if (rf && ra == 0) {
		cout << "Yes\n";
		for (int i{0}; i < n; ++i) {
			cout << rf << " \n"[i == n - 1];
			if ((rf && rr[i]) || (!rf && lr[i])) rf = !rf;
		}
	} else cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
