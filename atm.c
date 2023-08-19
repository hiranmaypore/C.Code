#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
struct swarnab {
	char name[100];
	 double acc;
	int pin;
	int balance;
};
deposite(struct swarnab s1,int *ptr){
	int amount,pin;
	printf("\tEnter amount :");
	scanf("%d",&amount);
	printf("\tEnter your pin :");
	scanf("%d",&pin);
	if(pin==s1.pin){
		*ptr+=amount;
		printf("\n");
		printf("\tTransuction successful\n");
		printf("\tamount of %d credited to acc. no. %.0lf\n",amount,s1.acc);
		printf("\tavilable balance %d\n",*ptr);
	}
	else{
		printf(ANSI_COLOR_RED "WRONG PIN" ANSI_COLOR_RESET);
	}
	}

withdraw( struct swarnab s1,int *ptr){
	int amount,pin;

	printf("\tEnter the amount :");
	scanf("%d",&amount);
	printf("\tEnter your pin :");
	scanf("%d",&pin);
    if(*ptr <= amount){
        printf("Insufficient balance");
    }
	else if(pin==s1.pin){
			*ptr-=amount;
			printf("\n");
			printf("\ttransaction successful\n");
			printf("\tamount of %d was debited from acc no. %.0lf\n",amount,s1.acc);
			printf("\tavilable balence: %d\n",*ptr);}
			else {
                printf(ANSI_COLOR_RED "WRONG PIN " ANSI_COLOR_RESET);
			}
	}
	sendmoney(struct swarnab s1,int *ptr){
		int amount,pin;
		double acc;
		printf("\tRecivers account number :");
		scanf("%lf",&acc);
		printf("\tAmount : ");
		scanf("%d",&amount);
		printf("\tEnter your pin :");
		scanf("%d",&pin);
		if(pin==s1.pin){
			*ptr-=amount;
			printf("\n");
				printf("\ttransuction successful\n");
		printf("\tamount of %d was transferd to %.0lf \n",amount,acc);
		printf("\tavilable balance: %d\n",*ptr);
	}
	else{
		printf(ANSI_COLOR_RED "WRONG PIN" ANSI_COLOR_RESET);
	}
		}
	
	
	

details(struct swarnab s1){
	int *ptr,i,j;
	ptr=&s1.balance;
	printf("\n");
	printf("\t\t\t\t\t\t ACCOUNT DETAILS \t\t\t\t\n");
	printf("\n");
	printf("\tHELLO %s\n",s1.name);
	printf("\tAcc. no. %.0lf\n",s1.acc);
	printf("\tBalance :%d\n",s1.balance);
printf("\n");
for(i=1;i<=3;i++){

	printf("\n");
	printf("\tYOU WANT TO :");
	printf("\t1. Withdraw money");
	printf("\t2. Send money");
	printf("\t3. Add money");
		printf("\t4. EXIT\n");


	printf("\toption :");
	scanf("%d",&j);
	if(j==1){
		withdraw(s1,ptr);
	}
	else if(j==2){
	sendmoney(s1,ptr);
	}
	else if (j==3) {
		deposite(s1,ptr);
	}
	else if(j==4){
		return 0;
	}
	else{
		printf(ANSI_COLOR_RED "WRONG INPUT" ANSI_COLOR_RESET);
		
	}}
}
void pincode(int a1, struct swarnab s1){
	int b1;
	printf("Enter you pin: ");
	scanf("%d",&b1);
	if(b1==a1){
		printf("YOU ARE VERIFIED\n");
		switch(b1){
			case 2005:details(s1);
			break;
			case 2004:details(s1);
			break;
			case 9265: details(s1);
		}
		
	}
	else{
		printf(ANSI_COLOR_RED "CHALA JA BSDK" ANSI_COLOR_RESET);
	}
}
void verification(double j, struct swarnab s1){

    srand(time(0));
    int b5,n,b=0,a = 101+ rand() % 999;
    double n1;
    printf("Random number: %d\n", a);
    while(a!=0){
    	n=a%10;
    	b+=n;
    	a/=10;
    
	}
    printf("Enter the sum of the digits\n");
    printf("sum=",n1);
    scanf("%lf.0",&n1);
    if(n1==b){
    	printf("YOU GOT THE ACCES\n");
   if(j==8653999068){
   	b5=2005;pincode(b5,s1);
   
   }
   else if(j==9339821896){
   	b5=2004;pincode(b5,s1);
   }
   else if(j==7047499265){
    b5=9265;pincode(b5,s1);
   }
        
    }
	else{
		printf(ANSI_COLOR_RED "WRONG PIN" ANSI_COLOR_RESET);
	}}


int main(){
	struct swarnab s1,s2,s3;
strcpy(s1.name,"Swarnab Ghorui");
	s1.acc=8653999068;
	s1.pin=2005;
	s1.balance=1000;

strcpy(s3.name,"Hiranmay Pore");
    s3.acc=7047499265;
    s3.pin=9265;
    s3.balance=100;
	
strcpy(s2.name,"Pritam Samanta");
	s2.acc=9339821896;
	s2.pin=2004;
	s2.balance=1000;

	double a,b,c,d;
	printf("Enter account no. :");
	scanf("%lf",&a);
	if(a==8653999068){
		printf(ANSI_COLOR_GREEN"HELLO SWARNAB\n"ANSI_COLOR_RESET);
	printf("verify yourself\n");
	verification(8653999068,s1);
	
	}
	else if(a==9339821896){
		printf(ANSI_COLOR_GREEN"HELLO PRITAM\n"ANSI_COLOR_RESET);
		printf("verify yourself\n");
		verification(9339821896,s2);
	
	}
    else if(a==7047499265){
        printf(ANSI_COLOR_GREEN"HELLO HIRANMAY\n"ANSI_COLOR_RESET);
        printf("verify yourself\n");
        verification(7047499265,s3);
    }
	else{
		printf(ANSI_COLOR_RED " Please enter a vaalid account no."ANSI_COLOR_RESET);
	}
return 0;
}