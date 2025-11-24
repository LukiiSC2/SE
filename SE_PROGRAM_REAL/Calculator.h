#pragma once

double Calculator(double x, int n) {
    double mlt = 1;
    if (x < 0) {
        for (int i = 1; i <= n; i++) {
            mlt = mlt * ((x + 2) / (i - x));
        }
        mlt = (3 * x) - mlt;
    }
    else {
        for (int j = 1; j <= n; j++) {
            double sum = 0;
            for (int i = 1; i <= n+1; i++) {
                sum = sum + 3 * x + ((i + x) / (i * j));
            }
            mlt = mlt * sum;
        }
    }
    return mlt;
}