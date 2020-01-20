/*
Author: @ShiroKlein

Program: Simple DC Circuit Solver

For Fun
*/

#include<stdio.h>
#include<math.h>

void Welcome(void);



int main(){

int type1;
double voltage, Resistence;
double Current;
double Capacitence,time1,CapacitorVoltage;
Welcome();

scanf("%d",&type1);




    switch (type1)
    {
    case 1:
        printf("    ------------\n");
        printf("    |          4\n");
        printf(" V ---         4  R \n");
        printf("    -          4\n");
        printf("    |----------|\n\n");
        printf("Enter the Voltage Source value (V) : \n");
        scanf("%lf",&voltage);
        printf("Enter Resistence value (R) : \n");
        scanf("%lf",&Resistence);
        
        Current = voltage/Resistence;

        printf("The Output Voltage = %lf V, The Output Current = %lf A",voltage,Current);
        break;
    
    case 2:
        printf("      R1   R2  ");
        printf("    -444--444----------     ---|\n");
        printf("    |                          4\n");
        printf(" V ---                  ....   4  Rn \n");
        printf("    -                          4\n");
        printf("    |-------------------    ---|\n\n");
        int i;
        double sum=0;
        printf("Enter the Voltage Source value (V) : \n");
        scanf("%lf",&voltage);
        printf("Enter the number of Resistors in Series: \n");
        scanf("%d",&i);
       
        for(int j=0 ; j<i ;j++ ){
            printf("Enter R%d :\n",j+1);
           scanf("%lf",&Resistence);
            sum= sum + Resistence;
        }

        Current = voltage/sum;
         printf("The Output Voltage = %lf V, The Output Current = %lf A",voltage,Current);

        break;

    case 3:
        printf("    -----------|----------|\n");
        printf("    |          4          4    \n");
        printf(" V ---         4  R  ...  4  Rn \n");
        printf("    -          4          4     \n");
        printf("    |----------|----------|\n\n");
        int k;
        double sum1;
        printf("Enter the Voltage Source value (V) : \n");
        scanf("%lf",&voltage);
        printf("Enter the number of Resistors in parallel: \n");
        scanf("%d",&k);
       
        for(int j=0 ; j<k ;j++ ){
            printf("Enter R%d :\n",j+1);
            scanf("%lf",&Resistence);
            sum1= sum1 + 1/Resistence;
            double Current1= 1/Resistence * voltage;
            printf("The current on that R%d = %lf A\n",j,Current1);
        }

         Current = voltage*sum1;
         printf("The Output Voltage = %lf V, The total Output Current at R1 = %lf A\n",voltage,Current);
        break;
    case 4:
        
        printf("           R     \n");
        printf("    -----4444--|\n");
        printf("    |         ---\n");
        printf(" V ---             C \n");
        printf("    -         ---\n");
        printf("    |----------|\n\n");
        printf("Enter the Voltage Source value (V) : \n");
        scanf("%lf",&voltage); 
        printf("Enter Resistence value (R) : \n");
        scanf("%lf",&Resistence);
        printf("Enter Capacitence value (C) : \n");
        scanf("%lf ",&Capacitence);
        printf("Enter the time of charging in (s): \n");
        scanf("%lf",&time1);

        CapacitorVoltage = voltage - voltage*exp(- time1/(Resistence * Capacitence));
        Current = Capacitence* voltage/time1;
        printf("%lf of time will charge for a :\n",time1);
        printf("CapacitorVoltage = %lf V \n ",CapacitorVoltage);
        printf("Current = %lf A",Current);



        
    default:
        break;
    }





return 0;
}





void Welcome(void){

    printf("Welcome to Simple Circuit Sovler By Shiro Klein\n\n");
    printf("-------------------------------------------------------\n");
    printf("Choose the type of circuit that you want to solve:\n");
    printf("1- Only series 1 Resistence (R) cirucit. \n");
    printf("2- Series of Rs Cirucit with a Voltage Source.\n");
    printf("3- Parallel circuit. \n");
    printf("4- RC circuit solver. \n");
    printf("-------------------------------------------------------\n");


}
