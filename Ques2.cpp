/*
The Program takes the BirthDate and Time As Input and Calculates the Number Of Hours , Minutes and Seconds 
That a Person Has Lived As On the Current Date.
*/

#include<iostream>
#include<conio.h>

using namespace std;

struct Date		//Data Structure for Representing The Date.
{
	int d, y, m;	// A date has day 'd', month 'm' and year 'y'
	int h, mn;		// hours 'h' , min 'mn'
};

// To Store The Number Of days In All 12 Months.
const int MonthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//Few basic Stuff Which Computers Dont Know ;_;
const int hours = 24;
const int Minutes = 24 * 60;
const int seconds = 24 * 60 * 60;

//Prototypes of the Function Used.
void inputDate(Date &a);
int countLeapYears(Date d);
int getDifference(Date Bdate, Date Cdate);

int main() //main function starts here
{
	system("cls"); //Clearing The Screen just in case

	Date Bdate, Cdate; //Declaring The Objects of date Structure

	cout << "Please Enter Your Date Of Birth :-" << endl;
	inputDate(Bdate);
	cout << "\n Please Enter Today's Date :- " << endl;
	inputDate(Cdate);

	

	float nh = getDifference(Bdate, Cdate); //getting the Number of Days from getDifference function.
	float nm = nh * 60; //Calculatimg the Number of minutes.
	float ns = nm * 60; //Calculating The Number of Seconds.

	//fixing the caclulation
	nh += (hours-Bdate.h)+(Minutes-Bdate.mn)+(hours-Cdate.h)+(Minutes-Cdate.mn);

	//output
	cout << "\nNumber Of Hours Person Has Lived :  " << nh << " hours " << endl;
	cout << "Number Of minutes Person Has Lived : " << nm << " mins " << endl;
	cout << "Number Of minutes Person Has Lived : " << ns << " secs " << endl;


	system("pause");
	return 0;
}

void inputDate(Date &a) //Universal Function For inputing The Values.
{
	cout << "Date : ";
	cin >> a.d;
	cout << "\nMonth : ";
	cin >> a.m;
	cout << "\nyear : ";
	cin >> a.y;
	cout << "\n\n Plox ;_; Enter Time in 24hr Clock System \n\n";
	cout << "\nHour : ";
	cin >> a.h;
	cout << "\nMinutes :";
	cin >> a.mn;
}

int countLeapYears(Date d) //This function counts The Number Of leap Years Before the Given Date 
{
	int years = d.y;

	//check if the current year needs to be considered for the count of leap year or not
	if (d.m <= 2)
		years--;

	//Calculating the Number of leap years 
	int nlpy = ((years / 4) + (years / 400) - (years / 100));

	return nlpy;
}

int getDifference(Date Bdate, Date Cdate)
{
	//count total Number Of Days Before Bdate
	long int n1 = ( (Bdate.y * 365) + (Bdate.d - 1) );
	for (int i = 0; i < Bdate.m - 1; i++)
		n1 += MonthDays[i];

	//since every leap year is of 366 days add a day for every leap year
	n1 += countLeapYears(Bdate);

	//Similarly Count total Number Of Days For Cdate.


	long int n2 = ( (Cdate.y * 365) + (Cdate.d - 1) );
	for (int i = 0; i<Cdate.m - 1; i++)
		n2 += MonthDays[i];
	n2 += countLeapYears(Cdate);

	return (n2 - n1);
}