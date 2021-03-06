#include <iostream>
#include <cmath>
using namespace std;

bool eq(double d1, double d2, double eps = 0.001) {
    return abs(d2 - d1) < eps;
}

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    void print(ostream& out) const {
        out<< "("<< x<< ", "<< y<< ")";
    }
};

ostream& operator<<(ostream& out, const Point& p) {
    p.print(out);
    return out;
}

istream& operator>>(istream& in, Point& p) {
    in >> p.x;
    in >> p.y;

    return in;
}

struct Line {
    double A, B, C;

    Line(double A = 0, double B = 0, double C = 0) : A(A), B(B), C(C) {}

    Line(const Point& p1, const Point& p2) {
        double x1 = p1.x, y1 = p1.y;
        double x2 = p2.x, y2 = p2.y;

        A = y1 - y2;
        B = x2 - x1;
        if(x1>=0)
        {
            C = A * (x1) - B * (y1);
        }
        else
        {
            C = A * (x2) - B * (y2);
        }
        if(B == 0)
        {
            C = -C;
        }

        //A = (y2 - y1) / (x2 - x1);
        //B = -1;
        //C = y1 - x1*A;


    }

    bool parallel(const Line& other) const {
        if(C != other.C)
        {
            if((A == other.A) || (B == 0 && other.B == 0))
            {
                return 1;
            }
        }

        return 0;
    }

    Line parallel(const Point& p) { // COLLINEAR NOT PARALLEL (NOT STATED IN THE TASK)
        double a = A, b = -1, c;
        double x = p.x, y = p.y;

        if(A*x+B*y+C == 0)
        {
            return Line(A, B, C);
        }
        if(B == 0)
        {
            b=0;
        }
        c = -(a*x+b*y);

        return Line(a, b, c);
    }

    bool perpendicular(const Line& other) const {
        if((other.A == -B && other.B == A) || (other.A == B && other.B == -A))
        {
            return 1;
        }

        return 0;
    }

    Line perpendicular(const Point& p) {
        double x = p.x, y = p.y;
        double a = -B, b = A, c = a*x+b*y;
        if(c != 0)
        {
            c = -c;
        }

        return Line(a,b,c);
    }

    void print(ostream& out) const {
        out<< A << "x + "<< B<< "y + "<< C<< " = 0";
    }
};

ostream& operator<<(ostream& out, const Line& l) {
    l.print(out);
    return out;
}

istream& operator>>(istream& in, Line& l) {
    in >> l.A;
    in >> l.B;
    in >> l.C;

    return in;
}
