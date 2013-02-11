#include <stdio.h>
#include <math.h>

int main(){
    double n, p;
    while(scanf("%lf", &p) != EOF){
        scanf("%lf", &n);
        printf("%.0lf\n", pow(n, 1/p));
    }
}
