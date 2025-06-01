#include <iostream>
using namespace std;
#include <stdio.h>

 typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
int i;
for(i = 0; i < len; i++){
printf(" %.2x", start[i]);	
}
printf("\n");
}

void show_int(int x){
show_bytes((byte_pointer) &x, sizeof(int));
}

 void show_float(float x) {
 show_bytes((byte_pointer) &x, sizeof(float));
 }
void show_double(double x) {
 show_bytes((byte_pointer) &x, sizeof(double));
 }
void show_pointer(void *x) {
show_bytes((byte_pointer) &x, sizeof(void *));}
int main(){
	/*
int var = 314156;
int* pvar = &var;
float fvar = 314156;
double dvar = 314156;
show_int(var);
show_float(fvar);
show_double(dvar);
show_pointer(pvar);
*/

int val = 0x87654321;
byte_pointer valp = (byte_pointer) &val;
show_bytes(valp,1);
show_bytes(valp,2);
show_bytes(valp,3);
const char * s = "abcdef";
show_bytes((byte_pointer)s, 8);
cout<<endl;
int x = 3510593;
show_int(x);
show_float((float)x);
	return 0;
}

