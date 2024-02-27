#include "custentrydb.h"
#include<stdio.h>
#include<stdlib.h>

void Custentry(custaddEntry e){
	FILE *fptr;
	fptr=fopen("customer.txt","a");
	fprintf(fptr,"%d\t%s\t%s\t%ld\t%s\n",e.id,e.name,e.city,e.number,e.email);
	fclose(fptr);
	printf("Customer information added............\n");
}

void Custsearch(){
	int custsearchId(int);
	int choice;
	printf("\n1.Search by Customer Id");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			int sid,result;
			printf("Enter Customer Id ::");
			scanf("%d",&sid);
			result=custsearchId(sid);
			if(result){
				printf("Customer found\n");
			}else{
				printf("Customer not found\n");
			}
			break;
		default:
			printf("wrong Choice!!");
			break;
	}
}

int custsearchId(int id){
	int flag=0;
	int sid=id;
	FILE *fptr;
	fptr=fopen("customer.txt","r");
	custaddEntry e;
	while(fscanf(fptr,"%d%s%s%ld%s",&e.id,&e.name,&e.city,&e.number,&e.email)!=-1){
		if(e.id==sid){
			flag=1;
			break;
		}
	}
	if(flag){
		printf("\nCustomer id:%d\nCustomer name:%s\nCustomer city name:%s\nCustomer Phone:%d\nCustomer Email:%s\n",e.id,e.name,e.city,e.number,e.email);
		return 1;
	}else{
		return 0;
	}
}

void Custlist(){
	FILE *fptr;
	custaddEntry e;
	fptr=fopen("customer.txt","r");
	while(fscanf(fptr,"%d%s%s%ld%s",&e.id,&e.name,&e.city,&e.number,&e.email)!=-1){
		printf("\nCustomer id:%d\nCustomer name:%s\nCustomer city name:%s\nCustomer Phone:%d\nCustomer Email:%s\n\n\n",e.id,e.name,e.city,e.number,e.email);
	}
}


