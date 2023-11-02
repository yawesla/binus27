#include <stdio.h>
#include <string.h>

int main() {
    int tc;
    scanf("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        char string[10001];
        scanf("%s", string);

        int len = strlen(string);
        int freq[26] = {0}; // Inisialisasi array untuk menghitung frekuensi huruf a-z
        int totalFreq = 0;

        for (int i = 0; i < len; i++) {
            freq[string[i] - 'a']++;
        }

        int maxFreq = 0;
        int indexToSkip = -1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (maxFreq == 0) {
                    maxFreq = freq[i];
                } else if (maxFreq != freq[i]) {
                    if (indexToSkip == -1) {
                        indexToSkip = i;
                    } else {
                        indexToSkip = -2; // Lebih dari satu karakter yang bisa dibuang
                        break;
                    }
                }
            }
        }

        printf("Case %d: ", t);
        if (indexToSkip == -1 || indexToSkip == -2) {
            printf("N/A\n");
        } else {
            printf("%c\n", 'a' + indexToSkip);
        }
    }

    return 0;
}


//PENJELASAN
// Kode yang diberikan adalah solusi untuk mengatasi masalah menentukan karakter yang dapat dibuang untuk membuat formula obat menjadi stabil. Berikut adalah penjelasan kode tersebut:

// 1. Kita mulai dengan mendeklarasikan variabel `tc` untuk menyimpan jumlah kasus uji (test cases) yang akan diuji.
// 2. Kemudian, kita menggunakan loop `for` untuk mengulangi setiap kasus uji sebanyak `tc` kali.
// 3. Di dalam loop untuk setiap kasus uji, kita deklarasikan array `string` untuk menyimpan string formula obat. Kemudian, kita membaca string tersebut dari input menggunakan `scanf`.
// 4. Kita menghitung panjang string dengan `strlen` dan menyimpannya dalam variabel `len`.
// 5. Selanjutnya, kita mendeklarasikan array `freq` dengan 26 elemen untuk menghitung frekuensi masing-masing huruf dari 'a' hingga 'z'. Setiap elemen array ini akan mewakili frekuensi dari satu huruf.
// 6. Kami juga mendeklarasikan variabel `totalFreq` yang akan digunakan untuk menghitung total frekuensi semua huruf dalam formula.
// 7. Kami menggunakan loop `for` untuk mengiterasi melalui setiap karakter dalam string formula:
//    - Kami menghitung frekuensi setiap karakter dengan mengurangkan karakter tersebut dengan 'a' dan kemudian menambahkan 1 ke elemen array `freq` yang sesuai.
//    - Kami juga menambahkan frekuensi tersebut ke `totalFreq`.
// 8. Setelah menghitung frekuensi semua huruf, kami mencari karakter yang frekuensinya berbeda dengan karakter lain dalam string formula:
//    - Kami menginisialisasi `maxFreq` dengan 0 untuk melacak karakter dengan frekuensi terbanyak.
//    - Kami juga menginisialisasi `indexToSkip` dengan -1 untuk menandai karakter yang mungkin dibuang. Jika tidak ada karakter yang mungkin dibuang, nilai ini tetap -1. Jika lebih dari satu karakter yang mungkin dibuang, nilai ini menjadi -2.
//    - Kami menggunakan loop untuk mengiterasi melalui setiap huruf dari 'a' hingga 'z':
//      - Jika frekuensi huruf ini lebih dari 0, kami memeriksa apakah `maxFreq` sudah diatur. Jika belum, kami atur `maxFreq` dengan frekuensi huruf ini.
//      - Jika `maxFreq` sudah diatur dan frekuensi huruf ini berbeda dengan `maxFreq`, kami memeriksa apakah `indexToSkip` sudah diatur. Jika belum, kami atur `indexToSkip` dengan indeks huruf ini. Jika `indexToSkip` sudah diatur, berarti ada lebih dari satu huruf yang mungkin dibuang, maka kami set `indexToSkip` menjadi -2.
// 9. Setelah menentukan karakter yang mungkin dibuang atau menentukan bahwa formula sudah stabil, kami mencetak hasil sesuai dengan format yang diminta:
//    - Jika `indexToSkip` adalah -1 atau -2, berarti tidak ada karakter yang mungkin dibuang atau ada lebih dari satu karakter yang mungkin dibuang. Kami mencetak "N/A".
//    - Jika `indexToSkip` adalah indeks yang valid (0 hingga 25), kami mencetak karakter yang mungkin dibuang.
// 10. Proses ini diulang untuk setiap kasus uji yang diberikan.

// Hasil akhir dari kode ini adalah menentukan karakter yang dapat dibuang agar formula obat menjadi stabil, atau mencetak "N/A" jika tidak ada karakter yang bisa dibuang atau ada lebih dari satu karakter yang harus dibuang.