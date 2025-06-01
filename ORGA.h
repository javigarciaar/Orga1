#include <iostream>
using namespace std;

typedef unsigned char byte;
typedef char sbyte;
	
	byte left_shift(byte x, int k){
		return x << k;
	}
	
	byte logic_right_shift(byte x, int k){
		return x >> k;
	}
	
	byte aritmethic_right_shift(sbyte x, int k){
		return x >> k;
	}
	/*
	sbyte aritmethic_right_shift(sbyte x, int k){
		return x >> k;
	}
	*/
	void mostrarBinario(byte num) {
	    int i;
	    // Determina el número de bits a imprimir
	    for (i = (sizeof(byte) * 8) - 1; i >= 0; i--) {
	        // Desplaza el bit 1 a la posición i y realiza un AND bit a bit
	        // Si el resultado es diferente de cero, el bit en esa posición es 1
	        
	        if ((num >> i) & 1) {
	            printf("1");
	        } else {
	            printf("0");
	        }
	        if(i%4==0){
	        	printf(" ");
			}
	    }
	}
	
	void mostrarHexadecimal(int num){
		printf("0x%X", num);
	}
	

