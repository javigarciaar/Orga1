/*
Suponga que se ejecutan como un programa de 32 bits en una máquina que utiliza aritmética en
complemento a dos. Suponga también que los desplazamientos a la derecha de valores con signo se realizan
aritméticamente, mientras que los desplazamientos a la derecha de valores sin signo se realizan de forma
lógica.

*/
#include <iostream>
using namespace std;

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len){
	for(int i=0; i<len; i++){
		printf(" %.2x", start[i]);
	}
	//printf("\n");
}

int fun1 (unsigned word) {
	return (int) ((word<< 24) >> 24);
}
int fun2 (unsigned word) {
	return ((int) word << 24) >> 24;
}

int main(){
	unsigned arr[] = {0x00000076, 0x87654321, 0x000000c9, 0xedbca987};
	cout<<"numero\tfunc1(x)\tfunc2(x)\n";
	for(int i=0; i<4; i++){
		int x = arr[i];
		show_bytes((byte_pointer) &x, sizeof(int));
		cout<<"\t";
		x = fun1(arr[i]);
		printf("x = %d:\t", x);
		show_bytes((byte_pointer) &x, sizeof(int));
		
		x = fun2(arr[i]);
		printf("x = %d:\t", x);
		show_bytes((byte_pointer) &x, sizeof(int));
		cout<<endl;
	}
	
	return 0;
}
