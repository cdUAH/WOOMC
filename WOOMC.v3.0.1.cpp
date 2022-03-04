/*******************************************************************
* Name: Worst Order of Magnetude calculator
* File: Worst_Order_Of_Magnetude_calculator.v3.0.1
* Author: Cooper cdUAH
* Desc: Calculates worst case order of magnetude for various 
* algorithm types
* Date: 11/1/2020
* Do not replicate or sell without express permission of cdUAH
* https://github.com/cdUAH
*******************************************************************/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
//initiate global variables
//low
double l_logResult, l_n, l_nlogResult, l_nsquaredResult, l_ncubedResult, l_nfactResult, l_twonResult;
//medium
double m_logResult, m_n, m_nlogResult, m_nsquaredResult, m_ncubedResult, m_nfactResult, m_twonResult;
//high
double h_logResult, h_n, h_nlogResult, h_nsquaredResult, h_ncubedResult, h_nfactResult, h_twonResult;
//units counter
string llrc, lnc, lnrc, lnsc, lncc, lnfc, ltnc;
string mlrc, mnc, mnrc, mnsc, mncc, mnfc, mtnc;
string hlrc, hnc, hnrc, hnsc, hncc, hnfc, htnc;

string l_gR = ""; // for if centuries is >1000
string m_gR = "";
string h_gR = "";
string nh_gR ="";
//to hold xIterations for factorial calculator
double lhold;
double mhold;
double hhold;
//main variables used in calculations
double duration;
double lIterations;
double mIterations;
double hIterations;

//initiate functions
int calculation ();
int l_timeAdjustment();
int m_timeAdjustment();
int h_timeAdjustment();
int outputTable();
double l_factorial(double lIterations);
double m_factorial(double mIterations);
double h_factorial(double hIterations);



int main ()
{
	//initiate variables

	
	//creates program header with name, date, assignment, and description
	cout << string(53,'*') << endl;
	cout << "*********************** START ***********************" << endl;
	cout << string(53,'*') << endl;
	cout << "*Created by*: Cooper (cdUAH) ";
	cout << "https://github.com/cdUAH" <<endl;
	cout << "*Date*: 11/1/2020, rev.3.0.1 3/3/2022" << endl;
	cout << "*Description*: Calculates worst case order of \n               magnetude for various algorithm types"<< endl;	
	cout << "Inputs*: *Time in seconds for one calculation\n";
	cout << "         (ex: 0.0002)\n";
	cout << "         *Low Iterations (ex: 100)\n";
	cout << "         *Medium Iterations (ex: 1000)\n";
	cout << "         *High Iterations (ex: 5000)"<<endl;
	cout << "*Outputs*: *Table containg caluclations for:\n";
	cout << "           *Log(n), n, nLog(n), n^2, n^3, n!, and 2^n\n";
	cout << "           algorithms" <<endl;
	cout << string(53,'*') << endl;
	cout << string(53,'*') << endl;
	cout << string(53,'*') << endl << endl;
	
	cout << "Enter the time for one calculation in seconds: ";
	cin >> duration;
	cout << "You entered " << duration << " seconds." << endl;
	cout << "Please enter 3 levels of iteration times: " <<endl;
	cout << "Low: ";
	cin >> lIterations;
	cout << "Medium: ";
	cin >> mIterations;
	cout << "High: ";
	cin >> hIterations;
	
	calculation();
	cout << "\n*****Calculations Complete*****\n" << endl;
	l_timeAdjustment();
	cout << "*****Time Adjustment: Low Complete*****\n" << endl;
	m_timeAdjustment();
	cout << "*****Time Adjustment: Medium Complete*****\n" << endl;
	h_timeAdjustment();
	cout << "*****Time Adjustment: High Complete*****\n" << endl;
	cout << "*****Printing Output Table*****\n" <<endl;
	cout << fixed<< "The table for a computation time of: " <<duration << " is below:" <<endl;
	outputTable();
	return (0);
}

int calculation()
{
	int i;
	//Function to calculate the algorithm total computational time
	//Calculates: log(n), (n), n*log(n), n^2, n^3, n!, and 2^n
	
	//log(n)
	l_logResult = (log10 (lIterations)) * duration;
	m_logResult = (log10 (mIterations)) * duration;
	h_logResult = (log10 (hIterations)) * duration;
	
	//(n)
	l_n = lIterations * duration;
	m_n = mIterations * duration;
	h_n = hIterations * duration;		
	
	//n*log(n)
	l_nlogResult = (l_logResult * lIterations) * duration;
	m_nlogResult = (m_logResult * mIterations) * duration;	
	h_nlogResult = (h_logResult * hIterations) * duration;	
	
	//n^2
	l_nsquaredResult = pow(lIterations, 2) * duration;
	m_nsquaredResult = pow(mIterations, 2) * duration;
	h_nsquaredResult = pow(hIterations, 2) * duration;	
	//n^3
	l_ncubedResult = pow(lIterations, 3) * duration;
	m_ncubedResult = pow(mIterations, 3) * duration;
	h_ncubedResult = pow(hIterations, 3) * duration;		
	
	//n!
		//////////////////////////////////////////////////////////////
	if (lIterations > 100)
	{
		lhold = lIterations;
		lIterations = 100;
		l_nfactResult = l_factorial(lIterations);
		l_nfactResult = l_nfactResult * duration;
		lIterations=lhold;
	}
	else
	{
	l_nfactResult = l_factorial(lIterations);
	l_nfactResult = l_nfactResult * duration;
	}
	
	if (mIterations > 100)
	{
		mhold = mIterations;
		mIterations = 100;
		m_nfactResult = m_factorial(mIterations);
		m_nfactResult = m_nfactResult * duration;
		mIterations=mhold;
	}
	else
	{
	m_nfactResult = m_factorial(mIterations);
	m_nfactResult = m_nfactResult * duration;
	}
	
	if (hIterations > 100)
	{
		hhold = hIterations;
		hIterations = 100;
		h_nfactResult = h_factorial(hIterations);
		h_nfactResult = h_nfactResult * duration;
		hIterations=hhold;		
	}
	else
	{
	h_nfactResult = h_factorial(hIterations);
	h_nfactResult = h_nfactResult * duration;
	}	
	//////////////////////////////////////////////////////////////
	
	//2^n
	l_twonResult= pow(2, lIterations) * duration;
	m_twonResult= pow(2, mIterations) * duration;
	h_twonResult= pow(2, hIterations) * duration;
	
	
	return (0);			
}

double l_factorial(double lIterations) //factorial low
{
    if(lIterations > 1)
	{
	    return lIterations * l_factorial(lIterations - 1);	
	}

}

double m_factorial(double mIterations) //factorial medium
{
    if(mIterations > 1)
	{
	    return mIterations * m_factorial(mIterations - 1);	
	}

}

double h_factorial(double hIterations) //factorial high
{
    if(hIterations > 1)
	{
	return hIterations * h_factorial(hIterations - 1);	
	}

}

