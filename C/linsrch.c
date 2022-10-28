#include<stdio.h>
void main()
{int ar[20],n,item,flg=0,i=0;
 
 printf("\nEnter the number of elements\n");
 scanf("%d",&n);
 printf("\nEnter the elements!\n");
 for(i=0;i<n;i++)
 {scanf("%d",&ar[i]); }
 printf("\nEnter the element to be searched for:- \n");
 scanf("%d",&item);

 for(i=0;i<n;i++)
 {if(ar[i]==item)
    {flg=1;}}

 if(flg==1)
 {printf("\n Element found!!\n"); }
 else
 {printf("\n Element not found!!\n"); }

}
