#include<stdio.h>
int main(){
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int gcd;
		scanf("%d",&n);
		int arr[n];
		for(int j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}
		for(int j=0;j<n-1;j++){
			for(int k=1;k<=arr[j] && k<=arr[j+1];k++){
				if(arr[j]%k==0 && arr[j+1]%k==0){
					gcd=k;
				}
			}
		}
		printf("%d\n",gcd);
	}
}


// JAWABAN
// #include <stdio.h>

// int ggcd(int a, int b) {
//   if (a == 0) {
//     return b;
//   } else if (b == 0) {
//     return a;
//   } else if (a == b) {
//     return a;
//   } else if (a > b) {
//     return ggcd(a - b, b);
//   } else {
//     return ggcd(a, b - a);
//   }
// }

// int main() {
//   int t;
//   scanf("%d", &t);

//   while (t--) {
//     int n;
//     scanf("%d", &n);

//     int a[n];
//     for (int i = 0; i < n; i++) {
//       scanf("%d", &a[i]);
//     }

//     int gcd = a[0];
//     for (int i = 1; i < n; i++) {
//         printf("b4 gcd- %d ; a = %d\n",gcd,a[i]);
//       gcd = ggcd(gcd, a[i]);
//       printf("gcd- %d\n",gcd);
//     }

//     printf("%d\n", gcd);
//   }

//   return 0;
// }
