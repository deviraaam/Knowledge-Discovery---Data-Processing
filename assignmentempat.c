#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,SumKelas,j,i,t,k,rank[200],ranking[5],klasifikasi,kelas,error[200];
    int distance[200];
    int Rank[200];
    int Color[100],Material[100],Classification[100],ClassificationReal;
    int distance1[200];
    float Age[200],Sexx[200],Steroid[200],Antivirals[200],Fatique[200],Malaise[200],Arexia[200],Big[200],Firm[200],Spleen[200],Speid[200],Ascit[200],Varices[200],Sex[200],Bilir[200],
    Alk[200],Sgot[200],Albumin[200],Protime[200],Histology[200],Class[200],totalerror,mean;
    float Aget[200],Sexxt[200],Steroidt[200],Antiviralst[200],Fatiquet[200],Malaiset[200],Arexiat[200],Bigt[200],Firmt[200],Spleent[200],Speidt[200],Ascitt[200],Varicest[200],Sext[200],Bilirt[200],
    Alkt[200],Sgott[200],Albumint[200],Protimet[200],Histologyt[200],Classt[200];
    int newmax=1, newmin=0,min,max;

    freopen("inputassignmenttiga.txt","r",stdin);//if You want to notepad , with name input.txt
    for( int i = 1 ; i <=155; i++ )
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
        //scanf("%f", &Class[i]);
    }

    freopen("inputempattesting.txt","r",stdin);//if You want to notepad , with name input.txt
    for( int i = 1 ; i <=155; i++ )
    {
        scanf("%f", &Aget[i]);
        scanf("%f", &Sexxt[i]);
        scanf("%f", &Steroidt[i]);
        scanf("%f", &Antiviralst[i]);
        scanf("%f", &Fatiquet[i]);
        scanf("%f", &Malaiset[i]);
        scanf("%f", &Arexiat[i]);
        scanf("%f", &Bigt[i]);
        scanf("%f", &Firmt[i]);
        scanf("%f", &Spleent[i]);
        scanf("%f", &Speidt[i]);
        scanf("%f", &Ascitt[i]);
        scanf("%f", &Varicest[i]);
        scanf("%f", &Bilirt[i]);
        scanf("%f", &Alkt[i]);
        scanf("%f", &Sgott[i]);
        scanf("%f", &Albumint[i]);
        scanf("%f", &Protimet[i]);
        scanf("%f", &Histologyt[i]);
        scanf("%f", &Classt[i]);
    }
    //printf("%f",Aget[2]);
