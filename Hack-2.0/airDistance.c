#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){

    double radius = 6371;
    double latA, latB, longA, longB;
    double airdistance, D;
    printf("Enter longitude and latitude of point A:" );
    scanf("%lf", &latA);
    scanf("%lf", &longA);
    printf("Enter Longitude and Latitude of point B: ");
    scanf("%lf", &latB);
    scanf("%lf", &longB);
    latA = (latA/180)*M_PI;
    latB = (latB/180)*M_PI;
    longA = (longA/180)*M_PI;
    longB = (longB/180)*M_PI;
    D = longB - longA;
    airdistance = acos(sin(latA)*sin(latB)+cos(latA)*cos(latB)*cos(D))*radius;
    printf("Origin: %f, %f\n", latA, longA);
    printf("Destination: %f, %f\n", latB, longB);
    printf("Air Distance is %f\n", airdistance);

    return 0;



}