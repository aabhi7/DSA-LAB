#include <stdio.h>
void TOH(int n, char src, char aux, char dest) {
    if (n > 0) {
        TOH(n - 1, src, dest, aux);
        printf("Move disk %d from %c to %c\n", n, src, dest);
        TOH(n - 1, aux, src, dest);
    }
}
int fib(int n) {
    return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}
int main() {
    TOH(3, 'A', 'B', 'C'); 
    printf("Fibonacci(5): %d\n", fib(5));
    return 0;
}