/*
    //Data Baru yang sudah diNormalisasi Min-Max(0-1)
    //Data Learning
    for(i=1; i<=155; i++)
    {
        Age[i]=((Age[i]-7)*(newmax-newmin))/((78-7)+newmin);
        Bilir[i]=((Bilir[i]-1)*(newmax-newmin))/((8-1)+newmin);
        Alk[i]=((Alk[i]-26)*(newmax-newmin))/((295-26)+newmin);
        Sgot[i]=((Sgot[i]-14)*(newmax-newmin))/((648-14)+newmin);
        Albumin[i]=((Albumin[i]-3)*(newmax-newmin))/((5-3)+newmin);
        Protime[i]=((Protime[i]-0)*(newmax-newmin))/((100-0)+newmin);
        printf("%d = %f %f %f %f %f %f\n",i,Age[i],Bilir[i],Alk[i],Sgot[i],Albumin[i],Protime[i]);
    }
    //Data Testing
    for(i=1; i<=155; i++)
    {
        Aget[i]=((Aget[i]-7)*(newmax-newmin))/((78-7)+newmin);
        Bilirt[i]=((Bilirt[i]-0)*(newmax-newmin))/((8-0)+newmin);
        Alkt[i]=((Alkt[i]-0)*(newmax-newmin))/((295-0)+newmin);
        Sgott[i]=((Sgott[i]-0)*(newmax-newmin))/((648-0)+newmin);
        Albumint[i]=((Albumint[i]-0)*(newmax-newmin))/((5-0)+newmin);
        Protimet[i]=((Protimet[i]-0)*(newmax-newmin))/((100-0)+newmin);
        printf("%d = %f %f %f %f %f %f\n",i,Aget[i],Bilirt[i],Alkt[i],Sgott[i],Albumint[i],Protimet[i]);
    }
*/
/*
    //Data Baru yang sudah diNormalisasi Z-Score
    //Mencari Mean terlebih dahulu
    float AgeN=0,SexxN=0,SteroidN=0,AntiviralsN=0,FatiqueN=0,MalaiseN=0,ArexiaN=0,BigN=0,FirmN=0,SpleenN=0,SpeidN=0,AscitN=0,
    VaricesN=0,BilirN=0,AlkN=0,SgotN=0,AlbuminN=0,ProtimeN=0,HistologyN=0;
    float SAge=0,SSexx=0,SSteroid=0,SAntivirals=0,SFatique=0,SMalaise=0,SArexia=0,SBig=0,SFirm=0,SSpleen=0,SSpeid=0,SAscit=0,
    SVarices=0,SBilir=0,SAlk=0,SSgot=0,SAlbumin=0,SProtime=0,SHistology=0;
    //Penjumlahan
    for(i=1; i<=155; i++)
    {
        AgeN=AgeN+Age[i];
        SexxN=SexxN+Sexx[i];
        SteroidN=SteroidN+Steroid[i];
        AntiviralsN=AntiviralsN+Antivirals[i];
        FatiqueN=FatiqueN+Fatique[i];
        MalaiseN=MalaiseN+Malaise[i];
        ArexiaN=ArexiaN+Arexia[i];
        BigN=BigN+Big[i];
        FirmN=FirmN+Firm[i];
        SpleenN=SpleenN+Spleen[i];
        SpeidN=SpeidN+Speid[i];
        AscitN=AscitN+Ascit[i];
        VaricesN=VaricesN+Varices[i];
        BilirN=BilirN+Bilir[i];
        AlkN=AlkN+Alk[i];
        SgotN=SgotN+Sgot[i];
        AlbuminN=AlbuminN+Albumin[i];
        ProtimeN=ProtimeN+Protime[i];
        HistologyN=HistologyN+Histology[i];
    }
    //Dibagai banyaknya data yaitu 155 //AgeN.... ini sudah dalam bentuk Mean
        AgeN=AgeN/155;
        SexxN=SexxN/155;
        SteroidN=SteroidN/155;
        AntiviralsN=AntiviralsN/155;
        FatiqueN=FatiqueN/155;
        MalaiseN=MalaiseN/155;
        ArexiaN=ArexiaN/155;
        BigN=BigN/155;
        FirmN=FirmN/155;
        SpleenN=SpleenN/155;
        SpeidN=SpeidN/155;
        AscitN=AscitN/155;
        VaricesN=VaricesN/155;
        BilirN=BilirN/155;
        AlkN=AlkN/155;
        SgotN=SgotN/155;
        AlbuminN=AlbuminN/155;
        ProtimeN=ProtimeN/155;
        HistologyN=HistologyN/155;
        //printf("Age= %f",AgeN);


    //Mencari standar deviasi
    for(i=1; i<=155; i++)
    {
        SAge=SAge+((Age[i]-AgeN)*(Age[i]-AgeN));
        SSexx=SSexx+((Sexx[i]-SexxN)*(Sexx[i]-SexxN));
        SSteroid=SSteroid+((Steroid[i]-SteroidN)*(Steroid[i]-SteroidN));
        SAntivirals=SAntivirals+((Antivirals[i]-AntiviralsN)*(Antivirals[i]-AntiviralsN));
        SFatique=SFatique+((Fatique[i]-FatiqueN)*(Fatique[i]-FatiqueN));
        SMalaise=SMalaise+((Malaise[i]-MalaiseN)*(Malaise[i]-MalaiseN));
        SArexia=SArexia+((Arexia[i]-ArexiaN)*(Arexia[i]-ArexiaN));
        SBig=SBig+((Big[i]-BigN)*(Big[i]-BigN));
        SFirm=SFirm+((Firm[i]-FirmN)*(Firm[i]-FirmN));
        SSpleen=SSpleen+((Spleen[i]-SpleenN)*(Spleen[i]-SpleenN));
        SSpeid=SSpeid+((Speid[i]-SpeidN)*(Speid[i]-SpeidN));
        SAscit=SAscit+((Ascit[i]-AscitN)*(Ascit[i]-AscitN));
        SVarices=SVarices+((Varices[i]-VaricesN)*(Varices[i]-VaricesN));
        SBilir=SBilir+((Bilir[i]-BilirN)*(Bilir[i]-BilirN));
        SAlk=SAlk+((Alk[i]-AlkN)*(Alk[i]-AlkN));
        SSgot=SSgot+((Sgot[i]-SgotN)*(Sgot[i]-SgotN));
        SAlbumin=SAlbumin+((Albumin[i]-AlbuminN)*(Albumin[i]-AlbuminN));
        SProtime=SProtime+((Protime[i]-ProtimeN)*(Protime[i]-ProtimeN));
        SHistology=SHistology+((Histology[i]-HistologyN)*(Histology[i]-HistologyN));
    }
    //SAge... Ini sudah dalam bentuk/nemu Standart deviasinya
    SAge=sqrt(SAge/(155-1));
    SSexx=sqrt(SSexx/(155-1));
    SSteroid=sqrt(SSteroid/(155-1));
    SAntivirals=sqrt(SAntivirals/(155-1));
    SFatique=sqrt(SFatique/(155-1));
    SMalaise=sqrt(SMalaise/(155-1));
    SArexia=sqrt(SArexia/(155-1));
    SBig=sqrt(SBig/(155-1));
    SFirm=sqrt(SFirm/(155-1));
    SSpleen=sqrt(SSpleen/(155-1));
    SSpeid=sqrt(SSpeid/(155-1));
    SAscit=sqrt(SAscit/(155-1));
    SVarices=sqrt(SVarices/(155-1));
    SBilir=sqrt(SBilir/(155-1));
    SAlk=sqrt(SAlk/(155-1));
    SSgot=sqrt(SSgot/(155-1));
    SAlbumin=sqrt(SAlbumin/(155-1));
    SProtime=sqrt(SProtime/(155-1));
    SHistology=sqrt(SHistology/(155-1));


    for(i=1; i<=155; i++)
    {
        Age[i]=(Age[i]-AgeN)/SAge;
        Sexx[i]=(Sexx[i]-SexxN)/SSexx;
        Steroid[i]=(Steroid[i]-SteroidN)/SSteroid;
        Antivirals[i]=(Antivirals[i]-AntiviralsN)/SAntivirals;
        Fatique[i]=(Fatique[i]-FatiqueN)/SFatique;
        Malaise[i]=(Malaise[i]-MalaiseN)/SMalaise;
        Arexia[i]=(Arexia[i]-ArexiaN)/SArexia;
        Big[i]=(Big[i]-BigN)/SBig;
        Firm[i]=(Firm[i]-FirmN)/SFirm;
        Spleen[i]=(Spleen[i]-SpleenN)/SSpleen;
        Speid[i]=(Speid[i]-SpeidN)/SSpeid;
        Ascit[i]=(Ascit[i]-AscitN)/SAscit;
        Varices[i]=(Varices[i]-VaricesN)/SVarices;
        Bilir[i]=(Bilir[i]-BilirN)/SBilir;
        Alk[i]=(Alk[i]-AlkN)/SAlk;
        Sgot[i]=(Sgot[i]-SgotN)/SSgot;
        Albumin[i]=(Albumin[i]-AlbuminN)/SAlbumin;
        Protime[i]=(Protime[i]-ProtimeN)/SProtime;
        Histology[i]=(Histology[i]-HistologyN)/SHistology;
    }

    //Data Testing Z-Score
    float AgeNt=0,SexxNt=0,SteroidNt=0,AntiviralsNt=0,FatiqueNt=0,MalaiseNt=0,ArexiaNt=0,BigNt=0,FirmNt=0,SpleenNt=0,SpeidNt=0,AscitNt=0,
    VaricesNt=0,BilirNt=0,AlkNt=0,SgotNt=0,AlbuminNt=0,ProtimeNt=0,HistologyNt=0;
    float SAget=0,SSexxt=0,SSteroidt=0,SAntiviralst=0,SFatiquet=0,SMalaiset=0,SArexiat=0,SBigt=0,SFirmt=0,SSpleent=0,SSpeidt=0,SAscitt=0,
    SVaricest=0,SBilirt=0,SAlkt=0,SSgott=0,SAlbumint=0,SProtimet=0,SHistologyt=0;
    //Penjumlahan
    for(i=1; i<=155; i++)
    {
        AgeNt=AgeNt+Aget[i];
        SexxNt=SexxNt+Sexxt[i];
        SteroidNt=SteroidNt+Steroidt[i];
        AntiviralsNt=AntiviralsNt+Antiviralst[i];
        FatiqueNt=FatiqueNt+Fatiquet[i];
        MalaiseNt=MalaiseNt+Malaiset[i];
        ArexiaNt=ArexiaNt+Arexiat[i];
        BigNt=BigNt+Bigt[i];
        FirmNt=FirmNt+Firmt[i];
        SpleenNt=SpleenNt+Spleent[i];
        SpeidNt=SpeidNt+Speidt[i];
        AscitNt=AscitNt+Ascitt[i];
        VaricesNt=VaricesNt+Varicest[i];
        BilirNt=BilirNt+Bilirt[i];
        AlkNt=AlkNt+Alkt[i];
        SgotNt=SgotNt+Sgott[i];
        AlbuminNt=AlbuminNt+Albumint[i];
        ProtimeNt=ProtimeNt+Protimet[i];
        HistologyNt=HistologyNt+Histologyt[i];
    }
    //Dibagai banyaknya data yaitu 155 //AgeN.... ini sudah dalam bentuk Mean
        AgeNt=AgeNt/155;
        SexxNt=SexxNt/155;
        SteroidNt=SteroidNt/155;
        AntiviralsNt=AntiviralsNt/155;
        FatiqueNt=FatiqueNt/155;
        MalaiseNt=MalaiseNt/155;
        ArexiaNt=ArexiaNt/155;
        BigNt=BigNt/155;
        FirmNt=FirmNt/155;
        SpleenNt=SpleenNt/155;
        SpeidNt=SpeidNt/155;
        AscitNt=AscitNt/155;
        VaricesNt=VaricesNt/155;
        BilirNt=BilirNt/155;
        AlkNt=AlkNt/155;
        SgotNt=SgotNt/155;
        AlbuminNt=AlbuminNt/155;
        ProtimeNt=ProtimeNt/155;
        HistologyNt=HistologyNt/155;
        //printf("Age= %f",AgeN);


    //Mencari standar deviasi
    for(i=1; i<=155; i++)
    {
        SAget=SAget+((Aget[i]-AgeNt)*(Aget[i]-AgeNt));
        SSexxt=SSexxt+((Sexxt[i]-SexxNt)*(Sexxt[i]-SexxNt));
        SSteroidt=SSteroidt+((Steroidt[i]-SteroidNt)*(Steroidt[i]-SteroidNt));
        SAntiviralst=SAntiviralst+((Antiviralst[i]-AntiviralsNt)*(Antiviralst[i]-AntiviralsNt));
        SFatiquet=SFatiquet+((Fatiquet[i]-FatiqueNt)*(Fatiquet[i]-FatiqueNt));
        SMalaiset=SMalaiset+((Malaiset[i]-MalaiseNt)*(Malaiset[i]-MalaiseNt));
        SArexiat=SArexiat+((Arexiat[i]-ArexiaNt)*(Arexiat[i]-ArexiaNt));
        SBigt=SBigt+((Bigt[i]-BigNt)*(Bigt[i]-BigNt));
        SFirmt=SFirmt+((Firmt[i]-FirmNt)*(Firmt[i]-FirmNt));
        SSpleent=SSpleent+((Spleent[i]-SpleenNt)*(Spleent[i]-SpleenNt));
        SSpeidt=SSpeidt+((Speidt[i]-SpeidNt)*(Speidt[i]-SpeidNt));
        SAscitt=SAscitt+((Ascitt[i]-AscitNt)*(Ascitt[i]-AscitNt));
        SVaricest=SVaricest+((Varicest[i]-VaricesNt)*(Varicest[i]-VaricesNt));
        SBilirt=SBilirt+((Bilirt[i]-BilirNt)*(Bilirt[i]-BilirNt));
        SAlkt=SAlkt+((Alkt[i]-AlkNt)*(Alkt[i]-AlkNt));
        SSgott=SSgott+((Sgott[i]-SgotNt)*(Sgott[i]-SgotNt));
        SAlbumint=SAlbumint+((Albumint[i]-AlbuminNt)*(Albumint[i]-AlbuminNt));
        SProtimet=SProtimet+((Protimet[i]-ProtimeNt)*(Protimet[i]-ProtimeNt));
        SHistologyt=SHistologyt+((Histologyt[i]-HistologyNt)*(Histologyt[i]-HistologyNt));
    }
    //SAge... Ini sudah dalam bentuk/nemu Standart deviasinya
    SAget=sqrt(SAget/(155-1));
    SSexxt=sqrt(SSexxt/(155-1));
    SSteroidt=sqrt(SSteroidt/(155-1));
    SAntiviralst=sqrt(SAntiviralst/(155-1));
    SFatiquet=sqrt(SFatiquet/(155-1));
    SMalaiset=sqrt(SMalaiset/(155-1));
    SArexiat=sqrt(SArexiat/(155-1));
    SBigt=sqrt(SBigt/(155-1));
    SFirmt=sqrt(SFirmt/(155-1));
    SSpleent=sqrt(SSpleent/(155-1));
    SSpeidt=sqrt(SSpeidt/(155-1));
    SAscitt=sqrt(SAscitt/(155-1));
    SVaricest=sqrt(SVaricest/(155-1));
    SBilirt=sqrt(SBilirt/(155-1));
    SAlkt=sqrt(SAlkt/(155-1));
    SSgott=sqrt(SSgott/(155-1));
    SAlbumint=sqrt(SAlbumint/(155-1));
    SProtimet=sqrt(SProtimet/(155-1));
    SHistologyt=sqrt(SHistologyt/(155-1));

    for(i=1; i<=155; i++)
    {
        Aget[i]=(Aget[i]-AgeNt)/SAget;
        Sexxt[i]=(Sexxt[i]-SexxNt)/SSexxt;
        Steroidt[i]=(Steroidt[i]-SteroidNt)/SSteroidt;
        Antiviralst[i]=(Antiviralst[i]-AntiviralsNt)/SAntiviralst;
        Fatiquet[i]=(Fatiquet[i]-FatiqueNt)/SFatiquet;
        Malaiset[i]=(Malaiset[i]-MalaiseNt)/SMalaiset;
        Arexiat[i]=(Arexiat[i]-ArexiaNt)/SArexiat;
        Bigt[i]=(Bigt[i]-BigNt)/SBigt;
        Firmt[i]=(Firmt[i]-FirmNt)/SFirmt;
        Spleent[i]=(Spleent[i]-SpleenNt)/SSpleent;
        Speidt[i]=(Speidt[i]-SpeidNt)/SSpeidt;
        Ascitt[i]=(Ascitt[i]-AscitNt)/SAscitt;
        Varicest[i]=(Varicest[i]-VaricesNt)/SVaricest;
        Bilirt[i]=(Bilirt[i]-BilirNt)/SBilirt;
        Alkt[i]=(Alkt[i]-AlkNt)/SAlkt;
        Sgott[i]=(Sgott[i]-SgotNt)/SSgott;
        Albumint[i]=(Albumint[i]-AlbuminNt)/SAlbumint;
        Protimet[i]=(Protimet[i]-ProtimeNt)/SProtimet;
        Histologyt[i]=(Histologyt[i]-HistologyNt)/SHistologyt;
    }
    for(i=1; i<=155; i++)
    {
        printf("%f", Aget[i]);
        printf("%f", Sexxt[i]);
        printf("%f", Steroidt[i]);
        printff("%f", Antiviralst[i]);
        printf("%f", Fatiquet[i]);
        printf("%f", Malaiset[i]);
        printf("%f", Arexiat[i]);
        printf("%f", Bigt[i]);
        printff("%f", Firmt[i]);
        printf("%f", Spleent[i]);
        printf("%f", Speidt[i]);
        printf("%f", Ascitt[i]);
        printf("%f", Varicest[i]);
        printf("%f", Bilirt[i]);
        printf("%f", Alkt[i]);
        printf("%f", Sgott[i]);
        printf("%f", Albumint[i]);
        printf("%f", Protimet[i]);
        printf("%f", Histologyt[i]);
    }
*/

    //Metode Normalisasi Sigmoidal
    //Datset Learning
        float AgeN=0,SexxN=0,SteroidN=0,AntiviralsN=0,FatiqueN=0,MalaiseN=0,ArexiaN=0,BigN=0,FirmN=0,SpleenN=0,SpeidN=0,AscitN=0,
    VaricesN=0,BilirN=0,AlkN=0,SgotN=0,AlbuminN=0,ProtimeN=0,HistologyN=0;
    float SAge=0,SSexx=0,SSteroid=0,SAntivirals=0,SFatique=0,SMalaise=0,SArexia=0,SBig=0,SFirm=0,SSpleen=0,SSpeid=0,SAscit=0,
    SVarices=0,SBilir=0,SAlk=0,SSgot=0,SAlbumin=0,SProtime=0,SHistology=0;
    //Penjumlahan
    for(i=1; i<=155; i++)
    {
        AgeN=AgeN+Age[i];
        SexxN=SexxN+Sexx[i];
        SteroidN=SteroidN+Steroid[i];
        AntiviralsN=AntiviralsN+Antivirals[i];
        FatiqueN=FatiqueN+Fatique[i];
        MalaiseN=MalaiseN+Malaise[i];
        ArexiaN=ArexiaN+Arexia[i];
        BigN=BigN+Big[i];
        FirmN=FirmN+Firm[i];
        SpleenN=SpleenN+Spleen[i];
        SpeidN=SpeidN+Speid[i];
        AscitN=AscitN+Ascit[i];
        VaricesN=VaricesN+Varices[i];
        BilirN=BilirN+Bilir[i];
        AlkN=AlkN+Alk[i];
        SgotN=SgotN+Sgot[i];
        AlbuminN=AlbuminN+Albumin[i];
        ProtimeN=ProtimeN+Protime[i];
        HistologyN=HistologyN+Histology[i];
    }
        AgeN=AgeN/155;
        SexxN=SexxN/155;
        SteroidN=SteroidN/155;
        AntiviralsN=AntiviralsN/155;
        FatiqueN=FatiqueN/155;
        MalaiseN=MalaiseN/155;
        ArexiaN=ArexiaN/155;
        BigN=BigN/155;
        FirmN=FirmN/155;
        SpleenN=SpleenN/155;
        SpeidN=SpeidN/155;
        AscitN=AscitN/155;
        VaricesN=VaricesN/155;
        BilirN=BilirN/155;
        AlkN=AlkN/155;
        SgotN=SgotN/155;
        AlbuminN=AlbuminN/155;
        ProtimeN=ProtimeN/155;
        HistologyN=HistologyN/155;
        //printf("Age= %f",AgeN);


    //Mencari standar deviasi
    for(i=1; i<=155; i++)
    {
        SAge=SAge+((Age[i]-AgeN)*(Age[i]-AgeN));
        SSexx=SSexx+((Sexx[i]-SexxN)*(Sexx[i]-SexxN));
        SSteroid=SSteroid+((Steroid[i]-SteroidN)*(Steroid[i]-SteroidN));
        SAntivirals=SAntivirals+((Antivirals[i]-AntiviralsN)*(Antivirals[i]-AntiviralsN));
        SFatique=SFatique+((Fatique[i]-FatiqueN)*(Fatique[i]-FatiqueN));
        SMalaise=SMalaise+((Malaise[i]-MalaiseN)*(Malaise[i]-MalaiseN));
        SArexia=SArexia+((Arexia[i]-ArexiaN)*(Arexia[i]-ArexiaN));
        SBig=SBig+((Big[i]-BigN)*(Big[i]-BigN));
        SFirm=SFirm+((Firm[i]-FirmN)*(Firm[i]-FirmN));
        SSpleen=SSpleen+((Spleen[i]-SpleenN)*(Spleen[i]-SpleenN));
        SSpeid=SSpeid+((Speid[i]-SpeidN)*(Speid[i]-SpeidN));
        SAscit=SAscit+((Ascit[i]-AscitN)*(Ascit[i]-AscitN));
        SVarices=SVarices+((Varices[i]-VaricesN)*(Varices[i]-VaricesN));
        SBilir=SBilir+((Bilir[i]-BilirN)*(Bilir[i]-BilirN));
        SAlk=SAlk+((Alk[i]-AlkN)*(Alk[i]-AlkN));
        SSgot=SSgot+((Sgot[i]-SgotN)*(Sgot[i]-SgotN));
        SAlbumin=SAlbumin+((Albumin[i]-AlbuminN)*(Albumin[i]-AlbuminN));
        SProtime=SProtime+((Protime[i]-ProtimeN)*(Protime[i]-ProtimeN));
        SHistology=SHistology+((Histology[i]-HistologyN)*(Histology[i]-HistologyN));
    }
    //SAge... Ini sudah dalam bentuk/nemu Standart deviasinya
    SAge=sqrt(SAge/(155-1));
    SSexx=sqrt(SSexx/(155-1));
    SSteroid=sqrt(SSteroid/(155-1));
    SAntivirals=sqrt(SAntivirals/(155-1));
    SFatique=sqrt(SFatique/(155-1));
    SMalaise=sqrt(SMalaise/(155-1));
    SArexia=sqrt(SArexia/(155-1));
    SBig=sqrt(SBig/(155-1));
    SFirm=sqrt(SFirm/(155-1));
    SSpleen=sqrt(SSpleen/(155-1));
    SSpeid=sqrt(SSpeid/(155-1));
    SAscit=sqrt(SAscit/(155-1));
    SVarices=sqrt(SVarices/(155-1));
    SBilir=sqrt(SBilir/(155-1));
    SAlk=sqrt(SAlk/(155-1));
    SSgot=sqrt(SSgot/(155-1));
    SAlbumin=sqrt(SAlbumin/(155-1));
    SProtime=sqrt(SProtime/(155-1));
    SHistology=sqrt(SHistology/(155-1));


    for(i=1; i<=155; i++)
    {
        Age[i]=(Age[i]-AgeN)/SAge;
        Sexx[i]=(Sexx[i]-SexxN)/SSexx;
        Steroid[i]=(Steroid[i]-SteroidN)/SSteroid;
        Antivirals[i]=(Antivirals[i]-AntiviralsN)/SAntivirals;
        Fatique[i]=(Fatique[i]-FatiqueN)/SFatique;
        Malaise[i]=(Malaise[i]-MalaiseN)/SMalaise;
        Arexia[i]=(Arexia[i]-ArexiaN)/SArexia;
        Big[i]=(Big[i]-BigN)/SBig;
        Firm[i]=(Firm[i]-FirmN)/SFirm;
        Spleen[i]=(Spleen[i]-SpleenN)/SSpleen;
        Speid[i]=(Speid[i]-SpeidN)/SSpeid;
        Ascit[i]=(Ascit[i]-AscitN)/SAscit;
        Varices[i]=(Varices[i]-VaricesN)/SVarices;
        Bilir[i]=(Bilir[i]-BilirN)/SBilir;
        Alk[i]=(Alk[i]-AlkN)/SAlk;
        Sgot[i]=(Sgot[i]-SgotN)/SSgot;
        Albumin[i]=(Albumin[i]-AlbuminN)/SAlbumin;
        Protime[i]=(Protime[i]-ProtimeN)/SProtime;
        Histology[i]=(Histology[i]-HistologyN)/SHistology;
    }
    for(i=1; i<=155; i++)
    {
        Age[i]=(1-exp(-Age[i]))/(1+exp(-Age[i]));
        Sexx[i]=(1-exp(-Sexx[i]))/(1+exp(-Sexx[i]));
        Steroid[i]=(1-exp(-Steroid[i]))/(1+exp(-Steroid[i]));
        Antivirals[i]=(1-exp(-Antivirals[i]))/(1+exp(-Antivirals[i]));
        Fatique[i]=(1-exp(-Fatique[i]))/(1+exp(-Fatique[i]));
        Malaise[i]=(1-exp(-Malaise[i]))/(1+exp(-Malaise[i]));
        Arexia[i]=(1-exp(-Arexia[i]))/(1+exp(-Arexia[i]));
        Big[i]=(1-exp(-Big[i]))/(1+exp(-Big[i]));
        Firm[i]=(1-exp(-Firm[i]))/(1+exp(-Firm[i]));
        Spleen[i]=(1-exp(-Spleen[i]))/(1+exp(-Spleen[i]));
        Speid[i]=(1-exp(-Speid[i]))/(1+exp(-Speid[i]));
        Ascit[i]=(1-exp(-Ascit[i]))/(1+exp(-Ascit[i]));
        Varices[i]=(1-exp(-Varices[i]))/(1+exp(-Varices[i]));
        Bilir[i]=(1-exp(-Bilir[i]))/(1+exp(-Bilir[i]));
        Alk[i]=(1-exp(-Alk[i]))/(1+exp(-Alk[i]));
        Sgot[i]=(1-exp(-Sgot[i]))/(1+exp(-Sgot[i]));
        Albumin[i]=(1-exp(-Albumin[i]))/(1+exp(-Albumin[i]));
        Protime[i]=(1-exp(-Protime[i]))/(1+exp(-Protime[i]));
        Histology[i]=(1-exp(-Histology[i]))/(1+exp(-Histology[i]));
    }

    //Data Testing
  float AgeNt=0,SexxNt=0,SteroidNt=0,AntiviralsNt=0,FatiqueNt=0,MalaiseNt=0,ArexiaNt=0,BigNt=0,FirmNt=0,SpleenNt=0,SpeidNt=0,AscitNt=0,
    VaricesNt=0,BilirNt=0,AlkNt=0,SgotNt=0,AlbuminNt=0,ProtimeNt=0,HistologyNt=0;
    float SAget=0,SSexxt=0,SSteroidt=0,SAntiviralst=0,SFatiquet=0,SMalaiset=0,SArexiat=0,SBigt=0,SFirmt=0,SSpleent=0,SSpeidt=0,SAscitt=0,
    SVaricest=0,SBilirt=0,SAlkt=0,SSgott=0,SAlbumint=0,SProtimet=0,SHistologyt=0;
    //Penjumlahan
    for(i=1; i<=155; i++)
    {
        AgeNt=AgeNt+Aget[i];
        SexxNt=SexxNt+Sexxt[i];
        SteroidNt=SteroidNt+Steroidt[i];
        AntiviralsNt=AntiviralsNt+Antiviralst[i];
        FatiqueNt=FatiqueNt+Fatiquet[i];
        MalaiseNt=MalaiseNt+Malaiset[i];
        ArexiaNt=ArexiaNt+Arexiat[i];
        BigNt=BigNt+Bigt[i];
        FirmNt=FirmNt+Firmt[i];
        SpleenNt=SpleenNt+Spleent[i];
        SpeidNt=SpeidNt+Speidt[i];
        AscitNt=AscitNt+Ascitt[i];
        VaricesNt=VaricesNt+Varicest[i];
        BilirNt=BilirNt+Bilirt[i];
        AlkNt=AlkNt+Alkt[i];
        SgotNt=SgotNt+Sgott[i];
        AlbuminNt=AlbuminNt+Albumint[i];
        ProtimeNt=ProtimeNt+Protimet[i];
        HistologyNt=HistologyNt+Histologyt[i];
    }
    //Dibagai banyaknya data yaitu 155 //AgeN.... ini sudah dalam bentuk Mean
        AgeNt=AgeNt/155;
        SexxNt=SexxNt/155;
        SteroidNt=SteroidNt/155;
        AntiviralsNt=AntiviralsNt/155;
        FatiqueNt=FatiqueNt/155;
        MalaiseNt=MalaiseNt/155;
        ArexiaNt=ArexiaNt/155;
        BigNt=BigNt/155;
        FirmNt=FirmNt/155;
        SpleenNt=SpleenNt/155;
        SpeidNt=SpeidNt/155;
        AscitNt=AscitNt/155;
        VaricesNt=VaricesNt/155;
        BilirNt=BilirNt/155;
        AlkNt=AlkNt/155;
        SgotNt=SgotNt/155;
        AlbuminNt=AlbuminNt/155;
        ProtimeNt=ProtimeNt/155;
        HistologyNt=HistologyNt/155;
        //printf("Age= %f",AgeN);


    //Mencari standar deviasi
    for(i=1; i<=155; i++)
    {
        SAget=SAget+((Aget[i]-AgeNt)*(Aget[i]-AgeNt));
        SSexxt=SSexxt+((Sexxt[i]-SexxNt)*(Sexxt[i]-SexxNt));
        SSteroidt=SSteroidt+((Steroidt[i]-SteroidNt)*(Steroidt[i]-SteroidNt));
        SAntiviralst=SAntiviralst+((Antiviralst[i]-AntiviralsNt)*(Antiviralst[i]-AntiviralsNt));
        SFatiquet=SFatiquet+((Fatiquet[i]-FatiqueNt)*(Fatiquet[i]-FatiqueNt));
        SMalaiset=SMalaiset+((Malaiset[i]-MalaiseNt)*(Malaiset[i]-MalaiseNt));
        SArexiat=SArexiat+((Arexiat[i]-ArexiaNt)*(Arexiat[i]-ArexiaNt));
        SBigt=SBigt+((Bigt[i]-BigNt)*(Bigt[i]-BigNt));
        SFirmt=SFirmt+((Firmt[i]-FirmNt)*(Firmt[i]-FirmNt));
        SSpleent=SSpleent+((Spleent[i]-SpleenNt)*(Spleent[i]-SpleenNt));
        SSpeidt=SSpeidt+((Speidt[i]-SpeidNt)*(Speidt[i]-SpeidNt));
        SAscitt=SAscitt+((Ascitt[i]-AscitNt)*(Ascitt[i]-AscitNt));
        SVaricest=SVaricest+((Varicest[i]-VaricesNt)*(Varicest[i]-VaricesNt));
        SBilirt=SBilirt+((Bilirt[i]-BilirNt)*(Bilirt[i]-BilirNt));
        SAlkt=SAlkt+((Alkt[i]-AlkNt)*(Alkt[i]-AlkNt));
        SSgott=SSgott+((Sgott[i]-SgotNt)*(Sgott[i]-SgotNt));
        SAlbumint=SAlbumint+((Albumint[i]-AlbuminNt)*(Albumint[i]-AlbuminNt));
        SProtimet=SProtimet+((Protimet[i]-ProtimeNt)*(Protimet[i]-ProtimeNt));
        SHistologyt=SHistologyt+((Histologyt[i]-HistologyNt)*(Histologyt[i]-HistologyNt));
    }
    //SAge... Ini sudah dalam bentuk/nemu Standart deviasinya
    SAget=sqrt(SAget/(155-1));
    SSexxt=sqrt(SSexxt/(155-1));
    SSteroidt=sqrt(SSteroidt/(155-1));
    SAntiviralst=sqrt(SAntiviralst/(155-1));
    SFatiquet=sqrt(SFatiquet/(155-1));
    SMalaiset=sqrt(SMalaiset/(155-1));
    SArexiat=sqrt(SArexiat/(155-1));
    SBigt=sqrt(SBigt/(155-1));
    SFirmt=sqrt(SFirmt/(155-1));
    SSpleent=sqrt(SSpleent/(155-1));
    SSpeidt=sqrt(SSpeidt/(155-1));
    SAscitt=sqrt(SAscitt/(155-1));
    SVaricest=sqrt(SVaricest/(155-1));
    SBilirt=sqrt(SBilirt/(155-1));
    SAlkt=sqrt(SAlkt/(155-1));
    SSgott=sqrt(SSgott/(155-1));
    SAlbumint=sqrt(SAlbumint/(155-1));
    SProtimet=sqrt(SProtimet/(155-1));
    SHistologyt=sqrt(SHistologyt/(155-1));

    for(i=1; i<=155; i++)
    {
        Aget[i]=(Aget[i]-AgeNt)/SAget;
        Sexxt[i]=(Sexxt[i]-SexxNt)/SSexxt;
        Steroidt[i]=(Steroidt[i]-SteroidNt)/SSteroidt;
        Antiviralst[i]=(Antiviralst[i]-AntiviralsNt)/SAntiviralst;
        Fatiquet[i]=(Fatiquet[i]-FatiqueNt)/SFatiquet;
        Malaiset[i]=(Malaiset[i]-MalaiseNt)/SMalaiset;
        Arexiat[i]=(Arexiat[i]-ArexiaNt)/SArexiat;
        Bigt[i]=(Bigt[i]-BigNt)/SBigt;
        Firmt[i]=(Firmt[i]-FirmNt)/SFirmt;
        Spleent[i]=(Spleent[i]-SpleenNt)/SSpleent;
        Speidt[i]=(Speidt[i]-SpeidNt)/SSpeidt;
        Ascitt[i]=(Ascitt[i]-AscitNt)/SAscitt;
        Varicest[i]=(Varicest[i]-VaricesNt)/SVaricest;
        Bilirt[i]=(Bilirt[i]-BilirNt)/SBilirt;
        Alkt[i]=(Alkt[i]-AlkNt)/SAlkt;
        Sgott[i]=(Sgott[i]-SgotNt)/SSgott;
        Albumint[i]=(Albumint[i]-AlbuminNt)/SAlbumint;
        Protimet[i]=(Protimet[i]-ProtimeNt)/SProtimet;
        Histologyt[i]=(Histologyt[i]-HistologyNt)/SHistologyt;
    }

    for(i=1; i<=155; i++)
    {
        Aget[i]=(1-exp(-Aget[i]))/(1+exp(-Aget[i]));
        Sexxt[i]=(1-exp(-Sexxt[i]))/(1+exp(-Sexxt[i]));
        Steroidt[i]=(1-exp(-Steroidt[i]))/(1+exp(-Steroidt[i]));
        Antiviralst[i]=(1-exp(-Antiviralst[i]))/(1+exp(-Antiviralst[i]));
        Fatiquet[i]=(1-exp(-Fatiquet[i]))/(1+exp(-Fatiquet[i]));
        Malaiset[i]=(1-exp(-Malaiset[i]))/(1+exp(-Malaiset[i]));
        Arexiat[i]=(1-exp(-Arexiat[i]))/(1+exp(-Arexiat[i]));
        Bigt[i]=(1-exp(-Bigt[i]))/(1+exp(-Bigt[i]));
        Firmt[i]=(1-exp(-Firmt[i]))/(1+exp(-Firmt[i]));
        Spleent[i]=(1-exp(-Spleent[i]))/(1+exp(-Spleent[i]));
        Speidt[i]=(1-exp(-Speidt[i]))/(1+exp(-Speidt[i]));
        Ascitt[i]=(1-exp(-Ascitt[i]))/(1+exp(-Ascitt[i]));
        Varicest[i]=(1-exp(-Varicest[i]))/(1+exp(-Varicest[i]));
        Bilirt[i]=(1-exp(-Bilirt[i]))/(1+exp(-Bilirt[i]));
        Alkt[i]=(1-exp(-Alkt[i]))/(1+exp(-Alkt[i]));
        Sgott[i]=(1-exp(-Sgott[i]))/(1+exp(-Sgott[i]));
        Albumint[i]=(1-exp(-Albumint[i]))/(1+exp(-Albumint[i]));
        Protimet[i]=(1-exp(-Protimet[i]))/(1+exp(-Protimet[i]));
        Histologyt[i]=(1-exp(-Histologyt[i]))/(1+exp(-Histologyt[i]));
    }

