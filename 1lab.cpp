#include <iostream>
#include <cmath>﻿
using namespace std;
int main() {
    double R, x0, y0, y, d, h, f;
    int p, q, k;
    cout << "Enter R (R > 0): ";
    cin >> R;
    if (R < 0) {
        cout << "Error, R < 0" << endl;
        return 0;
    }
    cout << "Enter x0, y0: ";
    // x^2 + y^2 = r^2
    cin >> x0 >> y0;
    if (x0 * x0 + y0 * y0 <= R * R) {
        cout << "Point in circle" << endl << "y = " << x0;
        return 0;
    }
    else {
        cout << "Point not in cicle" << endl << "Enter d,h,f: ";
        // y = (sin(fx+1))^(1/m), f = d + kh
        cin >> d >> h >> f;
        // Педставляем стпень корня m как p/q
        cout << "m = p/q, enter p,q: ";
        cin >> p >> q;

        // Проверка корректности ввода m = p/q 
        if (q == 0) {
            cout << "Error, q = 0" << endl;
            return 1;
        }
        if (p == 0) {
            cout << "Error, p = 0" << endl;
            return 1;
        }

        // Переносим знак в числитель: q > 0 (чтобы работать дальше можно было нормально работать с четностью 
        if (q < 0) {
            p = -p;
            q = -q;
        }

        // Сокращение дроби p/q (алгоритмом Евклида)
        int a = abs(p), b = q;
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        int g = a;   // НОД
        p /= g;
        q /= g;

        // После сокращения: m = p/q, показатель корня = q/p
        // y^(1/m) = y^(q/p)
        for (k = 1; k <= 10; k++) {
            y = sin((d + k * h) * f + 1);




            //  Случай y > 0: корень определён всегда 
            if (y > 0) cout << " k = " << k << " Result: " << pow(y, (double)q / p) << endl;// переводим q в double, чтобы деление было нецелочисленным
            //  Случай G == 0
            else if (y == 0) {
                // 0^(q/p) = 0 при q/p > 0, т.е. p > 0 (q > 0 после нормализации)
                if (p > 0) cout << " k = " << k << " Result: 0" << endl;
                else cout << " k = " << k << " Error: 0 in negative degree." << endl;
            }
            // Случай G < 0 
            // G^(q/p) определён, если p (знаменатель итоговой степени) НЕЧЁТНОЕ
            else {
                if (abs(p) % 2 == 0) cout << " k = " << k << " Error: G < 0, p even" << endl;
                // p нечётное => корень существует
                // Знак результата: q нечётное → минус, q чётное → плюс
                else {
                    double G = pow(-y, (double)q / p);
                    if (q % 2 != 0) G = -G;
                    cout << " k = " << k << " Result: " << G << endl;

                }

            }
        }
        return 0;
    }

}
