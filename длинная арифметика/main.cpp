#include <iostream>
#include <string>
#include<sstream>
#include<cctype>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return false;
}

vector <int> sum(const vector<int>& num1, const vector <int>& b1, int sdvig = 0, int k = 0) {

    int i = 0, s = 0, q = 0;
    vector <int> b = b1;
    vector <int> num = num1;

    vector <int> nul = { 0 };




    while (sdvig) {
        reverse(b.begin(), b.end());
        b.push_back(0);
        reverse(b.begin(), b.end());
        sdvig--;

    }
    if (k) {
        num.insert(num.end(), nul.begin(), nul.end());
        b.insert(b.end(), nul.begin(), nul.end());
    }

    vector<int> res;
    while (i < (int)num.size() || i < (int)b.size()) {
        if (i < (int)num.size())
            s += num[i];
        if (i < (int)b.size())
            s += b[i];
        res.push_back(s % 10);
        s /= 10;
        ++i;
    }

    if (res[res.size() - 1] == 0)res.pop_back();
    if (s != 0)
        res.push_back(s);


    return res;
}

vector<int> diff(const vector<int>& num, const vector<int>& b) {
    int i = 0, s = 0, q = 0;
    vector<int> res;
    while (i < (int)num.size() || i < (int)b.size()) {
        s = 0;
        if (i < (int)num.size())
            s += num[i];
        if (i < (int)b.size())
            s -= b[i];
        s -= q;
        if (s < 0) {
            s += 10;
            q = 1;
        }
        else
            q = 0;
        res.push_back(s % 10);
        ++i;

    }
    return res;
}


vector<int> mul(const vector<int>& a, int c) {
    vector<int> res;
    res.resize((int)a.size() + 1);
    for (int i = 0; i < (int)a.size(); i++) {
        int cur = 0;
        cur = cur + res[i] + a[i] * c;
        res[i] = cur % 10;
        cur /= 10;

        res[i + 1] = cur;
    }
    return res;
}
vector<int> mul(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    for (int i1 = 0; i1 < (int)b.size(); ++i1) {

        res = sum(res, mul(a, b[i1]), i1);
    }

    if (res.empty())return { 0 };
    return res;
}


class longint {
private:
    int sign;
    vector<int> num;
    void normalize() {
        while (num.size() > 1 && num.back() == 0) {
            num.pop_back();
        }
        if (num.size() == 1 && num[0] == 0) {
            sign = 1;
        }
        if (num.size() == 0)
            num.assign(1, 0);
    }
public:

    longint(const string& S = "") {
        if (S.size() == 0) {
            num.assign(1, 0);
            sign = 1;
            return;
        }
        int to = 0;
        sign = 1;
        if (S[0] == '-') {
            sign = -1;
            to = 1;
        }
        for (int i = S.size() - 1; i >= to; --i) {
            num.push_back(S[i] - '0');
        }
        normalize();
    }
    longint(const long long a) {

        long long q = a;

        if (q < 0) q = -q;

        while (q != 0) {
            num.push_back(q % 10);
            q /= 10;

        }
        if (num.size() == 0) {
            num.assign(1, 0);
            sign = 1;
            return;
        }
        sign = 1;
        if (a < 0) {
            sign = -1;
        }

        normalize();

    }
    string to_string() const {
        string S;
        if (sign == -1) {
            S.push_back('-');
        }
        for (int i = (int)num.size() - 1; i >= 0; --i) {
            S.push_back(num[i] + '0');
        }
        return S;
    }
    bool operator < (const longint& b) const {
        if (sign * b.sign == -1) {
            return sign < b.sign;
        }
        if (sign > 0 && cmp(num, b.num))
            return true;
        if (sign < 0 && cmp(b.num, num))
            return true;
        return false;
    }
    bool operator > (const longint& b) const {
        return b < *this;
    }
    bool operator == (const longint& b) const {
        return !((*this < b) || (b < *this));
    }
    bool operator >= (const longint& b) const {
        return ((*this > b) || (*this == b));
    }
    bool operator <= (const longint& b) const {
        return ((*this < b) || (*this == b));
    }
    bool operator != (const longint& b) const {
        return ((*this < b) && (b < *this));
    }
    longint operator + (const longint& b) const {
        if (sign * b.sign == 1) {
            longint res;
            res.sign = sign;
            res.num = sum(num, b.num);
            res.normalize();
            return res;
        }
        else {
            if (cmp(num, b.num)) {
                longint res;
                res.sign = b.sign;
                res.num = diff(b.num, num);
                res.normalize();
                return res;
            }
            else {
                longint res;
                res.sign = sign;
                res.num = diff(num, b.num);
                res.normalize();
                return res;
            }
        }
    }

    longint operator - (const longint& b) const {
        longint c;
        c.sign = -1 * b.sign;
        c.num = b.num;
        return *this + c;
    }
    longint operator * (const longint& b) const {
        longint res;
        res.num = mul(num, b.num);
        res.sign = sign * b.sign;
        res.normalize();
        return res;
    }
    longint operator / (const longint& b) const {


        longint res;


        longint R = 0;
        longint Q = 0;

        longint delim = *this;
        delim.sign = 1;
        longint delit = b;
        delit.sign = 1;
        for (int i = delim.num.size() - 1; i >= 0; i--) {
            R = R * 10 + delim.num[i];
            for (int w = 9; w >= 0; w--) {
                if (R >= (delit * w)) {
                    Q = Q * 10 + w;
                    break;

                }
            }
            R = (R - (delit * delit.sign * Q.num[0]));

        }

        R.normalize();

        Q.sign = sign * b.sign;
        Q.normalize();

        if (b.sign != sign && !(R == 0))Q = Q - 1;
        res.sign = sign * b.sign;
        res.normalize();
        res = Q;


        return res;
    }

    longint operator %(const longint& b) const {
        longint res;
        res = *this - (*this / b) * b;
        return res;
    }

};
istream& operator >>(istream& in, longint& l) {
    string S;
    in >> S;
    l = longint(S);
    return in;
}
ostream& operator <<(ostream& out, const longint& l) {
    out << l.to_string();
    return out;
}

int main() {
    longint a, b;
    cin >> a >> b;
    cout << a % b << endl;
    return 0;
}
