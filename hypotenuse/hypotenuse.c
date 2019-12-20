#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c;
	
	printf("enter a: ");
	scanf("%lf", &a);

	printf("enter b: ");
	scanf("%lf", &b);

	//a ^ 2 + b ^ 2 = c ^ 2
	c = sqrt( pow(a, 2) + pow(b, 2) ); 
	printf("\na is: %lf\tb is: %lf\t c is: %lf\n", a, b, c);	
	
	return 0;
}
