#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int tc,hh,mm;
    scanf("%d",&tc);
    
    double hdegree = 360/12;
    double mdegree = 360/60;
    for(int i=1;i<=tc;i++){
        scanf("%d %d",&hh,&mm);
        double h = hh * hdegree + (double)mm / 12 * mdegree;
        double m = mm * mdegree;

        double angle;
        if( m > h) angle = m-h;
        else angle = h-m;

    
    if (angle >= 180) {
        angle = 360.0 - angle;
    }
        
        printf("Case #%d: %.01lf\n",i,angle);
    }
    return 0;
}
