#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

int main()
{
	/*Declaración de Variables*/
	int cont;
	double r1, r2, r3, r4, theta1, theta2, degtorad, theta_ini, theta_fin, val;
	degtorad=3.141592654/180;
	/*Oscilación de theta_2*/
	theta_ini=60;
	theta_fin=61;
	val=(theta_fin-theta_ini);
	/*Variables independientes conocidas*/
	r1=0.9;
	r2=0.3;
	r3=1.5;
	r4=0.8;
	theta1=0;
	/*Variables dependientes de theta_2*/
	double *theta3, *theta4, *J, *K, *L;
	/*Declaración de punteros*/
	theta3=(double *) malloc(sizeof(double) * val);
	theta4=(double *) malloc(sizeof(double) * val);
	J=(double *) malloc(sizeof(double) * val);
	K=(double *) malloc(sizeof(double) * val);
	L=(double *) malloc(sizeof(double) * val);
	/*Ciclo para determinar theta_3 y theta_4*/
	for(cont=0;cont<val+1;cont++)
	{
		theta2=(theta_ini+cont)*degtorad;
		J[cont]=2*r1*r4*cos(theta1)-2*r2*r4*cos(theta2);
		K[cont]=2*r1*r4*sin(theta1)-2*r2*r4*sin(theta2);
		L[cont]=r1*r1+r2*r2+r4*r4-r3*r3-2*r1*r2*(cos(theta1)*cos(theta2)+sin(theta1)*sin(theta2));
		theta4[cont]=2*atan((-K[cont]-sqrt(K[cont]*K[cont]-L[cont]*L[cont]+J[cont]*J[cont]))/(L[cont]-J[cont]));
	}
	printf("theta_4: %f\n", theta4[0]/degtorad);
	free(theta3);
	free(theta4);
	free(J);
	free(K);
	free(L);
	system("pause");
	return 0;
}
