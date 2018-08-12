/*
Write a program to calculate the volume of a cylinder, cube and rectangular box using the concept
of function overloading
*/

#include<iostream>
#include<conio.h>

#define Pi 3.14 //defining the Value of PI

using namespace std;

//Prototypes of Functions Used (FUNCTION OVERLOADING)
float Volume(float r, float h);
float Volume(float a);
float Volume(float l, float w, float h);

int main()
{
	system("cls");
	//MENU FOR OUR PROGRAM

	int n;
	float r,h,a,l,w,v; //choice

	cout << "What Would You Like To Calculate ? : \n";
	cout << "\n1. CYLINDER \n";
	cout << "2. CUBE \n";
	cout << "3. CUBOID \n\n";
	cout << "Choose (1-3) : \t";
	cin >> n;
	switch (n)
	{
		case 1:
			cout << "Enter Radius : ";
			cin >> r;
			cout << "Enter height : ";
			cin >> h;
			v = Volume(r, h);
			cout << "Volume : " << v << endl;
			break;
		case 2:
			cout << "Enter Side : ";
			cin >> a;
			v = Volume(a);
			cout << "Volume : " << v << endl;
			break;
		case 3:
			cout << "Enter Length : ";
			cin >> l;
			cout << "Enter Width : ";
			cin >> w;
			cout << "Enter Height : ";
			cin >> h;
			v = Volume(l, w, h);
			cout << "Volume : " << v << endl;
			break;
	}

	system("pause");
	return 0;
}

float Volume(float r, float h) //Function for Calculating Volume of Cylinder
{
	float v;
	v = Pi*(r*r)*h;
	return v;
}

float Volume(float a) //Function for Calculating Volume of Cube
{
	float v;
	v = (a*a*a);
	return v;
}

float Volume(float l, float w, float h) //Function for Calculating Volume of Cuboid
{
	float v;
	v = l*w*h;
	return v;
}
