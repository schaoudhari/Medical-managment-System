#include "medicinedb.h"
#include<stdio.h>

void mediEntry(medicinedb m)
{
 	FILE *fptr;
 	fptr=fopen("medicinedb.txt","a");
 	fprintf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%ld\t%ld\t%ld\t%s\t%s\t%d\t%ld\n",m.id,m.name,m.qty,m.bill_no,m.rack,m.cabinet,m.cost,m.sale,m.unit,m.profit,m.pur_date,m.exp_date,m.manu_date,m.supp_name,m.comp_name,m.price,m.total);
 	fclose(fptr);
 	//%d\t%d\t%d\t%d\t%d\t%d\t     m.bill_no,m.rack,m.cabinet,m.cost,m.profit,m.unit,
 	//%d\t%d\t%d\t%d\t%d\t%dm.bill_no,m.rack,m.cabinet,m.cost,m.profit,m.unit,
 	printf("\nProduct Save Success\n");
};

void viewdata(){
	FILE *fptr;
	medicinedb m;
	fptr=fopen("medicinedb.txt","r");
	while(fscanf(fptr,"%d%s%d%d%d%d%d%d%d%d%ld%ld%ld%s%s%d%ld",&m.id,&m.name,&m.qty,&m.bill_no,&m.rack,&m.cabinet,&m.cost,&m.sale,&m.unit,&m.profit,&m.pur_date,&m.exp_date,&m.manu_date,&m.supp_name,&m.comp_name,&m.price,&m.total)!=-1)
	{
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%ld\t%ld\t%ld\t%s\t%s\t%d\t%ld\n\n",m.id,m.name,m.qty,m.bill_no,m.rack,m.cabinet,m.cost,m.sale,m.unit,m.profit,m.pur_date,m.exp_date,m.manu_date,m.supp_name,m.comp_name,m.price,m.total);		
	}
}/*m.bill_no,m.rack,m.cabinet,m.cost,m.profit,m.unit,%d\t%d\t%d\t%d\t%d\t%d\t
/*0&m.bill_no,&m.rack,&m.cabinet,&m.cost,&m.profit,&m.unit*/
int getmedicine(int sid)
{
	FILE *fptr;
	fptr=fopen("medicinedb.txt","r");
	int flag=0;
	medicinedb m;
	while(fscanf(fptr,"%d%s%d%d%d%d%d%d%d%d%ld%ld%ld%s%s%d%ld",&m.id,&m.name,&m.qty,&m.bill_no,&m.rack,&m.cabinet,&m.cost,&m.sale,&m.unit,&m.profit,&m.pur_date,&m.exp_date,&m.manu_date,&m.supp_name,&m.comp_name,&m.price,&m.total)!=-1)
	{
		if(m.id==sid){
			flag=1;
			break;
		}
	}
	if(flag)
	{
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%ld\t%ld\t%ld\t%s\t%s\t%d\t%ld\n\n",m.id,m.name,m.qty,m.bill_no,m.rack,m.cabinet,m.cost,m.sale,m.unit,m.profit,m.pur_date,m.exp_date,m.manu_date,m.supp_name,m.comp_name,m.price,m.total);
		return 1;
	}
	else{
		return 0;
	}
}

int mediSale(int sid)
{
	FILE *fptr;
	fptr=fopen("medicinedb.txt","r");
	int flag=0;
	medicinedb m;
	while(fscanf(fptr,"%d%s%d%d%d%d%d%d%d%d%ld%ld%ld%s%s%d%ld",&m.id,&m.name,&m.qty,&m.bill_no,&m.rack,&m.cabinet,&m.cost,&m.sale,&m.unit,&m.profit,&m.pur_date,&m.exp_date,&m.manu_date,&m.supp_name,&m.comp_name,&m.price,&m.total)!=-1)
	{
		if(m.id==sid){
			flag=1;
			break;
		}
	}
	if(flag){
		return 1;
	}
	else{
		return 0;
	}
}
