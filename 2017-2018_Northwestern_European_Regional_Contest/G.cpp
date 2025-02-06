//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <numbers> // std::pi_v<double>

using namespace std;

struct Point {
	double x, y;
	Point(double _x = 0, double _y = 0) : x{_x}, y{_y} {}
};
using Vector = Point;

Vector operator+(const Vector &v1, const Vector &v2) { return {v1.x + v2.x, v1.y + v2.y}; }
Vector operator-(const Vector &v1, const Vector &v2) { return {v1.x - v2.x, v1.y - v2.y}; }
Vector operator*(const Vector &v, double d) { return {v.x * d, v.y * d}; }
Vector operator/(const Vector &v, double d) { return {v.x / d, v.y / d}; }

/*
bool operator<(const Point &p1, const Point &p2) {
	if (p1.x != p2.x) return p1.x < p2.x;
	return p1.y < p2.y;
}
*/

int dcmp(double x) {
	if (fabs(x) < 1e-12) return 0;
	return x > 0 ? 1 : -1;
}

bool operator==(const Point &p1, const Point &p2) {
	return dcmp(p1.x - p2.x) == 0 && dcmp(p1.y - p2.y) == 0;
}

double dot(const Vector &v1, const Vector &v2) { return v1.x * v2.x + v1.y * v2.y; }
double length(const Vector &v) { return sqrt(dot(v, v)); }
double cross(const Vector &v1, const Vector &v2) { return v1.x * v2.y - v1.y * v2.x; }

double angle(const Vector &v1, const Vector &v2) {
	return acos(dot(v1, v2) / length(v1) / length(v2));
}

Vector rotate(const Vector &v, double rad) {
	return {v.x * cos(rad) - v.y * sin(rad),
			v.x * sin(rad) + v.y * cos(rad)};
}

double PolygonArea(const vector<Point> &p) {
	int n{p.size()};
	double area{0};
	for (int i{2}; i < n; ++i) area += cross(p[i - 1] - p[0], p[i] - p[0]);
	return fabs(area / 2);
}

bool PolyInside(const vector<Point>& p, const Point& pt) {
	int r{0};
	for (int i{0}; i < p.size(); ++i) {
		int s{dcmp(cross(p[i] - pt, p[(i + 1) % p.size()] - pt))};
		if (!s) continue;
		if (r && r != s) return false;
		r = s;
	}
	return true;
}

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<Point> v(n);
	for (auto& [x, y] : v) cin >> x >> y;

	double ans1{}; int ans2;
	for (int k{3}; k <= 8; ++k) {
		vector<Point> p(k);
		auto setp{[k, &p](double len) {
			p[0] = {len, 0};
			for (int i{1}; i < k; ++i) p[i] = rotate(p[i - 1], 2 * numbers::pi_v<double> / k);
		}};
		double ia, oa;
		{
			double l{0}, r{5e6};
			while (r - l > 1e-9) {
				double m{(l + r) / 2};
				setp(m);
				bool f{true};
				for (auto& pt : v) {
					if (!PolyInside(p, pt)) {
						f = false;
						break;
					}
				}
				(f ? r : l) = m;
			}
			setp(l), oa = PolygonArea(p);
		}
		{
			double l{0}, r{5e6};
			while (r - l > 1e-9) {
				double m{(l + r) / 2};
				setp(m);
				bool f{false};
				for (auto& pt : v) {
					if (PolyInside(p, pt)) {
						f = true;
						break;
					}
				}
				(f ? r : l) = m;
			}
			setp(l), ia = PolygonArea(p);
		}
		if (ia / oa > ans1) ans1 = ia / oa, ans2 = k;
	}

	cout << ans2 << ' ' << ans1 << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout << fixed << setprecision(10);

	while (solve()) ;
}
