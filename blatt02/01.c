#include <stdio.h>

int main(){

unsigned char x1,x2,result; // mit unsigned kommt das korrekte Ergebnis raus
//char x1,x2,result;
//char x1,x2;
//int result;
int groessevonchar;

groessevonchar = sizeof(char);

// Beispiel 1:
x1 = 35;
x2 = 85;
result = x1 + x2;



printf("Beispiel 1: %hi + %hi = %hi\n",x1 ,x2, result);


// Beispiel 2:
x1 = 85;
x2 = 85;
result = x1 + x2;
result = 86 + 86;

printf("Beispiel 2: %hi + %hi = %hi\n",x1 ,x2, result);

printf("%hi",groessevonchar);

return 0;
}
