#include <stdio.h>
#include <stdlib.h>
#ifndef c4_malloc
#define c4_malloc malloc
#define c4_free free
#endif
int add(int *c,int a,int b){
	if(a < 2){
		int *m = c4_malloc(56);
		c4_free(c);

		return m;
	}

	return c;

}
int add2(int *v,int a){
	if(a < 2){
		int *u = add(v,a,a);
		c4_free(u);
	}
	else if(a < 5){
		int *i = add(v,a,a);
		c4_free(i);
	}

	return v;

}
int main(){
	int *a = c4_malloc(8);
	int *b = a;
	int *z = add(b,6,9);
	int *d = c4_malloc(9);
	int *e = d;
	b = e;
	int *f = z;
	int *g = f;
	int *w = add2(g,900);
	c4_free(b);
	c4_free(w);

}
