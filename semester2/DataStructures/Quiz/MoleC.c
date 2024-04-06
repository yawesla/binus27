#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double balance=0;
double categoryAmount [5] = {0};
struct data{
	char category[50];
	char detail[50];
	double amount;
	struct data *prev,*next;
}*head,*tail,*current;
	
void push(char category[],char detail[], double amount){
	//new node
	current = (struct data*) malloc(sizeof(struct data));
	strcpy(current->category,category);
	strcpy(current->detail,detail);
	current->amount = amount;
	current->next = current->prev = NULL;
	
	if(head==NULL){
		head = tail = current;
	}else{
		tail->next = current;
		current->prev = tail;
		tail = current;
	}
		
}

void pop(char detail[]){
	
	current = head;
	
	while(current!=NULL){
		
		if(strcmp(current->detail,detail)==0){
			
			int index = 
				strcmp(current->category,"food") == 0 ? 0 :
				strcmp(current->category,"house") == 0 ? 1 :
				strcmp(current->category,"entertainment") == 0 ? 2 : 3;
			categoryAmount[index] -= current->amount;
			
			balance += current->amount;
			
			if(current==head){
				//pop head
				head = head->next;
				head->prev = NULL;
				free(current);
			}else if(current == tail){
				//pop tail
				tail = tail->prev;
				tail->next = NULL;
				free(current);
			}else{
				//pop mid
				current->prev->next = current->next;
				current->next->prev = current->prev;
				free(current);
			}
			break;
		}
		
		current = current->next;
	}
	
}


void view(){
	printf("Account Balance: %.0lf\n",balance);
	printf("Food: %.0lf\nHouse: %.0lf\nEntertaiment: %.0lf\nOther: %.0lf\n",
	categoryAmount[0],categoryAmount[1],categoryAmount[2],categoryAmount[3]);
	
	current = head;
	printf("tes");
	while(current!=NULL){
		printf("%s (%s): %.0lf\n",current->detail,current->category, current->amount);
		current = current->next;
	}
}
int main(){
	int number;
	char category[50],detail[50];
	double amount;
	
	scanf("%lf",&balance);getchar();
	scanf("%d",&number);getchar();
	for(int i=0;i<number;i++){
		scanf("%s %s %lf",&category,&detail,&amount);getchar();
		push(category,detail,amount);
		balance -= amount;
		int index = 
			strcmp(category,"food") == 0 ? 0 :
			strcmp(category,"house") == 0 ? 1 :
			strcmp(category,"entertainment") == 0 ? 2 : 3;
		categoryAmount[index] += amount;
	}
	scanf("%s",&detail);getchar();
	pop(detail);
	view();
	
	return 0;
}