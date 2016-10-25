#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
	/*Declaración de Variables*/
	double r1, r2, r3, r4, theta_1, theta_2, degtorad, theta_ini, theta_fin, val;
	degtorad=pi/180;
	/*Oscilación de theta_2*/
	theta_ini=60;
	theta_fin=60;
	val=(theta_fin-theta_ini)+1;
	/*Variables independientes conocidas*/
	r1=0.9;
	r2=0.3;
	r3=1.5;
	r4=0.8;
	theta_1=0;
	/*Variables dependientes de theta_2*/
	double theta_3[val], theta_4[val], J[val], K[val], L[val];
	for(theta_2=theta_ini*degtorad;theta_2<theta_fin*degtorad+1;theta_2++)
	{
		J[theta_2]=2*r1*r4*cos(theta_1)-2*r2*r4*cos(theta_2);
		K[theta_2]=2*r1*r4*sin(theta_1)-2*r2*r4*sin(theta_1);
		L[theta_2]=r1*r1+r2*r2+r4*r4-r3*r3-2*r1*r2*(cos(theta_1)*cos(theta_2)+sin(theta_1)*sin(theta_2));
	theta_4[theta_2]=2*arctan((-K[theta_2]-sqrt(K[theta_2]*K[theta_2]-L[theta_2]*L[theta_2]+J[theta_2]*J[theta_2]))/(L[theta_2]-J[theta_2]));
	}
	printf("theta_4: %f\n", theta_4[1]);
	return 0;
}
