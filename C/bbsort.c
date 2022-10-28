#include<stdio.h>
void main()
{int ar[20],n,i=0,j,temp,swap=0;
 
 printf("\nEnter the number of elements\n");
 scanf("%d",&n);
 printf("\nEnter the elements!\n");
 for(i=0;i<n;i++)
 {scanf("%d",&ar[i]); }

 for(i=0;i<n;i++)
 {for(j=0;j<(n-1)-i;j++)
  {if(ar[j]>ar[j+1])
   {temp=ar[j];
    ar[j]=ar[j+1];
    ar[j+1]=temp; }
  }swap++;}

printf("\n Sorted elements are :-\n");
for(i=0;i<n;i++)
 {printf("%d",ar[i]); }

printf("\n Number of Swaps %d",swap);
}
 
