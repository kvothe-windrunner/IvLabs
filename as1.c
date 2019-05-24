
#include <stdio.h>
#include<stdlib.h>
int ind(int *arr, int n,int m){
    for(int i=0;i<m;i++){
        if(arr[i]== n)
            return i;
    }
    return 0;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void Sort(int arr[],int arr2[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1]){
              swap(&arr[j], &arr[j+1]);
               swap(&arr2[j], &arr2[j+1]);}

}
int sum=0;
int max=0;
void findMaxPrice(int arr[], int index,
					int num, int reducedNum,int*c,int *price,int m)
{
	if (reducedNum < 0)
		return;

	if (reducedNum == 0)
	{   sum = 0;
		for (int i = 0; i < index; i++){
            int temp = ind(c,arr[i],m);
            sum += price[temp];
		}
			if(sum > max){
                max = sum;
			}

		return;
	}

int prev=1;
	for (int k = prev; k <= m ; k++)
	{

		arr[index] = c[k-1];

		findMaxPrice(arr, index + 1, num,
								reducedNum - c[k-1],c,price,m);
	}
}


void FindPrice(int n,int*c,int *price,int m)
{

	int arr[n];


	findMaxPrice(arr, 0, n, n,c,price,m);
}

int main()
{
	int n = 0;
	int m= 0;
	scanf("%d %d",&n,&m);
    int *c = calloc(m,sizeof(int));
    int *price=calloc(m,sizeof(int));
    printf("Enter length array \n");
    for(int i = 0;i<m;i++){
        scanf("%d",&c[i]);
    }
    printf("Enter price array \n");
    for(int i = 0;i<m;i++){
        scanf("%d",&price[i]);
    }
    Sort(c,price,m);

	FindPrice(n,c,price,m);
	printf("\nMax price is %d.",max);
	return 0;
}

