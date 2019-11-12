#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


#define concat(x) {.n=x##init, .z=1, .r=NULL}

struct y {
	void (*n)(void);
	int z;
	const int *r;
};

struct data {
	int v;
	int i;
};

struct class_ {
	const struct data *dat;
};

void oneinit();
struct y y1 = concat(one);
void oneinit() {
	printf("oneinit %d\n", y1.z);
	return;
}

static struct class_ g_c;
static struct data d;
const struct class_ *get_class(void)
{
	d.v = 4;
	d.i = 3;
	g_c.dat = &d;
	return &g_c;
}

int num[3] = {0, 1, 2};
int main()
{
	const struct class_ *c = get_class();

	printf("%d\n", c->dat->v); 
	d.v = 6;
	
	printf("%d\n", c->dat->v);

	int b = 30;
	y1.r = &b;
	b = 45;
	y1.n();
	printf("%d\n", *y1.r);

	for (int i=0; i<3; ++i) {
		printf("%d\n", num[i]);
	}

	for (int j=0; j<3; j++) {
		printf("%d\n", num[j]);
	}
	return 0;
}