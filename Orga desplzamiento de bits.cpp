#include <iostream>
using namespace std;
/*
01/05/25 Orga Operaciones de desplzamiento de bits
 1) x << k: elimina los k bits mas significativos, rellena con 0s por la derecha
 
 2) x >> k:
 	a) Logico: LLena con k 0s a la izquierda + concatena el vector de bits
 	
 	b) Aritmetico: Repite k veces el bit mas significativo + concatena el vector
 	
 	Se asume que el aritmetico es para los signed y el logico para los unsigned
*/	

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
int main(){

	byte a = 0b01100011;
	byte aux1 = a<<4; //La operacion debe hacerse como bytes
	//int x = a; // se debe mostrar como un entero
	
	byte b = 0b10010101;
	sbyte sb = 0b10010101;
	byte aux2 = b << 4;
	
	byte aux3, aux4;
	sbyte aux5; //imprimira el numero con signo
	byte aux6; //imprmira como unsigned
	
	aux3= a >> 4;
	aux4 = b>>4;
	aux6 = sb>>4;
    cout<<(int)aux1<<endl;
    cout<<(int)aux2<<endl;
    cout<<(int)aux3<<endl;
    cout<<(int)aux4<<endl;
    cout<<(int)aux5<<endl;
    cout<<(int)aux6<<endl;
    //--------------------------------------------------
    
    //byte c=0x63, c1 =left_shift(c,3), c2 = logic_right_shift(c,2);
    //byte c3 = aritmethic_right_shift((sbyte)c, 2);
    
    
    byte numeros[] = {0x63, 0x75, 0x87, 0x66};
    
    cout<<"x\t\t\tx<<3\t\t\tx>>2(log)\t\tx>>2 (arit)\n";
    cout<<"Hex\tBin\t\tHex\tBin\t\tHex\tBin\t\tHex\tBin\n";
    
    for(int i=0; i < sizeof(numeros)/sizeof(byte); i++){
        byte c = numeros[i];
        byte c1 =left_shift(c,3);
        byte c2 = logic_right_shift(c,2);
        byte c3 = aritmethic_right_shift((sbyte)c, 2);
        
        mostrarHexadecimal((int)c);
        cout<<"\t";
        mostrarBinario(c);
        
        cout<<"\t";
        mostrarHexadecimal((int)c1);
        cout<<"\t";
        mostrarBinario(c1);
        
        cout<<"\t";
        mostrarHexadecimal((int)c2);
        cout<<"\t";
        mostrarBinario(c2);
        
        cout<<"\t";
        mostrarHexadecimal((int)c3);
        cout<<"\t";
        mostrarBinario(c3);
        cout<<endl;
    }
    
    
	return 0;
}
