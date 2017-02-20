// -----------
// Fri, 17 Feb
// -----------

int i;
i = 2;
++i;
cout << i; // 3

const int ci;     // not ok
const int ci = 3;
++ci;             // not ok

      int i  = 2;
const int ci = 3;
int* p;
p = &i;
++*p;
cout << i; // 4
p = &ci;   // not ok

      int  i  = 2;
const int  ci = 3;
const int  cj = 4;
const int* pc;
pc = &ci;
pc = &cj;
++*pc;       // not ok
pc = &i;
cout << *pc; // 2
++i;
cout << *pc; // 3

      int  i  = 2;
const int  ci = 3;
int* const cp = &ci; // not ok
int* const cp = &i;
++*cp;
++cp;               // not ok

      int        i   = 2;
const int        ci  = 3;
const int* const cpc = &ci;
++*cpc;                     // not ok
++cpc;                      // not ok

      int  i  = 2;
const int  ci = 3;
      int& r;       // not ok
      int& r  = ci; // not ok
      int& r  = i;
++r;

// T& is most like T* const

      int  i  = 2;
const int  ci = 3;
const int& r;       // not ok
const int& r  = ci;
++r;                // not ok
const int& s  = i;
++s;                // not ok

// const T& is most like const T* const
