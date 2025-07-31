fn add(int *c,int a,int b)->int:
    if a < 2:
        int *m = alloc!(56)
        return m
    :
    return c
:

fn add2(int *v,int a)->int:
    if a < 2:
        int *u = add(v,a,a)
    :
    elif a < 5:
        int *i = add(v,a,a)
    :
    return v
:

fn main()->int:
    int *a = alloc!(8)
    int *b = a
    

    int *z = add(b,6,9)
    int *d = alloc!(9)
	int *e = d
	b = e
    int *f = z
    int *g = f
    int *w = add2(g,900)

:


