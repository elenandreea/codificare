#include <stdio.h>
#include <stdlib.h>

int encode_number(int a)	//prelucrarea numerelor
{

int max,min,t,d,nr;
max=min=a;
d=a;
nr=1;

while(d!=0)
{
	d=d/10;
	nr=nr*10;
}

nr=nr/10;
t=a;
		//permutarea numarului in functie de semn
do
{
	t=(t%10)*nr+t/10;
		
	if(t>0)
	{
		if(max<t)
			max=t;
	}
	else
	{
		if(t<0)
			if(min<t)
				min=t;
	}

}
while(t!=a);

if(a>0)
	return max;
else
	return abs(min);
}
	