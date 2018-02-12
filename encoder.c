#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "encode_charmod.c"
#include "encode_word.c"
#include "encode_number.c"
#include "stringToNumber.c"
#include "findType.c"



typedef struct 
{
	char* sir;
	double complex ;

} word;


char* rearanjare(word *v, int n, int nr)
{
	int i,j;
	char* sol2=(char*)malloc(nr * sizeof(char));
	for(i=0;i<n/2;i++)
	{
		strcat(sol2,v[i].sir);
		strcat(sol2,v[n-i-1].sir);
	}
	if(n%2==1)
		strcat(sol2,v[n/2].sir);

	return sol2;
}


int main()
{
	char* line1;
	char* line2;
	char solution1[5000];
	int lenght1 = 100;
	size_t size = 100;
	int nword = 0, nchar = 0, nnumber = 0;
	line1 = (char*)malloc(size* sizeof(char));
	line2 = (char*)malloc(size* sizeof(char));
	getline(&line1, &size, stdin);
	int nr1 = strlen(line1)-1;
	line1[nr1]='\0';
	getline(&line2, &size, stdin);
	int nr2 = strlen(line2)-1;
	line2[nr2]='\0';
	
	while(strcmp(line2,"END")!= 0)		//citeste si prelucreaza linii pana la ultima linie de dinainte de end
	{
		int type = findType(line1);
			
		switch(type)
		{	
			case 1:
			{ 
				encode_word(line1);
				strcat(solution1, line1);
				nword++;
				break;
			}
			case 2:
			{	
				if(strlen(solution1)==0)
						strcat(solution1,line1);
				else
					{	
						encode_charmod(solution1,&line1[0]);
						
					}
				nchar++;
				break;
			}
			case 3:
			{
				int number=stringToNumber(line1);
				number=encode_number(number);
				sprintf(line1,"%d",number);
				strcat(solution1, line1);
				nnumber++;
				break;
			}
		}
			
		strcpy(line1,line2);
		getline(&line2,&size,stdin);
		line2[strlen(line2)-1] = '\0';
	}

	printf("%d %d %d\n",nword,nchar,nnumber);	//afisarea primei linii cerute
	
	puts(solution1);	//afisare solutie dupa codificare


	int n = stringToNumber(line1);	
	int nr = strlen(solution1);

	int d = nr/n;
	int ind_msg=-1;
	int poz,i;
	word *v;
	v = (word*)malloc((n+2)* sizeof(word));
	int sum;
	int j;
   
	
	for(i = 0; i <nr; i++)
	{
			
		if( (i % d) == 0 && ind_msg != n - 1)
		{
					
			if(i != 0)
			{	
				v[ind_msg].sir[poz] = '\0';
				v[ind_msg].complex = (double)sum / (double)strlen(v[ind_msg].sir);
						
			}

			ind_msg ++;
			poz = 0;
			sum = 0;
			if (ind_msg != n-1)
				v[ind_msg].sir = (char*)malloc((d+1)* sizeof(char));
			else if(ind_msg == n -1)			
				v[ind_msg].sir = (char*)malloc((nr-i+1));				
			
		}
					
		sum = sum + (int)solution1[i];
		v[ind_msg].sir[poz] = solution1[i];
		poz ++;
			
	}

	v[ind_msg].sir[poz] = '\0';
	v[ind_msg].complex = (double)sum / (double)strlen(v[ind_msg].sir);
	    
	double aux;
	char* chng;
	chng=(char*)malloc(lenght1* sizeof(char));
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{	
			if(v[i].complex < v[j].complex)
			{
				aux=v[i].complex;
				v[i].complex = v[j].complex;
				v[j].complex = aux;
				chng=strdup(v[i].sir);
				v[i].sir=strdup(v[j].sir);
				v[j].sir=strdup(chng);	
			}

			else if(v[i].complex == v[j].complex)
				{	
					if(strcmp(v[i].sir,v[j].sir) > 0)
					{				
						chng=strdup(v[i].sir);
						v[i].sir=strdup(v[j].sir);
						v[j].sir=strdup(chng);
					}
				}
			
		}
		
	char* sol2 = (char*)malloc(nr * sizeof(char));
	for(i=0;i<n/2;i++)
	{
		strcat(sol2,v[i].sir);
		strcat(sol2,v[n-i-1].sir);
	}
	if(n%2==1)
		strcat(sol2,v[n/2].sir);

	puts(sol2);

	return 0;
}