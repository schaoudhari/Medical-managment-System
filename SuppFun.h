#include "SupplierEntry.h"
#include<stdio.h>
#include<stdlib.h>

void Supplierentry(SupplieraddEntry e){
	FILE *fptr;
	fptr=fopen("supplier.txt","a");
	fprintf(fptr,"%d\t%s\t%s\t%d\t%s\n",e.id,e.name,e.city,e.number,e.email);
	fclose(fptr);
	printf("Supplier information added............\n");
}

void Suppliersearch(){
	int SuppliersearchId(int);
	int choice;
	printf("\n1.Search by Customer Id");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			int sid,result;
			printf("Enter Customer Id:\n");
			scanf("%d",&sid);
			result=SuppliersearchId(sid);
			if(result){
				printf("Supplier found in database......");
			}else{
				printf("Supplier not found in database....");
			}
			break;
			default:
			printf("wrong Choice!!");
			break;
	}
}

int SuppliersearchId(int id){
	int flag=0;
	int sid=id;
	char $;
	FILE *fptr;
	fptr=fopen("supplier.txt","r");
	SupplieraddEntry e;
	while(fscanf(fptr,"%d%s%s%ld%s",&e.id,&e.name,&e.city,&e.number,&e.email)!=-1){
		if(e.id==sid){
			flag=1;
			break;
		}
	}
	if(flag){
		printf("\nSupplier id:%d\nSupplier name:%s\nSupplier city name:%s\nSupplier Phone:%d\nSupplier Email:%s\n",e.id,e.name,e.city,e.number,e.email);
		return 1;
	}else{
		return 0;
	}
}

void Supplierlist(){
	char $;
	FILE *fptr;
	SupplieraddEntry e;
	fptr=fopen("supplier.txt","r");
	while(fscanf(fptr,"%d%s%s%ld%s",&e.id,&e.name,&e.city,&e.number,&e.email)!=-1){
		printf("\nSupplier id:%d\nSupplier name:%s\nSupplier city name:%s\nSupplier Phone:%d\nSupplier Email:%s\n",e.id,e.name,e.city,e.number,e.email);
	}
}

