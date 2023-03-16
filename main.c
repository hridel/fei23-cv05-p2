#include <stdio.h>
#include <math.h>

int solveQuadratic(double a, double b, double c, double* roots);

int main() {
    double a, b, c, roots[2];
    int numRoots;

    printf("Zadejte koeficienty a, b, c\npro kvadratickou rovnici ax^2 + bx + c = 0: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    numRoots = solveQuadratic(a, b, c, roots);

    if (numRoots == 0) {
        printf("Rovnice nemá reálné řešení.\n");
    } else if (numRoots == 1) {
        printf("Rovnice má jedno dvojnásobné řešení: x = %lf\n", roots[0]);
    } else {
        printf("Rovnice má dvě různá řešení: x1 = %lf, x2 = %lf\n", roots[0], roots[1]);
    }
    return 0;
}

int solveQuadratic(double a, double b, double c, double* roots) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return 0; // rovnice nemá reálné řešení
    } else if (discriminant == 0) {
        roots[0] = -b / (2 * a);
        return 1; // rovnice má jedno dvojnásobné řešení
    } else {
        roots[0] = (-b + sqrt(discriminant)) / (2 * a);
        roots[1] = (-b - sqrt(discriminant)) / (2 * a);
        return 2; // rovnice má dvě různá řešení
    }
}
