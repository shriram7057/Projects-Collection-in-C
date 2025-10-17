#include <stdio.h>
#include <unistd.h>

int main(){
    int sec;
    printf("=== Console Stopwatch ===\nEnter seconds to count: "); scanf("%d",&sec);

    for(int i=1;i<=sec;i++){
        printf("%d sec\n",i);
        sleep(1); // Wait 1 second
    }
    printf("Time's up!\n");
    return 0;
}
