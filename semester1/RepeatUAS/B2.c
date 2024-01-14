#include <stdio.h>
#include <string.h>


typedef struct{
	int quantity;
	char nama[105];
	int price;
	int total;
}list;

list cust[1000];

int main (){
	FILE *fp;
	fp = fopen("C:/Users/user/OneDrive/Kuliah/sem1/socs1/RepeatUAS/B2.txt", "r");
	
	int tc, size;
	
	fscanf(fp, "%d\n", &tc);
	
	for(int i = 0; i < tc; i++){
		fscanf(fp,"%d\n", &size);
		
		int res=0;
		for(int j = 0; j < size; j++){
			fscanf(fp,"%d#%[^@]@%d", &cust[j].quantity, cust[j].nama, &cust[j].price);
			cust[j].total = (cust[j].quantity  * cust[j].price);
			res += cust[j].total;
		}
		printf("Customer #%d: Rp %d\n",i+1, res*85/100);
		
	}
	

	
	fclose(fp);

	
	return 0;
}
