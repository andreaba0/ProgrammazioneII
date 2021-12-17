#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void dump_array(const void *base, size_t num_elem, size_t elem_size, void (*dump_element)(const void *, FILE *), FILE *fp);
static void dump_int(const void *p, FILE *fp);
static void dump_string(const void *p, FILE *fp);

void dump_array(const void *base, size_t num_elem, size_t elem_size, void (*dump_element)(const void *, FILE *), FILE *fp) {
	assert(base != NULL);
	assert(fp != NULL);

	const unsigned char *pcb=base;
	for(int i=0;i<num_elem;i++) {
		size_t cnt=i;
		const void *pelem=pcb+cnt*elem_size;
		dump_element(pelem, fp);
	}
}

void dump_int(const void *p, FILE *fp) {
	assert(p!=NULL);
	assert(fp!=NULL);

	unsigned const int *a=p;
	fprintf(fp, "%d\t",*a);
}

void dump_string(const void *p, FILE *fp) {
	assert(p!=NULL);
	assert(fp!=NULL);

	unsigned const char *pcb=p;
	size_t x_size=sizeof pcb/sizeof pcb[0];
	for(int i=0;i<x_size;++i) {
		printf("'%d' ", pcb[i]);
	}
	printf("\n");
}

int main() {
	int iary[]={1,20,25,32,76,123};
	const char *sary[]={"e01", "e02","e03","e04","e05","e06"};
	FILE *fp = stdout;

	size_t x_size = sizeof sary/sizeof sary[0];
	for(int i=0;i<x_size;++i) {
		printf("'%s' ",sary[i]);
	}
	printf("\n");

	dump_array(iary, sizeof iary/sizeof iary[0], sizeof iary[0], dump_int, fp);
	fputc('\n', fp);
	dump_array(sary, sizeof sary/sizeof sary[0], sizeof sary[0], dump_string, fp);
	fputc('\n', fp);
	
	return 0;
}
