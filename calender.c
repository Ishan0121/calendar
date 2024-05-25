#include<stdio.h>
int daynumber(int day,int month,int year){
    int i,cen_val,year_rem;
    static int a[]={0,3,3,6,1,4,6,2,5,0,3,5};
    if((year%400)<100){
        cen_val=6;
    }else if((year%400)<200){
        cen_val=4;
    }else if((year%400)<300){
        cen_val=2;
    }else if((year%400)<400){
        cen_val=0;
    }
    year_rem=year%100;
    return(((year_rem)+(year_rem/4)+day+a[month-1]+cen_val)%7);
}

void printcal(int yr){
    int day[7],dayn,i=0,j,flag=0;
    int month[12];
    month[0]=month[2]=month[4]=month[6]=month[7]=month[9]=month[11]=31;
    month[1]=month[3]=month[5]=month[8]=month[10]=30;
    if((yr%400==0)||((yr%100!=0)&&(yr%4==0))){
        month[1]=29;
        flag=1;
    }else{
        month[1]=28;
    }
    char monthname[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    for(i=0;i<12;i++){
        dayn=daynumber(1,i+1,yr);
        if(flag==1&&i<2){
            dayn--;
        }
        printf("\t--------------%s-------------\n\n",monthname[i]);
        printf("sun\tmon\ttue\twed\tthu\tfri\tsat\n\n");
        for(j=0;j<dayn;j++){
            printf(" \t");
        }
        for(j=1;j<=month[i];j++){
            if(j==1&&dayn==0){
                printf("\033[0;31m");
            }
            printf("%d\t",j);
            printf("\033[0m");
            if((j+dayn)%7==0){
                printf("\n\n");
                printf("\033[0;31m");
            }
        }
        printf("\033[0m");
        printf("\n");
    }
}
int main(){
    int yr;
    printf("Enter the year : ");
    scanf("%d",&yr);
    printcal(yr);
    return 0;
}