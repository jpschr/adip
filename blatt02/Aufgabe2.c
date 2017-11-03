#include <stdio.h>
#include <stdlib.h>


unsigned long fibrec(int n){          \\unsigned long, da sonst zu hohe Zahlen den Speicher verlassen
    unsigned long x1=0;
    unsigned long x2=1;
    unsigned long tmp;
    int i;

    for(i=1; i<=n;i++){
        tmp=x2;
        x2+=x1;
        x1=tmp;
    }

    return x1;
}

void printfib(){
    unsigned long x1=0;
    unsigned long x2=1;
    unsigned long tmp;
    int i;
    printf("0");
    for(i=1; i<50;i++){                             \\jede dritte FibZahl ist gerade, also mache ich einfach drei Schritte auf einmal
        x1+=x2;
        x2+=x1;
        tmp=x2;
        x2+=x1;
        x1=tmp;
        printf(", %lu", x1);

    }

}

int main() {
   printf("%lu \n", (fibrec(20)));
   printfib();
   return 0;
}
