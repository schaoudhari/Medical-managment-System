#include "billDB.h"
#include<stdio.h>
void billEntry()
{
	FILE *fptr;
	billDB b;
	fptr=fopen("Bill.txt","a");
	fprintf(fptr,"%d\t%s\t%s\t%d\t%d\t%d\t%s\n",b.billno,b.cust_name,b.medi_name,b.medi_qty,b.medi_rate,b.Total,b.date);
	fclose(fptr);
	printf("bill information added to the database\n\n");
}
void Bill_list(){
	FILE *fptr;
	billDB b;
	fptr=fopen("Bill.txt","r");
	while(fscanf(fptr,"%d%s%s%d%d%d%s",&b.billno,&b.cust_name,&b.medi_name,&b.medi_qty,&b.medi_rate,&b.Total,&b.date)!=-1){
		printf("%d\t%s\t%s\t%d\t%d\t%d\t%s\n",b.billno,b.cust_name,b.medi_name,b.medi_qty,b.medi_rate,b.Total,b.date);
	}
}
