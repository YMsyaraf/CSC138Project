#ifndef main_H
#define main_H
//--------------------------------//
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <math.h>


using namespace std;

string monthString[] =
{
    "January", "February", "March"    , "April"  , "May"     , "June"    ,
    "July"   , "August"  , "September", "October", "November", "December"
};


string dayString[] =
{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };


//array index
const int countday=1000;
const int size=30;

//--------------------------------//
//customer's detail
struct customer
{
    char customname [30];
    int customcount;    //customer's counter
//--------------------------------//
//minimum/maximum order but according to the price
    float minmenu;
    float maxmenu;
    char minimenu[30];
    char maximumenu[30];
    int minquantmenu;
    int maxquantmenu;
//--------------------------------//
};
//--------------------------------//
//getting the current time
struct timing
{
	int year;
	int month;
	int day;
	int hour;
	int mins;
	int secs;
	int weekDay;
};
//--------------------------------//

//specialize for customer's menu order
struct menucustomer
{
//--------------------------------//
//specialize for orders list
    float totalpricemenu[30];
    char allmenu[30][30] ;
    int quantitymenu[30];
    float pricemenu[30];
//--------------------------------//
    float totalprice; //total all including tax
    int ordertaken;   //the number of the order
};
//--------------------------------//

//not available(waiting for the i/o)
struct record
{
    char customname[30];
    float thecustomercount;
    char minmenu[30];
    char maxmenu[30];
    float theminmenu;
    float themaxmenu;
    int minquantmenu;
    int maxquantmenu;

    char allmenu[30][30];
    float quantitymenu[30];
    float pricemenu[30];
    float totalpricemenu[30];
    float totalprice;
    int ordertaken;
};

//--------------------------------//
#endif
