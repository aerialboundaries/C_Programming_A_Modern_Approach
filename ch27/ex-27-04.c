/*
(C99) Assume that the following variable declarations are in effect:

int i;
float f;
double d;
long double ld;
float complex fc;
double complex dc;
long double complex ldc;

Each of the following is an invocation of a macro in <tgmath. h>. Show what it
will look like after preprocessing, when the macro has been replaced by a
function from <math.h> or <complex.h>.

(a) tan(i)
(b) fabs (f)
(c) asin (d)
(d) exp (ld)
(e) log(fc)
(f) acosh (dc)
(g) nexttoward (d, ld)
(h) remainder (f, i)
(i) copysign(d, ld)
(j) carg(i)
(k) cimag(f)
(1) conj(ldc)
*/

/* My Ansewr
(a) tan(i)
tan(i)

(b) fabs (f)
fabsf(f)

(c) asin (d)
asin(d)

(d) exp (ld)
expl double(ld)

(e) log(fc)
clogf(fc)

(f) acosh (dc)
cacosh(dc)

(g) nexttoward (d, ld)
nexttowardl(d, ld)

(h) remainder (f, i)
remainderf(f, i)

(i) copysign(d, ld)
copysignl(d, ld)

(j) carg(i)
carg(i)

(k) cimag(f)
cimagf(f)

(1) conj(ldc)
conjl(ldc)
*/
