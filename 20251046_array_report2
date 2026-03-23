/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
    int sales[12] = {200, 300, 250, 400, 320, 600, 500, 700, 450, 350, 400, 300};
    int total = 0, maxSales = sales[0], maxMonth = 0;

    for (int i = 0; i < 12; i++) {
        total += sales[i];
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxMonth = i;
        }
    }

    printf("총 매출: %d\n", total);
    printf("최대 매출: %d (월: %d)\n", maxSales, maxMonth + 1); 

    return 0;
}
