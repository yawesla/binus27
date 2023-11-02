#include <stdio.h>

int main() {
  int t, n, k;
  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    scanf("%d %d", &n, &k);

    // Generate the sequence up to the k-th digit.
    int sequence[n + 1];
    sequence[1] = 1;
    for (int j = 2; j <= n; j++) {
      sequence[j] = sequence[j - 1] + 1;
      if (sequence[j] > n) {
        sequence[j] = 1;
      }
    }

    // Retrieve the k-th digit from the sequence.
    int digit = sequence[k];
    while (digit > 9) {
      digit /= 10;
      k++;
    }
    printf("%d\n", digit);
  }

  return 0;
}