int l_timeAdjustment() 
{
	//adjusts units of time from seconds up to centuries for low duration
	
	//string llrc, lnc, lnrc, lnsc, lncc, lnfc, ltnc;
	
	//l_logResult Time adjust
	if (l_logResult < 60)
	{
		llrc = "sec.";
	}
	if (l_logResult > 59)
	{
		l_logResult = l_logResult / 60; //convert from seconds to minutes
		llrc = "min.";
		if (l_logResult > 59)
		{
			l_logResult = l_logResult / 60; //convert from minutes to hours
			llrc = "hr.";
			if (l_logResult > 23)
			{
				l_logResult = l_logResult / 24; //converts from hours to days
				llrc = "days.";
				if (l_logResult > 364)
				{
					l_logResult = l_logResult / 365; // converts from days to years
					llrc = "yr.";
					if (l_logResult > 99)
					{
						l_logResult = l_logResult /100 ;
						llrc = "cen.";
					} 
				}
			}
		}
	}
	
	//l_n Time Adjust (lnc)
	if (l_n < 60)
	{
		lnc = "sec.";
	}
	if (l_n > 59)
	{
		l_n = l_n / 60; //convert from seconds to minutes
		lnc = "min.";
		if (l_n > 59)
		{
			l_n = l_n / 60; //convert from minutes to hours
			lnc = "hr.";
			if (l_n > 23)
			{
				l_n = l_n / 24; //converts from hours to days
				lnc = "days.";
				if (l_n > 364)
				{
					l_n = l_n / 365; // converts from days to years
					lnc = "yr.";
					if (l_n > 99)
					{
						l_n = l_n /100 ;
						lnc = "cen.";
					} 
				}
			}
		}
	}
	
	//l_nlogResult Time Adjust (lnrc)
	if (l_nlogResult < 60)
	{
		lnrc = "sec.";
	}
	if (l_nlogResult > 59)
	{
		l_nlogResult = l_nlogResult / 60; //convert from seconds to minutes
		lnrc = "min.";
		if (l_nlogResult > 59)
		{
			l_nlogResult = l_nlogResult / 60; //convert from minutes to hours
			lnrc = "hr.";
			if (l_nlogResult > 23)
			{
				l_nlogResult = l_nlogResult / 24; //converts from hours to days
				lnrc = "days.";
				if (l_nlogResult > 364)
				{
					l_nlogResult = l_nlogResult / 365; // converts from days to years
					lnrc = "yr.";
					if (l_nlogResult > 99)
					{
						l_nlogResult = l_nlogResult /100 ;
						lnrc = "cen.";
					} 
				}
			}
		}
	}
	
	//l_nsquaredResult Time Adjust (lnsc)
	if (l_nsquaredResult < 60)
	{
		lnsc = "sec.";
	}
	if (l_nsquaredResult > 59)
	{
		l_nsquaredResult = l_nsquaredResult / 60; //convert from seconds to minutes
		lnsc = "min.";
		if (l_nsquaredResult > 59)
		{
			l_nsquaredResult = l_nsquaredResult / 60; //convert from minutes to hours
			lnsc = "hr.";
			if (l_nsquaredResult > 23)
			{
				l_nsquaredResult = l_nsquaredResult / 24; //converts from hours to days
				lnsc = "days.";
				if (l_nsquaredResult > 364)
				{
					l_nsquaredResult = l_nsquaredResult / 365; // converts from days to years
					lnsc = "yr.";
					if (l_nsquaredResult > 99)
					{
						l_nsquaredResult = l_nsquaredResult /100 ;
						lnsc = "cen.";
					} 
				}
			}
		}
	}
	
	//l_ncubedResult Time Adjust (lncc)
	if (l_ncubedResult < 59)
	{
		lncc = "sec.";
	}
	if (l_ncubedResult > 59)
	{
		l_ncubedResult = l_ncubedResult / 60; //convert from seconds to minutes
		lncc = "min.";
		if (l_ncubedResult > 59)
		{
			l_ncubedResult = l_ncubedResult / 60; //convert from minutes to hours
			lncc = "hr.";
			if (l_ncubedResult > 23)
			{
				l_ncubedResult = l_ncubedResult / 24; //converts from hours to days
				lncc = "days.";
				if (l_ncubedResult > 364)
				{
					l_ncubedResult = l_ncubedResult / 365; // converts from days to years
					lncc = "yr.";
					if (l_ncubedResult > 99)
					{
						l_ncubedResult = l_ncubedResult /100 ;
						lncc = "cen.";
					} 
				}
			}
		}
	}
	
	//FACTORIAL, NEED TO DO!!!!
	/////////////////////////////////////////////////
	if (l_nfactResult < 60)
	{
		lnfc = "sec.";
	}
	if (l_nfactResult > 59)
	{
		l_nfactResult = l_nfactResult / 60; //convert from seconds to minutes
		lnfc = "min.";
		if (l_nfactResult > 59)
		{
			l_nfactResult = l_nfactResult / 60; //convert from minutes to hours
			lnfc = "hr.";
			if (l_nfactResult > 23)
			{
				l_nfactResult = l_nfactResult / 24; //converts from hours to days
				lnfc = "days.";
				if (l_nfactResult > 364)
				{
					l_nfactResult = l_nfactResult / 365; // converts from days to years
					lnfc = "yr.";
					if (l_nfactResult > 99)
					{
						l_nfactResult = l_nfactResult /100 ;
						lnfc = "cen.";
						if (l_nfactResult > 1000)
						{
							l_nfactResult = 1000;
							l_gR = ">";
						}
					}
				} 
			}
		}
	}

	
	//l_twonResult Time Adjust (ltnc)
	if (l_twonResult < 60)
	{
		ltnc = "sec.";
	}
	if (l_twonResult > 59)
	{
		l_twonResult = l_twonResult / 60; //convert from seconds to minutes
		ltnc = "min.";
		if (l_twonResult > 59)
		{
			l_twonResult = l_twonResult / 60; //convert from minutes to hours
			ltnc = "hr.";
			if (l_twonResult > 23)
			{
				l_twonResult = l_twonResult / 24; //converts from hours to days
				ltnc = "days.";
				if (l_twonResult > 364)
				{
					l_twonResult = l_twonResult / 365; // converts from days to years
					ltnc = "yr.";
					if (l_twonResult > 99)
					{
						l_twonResult = l_twonResult /100 ;
						ltnc = "cen.";
						if (l_twonResult > 1000)
						{
							l_twonResult = 1000;
							l_gR = ">";
						}
					} 
				}
			}
		}
	}
		
	return (0);
}

int m_timeAdjustment()
{
	//adjusts units of time from seconds up to centuries for medium duration
	

	//string mlrc, mnc, mnrc, mnsc, mncc, mnfc, mtnc;
	
	//m_logResult Time adjust (mlrc)
	if (m_logResult < 60)
	{
		mlrc = "sec.";
	}
	if (m_logResult > 59)
	{
		m_logResult = m_logResult / 60; //convert from seconds to minutes
		mlrc = "min.";
		if (m_logResult > 59)
		{
			m_logResult = m_logResult / 60; //convert from minutes to hours
			mlrc = "hr.";
			if (m_logResult > 23)
			{
				m_logResult = m_logResult / 24; //converts from hours to days
				mlrc = "days.";
				if (m_logResult > 364)
				{
					m_logResult = m_logResult / 365; // converts from days to years
					mlrc = "yr.";
					if (m_logResult > 99)
					{
						m_logResult = m_logResult /100 ;
						mlrc = "cen.";
					} 
				}
			}
		}
	}
	
	//m_n Time Adjust (mnc)
	if (m_n < 60)
	{
		mnc = "sec.";
	}
	if (m_n > 59)
	{
		m_n = m_n / 60; //convert from seconds to minutes
		mnc = "min.";
		if (m_n > 59)
		{
			m_n = m_n / 60; //convert from minutes to hours
			mnc = "hr.";
			if (m_n > 23)
			{
				m_n = m_n / 24; //converts from hours to days
				mnc = "days.";
				if (m_n > 364)
				{
					m_n = m_n / 365; // converts from days to years
					mnc = "yr.";
					if (m_n > 99)
					{
						m_n = m_n /100 ;
						mnc = "cen.";
					} 
				}
			}
		}
	}
	
	//m_nlogResult Time Adjust (mnrc)
	if (m_nlogResult < 60)
	{
		mnrc = "sec.";
	}
	if (m_nlogResult > 59)
	{
		m_nlogResult = m_nlogResult / 60; //convert from seconds to minutes
		mnrc = "min.";
		if (m_nlogResult > 59)
		{
			m_nlogResult = m_nlogResult / 60; //convert from minutes to hours
			mnrc = "hr.";
			if (m_nlogResult > 23)
			{
				m_nlogResult = m_nlogResult / 24; //converts from hours to days
				mnrc = "days.";
				if (m_nlogResult > 364)
				{
					m_nlogResult =m_nlogResult / 365; // converts from days to years
					mnrc = "yr.";
					if (m_nlogResult > 99)
					{
						m_nlogResult = m_nlogResult /100 ;
						mnrc = "cen.";
					} 
				}
			}
		}
	}
	
	//m_nsquaredResult Time Adjust (mnsc)
	if (m_nsquaredResult < 60)
	{
		mnsc = "sec.";
	}
	if (m_nsquaredResult > 59)
	{
		m_nsquaredResult = m_nsquaredResult / 60; //convert from seconds to minutes
		mnsc = "min.";
		if (m_nsquaredResult > 59)
		{
			m_nsquaredResult = m_nsquaredResult / 60; //convert from minutes to hours
			mnsc = "hr.";
			if (m_nsquaredResult > 23)
			{
				m_nsquaredResult = m_nsquaredResult / 24; //converts from hours to days
				mnsc = "days.";
				if (m_nsquaredResult > 364)
				{
					m_nsquaredResult = m_nsquaredResult / 365; // converts from days to years
					mnsc = "yr.";
					if (m_nsquaredResult > 99)
					{
						m_nsquaredResult = m_nsquaredResult /100 ;
						mnsc = "cen.";
					} 
				}
			}
		}
	}
	
	//m_ncubedResult Time Adjust (mncc)
	if (m_ncubedResult < 59)
	{
		mncc = "sec.";
	}
	if (m_ncubedResult > 59)
	{
		m_ncubedResult = m_ncubedResult / 60; //convert from seconds to minutes
		mncc = "min.";
		if (m_ncubedResult > 59)
		{
			m_ncubedResult = m_ncubedResult / 60; //convert from minutes to hours
			lncc = "hr.";
			if (m_ncubedResult > 23)
			{
				m_ncubedResult = m_ncubedResult / 24; //converts from hours to days
				mncc = "days.";
				if (m_ncubedResult > 364)
				{
					m_ncubedResult = m_ncubedResult / 365; // converts from days to years
					lncc = "yr.";
					if (m_ncubedResult > 99)
					{
						m_ncubedResult = m_ncubedResult /100 ;
						mncc = "cen.";
					} 
				}
			}
		}
	}
	
	if (m_nfactResult < 60)
	{
		mnfc = "sec.";
	}
	if (m_nfactResult > 59)
	{
		m_nfactResult = m_nfactResult / 60; //convert from seconds to minutes
		mnfc = "min.";
		if (m_nfactResult > 59)
		{
			m_nfactResult = m_nfactResult / 60; //convert from minutes to hours
			mnfc = "hr.";
			if (m_nfactResult > 23)
			{
				m_nfactResult = m_nfactResult / 24; //converts from hours to days
				mnfc = "days.";
				if (m_nfactResult > 364)
				{
					m_nfactResult = m_nfactResult / 365; // converts from days to years
					mnfc = "yr.";
					if (m_nfactResult > 99)
					{
						m_nfactResult = m_nfactResult /100 ;
						mnfc = "cen.";
						if (m_nfactResult > 1000)
						{
							m_nfactResult = 1000;
							m_gR = ">";
						}
					}
				} 
			}
		}
	}
	
	
	//m_twonResult Time Adjust (mtnc)
	if (m_twonResult < 60)
	{
		mtnc = "sec.";
	}
	if (m_twonResult > 59)
	{
		m_twonResult = m_twonResult / 60; //convert from seconds to minutes
		mtnc = "min.";
		if (m_twonResult > 59)
		{
			m_twonResult = m_twonResult / 60; //convert from minutes to hours
			mtnc = "hr.";
			if (m_twonResult > 23)
			{
				m_twonResult = m_twonResult / 24; //converts from hours to days
				mtnc = "days.";
				if (m_twonResult > 364)
				{
					m_twonResult = m_twonResult / 365; // converts from days to years
					mtnc = "yr.";
					if (m_twonResult > 99)
					{
						m_twonResult = m_twonResult /100 ;
						mtnc = "cen.";
						if (m_twonResult > 1000)
						{
							m_twonResult = 1000;
							m_gR = ">";
						}
					} 
				}
			}
		}
	}
		
	return(0);
}

