// cd "algoritmos\lista 1"
// g++ expressions.c -o expressions
// ./expressions

int main() {
    float a = 1.5, e = 1.2, f = 4.3;
    int b = 4, c = 2, d = 3;

    double expA = ((b * a) - c) / f;
    double expB = (f * a) + (d / e);
    double expC = (b * d) - (f / e);
    double expD = (a / a) - c;

    printf("a) %.16f\n", expA);
    printf("b) %.16f\n", expB);
    printf("c) %.16f\n", expC);
    printf("d) %.16f\n", expD);

    return 0;
}