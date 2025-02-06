//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdlib>

using namespace std;

void solve() {
	int n;
	cin >> n;

	auto query1 = [](int x) {
		cout << "+ " << x << endl;
		int ret; cin >> ret;
		if (ret == -2) exit(EXIT_FAILURE);
	};
	auto query2 = [](int i, int j) {
		cout << "? " << i + 1 << ' ' << j + 1 << endl;
		int ret; cin >> ret;
		if (ret == -2) exit(EXIT_FAILURE);
		return ret;
	};
	auto answer = [](const vector<int>& p1, const vector<int>& p2) {
		cout << "! ";
		for (auto& x : p1) cout << x + 1 << ' ';
		for (auto& x : p2) cout << x + 1 << ' ';
		cout << endl;
		int ret; cin >> ret;
		if (ret == -2) exit(EXIT_FAILURE);
	};

	int x1{n - 1}, x2{n};
	vector<int> con(n); con[0] = 0, con[1] = n - 1;
	for (int i{1}; i + 1 < n; ++i) con[i + 1] = (x1 - con[i] == con[i - 1] ? x2 - con[i] : x1 - con[i]);

	query1(x1 + 2), query1(x2 + 2);
	vector<int> j(n), k(n), q(n), qj(n), qk(n);
	j[1] = 0, k[1] = 1, q[1] = query2(j[1], k[1]);
	for (int i{2}; i < n; ++i) {
		j[i] = j[i - 1], k[i] = k[i - 1], q[i] = q[i - 1];
		if (i == n - 1) {
			qj[i] = query2(i, j[i]);
			if (q[i] == n - 1) qk[i] = n - 1 - qj[i];
			else if (qj[i] == n - 1) k[i] = i, qk[i] = n - 1 - q[i];
			else j[i] = i, qk[i] = n - 1;
			q[i] = n - 1;
		} else {
			qj[i] = query2(i, j[i]), qk[i] = query2(i, k[i]);
			if (qj[i] > q[i] && qj[i] > qk[i]) k[i] = i, q[i] = qj[i];
			else if (qk[i] > q[i]) j[i] = i, q[i] = qk[i];
		}
	}

	auto rev = [&](int h, int t) {
		vector<int> ans(n, -1); ans[h] = 0, ans[t] = n - 1;
		auto slv = [&](int x, int y, int dx) {
			return ans[x] + (ans[x] < ans[y] ? 1 : -1) * dx;
		};
		for (int i{n - 1}; i >= 2; --i) {
			if (j[i] == i) ans[j[i - 1]] = slv(i, k[i], qj[i]);
			else if (k[i] == i) ans[k[i - 1]] = slv(i, j[i], qk[i]);
			else ans[i] = slv(j[i], k[i], qj[i]);
		}
		for (auto& x : ans) x = con[x];
		return ans;
	};

	answer(rev(j[n - 1], k[n - 1]), rev(k[n - 1], j[n - 1]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
