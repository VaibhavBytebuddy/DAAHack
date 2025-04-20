#include<stdio.h>
#include<time.h>

void display(int arr[],int n)
{
          int i;
          for(i=0;i<n;i++)
          {
                    printf("%d ",arr[i]);
          }
}

void selectionSort(int arr[],int n)
{
          int i,j,min,pos,temp;
          for(int i=0;i<n-1;i++)
          {
                    min=arr[i];
                    pos=i;
                    for(j=i+1;j<n;j++)
                    {
                              if(arr[j]<min)
                              {
                                        min=arr[j];
                                        pos=j;
                              }
                    }
                    temp=arr[i];
                    arr[i]=arr[pos];
                    arr[pos]=temp;
          }
}

int main()
{
          int n,i;
          printf("Enter the number of elements in the array: ");
          scanf("%d",&n);
          int arr[n];
          printf("Enter the elements of the array: ");
          for(i=0;i<n;i++)
          {
                    scanf("%d",&arr[i]);
          }

          clock_t  start=clock();
          selectionSort(arr,n);
          clock_t end=clock();

          double time_taken=((double)(end-start))/CLOCKS_PER_SEC;

          printf("Sorted array: ");
          display(arr,n);
          printf("\nTime taken to sort the array: %f seconds\n",time_taken);

}