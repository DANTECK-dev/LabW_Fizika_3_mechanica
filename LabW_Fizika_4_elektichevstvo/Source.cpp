#include <iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main() {

	const float pi = 3.14, g = 9.81, M = 0.124, a = 0.059, R = 0.088, m = 0.099, r = 0.032, rgryz = 0.029, l = 0.505;

	int   n10(10),   n15 (15),  n20  (20);

	float t11 = 18.2, t12 = 19.7, t13 = 19.1,
		  t21 = 12.6, t22 = 19.4, t23 = 25.8,
		  t31 = 19.2, t32 = 28.9, t33 = 38.4;

	double T11,    T12,    T13,    T1_mean,
		   T21,    T22,    T23,    T2_mean,
		   T31,    T32,    T33,    T3_mean,
		   Iplexp, Iplteo, I1grexp,I1grteo,
		   I2grexp,I2grteo, m_mean = 0.322;

	T11 = t11 / n10;	T12 = t12 / n10;	T13 = t13 / n10;	T1_mean = (T11 + T12 + T13) / 3;	
	T21 = t21 / n10;	T22 = t22 / n15;	T23 = t23 / n20;	T2_mean = (T21 + T22 + T23) / 3;	
	T31 = t31 / n10;	T32 = t32 / n15;	T33 = t33 / n20;	T3_mean = (T31 + T32 + T33) / 3;

	cout << "\nT11 = " << T11 << "\nT12 = " << T12 << "\nT13 = " << T13 << "\nT1-mean = " << T1_mean << endl;
	cout << "\nT21 = " << T21 << "\nT22 = " << T22 << "\nT23 = " << T23 << "\nT1-mean = " << T2_mean << endl;
	cout << "\nT31 = " << T31 << "\nT32 = " << T32 << "\nT33 = " << T33 << "\nT1-mean = " << T3_mean << endl;

	Iplexp = ((M * g * R * r * T1_mean * T1_mean) / (4 * pi * pi * l));
	Iplteo = (0.5 * M * R * R);

	I1grexp = ((m_mean * g * R * r * T2_mean * T2_mean) / (4 * pi * pi * l)) - Iplexp;
	I1grteo = m * rgryz * rgryz;

	I2grexp = ((m_mean * g * R * r * T3_mean * T3_mean) / (4 * pi * pi * l)) - Iplexp;;
	I2grteo = I1grteo + (2 * m * a * a);

	cout << "\nIplexp  = " << Iplexp << "\nIplteo  = " << Iplteo << "\nI1grexp = " << I1grexp <<
		  "\nI1grteo = " << I1grteo << "\nI2grexp = " << I2grexp << "\nI2grteo = " << I2grteo << endl << endl;
}