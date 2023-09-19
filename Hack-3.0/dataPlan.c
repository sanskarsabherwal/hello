#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    if(argc != 4) {
        printf("ERROR! Invalid number of arguments\n");
        printf("Input: Days on plan, total GB on plan, total GB used so far\n");
    } else {

        double totalGB = atof(argv[1]);
        int days = atoi(argv[2]);
        double usedGB = atof(argv[3]);

        int remainingData = totalGB - usedGB;
        int remainingDays = 30 - days;
        double expectedUse = totalGB/30;
        double userAvg = usedGB/days;
        double remainingExpectedUsage = (30*userAvg) - totalGB;
        double useStaybelow = (totalGB - usedGB)/remainingDays;


        printf("Days used: %d\n", days);
        printf("Remaining days on plan: %d\n", remainingDays);
        printf("Average daily use: %lf\n", userAvg);

        if(days<0) {
            printf("ERROR");
        }

        if(remainingData < 0) {
            printf("You have already met your limit for this month.  Looks like you're getting some overage charges...");
        }
        if(userAvg>expectedUse) {
            printf("You are EXCEEDING your expected average daily usage (%0.3lf GB/day).\n", expectedUse);
            printf("Continuing this high usage, you'll exceed your data plan by %0.3lf GB.\n",remainingExpectedUsage);
            printf("To stay below your data plan use %0.3lf GB/day. \n", useStaybelow);
        }
        else if(userAvg<expectedUse) {
            printf("You are at or below your average daily use(%0.3lf GB/day).\n", expectedUse);
            printf("You can use up to %0.3lf GB/day and stay below your limit.\n", useStaybelow);
        }



    }

}