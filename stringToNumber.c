int stringToNumber(char* l)	// conversia unui string intr un numar
{
	int minusFlag=0;
	int p=strlen(l)-1;
	int i=0;
	if(l[0]=='-')
	{
		minusFlag=1;
		p--;
		i++;
	}
	int num=0;
	while(i<strlen(l))
	{
		num=num+(l[i]-'0')*pow(10,p);
		i++;
		p--;
	}
	if(minusFlag==1)
		return -num;
	else
		return num;
}
