#include <stdio.h>

char single[10][10]= {
	"zero","one","two","three","four","five","six","seven","eight","nine"
};

char doub[9][10]= {
	"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"
};

char doub1[9][10]= {
	"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"
};

int main()
{
	int n,l=0,temp,rev=0,r;
	
	printf("Enter a number : ");
	scanf("%d", &n);
	temp=n;
	
	while(temp>0)
	{
		r=temp%10;
		rev=rev*10+r;
		temp=temp/10;
		l++;
	}
	
	switch(l)
	{
		case 0: printf("%s",single+n);
				break;
		case 1: printf("%s",single+n);
				break;
		case 2: if(rev<=9 && rev>=1)
				{
					printf("%s",doub1+(rev-1));
					break;
				}
				else if(n<=19 && n>=11)
				{	
					n=n%10;
					printf("%s",doub+(n-1));
					break;
				}
				else
				{
					temp=rev%10;
					rev=rev/10;
					printf("%s %s",doub1+(temp-1), single+rev);
					break;
				}
		case 3: if(rev<=9 && rev>=1)
				{
					printf("%s hundred",single+(rev));
					break;
				}
				else if(rev<=99 && rev>=11)
				{
					temp=rev%10;
					rev=rev/10;
					printf("%s hundred %s",single+(temp), doub1+(rev-1));
					break;
				}
				else
				{
					r=rev%10;
					rev/=10;
					
					temp=rev%10;
					rev/=10;
					
					if(temp==1)
						printf("%s hundred %s",single+r,doub+(rev-1));
					else
						printf("%s hundred %s %s",single+r,doub1+(temp-1),single+rev);
					break;
				}
		case 4: if(rev<=9 && rev>=1)
				{
					printf("%s thousand",single+rev);
					break;	
				}		
				else if(rev<=99 && rev>=11)
				{
					temp=rev%10;
					rev=rev/10;
					printf("%s thousand %s hundred",single+(temp), single+(rev));
					break;
				}
				else if(rev>=101 && rev<=999)
				{
					r=rev%10;
					rev/=10;
					
					temp=rev%10;
					rev=rev/10;
					if(temp!=0)
						printf("%s thousand %s hundred %s",single+r,single+(temp),doub1+(rev-1));
					else
						printf("%s thousand %s",single+r,doub1+(rev-1));
					break;
				}
				else
				{
					n=rev%10;
					rev/=10;
					r=rev%10;
					rev/=10;

					if(r!=0)
						printf("%s thousand %s hundred ",single+n,single+r);
					else
						printf("%s thousand ",single+n);
					
					temp=rev%10;
					rev/=10;
					if(temp==1)
						printf("%s",doub+(rev-1));
					else
						printf("%s %s",doub1+(temp-1),single+rev);
					break;
				}			
	}
}
