#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int findType(char *s)
{
	int type,nr,i,ok=1;
	nr=strlen(s);
	if(nr==1)
		if(s[0]>48 && s[0]<=57)
			type=3;		//numar
		else
			type=2;		//caracter

	else
	{	
		if(s[0]==45)
		{
			for(i=1;i<nr;i++)
				if(isdigit(s[i])==0)
					ok=0;
		}
	
		else
		{	
			for(i=0;i<nr;i++)
				if(isdigit(s[i])==0)
					ok=0;
		}
		
		if(ok==1)
			type=3;		//numar
		else
			if(ok==0)
				type=1;		//cuvant
	}
	
	return type;
}