#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void frequence(char s[], int f[]);
int max (int *s);
int min (int *s);


void frequence(char s[], int f[])  //vector de frecventa
{
	int i, j, nr;
	nr=strlen(s);
	for(i=0;i<127;i++)
		for(j=0;j<nr;j++)
			if(s[j]==i)
				f[i]=f[i]+1;

}

void Max (int *s , int *poz1 , int *max)	//maximul dintr un sir
{
	int i;
	for(i=0;i<127;i++)
		if((*max)<s[i])
		{
			(*max)=s[i];
			(*poz1)=i;
		}
	
}

void Min (int *s, int *poz2, int *min)		//minimul dintr un sir
{
	int i;
	for(i=0; i<127; i++ )
		if((*min)>s[i] && s[i]!=0 )
		{
			(*min)=s[i];
			(*poz2)=i;
		}
	
}

void encode_charmod ( char *s, char *x)		//prelucrare caracter
{
	int   poz1=0, poz2=0, f[127]={0}, i,sLen, max=0, min=130;
	char maxChar, minChar;
	frequence(s, f);
	Max(f,&poz1,&max); 
	Min(f,&poz2,&min); 

	for(i=0;i<strlen(s);i++)		//determinarea primului element de frecventa maxima
		if(f[(int)s[i]]==max)
		{
			maxChar=s[i];
			i=strlen(s);
		}

	for(i=0;i<strlen(s);i++)		//determinarea primului element de frecventa minima

		if(f[(int)s[i]]==min)
		{
			minChar=s[i];
			i=strlen(s);
		}

	sLen=strlen(s);			//alipirea caracterelor in ordinea specificata
	s[sLen]=maxChar;
	s[sLen+1]=(*x); 
	s[sLen+2]=minChar;
	s[sLen+3]='\0';
	
}