int h_timeAdjustment()
{

	//adjusts units of time from seconds up to centuries for high duration
	

	//string hlrc, hnc, hnrc, hnsc, hncc, hnfc, htnc;
	
	//h_logResult Time adjust (hlrc)
	if (h_logResult < 60)
	{
		hlrc = "sec.";
	}
	if (h_logResult > 59)
	{
		h_logResult = h_logResult / 60; //convert from seconds to minutes
		hlrc = "min.";
		if (h_logResult > 59)
		{
			h_logResult = h_logResult / 60; //convert from minutes to hours
			hlrc = "hr.";
			if (h_logResult > 23)
			{
				h_logResult = h_logResult / 24; //converts from hours to days
				hlrc = "days.";
				if (h_logResult > 364)
				{
					h_logResult = h_logResult / 365; // converts from days to years
					hlrc = "yr.";
					if (h_logResult > 99)
					{
						h_logResult = h_logResult /100 ;
						hlrc = "cen.";
					} 
				}
			}
		}
	}
	
	//h_n Time Adjust (hnc)
	if (h_n < 60)
	{
		hnc = "sec.";
	}
	if (h_n > 59)
	{
		h_n = h_n / 60; //convert from seconds to minutes
		hnc = "min.";
		if (h_n > 59)
		{
			h_n = h_n / 60; //convert from minutes to hours
			hnc = "hr.";
			if (h_n > 23)
			{
				h_n = h_n / 24; //converts from hours to days
				hnc = "days.";
				if (h_n > 364)
				{
					h_n = h_n / 365; // converts from days to years
					hnc = "yr.";
					if (h_n > 99)
					{
						h_n = h_n /100 ;
						hnc = "cen.";
					} 
				}
			}
		}
	}
	
	//h_nlogResult Time Adjust (hnrc)
	if (h_nlogResult < 60)
	{
		hnrc = "sec.";
	}
	if (h_nlogResult > 59)
	{
		h_nlogResult = h_nlogResult / 60; //convert from seconds to minutes
		hnrc = "min.";
		if (h_nlogResult > 59)
		{
			h_nlogResult = h_nlogResult / 60; //convert from minutes to hours
			hnrc = "hr.";
			if (h_nlogResult > 23)
			{
				h_nlogResult = h_nlogResult / 24; //converts from hours to days
				hnrc = "days.";
				if (h_nlogResult > 364)
				{
					h_nlogResult =h_nlogResult / 365; // converts from days to years
					hnrc = "yr.";
					if (h_nlogResult > 99)
					{
						h_nlogResult = h_nlogResult /100 ;
						hnrc = "cen.";
					} 
				}
			}
		}
	}
	
	//h_nsquaredResult Time Adjust (hnsc)
	if (h_nsquaredResult < 60)
	{
		hnsc = "sec.";
	}
	if (h_nsquaredResult > 59)
	{
		h_nsquaredResult = h_nsquaredResult / 60; //convert from seconds to minutes
		hnsc = "min.";
		if (h_nsquaredResult > 59)
		{
			h_nsquaredResult = h_nsquaredResult / 60; //convert from minutes to hours
			hnsc = "hr.";
			if (h_nsquaredResult > 23)
			{
				h_nsquaredResult = h_nsquaredResult / 24; //converts from hours to days
				hnsc = "days.";
				if (h_nsquaredResult > 364)
				{
					h_nsquaredResult = h_nsquaredResult / 365; // converts from days to years
					hnsc = "yr.";
					if (h_nsquaredResult > 99)
					{
						h_nsquaredResult = h_nsquaredResult /100 ;
						hnsc = "cen.";
					} 
				}
			}
		}
	}
	
	//h_ncubedResult Time Adjust (hncc)
	if (h_ncubedResult < 59)
	{
		hncc = "sec.";
	}
	if (h_ncubedResult > 59)
	{
		h_ncubedResult = h_ncubedResult / 60; //convert from seconds to minutes
		hncc = "min.";
		if (h_ncubedResult > 59)
		{
			h_ncubedResult = h_ncubedResult / 60; //convert from minutes to hours
			hncc = "hr.";
			if (h_ncubedResult > 23)
			{
				h_ncubedResult = h_ncubedResult / 24; //converts from hours to days
				hncc = "days.";
				if (h_ncubedResult > 364)
				{
					h_ncubedResult = h_ncubedResult / 365; // converts from days to years
					hncc = "yr.";
					if (h_ncubedResult > 99)
					{
						h_ncubedResult = h_ncubedResult /100 ;
						hncc = "cen.";
					} 
				}
			}
		}
	}
	
	if (h_nfactResult < 60)
	{
		hnfc = "sec.";
	}
	if (h_nfactResult > 59)
	{
		h_nfactResult = h_nfactResult / 60; //convert from seconds to minutes
		hnfc = "min.";
		if (h_nfactResult > 59)
		{
			h_nfactResult = h_nfactResult / 60; //convert from minutes to hours
			hnfc = "hr.";
			if (h_nfactResult > 23)
			{
				h_nfactResult = h_nfactResult / 24; //converts from hours to days
				hnfc = "days.";
				if (h_nfactResult > 364)
				{
					h_nfactResult = h_nfactResult / 365; // converts from days to years
					hnfc = "yr.";
					if (h_nfactResult > 99)
					{
						h_nfactResult = h_nfactResult /100 ;
						hnfc = "cen.";
						if (h_nfactResult > 1000)
						{
							h_nfactResult = 1000;
							h_gR = ">";
						}
					}
				} 
			}
		}
	}
	
	
	//h_twonResult Time Adjust (htnc)
	if (h_twonResult < 60)
	{
		htnc = "sec.";
	}
	if (h_twonResult > 59)
	{
		h_twonResult = h_twonResult / 60; //convert from seconds to minutes
		htnc = "min.";
		if (h_twonResult > 59)
		{
			h_twonResult = h_twonResult / 60; //convert from minutes to hours
			htnc = "hr.";
			if (h_twonResult > 23)
			{
				h_twonResult = h_twonResult / 24; //converts from hours to days
				htnc = "days.";
				if (h_twonResult > 364)
				{
					h_twonResult = h_twonResult / 365; // converts from days to years
					htnc = "yr.";
					if (h_twonResult > 99)
					{
						h_twonResult = h_twonResult /100 ; //years to centuries
						htnc = "cen.";
						if (h_twonResult > 1000)
						{
							h_twonResult = 1000;
							nh_gR = ">";
						}
					} 
				}
			}
		}
	}
		
	return(0);
}
int outputTable()
{
	//Creats the output table. Each line (730-738) is a corresponding row on the table
	cout << setprecision(0) <<"* Order          * Low = " << lIterations << "          * Medium = " << mIterations << "        * High = " <<hIterations << "  *" <<endl;
	
	cout << string(75,'*') << endl;
	
	cout << setprecision(4) << fixed << "* Log(n)         * " << l_logResult <<" " <<llrc<<"        * " <<m_logResult <<" "<<mlrc<<"         *" <<h_logResult <<" " <<hlrc<<"  *"<<endl;
	
	cout << "* n              * " << l_n <<" " <<lnc<<"        * " <<m_n <<" "<<mnc<<"         *" <<h_n <<" " <<hnc<<"  *"<<endl;
	
	cout << "* nLog(n)        * " << l_nlogResult <<" " <<lnrc<<"        * " <<m_nlogResult <<" "<<mnrc<<"         *" <<h_nlogResult <<" " <<hnrc<<"  *"<<endl;
	
	cout << "* n^2            * " << l_nsquaredResult <<" " <<lnsc<<"        * " <<m_nsquaredResult <<" "<<mnsc<<"         *" <<h_nsquaredResult <<" " <<hnsc<<"  *"<<endl;
	
	cout << "* n^3            * " << l_ncubedResult <<" " <<lncc<<"        * " <<m_ncubedResult <<" "<<mncc<<"         *" <<h_ncubedResult <<" " <<hncc<<"  *"<<endl;
	
	cout << "* n!             * " << l_gR<<l_nfactResult <<" " <<lnfc<<"       * " <<m_gR<<m_nfactResult <<" "<<mnfc<<"          *" <<h_gR<<h_nfactResult <<" " <<hnfc<<"   *"<<endl;
	
	cout << "* 2^n            * " << l_gR<<l_twonResult <<" " <<ltnc<<"        * " <<m_gR<<m_twonResult <<" "<<mtnc<<"         *" <<nh_gR << h_twonResult <<" " <<htnc<<"  *"<<endl;
	return(0);
}