/*
    mean=0;
    for(i=1;i<=155;i++)
    {
        if(Class[i]==1)
        {
            mean=mean+Arexia[i];
        }
    }
    mean=mean/122;
    printf("%f",mean);
*/
    //printf("%f\n\n\n",Class[2]);





    //////////////////////////////////////////////////
    //for(int loop=1; loop<=15; loop++)
    //{

            printf("---------------------------------------------------\n");
            printf(" \ndistance\n");
            for(int j = 1 ; j<=155 ; j++) //80 testing
            {
                printf("testing ke-%d\n",j);
                for(i=1; i<=155; i++) //80 data supervised
                {
                    distance[i]= (Age[i]-Aget[j])*(Age[i]-Aget[j]) + (Sexx[i]-Sexxt[j])*(Sexx[i]-Sexxt[j]) + (Steroid[i]-Steroidt[j])*(Steroid[i]-Steroidt[j]) +
                                (Antivirals[i]-Antiviralst[j])*(Antivirals[i]-Antiviralst[j]) + (Fatique[i]-Fatiquet[j])*(Fatique[i]-Fatiquet[j]) + (Malaise[i]-Malaiset[j])*(Malaise[i]-Malaiset[j]) +
                                (Arexia[i]-Arexiat[j])*(Arexia[i]-Arexiat[j]) + (Big[i]-Bigt[j])*(Big[i]-Bigt[j]) + (Firm[i]-Firmt[j])*(Firm[i]-Firmt[j]) +
                                (Spleen[i]-Spleent[j])*(Spleen[i]-Spleent[j]) + (Speid[i]-Speidt[j])*(Speid[i]-Speidt[j]) + (Ascit[i]-Ascitt[j])*(Ascit[i]-Ascitt[j]) +
                                (Varices[i]-Varicest[j])*(Varices[i]-Varicest[j]) + (Bilir[i]-Bilirt[j])*(Bilir[i]-Bilirt[j]) + (Alk[i]-Alkt[j])*(Alk[i]-Alkt[j]) +
                                (Sgot[i]-Sgott[j])*(Sgot[i]-Sgott[j]) + (Albumin[i]-Albumint[j])*(Albumin[i]-Albumint[j]) + (Protime[i]-Protimet[j])*(Protime[i]-Protimet[j]) +
                                (Histology[i]-Histologyt[j])*(Histology[i]-Histologyt[j]);
                    distance1[i] = distance[i];
                    //printf("distance[%d] = %d\n",i,distance[i]);
                }
                printf("\n");

                for(i=1; i<=155; i++)
                {
                    rank[i]=1;
                    for(k=1; k<=155; k++)
                    {
                        if(distance[i]>distance[k])
                        {
                            rank[i]++;
                        }
                    }
                }
                //printf("Nilai Ujian\t Rangking\n");

                for(i=1; i<=155; i++)
                {
                     //printf("%d\t\t %d\n",distance[i], rank[i]);
                     if(rank[i]==1) //knn dengan k=3
                     {
                         ranking[1]=Classt[i];
                     }
                     else if(rank[i]==2)
                     {
                         ranking[2]=Classt[i];
                     }
                     else if(rank[i]==3)
                     {
                         ranking[3]=Classt[i];
                     }
                }

                klasifikasi=ranking[1]+ranking[2]+ranking[3];
                printf("klasifikasi = %d\n",klasifikasi);
                if(klasifikasi>=2)
                {
                    kelas=1;
                    printf("LIVE\n");
                    printf("Class[%d] = %f\n",j,Classt[j]);
                    if(Classt[j]==kelas)
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
                    printf("Class[%d] = %f\n",j,Classt[j]);
                    if(Classt[j]==kelas)
                    {
                        error[j]=0;
                    }
                    else
                    {
                        error[j]=1;
                    }
                }
            printf("class learning ke-%d= %f\n",j,Classt[j]);
            printf("error testing ke-%d= %d\n",j,error[j]);
            printf("----------------------------------------------------------------------------------\n");
            }
            totalerror=0;
            for(i=1; i<=155; i++)
            {
                totalerror=totalerror + error[i];
            }
            printf("Error semua data = %f\n",totalerror);
            totalerror=(totalerror/155)*100;
            printf("total error = %f\n",totalerror);

    }

