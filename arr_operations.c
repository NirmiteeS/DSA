#include<stdio.h>

void insertion(int arr[], int index,int size){
    for(int i=size-1; i>=index; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=1;

    for(int i=0;i<size+1;i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void deletion(int arr[], int size, int index){
    for(int i=index;i<size;i++){
        arr[i]=arr[i+1];
    }

    for(int i=0;i<size;i++){
        printf("%d  ", arr[i]);
    }
}
int main(){
    int arr[20]={5,8,6,3,4,9};
    insertion(arr, 3, 6);
    deletion(arr,7,3);
    return 0;
}