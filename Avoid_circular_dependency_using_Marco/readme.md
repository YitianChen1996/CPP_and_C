Recently when I do CS240's CA2, I met a problem that I have to include header1.h in header2.h, and and include header2.h in header1.h.
And it comes out that some variables have multidefined.
I know this should be avoided when the initial design, but I have wrote most of the code, so I have to find some other way to solve it.<br>
In cs220, I learned that using Marco, we can do something before compiling (called preprocessor), and it is a good way to solve this problem.
<br><br>
We can use:<br><br>
#ifndef header1<br>
#define header1<br><br>
#include something here<br>

#endif<br><br>
so that when header2.h want to include header1.h, it will check whether header1(can be considered as a variable) has been defined,
so it will jump over all the code between #ifndef and #endif, so, multidefined error will not happen.
