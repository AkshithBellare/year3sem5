#include<omp.h>
#include<stdio.h>
int main() {
    int x=0, i=0, n=0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        #pragma omp for lastprivate(i)
            for(i=0; i<n; i++) 
            {
                printf("Thread %d : value of i : %d\n", id, i);
                x = x + i;
                printf("Thread %d : x is %d\n", id, x);
            }
    }
    printf("x is %d: \n", x);
    printf("i is %d: \n", i);
    return 0;
}