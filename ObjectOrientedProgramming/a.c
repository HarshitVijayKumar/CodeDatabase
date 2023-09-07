#include<stdio.h>
#include<string.h>

void main()
{
    // sort the names alphabetical order
    char a[20][20];
    char t[20];
    int n,i,j;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    //Reading an array
    for(i=0;i<n;i++)
    {
        printf("Enter %d number: ",i+1);
        scanf("%s",a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if ((int)a[i][0]>(int)a[j][0])
            {
                strcpy(t,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],t);
            }
        }
    }
    //printing an array
    printf("\nArray contents after sorting\t");
    for(i=0;i<n;i++)
    {
    printf("%s\t",a[i]);
    }
}