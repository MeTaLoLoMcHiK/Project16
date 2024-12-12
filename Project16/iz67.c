#include <stdio.h>
#include <math.h>

double f(double t) {
    return exp(t) * sqrt(1 - exp(t));
}

double left_rectangle(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double right_rectangle(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double midpoint_rectangle(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += f(a + (i + 0.5) * h);
    }
    return h * sum;
}

double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double simpsons(double a, double b, int n) {
    if (n % 2 != 0) n++; 
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 2) {
        sum += 4 * f(a + i * h);
    }
    for (int i = 2; i < n - 1; i += 2) {
        sum += 2 * f(a + i * h);
    }
    return h * sum / 3.0;
}

int main() {
    double a = 0, b = 1, epsilon = 1e-4;
    int n;
    double result, prev_result;

    printf("Numerical Integration Results:\n");

    n = 4;
    result = 0.0; 
    do {
        prev_result = result;
        result = left_rectangle(a, b, n);
        n *= 2;
    } while (fabs(result - prev_result) > epsilon);
    printf("Left Rectangles: %.6f (n = %d)\n", result, n / 2);

    n = 4;
    result = 0.0; 
    do {
        prev_result = result;
        result = right_rectangle(a, b, n);
        n *= 2;
    } while (fabs(result - prev_result) > epsilon);
    printf("Right Rectangles: %.6f (n = %d)\n", result, n / 2);

    
    n = 4;
    result = 0.0; 
    do {
        prev_result = result;
        result = midpoint_rectangle(a, b, n);
        n *= 2;
    } while (fabs(result - prev_result) > epsilon);
    printf("Midpoint Rectangles: %.6f (n = %d)\n", result, n / 2);

    n = 4;
    result = 0.0; 
    do {
        prev_result = result;
        result = trapezoidal(a, b, n);
        n *= 2;
    } while (fabs(result - prev_result) > epsilon);
    printf("Trapezoidal: %.6f (n = %d)\n", result, n / 2);

  
    n = 4;
    result = 0.0; 
    do {
        prev_result = result;
        result = simpsons(a, b, n);
        n *= 2;
    } while (fabs(result - prev_result) > epsilon);
    printf("Simpson's: %.6f (n = %d)\n", result, n / 2);

    return 0;
}

