#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//need to import file : customer medicine supplier bill 
#include "medicine.h"
#include "MediAbout.h"
#include "customer.h"
#include "SuppFun.h"
#include "billfunction.h"


int main(){
	int choice;
	
	do{
		printf("1.Customer Information\n");	
		printf("2.Medicine Information\n");	
		printf("3.Supplier Information\n");	
		printf("4.Bill generator\n");	
		printf("5.About US\n");	
		printf("6.Exit Application\n");	
		printf("Enter Choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				//access to customer code
				int opt;
				printf("\n1.Customer Entry\n");	
				printf("2.Customer search\n");	
				printf("3.Customer list\n");
				printf("4.Customer Update\n");	
				printf("Select operation\n");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						int size;
						struct custaddEntry *p;
						printf("Enter Customer count\n");
						scanf("%d",&size);
						p=(struct custaddEntry *)malloc(sizeof(custaddEntry)*size);
						for(int i=0;i<size;i++){
							printf("\n\tEnter Customer\n");
							printf("Enter Id:");
							scanf("%d",&p[i].id);
							printf("\nEnter Name:");
							scanf("%s",&p[i].name);
							printf("\nEnter City:");
							scanf("%s",&p[i].city);
							printf("\nEnter Number:");
							scanf("%s",&p[i].number);
							printf("\nEnter Email:");
							scanf("%s",&p[i].email);
							Custentry(p[i]);
						}
						break;
					case 2:
						Custsearch();
						break;
					case 3:
						Custlist();
						break;
					case 4:
						//update
						break;
					default:
						printf("wrong Choice!!\n");
						break;
				}	
				break;
			case 2:
				printf("1.Medicine Entry\n");//done
				printf("2.Update Stock\n");
				printf("3.Search Medicine\n");
				printf("4.Medicine Sale\n");
				printf("5.Stock of Medicine\n");//done
				printf("Enter Your Choice :: ");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
					int size;
					medicinedb *m;
					printf("How many types Medicine you want to add ::\n");
					scanf("%d",&size);
					m=(struct medicinedb *)malloc(sizeof (medicinedb)*size);
					for(int i=0;i<size;i++)
					{
						printf("Enter ID :: ");
						scanf("%d",&m[i].id);
						printf("enter Medicine Name :: ");
						scanf("%s",&m[i].name);
						printf("Enter Quantity :: ");
						scanf("%d",&m[i].qty);
						printf("Enter Bill Number ::");
						scanf("%d",&m[i].bill_no);
						printf("Enter Rack ::");
						scanf("%d",&m[i].rack);
						printf("Enter Cabinet ::");
						scanf("%d",&m[i].cabinet);
						printf("Enter Cost ::");
						scanf("%d",&m[i].cost);
						printf("Enter Sale ::");
						scanf("%d",&m[i].sale);
						printf("Enter Unit ::");
						scanf("%d",&m[i].unit);
						printf("Enter Profit ::");
						scanf("%d",&m[i].profit);
						printf("Enter Pur_date ::");
						scanf("%d",&m[i].pur_date);
						printf("Enter Exp_date ::");
						scanf("%d",&m[i].exp_date);
						printf("Enter Manufactoring_date ::");
						scanf("%d",&m[i].manu_date);
						printf("Enter Supplyer_Name ::");
						scanf("%s",&m[i].supp_name);
						printf("Enter Company_Name ::");
						scanf("%s",&m[i].comp_name);
						printf("Enter Price ::");
						scanf("%d",&m[i].price);
						m[i].total=m[i].price*m[i].qty;
						printf("\n Total of medicine is %d",m[i].total);
						mediEntry(m[i]);
					}
					break;
					case 2:
						//update stock
						break;
					case 3:
						//Search medicine
						int pid,result;
						printf("Enter ID for Search");
						scanf("%d",&pid);
						result=getmedicine(pid);
						if(result)
							{
								printf("\nproduct found\n");
							}
						else
							{
								printf("\nproduct not found\n");
							}
						break;
					case 4:
						//Medicine Sale
						int mid,sale;
						printf("Enter ID for Sale ::");
						scanf("%d",&mid);
						sale=mediSale(mid);
						if(sale){
							printf("Medicine sale Completed\n");
						}
						else{
							printf("ID is Incorrect\n");
						}
						break;
					case 5:
						//stock of Medicine
						viewdata();
						break;
				}
				break;
			case 3:
				//supplier information
				printf("\n1.Supplier Entry\n");	
				printf("2.Supplier search\n");	
				printf("3.Supplier list\n");
				printf("4.Supplier Update\n");	
				printf("Select operation\n");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						int size;
						struct SupplieraddEntry *e;
						printf("Enter Supplier count\n");
						scanf("%d",&size);
						e=(struct SupplieraddEntry *)malloc(sizeof(SupplieraddEntry)*size);
						for(int i=0;i<size;i++){
							printf("\n\tEnter Supplier\n");
							printf("Enter Id:");
							scanf("%d",&e[i].id);
							printf("\nEnter Name:");
							scanf("%s",&e[i].name);
							printf("\nEnter City:");
							scanf("%s",&e[i].city);
							printf("\nEnter Number:");
							scanf("%s",&e[i].number);
							printf("\nEnter Email:"); 
							scanf("%s",&e[i].email);
							Supplierentry(e[i]);
						}
						break;
					case 2:
						Suppliersearch();
						break;
					case 3:
						Supplierlist();
						break;
					case 4:
						//update
						break;

					default:
						printf("wrong Choice!!\n");
						break;
				}	
		break;
			case 4:
				// access to bill generator
				printf("1.Bill entry\n");
				printf("2.Bill list\n");
				printf("Enter Your Choice ::");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						struct billDB b;
						printf("Enter Bill Number   ::");
						scanf("%d",&b.billno);
						printf("Enter Customer Name ::");
						scanf("%s",&b.cust_name);
						printf("Enter Medicine Name ::");
						scanf("%s",&b.medi_name);
						printf("Enter Quantity      ::");
						scanf("%d",&b.medi_qty);
						printf("Enter Price         ::");
						scanf("%d",&b.medi_rate);
						printf("Enter Today's Date(DD/MM/YYYY) :: \t ");
						scanf("%s",&b.date);
						b.Total= (b.medi_rate*b.medi_qty);
						printf("\n\n Total Bill is  :: %d\n\n",b.Total);
						billEntry();
						break;
					case 2:
					// see the list of bill entrys
						Bill_list();
						break;
					default:
						printf("\nwrong choice\n");
						break;
			}
				break;
			case 5:
				//access about my company
				about();
				break;
			case 6:
				printf("Thank You for Using Our Application ");
				break;
			default:
				printf("Wrong Choice\n");
				break;
			}
	}while(choice!=6);
return 0;
}
