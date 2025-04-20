#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void display(int arr[],int n)
{
          int i;
          for(i=0;i<n;i++)
          {
                    printf("%d ",arr[i]);
          }
}
int partition(int arr[],int lb,int ub)
{
          int pivot=arr[lb];
          int up=ub;
          int down=lb;
          do
          {
                    while(pivot>arr[down] && down<=up)
                    {
                        down++;
                    }
                    while (pivot<=arr[up] && up>lb)
                    {
                              up--;
                              /* code */
                    }
                    if(down<up)
                    {
                             int temp=arr[down];
                             arr[down]=arr[up];
                             arr[up]=temp;
                    }
                    
                    /* code */
          } while (down<up);

          arr[lb]=arr[up];
          arr[up]=pivot;

          return up;
          
}

void quickSort(int arr[],int lb,int ub)
{
          int pos;
          if(lb<ub)
          {
                    pos=partition(arr,lb,ub);
                    quickSort(arr,lb,pos-1);
                    quickSort(arr,pos+1,ub);
          }
}
int main()
{
          int i,n;
          printf("Enter the number of elements in the array: ");
          scanf("%d",&n);
          int arr[n];
          for(i=0;i<n;i++)
          {
                    arr[i]=rand()%100;
          }
          clock_t start=clock();
          partition(arr,0,n-1);
          clock_t end=clock();
          double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
          printf("Sorted array: ");
          display(arr,n);
          printf("\nTime taken to sort the array: %f seconds\n",time_taken);
}