// Soal 2: Strong Password

// Bibi ingin membuat password yang kuat untuk melindungi datanya. Sebuah password dikatakan kuat jika memenuhi kriteria berikut:

// Panjangnya minimal 8 karakter.
// Mengandung setidaknya satu huruf besar, satu huruf kecil, satu angka, dan satu karakter khusus.
// Tidak mengandung huruf berulang secara berurutan, contoh 'aab' adalah salah, tetapi 'aba' bisa.
// Bantulah Bibi membuat program untuk membuat password yang kuat. Program harus memenuhi syarat berikut:

// Program harus menerima input berupa kata sandi yang diinginkan.
// Program harus memeriksa apakah kata sandi tersebut memenuhi kriteria kuat password.
// Jika kata sandi tersebut memenuhi kriteria, program harus mencetak "Password Anda kuat!".
// Jika kata sandi tersebut tidak memenuhi kriteria, program harus mencetak "Password Anda lemah! Berikut adalah beberapa saran untuk membuat password yang kuat:"
// "Panjangnya minimal 8 karakter."
// "Mengandung setidaknya satu huruf besar, satu huruf kecil, satu angka, dan satu karakter khusus."
// "Tidak mengandung kata-kata yang umum digunakan."
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char password[256];
    int upper=0,lower=0,number=0,special=0,isLooping=0;

    scanf("%s", password);
    // printf("%s",password);

    int len = strlen(password);
    for(int i=0;i<len;i++){
        // printf("sebelum %c sesudah %c\n",password[i],password[i+1]);
        if(isupper(password[i])){
            upper++;
        } else if(islower(password[i])){
            lower++;
        } else if(isdigit(password[i])){
            number++;
        } else {
            special++;
        }
    
        if( password[i+1] == password[i]){
            isLooping++;
        }
    }


    printf("total char: %d upper:%d, lower: %d, number:%d, Special:%d isLooping:%d\n",len,upper,lower,number,special,isLooping);
    if(len>8 && upper && lower && number && special && isLooping == 0) {
        printf("Password Kuat\n");
    } else {
        printf("Password Lemah\n");
    }


    return 0;
}
