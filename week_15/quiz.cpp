#include <iostream>
#include <cmath>
using namespace std;

// ===== Lớp cha: PT =====
class PT {
protected:
    int degree;              // bậc của phương trình
    double coefficients[4];  // mảng hệ số: coefficients[0] = hệ số bậc cao nhất
public:
    // Constructor
    PT(int degree = 0, const double coef[] = nullptr) {
        this->degree = degree;
        for (int i = 0; i < 4; i++)
            coefficients[i] = (coef != nullptr && i <= degree) ? coef[i] : 0;
    }
    virtual ~PT() {}

    // Getter
    int getDegree() const { return degree; }
    double getCoefficient(int index) const { return coefficients[index]; }

    // Setter
    void setDegree(int d) { degree = d; }
    void setCoefficient(int index, double value) {
        if (index >= 0 && index <= degree) coefficients[index] = value;
    }

    virtual void solve() {}   // lớp con sẽ viết lại hàm này
};

// ===== Lớp con: PTB2 =====
// a x^2 + b x + c = 0
class PTB2 : public PT {
public:
    PTB2(double a = 1, double b = 0, double c = 0) {
        degree = 2;
        coefficients[0] = a;
        coefficients[1] = b;
        coefficients[2] = c;
    }

    void solve() {
        double a = coefficients[0], b = coefficients[1], c = coefficients[2];
        cout << "Quadratic: " << a << "x^2 + " << b << "x + " << c << " = 0\n";
        if (a == 0) {
            if (b == 0) cout << (c == 0 ? "Infinitely many solutions\n" : "No solution\n");
            else cout << "x = " << -c / b << "\n";
            return;
        }
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) cout << "No real solution\n";
        else if (discriminant == 0) cout << "Double root x = " << -b / (2 * a) << "\n";
        else {
            cout << "x1 = " << (-b + sqrt(discriminant)) / (2 * a) << "\n";
            cout << "x2 = " << (-b - sqrt(discriminant)) / (2 * a) << "\n";
        }
    }
};

// ===== Lớp con: PTB3 =====
// a x^3 + b x^2 + c x + d = 0
class PTB3 : public PT {
public:
    PTB3(double a = 1, double b = 0, double c = 0, double d = 0) {
        degree = 3;
        coefficients[0] = a;
        coefficients[1] = b;
        coefficients[2] = c;
        coefficients[3] = d;
    }

    void solve() {
        double a = coefficients[0];
        cout << "Cubic: " << coefficients[0] << "x^3 + " << coefficients[1] << "x^2 + "
             << coefficients[2] << "x + " << coefficients[3] << " = 0\n";
        if (a == 0) {
            cout << "Coefficient a = 0, not a cubic equation\n";
            return;
        }
        // Chuẩn hoá: x^3 + A x^2 + B x + C = 0
        double A = coefficients[1] / a;
        double B = coefficients[2] / a;
        double C = coefficients[3] / a;
        // Đặt x = t - A/3  ->  t^3 + p t + q = 0
        double p = B - A * A / 3;
        double q = 2 * A * A * A / 27 - A * B / 3 + C;
        double D = (q / 2) * (q / 2) + (p / 3) * (p / 3) * (p / 3);
        double shift = -A / 3;
        const double EPS = 1e-9;

        if (D > EPS) {                      // 1 nghiệm thực
            double u = cbrt(-q / 2 + sqrt(D));
            double v = cbrt(-q / 2 - sqrt(D));
            cout << "x = " << u + v + shift << "\n";
        } else if (fabs(D) <= EPS) {        // nghiệm bội
            if (fabs(p) <= EPS) {
                cout << "Triple root x = " << shift << "\n";
            } else {
                cout << "x1 = " << 3 * q / p + shift << "\n";
                cout << "x2 = x3 = " << -3 * q / (2 * p) + shift << "\n";
            }
        } else {                            // 3 nghiệm thực phân biệt
            double r = 2 * sqrt(-p / 3);
            double phi = acos((-q / 2) / sqrt(-(p / 3) * (p / 3) * (p / 3)));
            for (int k = 0; k < 3; k++)
                cout << "x" << k + 1 << " = "
                     << r * cos((phi + 2 * M_PI * k) / 3) + shift << "\n";
        }
    }
};

// ===== main =====
int main() {
    PT* equations[2];                          // mảng con trỏ PT
    equations[0] = new PTB2(1, -3, 2);         // x^2 - 3x + 2 = 0
    equations[1] = new PTB3(1, -6, 11, -6);    // x^3 - 6x^2 + 11x - 6 = 0

    // Dùng setter / getter
    equations[0]->setCoefficient(2, -4);       // đổi c thành -4
    cout << "Degree: " << equations[0]->getDegree()
         << ", c = " << equations[0]->getCoefficient(2) << "\n\n";

    for (int i = 0; i < 2; i++) {
        equations[i]->solve();   // nhờ virtual nên gọi đúng solve() của lớp con
        cout << "-----------\n";
        delete equations[i];
    }
    return 0;
}