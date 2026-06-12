#include<stdio.h>

void bubblesort(int nath[]){
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5 - i - 1; j++){
            if (nath[j + 1] < nath[j]){
                int temp = nath[j];
                nath[j] = nath[j+1];
                nath[j+1] = temp;
            }
        }

    }

    for(int x = 0; x < 5; x++){
        printf("%d", nath[x]);
    }
}

int main(){
    int nath[5] = {};

    for(int x = 0; x < 5; x++){
        printf("I: ");
        scanf("%d", &nath[x]);
    }
    
    bubblesort(nath);
}