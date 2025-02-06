//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

int Ask(int a, int b, int c) {
	cout << "? "s << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
	int res;
	return cin >> res, res;
}

void Ans(const vector<int>& v) {
	cout << "! "s << v.size();
	for (auto& x : v) cout << ' ' << x + 1;
	cout << endl;
}

void solve1() {
	int n;
	cin >> n;

	int last{Ask(0, 1, 2)};
	for (int i{1}; i < n; ++i) {
		int x{Ask(i, (i + 1) % n, (i + 2) % n)};
		if (x != last) {
			vector<int> v(n);
			v[i - 1] = last, v[(i + 2) % n] = x;
			for (int j{0}; j < n; ++j) {
				if (j == i - 1 || j == (i + 2) % n) continue;
				v[j] = Ask(i - 1, (i + 2) % n, j);
			}

			vector<int> imp{};
			for (int j{0}; j < n; ++j)
				if (v[j] == 0) imp.push_back(j);
			return Ans(imp), []{}();
		}
		last = x;
	}
}

void solve2() {
	int n;
	cin >> n;

	int im, cr;
	vector<int> rec(n / 3);
	for (int i{0}; i + 2 < n; i += 3) {
		rec[i / 3] = Ask(i, i + 1, i + 2);
		if (rec[i / 3] == 0) im = i;
		else cr = i;
	}

	if (Ask(im + 1, im + 2, cr) == 1) im = im, cr = cr;
	else if (Ask(im + 2, cr, cr + 1) == 1) im = im + 1, cr = cr + 1;
	else im = im + 2, cr = cr + 2;

	vector<int> v(n);
	v[im] = 0, v[cr] = 1;
	for (int i{0}; i + 2 < n; i += 3) {
		if ((i <= im && im <= i + 2) || (i <= cr && cr <= i + 2)) {
			if (i != im && i != cr) v[i] = Ask(i, im, cr);
			if (i + 1 != im && i + 1 != cr) v[i + 1] = Ask(i + 1, im, cr);
			if (i + 2 != im && i + 2 != cr) v[i + 2] = Ask(i + 2, im, cr);
		} else if (rec[i / 3] == 0) {
			if (Ask(i, i + 1, cr) == 0) {
				v[i] = v[i + 1] = 0;
				v[i + 2] = Ask(i + 2, im, cr);
			} else {
				v[i + 2] = 0;
				v[i] = Ask(i, im, cr), v[i + 1] = (v[i] == 0 ? 1 : 0);
			}
		} else {
			if (Ask(i, i + 1, im) == 1) {
				v[i] = v[i + 1] = 1;
				v[i + 2] = Ask(i + 2, im, cr);
			} else {
				v[i + 2] = 1;
				v[i] = Ask(i, im, cr), v[i + 1] = (v[i] == 1 ? 0 : 1);
			}
		}
	}

	vector<int> imp{};
	for (int j{0}; j < n; ++j)
		if (v[j] == 0) imp.push_back(j);
	Ans(imp);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve2();

	return 0;
}
