#include <stdio.h>
#include <setjmp.h>
#include <signal.h>

static jmp_buf env;

void handler(int signnum) {
    if (signnum == SIGSEGV) {
        printf("segmentation fault\n");
        longjmp(env, signnum);//when you go back, signum is going set the return value of setjmp(), and the program will go on at where the setjmp is.
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
    signal(SIGSEGV, handler);//only once, if the handler is called, and reach the same exception the next time, it will not handle it. You have to regist it again.
    //scanf("%lf%lf", &a, &b);
    i = setjmp(env);//take a photo of the program's state
    if (i == 0) {
        *p = 1;
        //c = divide(a, b);
    } else if (i == SIGSEGV) {
        printf("segmentation fault, handle it\n");
    } else if (i == 1) {
        printf("divided by zero\n");
    }
    return 0;
}
