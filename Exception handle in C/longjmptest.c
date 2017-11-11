#include <stdio.h>
#include <setjmp.h>
#include <signal.h>

static jmp_buf env;

void handler(int signnum) {
    if (signnum == SIGSEGV) {
        printf("segmentation fault\n");
        longjmp(env, signnum);
    }
}

/*double divide(double a, double b) {
    if (b == 0) {
        longjmp(env, 1);
    } else if (a > 100) {
        longjmp(env, 2);
    }
    return a / b;
}*/

int main() {
    int i, *p = NULL;
    double a, b, c;
    signal(SIGSEGV, handler);
    //scanf("%lf%lf", &a, &b);
    i = setjmp(env);
    if (i == 0) {
        *p = 1;
        //c = divide(a, b);
    } else if (i == SIGSEGV) {
        printf("segmentation fault, handle it\n");
    } else if (i == 2) {
        printf("too big\n");
    }
    return 0;
}
