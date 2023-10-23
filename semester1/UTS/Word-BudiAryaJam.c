#include <stdio.h>

int main() {
  int t, x, y;

  // Membaca input
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &x, &y);

    // Konversi waktu Andi ke format 24 jam
    int jam_andi = x % 12 + 12;
    if (y >= 30) {
      jam_andi++;
    }

    // Cek apakah jam lebih dari atau sama dengan 12, maka AM menjadi PM
    if (jam_andi >= 12) {
      jam_andi -= 12;
    }

    // Mencetak waktu dalam format 24 jam
    printf("Case #%d: %02d:%02d\n", i + 1, jam_andi, y);
  }

  return 0;
}
