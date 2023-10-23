// #include <stdio.h>
// #include <math.h>

// int main() {
//   int hour, minute;
//   scanf("%d %d", &hour, &minute);

//   double h = (hour % 12 * 30) + (minute / 60 * 30);
//   double m = minute * 6;

//   double angle = abs(h - m);

//   if (angle > 180) {
//     angle = 360.0 - angle;
//   }

//   printf("Angle between hour and minute hand: %.2f degrees\n", angle);

//   return 0;
// }

//impove
// #include <stdio.h>
// #include <math.h>

// int main() {
//   int hour, minute,test_case;
//   scanf("%d", &test_case);

//   for(int i=0;i<test_case;i++){

//   scanf("%d %d", &hour, &minute);

//   double h = (hour % 12 * 30) + (minute / 60 * 30);
//   double m = minute * 6;

//   double angle = abs(h - m);

//   if (angle > 180) {
//     angle = 360.0 - angle;
//   }

//   printf("Angle between hour and minute hand: %.2f degrees\n", angle);
//   }

  

//   return 0;
// }



//onlingdb
#include <stdio.h>
#include <stdlib.h>


int main() {
  int hour, minute,test_case;
  scanf("%d %d", &hour, &minute);

  double h = (hour % 12 * 30) + (minute / 60 * 30);
  double m = minute * 6;

  double angle = abs(h - m);

  if (angle > 180) {
    angle = 360.0 - angle;
  }

  printf("Angle between hour and minute hand: %.2f degrees\n", angle);


  return 0;
}
