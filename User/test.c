#include <stdio.h>
#include <stdarg.h>
int sum(int, ...);

void create(char*, char*, int, ...);

#define minh(...) printf(__VA_ARGS__)
#define ok(...){minh(__VA_ARGS__); printf("Da ghi %s", __VA_ARGS__);}


#define BRUNION_32x16(name,feature,reg1,reg2,...)\
union\
{\
  unsigned long feature REG;\
  RSTRUCT(,unsigned short feature,reg1,reg2);\
  BSTRUCT(BITS,unsigned char,__VA_ARGS__);\
} name

int main(){
	printf("Tong = %d", sum(3, 1, 2, 3));
	return 0;
}


int sum(int num_args, ...){
	int val = 0;
	va_list  ap;
	int i;
	va_start(ap, num_args);
	for(i = 0; i < num_args; ++i){
		val += va_arg(ap, int); 
	}
	va_end(ap);
	return val;
}

void create(char* name, char* type, int number_args, ...){
	va_list ap;
	va_start(ap, number_args);
	int i;
	for(i = 0; i < number_args; ++i){
		int va_arg(ap)
	}
}
