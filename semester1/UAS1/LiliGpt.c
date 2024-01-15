#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    char num[101]; // Assuming a maximum of 100 digits plus 1 for null-terminator
    int score;
} list;

int calculateBeauty(const char *number)
{
    int beauty = 0;
    while (*number != '\0')
    {
        beauty += *number - '0'; // Extract the current digit and add to beauty
        number++;               // Move to the next digit
    }
    return beauty;
}

// Bubble sort function to sort the array of structures based on scores and nums
void bubbleSort(list arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].score > arr[j + 1].score || (arr[j].score == arr[j + 1].score && atoi(arr[j].num) > atoi(arr[j + 1].num)))
            {
                // Swap the elements if they are in the wrong order
                list temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    list beauty[N];

    // Simpan angka ke objek
    for (int i = 0; i < N; i++)
    {
        scanf("%s", beauty[i].num);
        beauty[i].score = calculateBeauty(beauty[i].num);
    }

    // Gunakan bubble sort untuk mengurutkan berdasarkan skor (dari yang terkecil ke terbesar), jika skor sama diurutkan berdasarkan num
    bubbleSort(beauty, N);

    // Print hasil
    printf("\nHasil: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%s %d\n", beauty[i].num, beauty[i].score);
    }

    return 0;
}


// Notes 1:
// The expression *number - '0' is used to convert a character representing a digit to its corresponding integer value. In the ASCII character set, the numeric characters '0' to '9' are assigned consecutive integer values. The character '0' has the smallest integer value among them.

// So, when you subtract the ASCII value of '0' from the ASCII value of any numeric character, you get the integer value of that digit.

// For example:

// '0' - '0' = 0
// '1' - '0' = 1
// '2' - '0' = 2
// '3' - '0' = 3


//Notes 2:
// Now, let's apply this function to the number "2341":

// Initial State:

// number points to the first character '2'.
// beauty = 0
// First Iteration (number = "2341"):

// beauty += *number - '0'; → beauty += '2' - '0'; → beauty += 2; → beauty = 2
// number++; → number now points to the second character '3'
// Second Iteration (number = "341"):

// beauty += *number - '0'; → beauty += '3' - '0'; → beauty += 3; → beauty = 5
// number++; → number now points to the third character '4'
// Third Iteration (number = "41"):

// beauty += *number - '0'; → beauty += '4' - '0'; → beauty += 4; → beauty = 9
// number++; → number now points to the fourth character '1'
// Fourth Iteration (number = "1"):

// beauty += *number - '0'; → beauty += '1' - '0'; → beauty += 1; → beauty = 10
// number++; → number now points to the null-terminator '\0'
// End of Loop:

// The loop stops because *number is now '\0', indicating the end of the string.
// Final Result:

// beauty is now 10, which is the sum of all digits in the original number "2341".
// The function successfully iterated through each digit in the string and calculated the beauty of the number.


// Notes 3:
// The while (*number != '\0') construct is a common idiom used in C to 
// iterate through a null-terminated string until the null character ('\0') 
// is encountered. In C, strings are represented as arrays of characters 
// terminated by a null character. This null character indicates the end of 
// the string.

// *number != '\0':

// *number is the value pointed to by the number pointer, which is the current character in the string.
// The condition *number != '\0' checks whether the current character is not the null character, signaling the end of the string.
// As long as the current character is not the null character, the loop continues.
// beauty += *number - '0';:

// Inside the loop, this line extracts the current digit (character) from the string and converts it to its numeric value by subtracting the ASCII value of '0'.
// The result is added to the beauty variable, which accumulates the sum of all digits in the string.
// number++;:

// After processing the current character, the number pointer is incremented to point to the next character in the string.
// This while (*number != '\0') loop ensures that the function iterates through each character in the string until the null character is reached, effectively processing all 
// digits in the string. It's a common and concise way to loop through strings in C, taking advantage of the null-terminated string representation.
