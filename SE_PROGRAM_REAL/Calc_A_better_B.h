#pragma once

double Calc_A_better_B(double x, int n) {
    double mlt = 1;
    if (x < 0) {
        double i = 1;
        while (i <= n) {
            mlt = mlt * (x + 2) / (i - x);
            i++;
        }
    }
    else {
        int j = 1;
        while (j <= n) {
            double sum = 0;
            int i = 1;
            while (i <= (n + 1)) {
                sum = sum + 3 * x + ((i + x) / (i * j));
                i++;
            }
            mlt = mlt * sum;
            j++;
        }
    }
    return mlt;
}