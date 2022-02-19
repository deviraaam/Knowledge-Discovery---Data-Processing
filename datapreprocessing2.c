#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,SumKelas,j,i,t,k,rank[100],ranking[5],klasifikasi,kelas,error[100];
    int distance[100];
    int Rank[100];
    int Color[100],Material[100],Classification[100],ClassificationReal;
    int distance1[100];
    float Age[200],Sexx[200],Steroid[200],Antivirals[200],Fatique[200],Malaise[200],Arexia[200],Big[200],Firm[200],Spleen[200],Speid[200],Ascit[200],Varices[200],Sex[200],Bilir[200],
    Alk[200],Sgot[200],Albumin[200],Protime[200],Histology[200],Class[200],totalerror;

    freopen("inputdua.txt","r",stdin);//if You want to notepad , with name input.txt

    // printf(“Color Rank Classification\n”);

    //scanf("%d", &n);
    for( int i = 1 ; i <=80; i++ )
    {
        scanf("%f", &Age[i]);
        scanf("%f", &Sexx[i]);
        scanf("%f", &Steroid[i]);
        scanf("%f", &Antivirals[i]);
        scanf("%f", &Fatique[i]);
        scanf("%f", &Malaise[i]);
        scanf("%f", &Arexia[i]);
        scanf("%f", &Big[i]);
        scanf("%f", &Firm[i]);
        scanf("%f", &Spleen[i]);
        scanf("%f", &Speid[i]);
        scanf("%f", &Ascit[i]);
        scanf("%f", &Varices[i]);
        scanf("%f", &Bilir[i]);
        scanf("%f", &Alk[i]);
        scanf("%f", &Sgot[i]);
        scanf("%f", &Albumin[i]);
        scanf("%f", &Protime[i]);
        scanf("%f", &Histology[i]);
        scanf("%f", &Class[i]);
    }
    //printf("%f\n\n\n",Steroid[2]);

    //////////////////////////////////////////////////
    //for(int loop=1; loop<=15; loop++)
    //{

            printf("---------------------------------------------------\n");
            printf(" \ndistance\n");
            for(int j = 1 ; j<=80 ; j++) //80 testing
            {
                printf("testing ke-%d\n",j);
                for(i=1; i<=80; i++) //80 data supervised
                {
                    distance[i]= (Age[i]-Age[j])*(Age[i]-Age[j]) + (Sexx[i]-Sexx[j])*(Sexx[i]-Sexx[j]) + (Steroid[i]-Steroid[j])*(Steroid[i]-Steroid[j]) +
                                (Antivirals[i]-Antivirals[j])*(Antivirals[i]-Antivirals[j]) + (Fatique[i]-Fatique[j])*(Fatique[i]-Fatique[j]) + (Malaise[i]-Malaise[j])*(Malaise[i]-Malaise[j]) +
                                (Arexia[i]-Arexia[j])*(Arexia[i]-Arexia[j]) + (Big[i]-Big[j])*(Big[i]-Big[j]) + (Firm[i]-Firm[j])*(Firm[i]-Firm[j]) +
                                (Spleen[i]-Spleen[j])*(Spleen[i]-Spleen[j]) + (Speid[i]-Speid[j])*(Speid[i]-Speid[j]) + (Ascit[i]-Ascit[j])*(Ascit[i]-Ascit[j]) +
                                (Varices[i]-Varices[j])*(Varices[i]-Varices[j]) + (Bilir[i]-Bilir[j])*(Bilir[i]-Bilir[j]) + (Alk[i]-Alk[j])*(Alk[i]-Alk[j]) +
                                (Sgot[i]-Sgot[j])*(Sgot[i]-Sgot[j]) + (Albumin[i]-Albumin[j])*(Albumin[i]-Albumin[j]) + (Protime[i]-Protime[j])*(Protime[i]-Protime[j]) +
                                (Histology[i]-Histology[j])*(Histology[i]-Histology[j]);
                    distance1[i] = distance[i];
                    //printf("distance[%d] = %d\n",i,distance[i]);
                }
                printf("\n");

                for(i=1; i<=80; i++)
                {
                    rank[i]=1;
                    for(k=1; k<=80; k++)
                    {
                        if(distance[i]>distance[k])
                        {
                            rank[i]++;
                        }
                    }
                }
                printf("Nilai Ujian\t Rangking\n");

                for(i=1; i<=80; i++)
                {
                     printf("%d\t\t %d\n",distance[i], rank[i]);
                     if(rank[i]==1) //knn dengan k=3
                     {
                         ranking[1]=Class[i];
                     }
                     else if(rank[i]==2)
                     {
                         ranking[2]=Class[i];
                     }
                     else if(rank[i]==3)
                     {
                         ranking[3]=Class[i];
                     }
                }

                klasifikasi=ranking[1]+ranking[2]+ranking[3];
                printf("klasifikasi = %d\n",klasifikasi);
                if(klasifikasi>=2)
                {
                    kelas=1;
                    printf("LIVE\n");
                    //printf("Class[%d] = %f\n",j,Class[j]);
                    if(Class[j]==kelas)
                    {
                        error[j]=0;

                    }
                    else
                    {
                        error[j]=1;
                    }
                }
                else
                {   kelas=0;
                    printf("DIE\n");
                    //printf("Class[%d] = %f\n",j,Class[j]);
                    if(Class[j]==kelas)
                    {
                        error[j]=0;
                    }
                    else
                    {
                        error[j]=1;
                    }
                }
            printf("class learning ke-%d= %f\n",j,Class[j]);
            printf("error testing ke-%d= %d\n",j,error[j]);
            printf("----------------------------------------------------------------------------------\n");
            }
            totalerror=0;
            for(i=1; i<=80; i++)
            {
                totalerror=totalerror + error[i];
            }
            printf("Error semua data = %f\n",totalerror);
            totalerror=(totalerror/80)*100;
            printf("total error = %f\n",totalerror);

    }

