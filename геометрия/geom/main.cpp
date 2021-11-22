#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const double Pi = 3.1415926535;
const double eps = 1e-10;

struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) :x(x), y(y)
    {}
    Point operator - (const Point& b)
    {
        Point ret;
        ret.x = x - b.x;
        ret.y = y - b.y;
        return ret;
    }
    Point operator + (const Point& b)
    {
        Point ret;
        ret.x = x + b.x;
        ret.y = y + b.y;
        return ret;
    }
    Point operator * (const double k)
    {
        Point ret;
        ret.x = x * k;
        ret.y = y * k;
        return ret;
    }
    Point operator / (const double k)
    {
        Point ret;
        ret.x = x / k;
        ret.y = y / k;
        return ret;
    }
    double at() {
        if (atan2(y, x) >= 0)
            return atan2(y, x);
        else
            return Pi * 2 + atan2(y, x);

    }
    double dist2() {
        return x * x + y * y;
    }
    double dist() {
        return sqrt(dist2());
    }



};
/*
struct Line {

    double A, B, C;

    Line(double A = 0, double B = 0, double C = 0) : A(A), B(B), C(C) {


    }


};
struct Line {

    double A, B, C;
    Line() {}
    Line(Point w, Point s) {

        A = s.y - w.y;
        B = w.x - s.x;
        C = w.y * (s.x - w.x) - w.x * (s.y - w.y);
    }
};
double f(Line l, Point p)
{
    return l.A * p.x + l.B * p.y + l.C;
}
string prin(Line l, Point p) {
    if (fabs(f(l, p)) < eps)
        return "YES";
    else return "NO";
}*/
double skalpr(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

double pl(Point a, Point b) {
    return  a.x * b.y - a.y * b.x;
}
double rast(Point a, Point b, Point c) {
    Point q = c - b;
    if (skalpr(a - b, q) >= 0)
        return abs(pl(q, a - b) / q.dist());
    else return (a - b).dist();
}
double rastdootr(Point a, Point b, Point c) {
    Point q = c - b;
    if (skalpr(a - b, q) >= 0)
        if (skalpr(b - c, a - c) >= 0)return abs(pl(q, a - b) / q.dist());
        else return (a - c).dist();
    else return (a - b).dist();
}

double rastdopr(Point a, Point b1, Point b2) {
    double d = abs(pl(b1 - a, b1 - b2));

    d /= (b1 - b2).dist();
    return d;
}
/*
double rastdopr2(Point a, Line q) {
    Point b1;
    Point b2;
    if (q.B == 0 && q.A != 0) {
        b1.x = -1 * q.C / q.A;
        b1.y = 0;
        b2.x = -1 * q.C / q.A;
        b2.y = 1;
    }

    if (q.B != 0) {
        b1.x = 0;
        b1.y = -1 * (q.C / q.B);
        b2.x = 1;
        b2.y = (q.A * 1 + q.C) / q.B * -1;
    }
    double d = abs(pl(b1 - a, b1 - b2));

    d /= (b1 - b2).dist();
    return d;
}*/
double ugol(Point a, Point b) {
    return acos(skalpr(a, b) / (a.dist() * b.dist()));
}
double sinn(Point a, Point b) {
    return sin(ugol(a, b));
}
double coss(Point a, Point b) {
    return (skalpr(a, b) / (a.dist() * b.dist()));
}
/*
Line perp(Line w, Point q) { //возвращ прямую перп данной ч/з заданную точку
    Line n;
    n.A = w.B;
    n.B = -1 * w.A;
    n.C = w.A * q.y - w.B * q.x;
    return n;
}*/
Point norm(Point a, double l = 1.0) {
    if (a.dist2() < eps)
        return a;
    a = a / a.dist() * 1;
    return a;
}/*
double peresx(Line q, Line q1) {
    Point w;
    w.x = q.A;
    w.y = q.B;
    Point w1;
    w1.x = q1.A;
    w1.y = q1.B;
    double det = pl(w, w1);
    w.x = q.C;
    w1.x = q1.C;
    double det1 = pl(w, w1);
    return det1 / det;
}

double peresy(Line q, Line q1) {
    Point w;
    w.x = q.A;
    w.y = q.B;
    Point w1;
    w1.x = q1.A;
    w1.y = q1.B;
    double det = pl(w, w1);
    w.x = q.C;
    w1.x = q1.C;

    swap(w.x, w.y);
    swap(w1.x, w1.y);
    w.x = q.A;
    w1.x = q1.A;
    double det2 = pl(w, w1);

    return det2 / det;
}
Point PERES(Line q, Line q1) {
    Point w;
    w.x = peresx(q, q1) * -1;
    w.y = peresy(q, q1) * -1;
    return w;

}
Line bisektr(Point a, Point b, Point c) {
    double l = 1.0;
    Point e;
    Point q = c - a;
    Point q1 = b - a;
    c = a + norm(q, l);
    b = a + norm(q1, l);
    Line w(a, (c + b) / 2);



    if ((coss(c - a, b - a)) == -1) { // если угол 180
        Line q(a, b);
        return perp(q, a);

    }
    if ((coss(c - a, b - a)) == 1) { // если угол 0
        Line q(a, b);
        return q;

    }
    return w;
}
double peresx(Line q, Line q1) {
    Point w;
    w.x = q.A;
    w.y = q.B;
    Point w1;
    w1.x = q1.A;
    w1.y = q1.B;
    double det = pl(w, w1);
    w.x = q.C;
    w1.x = q1.C;
    double det1 = pl(w, w1);
    return det1 / det;
}

double peresy(Line q, Line q1) {
    Point w;
    w.x = q.A;
    w.y = q.B;
    Point w1;
    w1.x = q1.A;
    w1.y = q1.B;
    double det = pl(w, w1);
    w.x = q.C;
    w1.x = q1.C;

    swap(w.x, w.y);
    swap(w1.x, w1.y);
    w.x = q.A;
    w1.x = q1.A;
    double det2 = pl(w, w1);

    return det2 / det;
}
Point PERES(Line q, Line q1) {
    Point w;
    w.x = peresx(q, q1) * -1;
    w.y = peresy(q, q1) * -1;
    return w;

}*/
ostream& operator << (ostream& out, Point& a)
{
    return out << a.x << " " << a.y;
}
istream& operator >> (istream& in, Point& a)
{
    return in >> a.x >> a.y;
}/*
ostream& operator << (ostream& out, Line& a)
{
    return out << a.A << " " << a.B << " " << a.C;
}
istream& operator >> (istream& in, Line& a)
{
    return in >> a.A >> a.B >> a.C;
}
void paral(Line q, double R) {
    Point Q;
    Q.x = q.A;
    Q.y = q.B;
    cout << fixed << q.A << " " << q.B << " " << q.C + R * Q.dist() << endl;
}
bool prinadl(Point a, Line q) {
    if (f(q, a) != 0)return 0;
    else return 1;
}*/
bool prinadlotr(Point a, Point b, Point c) {

    if (skalpr(b - a, c - a) <= 0 && pl(c - b, a - b) == 0)
        return 1;
    else return 0;

}

bool per(Point a, Point b, Point c, Point d) {
    Point q = a - b;
    Point w = d - c;
    if (pl(q, w) == 0)
        if (prinadlotr(a, c, d) || prinadlotr(b, c, d) || prinadlotr(c, a, b) || prinadlotr(d, a, b))return 1;
        else return 0;
    else if (pl(d - b, w) / pl(q, w) >= 0 && pl(q, d - b) / pl(q, w) >= 0 && pl(d - b, w) / pl(q, w) <= 1 && pl(q, d - b) / pl(q, w) <= 1) return 1;
    else return 0;
}
int main()
{


    Point a, b, c, d;
    cin >> a >> b >> c >> d;

    cout.precision(10);
    if (per(a, b, c, d)) cout << "Yes";
    else cout << "No";
    return 0;
}
