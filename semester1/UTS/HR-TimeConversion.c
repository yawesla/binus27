/**
Given a time in -hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

Example


Return '12:01:00'.


Return '00:01:00'.

Function Description

Complete the timeConversion function in the editor below. It should return a new string representing the input time in 24 hour format.

timeConversion has the following parameter(s):

string s: a time in  hour format
Returns

string: the time in  hour format
Input Format

A single string  that represents a time in -hour clock format (i.e.:  or ).

Constraints

All input times are valid
Sample Input 0

07:05:45PM
Sample Output 0

19:05:45
*/

#include <stdio.h>
#include <string.h>

int main() {

  // Mendeklarasikan variabel
  char s[10];
  int hour, minute, second;

  // Membaca input
  scanf("%s", &s);

  // Mengambil nilai jam, menit, dan detik
  hour = (s[0] - '0') * 10 + (s[1] - '0');
  minute = (s[3] - '0') * 10 + (s[4] - '0');
  second = (s[6] - '0') * 10 + (s[7] - '0');

  // Mengubah waktu ke format 24 jam
  if (strcmp(s + 8, "PM") == 0 && hour != 12) {
    hour += 12;
  }

  // Mencetak output
  printf("%02d:%02d:%02d\n", hour, minute, second);

  return 0;
}
