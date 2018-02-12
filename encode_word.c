#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int cmmdc(int c)
{
	int i=2,div=1;
	for(i=2;i<=c/2;i++)
		if(c%i==0)
			if(div<i)
				div=i;
	return div;
}

void reverse(char* s)		//inversul sirului
{
	char *reversed =(char*)malloc((strlen(s)+1)*sizeof(char));
	int i;
	for(i=0;i<strlen(s);i++)
		reversed[i]=s[strlen(s)-1-i];
	strcpy(s,reversed);
	
}
void encode_word(char *s)
{
	int nr,i=0,ok=0,d;
	char *second;
	nr=strlen(s);
	d=cmmdc(nr);
	for(i=0;i<nr;i++)	
		if(isdigit(s[i]))	//verificarea daca cuv contine cifre
			ok=1;
	second = strdup(s+d);
	s[d] = '\0';
	if(ok==1)
		reverse(second);
	second=strcat(second,s);
	strcpy(s,second);
}