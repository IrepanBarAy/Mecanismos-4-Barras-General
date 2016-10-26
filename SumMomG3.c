#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

int main()
{
	/*Declaración de Variables*/
	int cont;
	double r1, r2, r3, r4, theta1, theta2, degtorad, theta_ini, theta_fin, val, omega2;
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
	omega2=12;
	/*Variables dependientes de theta_2*/
	double *theta3, *theta4, *J, *K, *L, *omega3, *omega4;
	/*Declaración de punteros*/
	theta3=(double *) malloc(sizeof(double) * val);
	theta4=(double *) malloc(sizeof(double) * val);
	J=(double *) malloc(sizeof(double) * val);
	K=(double *) malloc(sizeof(double) * val);
	L=(double *) malloc(sizeof(double) * val);
	omega3=(double *) malloc(sizeof(double) * val);
	omega4=(double *) malloc(sizeof(double) * val);
	/*Ciclo de cálculos*/
	for(cont=0;cont<val+1;cont++)
	{
		theta2=(theta_ini+cont)*degtorad;
		/*Cálculo de theta_3 y theta_4*/
		J[cont]=2*r1*r4*cos(theta1)-2*r2*r4*cos(theta2);
		K[cont]=2*r1*r4*sin(theta1)-2*r2*r4*sin(theta2);
		L[cont]=r1*r1+r2*r2+r4*r4-r3*r3-2*r1*r2*(cos(theta1)*cos(theta2)+sin(theta1)*sin(theta2));
		theta4[cont]=2*atan((-K[cont]-sqrt(K[cont]*K[cont]-L[cont]*L[cont]+J[cont]*J[cont]))/(L[cont]-J[cont]));
		theta3[cont]=atan((r1*sin(theta1)+r4*sin(theta4[cont])-r2*sin(theta2))/(r1*cos(theta1)+r4*cos(theta4[cont])-r2*cos(theta2)));
		/*Cálculo de las velocidades angulares*/
		omega4[cont]=(omega2*r2*(tan(theta3[cont])*cos(theta2)-sin(theta2)))/(r4*(tan(theta3[cont])*cos(theta4[cont])-sin(theta4[cont])));
	}
	printf("theta_3: %f\n", theta3[0]/degtorad);
	printf("theta_4: %f\n", theta4[0]/degtorad);
	printf("omega_4: %f\n", omega4[0]);
	free(theta3);
	free(theta4);
	free(J);
	free(K);
	free(L);
	free(omega3);
	free(omega4);
	return 0;
}
