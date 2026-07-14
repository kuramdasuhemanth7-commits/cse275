#include <stdio.h>

int main() {
    double x, y;

    scanf("%lf %lf", &x, &y);


    if (y == 0) {
        printf("Division by zero is not possible");
        return 0;
    }

   
    int negative = 0;
    if ((x < 0 && y > 0) || (x > 0 && y < 0))
        negative = 1;


    if (x < 0) x = -x;
    if (y < 0) y = -y;

    double low = 0, high;

    if (x >= y)
        high = x;
    else
        high = 1;

    double mid;

   
    while (high - low > 0.000001) {
        mid = (low + high) / 2.0;

        if (mid * y < x)
            low = mid;
        else
            high = mid;
    }

    double result = (low + high) / 2.0;

    if (negative)
        result = -result;

    printf("%.5f", result);

    return 0;
}