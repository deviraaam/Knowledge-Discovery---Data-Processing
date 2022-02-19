#include<stdio.h>
#include<math.h>

main(void)
{
    int i,j,k,r;
    float I[200][200],target[200];

    freopen("inputdua.txt","r",stdin);
    //scanf("%d", &z);
    for( int r= 1; r <=80 ; r++)
    {
        for(j=1; j<=19; j++)
        {
            scanf("%f", &I[j][r]);
            printf("I[%d][%d] = %f\n",j,r,I[j][r]);
        }
        scanf("%f",&target[r]);
        printf("Target[%d] = %f\n",r,target[r]);
    }
    //jarak[i] = sqrt(pow((x[i]-xx),2)+pow((y[i]-yy),2));
    for(i=1; i<=80; i++)
    {
        for(j=1; j<=19; j++)
        {
            jarak[i]= sqrt(pow((I[i][j]-x[i][j]),2)+pow((I[i][j]-),2));
        }
    }
}




