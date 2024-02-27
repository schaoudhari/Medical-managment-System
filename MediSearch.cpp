int medicinedb getmedicine(int sid)
{
	FILE *fptr;
	fptr=fopen("medicinedb.txt","r");
	int flag=0;
	medicinedb m;
	while(fscanf(fptr,"%d%s%d%ld%ld%ld%s%s%d%ld",&m.id,&m.name,&m.qty,&m.pur_date,&m.exp_date,&m.manu_date,&m.supp_name,&m.comp_name,&m.price,&m.total)!=-1)
	{
		if(m.id==sid){
			flag=1;
			break;
		}
	}
	if(flag)
	{
		printf("%d\t%s\t%d\t%ld\t%ld\t%ld\t%s\t%s\t%d\t%ld\n",m.id,m.name,m.qty,m.pur_date,m.exp_date,m.manu_date,m.supp_name,m.comp_name,m.price,m.total);
		return 1;
	}
	else{
		return 0;
	}
}
