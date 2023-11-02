#include <stdio.h>

int main() {
    int tc;
    scanf("%d", &tc);

    for (int t = 0; t < tc; t++) {
        int pintu;
        scanf("%d", &pintu);

        int total = 0; // Menginisialisasi total ke 0 untuk setiap kasus uji 1

        // Inisialisasi pintu pertama dibuka 2
        int visit[pintu];
        for (int i = 0; i < pintu; i++) {
            visit[i] = 1;
        }

        // Pintu genap 3
        for (int i = 2; i <= pintu; i += 2) {
            if (visit[i] == 1) {
                visit[i] = 0;
            }
        }

        // Pintu X (X dimulai dari 3, dan dakan divisit setiap X,2X,3X,..)
        for (int i = 3; i <= pintu; i ++) {
            int j;
            for ( j = i; j <= pintu; j +=i) {
                for(int k = 1 ;k<= pintu;k++){
                    j = j*k;
                    if (visit[j] == 1) {
                        visit[j] = 0;
                    } else {
                        visit[j] = 1;
                     }
                }
            }
        }



        // Menghitung total pintu terbuka
        for (int i = 0; i < pintu; i++) {
            if (visit[i]) total++;
        }

        printf("total : %d\n", total);
    }

    return 0;
}







//JAWABAN
// #include <stdio.h>

// int main(){
// 	int t, n;
// 	scanf("%d", &t);

// 	for(int i = 0; i<t; i++){
// 		int count = 0;
// 		scanf(" %d", &n);

// 		int arr[n];
// 		for(int j = 0; j<n; j++){
// 			arr[j] = 0;
// 		}


// 		for(int j = 2; j<=n; j++){
// 			for(int k = j; k<=n; k+=j){
// 				if(arr[k-1]==0){
// 					arr[k-1] = 1;
// 				}else{
// 					arr[k-1] = 0;
// 				}
// 			}
// 		}
// 		for(int j = 0; j<n; j++){
// 			if(arr[j]==0){
// 				count++;
// 			}
// 		}
// 		printf("%d\n", count);
// 	}
// 	return 0;
// }
