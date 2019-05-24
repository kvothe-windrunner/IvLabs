#include<stdio.h>

int noOfSteps(int arr[],int arr_count){
    int start = 0,stop = arr[0];
    int j=0;
    int ns=1,max=0,max_index=0;;

    for(int i=0;i<arr_count;i++){
        ns++;
        for(j=start+1;j<=start + stop;j++){
            if(arr[j] + j >max){
                max = arr[j];
                max_index=j;
            }

            }
            stop = max;
        start = max_index;
        if(start + stop >=arr_count-1){
                return ns;
                break;
    }
        }


    return ns;
}

int main(void){
    int arr_count = 0;
    scanf("%d",&arr_count);
    int arr[arr_count];
    for(int i=0;i<arr_count;i++)
        scanf("%d",&arr[i]);
    int steps = noOfSteps(arr,arr_count);
    printf("%d",steps);

}
