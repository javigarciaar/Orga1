/*Lectura 4 representacion de enteros
Expansion de la representacion de un numero (unsigned y complemento a 2)

	1) Sin signo: Se agregan 0 a la izquierda tantos sean necesarios
	
	2) Complemento: Extension del signo, Se repite el MSB (el bit de signo) a la izq tantos sea necesario
*/
#include <iostream>
using namespace std;

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len){
	for(int i=0; i<len; i++){
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

int main(){
	cout<<"Es una maquina Little Endian\n";
	short sx = -12345; /* -12345 */
	unsigned short usx = sx; /* 53191 */
	int x = sx; /* -12345 */
	unsigned ux = usx; /* 53191 */ 
	
	printf("sx = %d:\t", sx);
	show_bytes((byte_pointer) &sx, sizeof(short));
	printf("usx = %u:\t", usx);
	show_bytes((byte_pointer) &usx, sizeof(unsigned short));
	printf("x = %d:\t", x);
	show_bytes((byte_pointer) &x, sizeof(int));
	printf ("ux = %u: \t", ux);
	show_bytes((byte_pointer) &ux, sizeof(unsigned));
	
	
	cout<<"Parte 2: "<<endl;
	short sx1 = -12345; /* -12345 */
	unsigned uy1 = sx1; /* Mystery! */

	printf("uy1 = %u:\t", uy1);
	show_bytes((byte_pointer) &uy1, sizeof (unsigned));
	return 0;
}


