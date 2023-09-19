/**
 *
 * Author: Sanskar Sabherwal
 * Date: 17th Sept, 2023
 *
 *  The program computes a monthly savings table detailing
 *  the inflation-adjusted interest earned,
 *  contribution, and new balance for each month
 *
 */



#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
     if(argc != 6) {
        printf("ERROR! Invalid number of arguments\n");
        printf("Input: Initial starting Balance, Monthly contribution, (average) annual rate of return, (average) annual rate of inflation, and number of years until retirement\n");
    } else {
        double startingBalance = atof(argv[1]);
        double monthlyContribution = atof(argv[2]);
        double returnRate = atof(argv[3]);
        double inflationRate = atof(argv[4]);
        double years = atof(argv[5]);


        if(monthlyContribution * 12 >= 18500){
            printf("ERROR: monthly contributions exceed $18,500 annual limit");
            exit(1);
        }
        else if(startingBalance < 0 || monthlyContribution < 0 || returnRate < 0 || inflationRate < 0 || years < 0 || returnRate > 1 || inflationRate > 1){
            printf("ERROR: One or more arguments are invalid ");
            exit(1);
        }


        else {
            double Interest;
            double newBalance;
            int currentMonth;
            double totalInterest;

            double months = years*12;
            double adjustedRate= ((1 + returnRate)/(1 + inflationRate)) - 1;
            double monthlyInflation = adjustedRate/12;
            double InterestOne = startingBalance * monthlyInflation;
            double BalanceOne = startingBalance + monthlyContribution + InterestOne;
            newBalance = BalanceOne;


            printf("Month          Interest         Balance\n");
            printf("    1        $ %.2f          $ %.2f\n",      InterestOne,      BalanceOne );

            for(int i = 1; i < months ; i++){
                 Interest = (newBalance) * monthlyInflation;
                 Interest = round(Interest*100)/100;
                 newBalance = (newBalance + monthlyContribution + Interest);
                 currentMonth = i + 1;

                 printf("    %d", currentMonth);
                 printf("        $%0.2f", Interest);
                 printf("             $%0.2f\n", newBalance);

                 totalInterest = totalInterest + Interest;

            }

            totalInterest = totalInterest + InterestOne;

            printf("Total Interest is: $ %0.2f\n", totalInterest);
            printf("Total Nest Egg: $ %0.2f\n\n", newBalance);

            return 0;

        }


    }
}





