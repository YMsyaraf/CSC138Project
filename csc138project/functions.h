#include "main.h"


customer custdetail1(int countnow)
{
    customer detail;
    int i=countnow;

    cout<<"\nCustomer's name:";
    cin>>detail.customname;

    cout<<"\nThis is number for the customer:"<<i+1<<'\n';
    detail.customcount=i+1;

    return detail;
}

void displaymenu1(int b,int c)
{
        cout<<"1=Regular 2=Special 3=Double 4=Big Burger Lover\nInput:";
        cin>>b;
    if(b==1)
    {
        cout<<"\n1=Benjo(RM2.00)\n2=Beef(RM2.50)\n3=Chicken(RM2.50)\n4=Fish(RM3.50)\n5=Rabbit(RM4.00)\n5=Deer(RM6.00)\n";
        cin>>c;
    }

    if(b==2)
    {
        cout<<"\n2=Beef(RM3.50)\n3=Chicken(RM3.50)\n4=Fish(RM4.50)\n5=Rabbit(RM5.00)\n5=Deer(RM7.00)\n";
        do{cin>>c;}while(c==0);
    }

    if(b==3)
    {
        cout<<"\n2=Beef(RM5.00)\n3=Chicken(RM5.500)\n4=Fish(RM7.00)\n5=Rabbit(RM8.00)\n5=Deer(RM12.00)\n";
        do{cin>>c;}while(c==0);
    }

    if(b==4)
    {
        cout<<"\n2=Beef(RM8.50)\n3=Chicken(RM8.50)\n4=Fish(RM10.50)\n5=Rabbit(RM13.00)\n5=Deer(RM18.00)\n";
        do{cin>>c;}while(c==0);
    }

}

void displaymenu2(int a)
{
    if(a==2)
    {cout<<"\n1=Coke(RM1.50)\n2=Sprint(RM1.50)\n3=Pepsi(RM1.50)\n4=Milo(RM2.50)\n5=Coffee(RM2.00)\n6=Lemon Tea(RM2.00)\n\n";}

    if(a==3)
    {cout<<"\n1=Nugget Small(RM3.50)\n2=Nugget Medium(RM5.50)\n3=Nugget Large(RM7.00)\n4=Nugget Super Large(RM8.00)\n\n";}

    if(a==4)
    {cout<<"\n1=Fries Small(RM3.00)\n2=FrIES Medium(RM4.50)\n3=Fries Large(RM6.00)\n4=Fries Super Large(RM7.00)\n\n";}
}

void menutype1(menucustomer day2[],int countnow,int order,int b,int c)
{
    char burger1[4][6][30]=
    {
        {"Benjo"    ,"Beef"           ,"Chicken"           ,"Fish"           ,"Rabbit"           ,"Deer"           },
        {"no option","Beef Special"   ,"Chicken Special"   ,"Fish Special"   ,"Rabbit Special"   ,"Deer Special"   },
        {"no option","Beef Double"    ,"Chicken Double"    ,"Fish Double"    ,"Rabbit Double"    ,"Deer Double"    },
        {"no option","Big Beef Burger","Big Chicken Burger","Big Fish Burger","Big Rabbit Burger","Big Deer Burger"}
    };

    float burger2[4][6]=
    {
        {2.00,2.50,2.50, 3.50, 4.00, 6.00},
        {   0,3.50,3.50, 4.50, 5.00, 7.00},
        {   0,5.00,5.00, 7.00, 8.00,12.00},
        {   0,7.50,7.50,10.50,12.00,17.00},
    };
//-------------------------------------------------------------//
//copying data from array into 'menucustomer' struct

    strcpy( day2[countnow].allmenu[order] , burger1[b][c] );
    day2[countnow].pricemenu[order] = burger2[b][c];
//-------------------------------------------------------------//

    cout<<"\nHow much do you want?\n";
    cin>>day2[countnow].quantitymenu[order];
}

void menutype2(menucustomer day2[],int countnow,int order,int a,int b)
{

    char
    beverage1[6][30]=
    {"Coke","Sprint","Pepsi","Coffee","Lemon Tea"},
    nugget1[4][30]=
    {"Nugget Small","Nugget Medium","Nugget Large","Nugget Super Large"},
    frenchfries1[4][30]=
    {"Small Fries","Medium Fries","Large Fries","Super Large Fries"};


    float
    beverage2[6]=
    {1.50,1.50,1.50,2.50,2.00,2.00},
    nugget2[4]=
    {3.00,5.50,7.00,8.00},
    frenchfries2[4]=
    {3.00,4.50,6.00,7.00};
//-------------------------------------------------------------//
//copying data from array into 'menucustomer' struct
    if(a==2)
    {
    strcpy( day2[countnow].allmenu[order] , beverage1[b] );
    day2[countnow].pricemenu[order] = beverage2[b];
    }

    if(a==3)
    {
    strcpy( day2[countnow].allmenu[order] , nugget1[b]);
    day2[countnow].pricemenu[order] = nugget2[b];
    }


    if(a==4)
    {
    strcpy( day2[countnow].allmenu[order] , frenchfries1[b]);
    day2[countnow].pricemenu[order] = frenchfries2[b];
    }
//-------------------------------------------------------------//
    cout<<"\nHow much do you want?\n";
    cin>>day2[countnow].quantitymenu[order];
}

void displayorder(menucustomer day2[],int countnow, int order)
{
    cout<<"\nMenu      :"<<day2[countnow].allmenu[order]
        <<"\nQuantity  :"<<day2[countnow].quantitymenu[order]
        <<"\nPrice Menu:"<<day2[countnow].pricemenu[order]
        <<"\nTotal     :"<<day2[countnow].totalpricemenu[order];


}

float totalpricemenu(menucustomer day2[],int countnow,int order)
{
    int total;
    day2[countnow].totalpricemenu[order]=day2[countnow].pricemenu[order]*day2[countnow].quantitymenu[order];
    total=day2[countnow].totalpricemenu[order];

    return total;

}

void sortingorder(menucustomer day2[], int countnow, int order) //array for sorting is
{                                                               //day2[countnow].allmenu[order]
    int result,size=day2[countnow].ordertaken;

    for(int pass=0;pass<size-1;++pass)                  //a=3 b=2  sat=a  if a>b   a=b b=sat
    {
        for (int j=0;j<size-1-pass;++j)
        {
            result=strcmp(day2[countnow].allmenu[j],day2[countnow].allmenu[j+1]);

            if(result>0)
            {
                swap(day2[countnow].allmenu[j],day2[countnow].allmenu[j+1]);
                swap(day2[countnow].pricemenu[j],day2[countnow].pricemenu[j+1]);
                swap(day2[countnow].quantitymenu[j],day2[countnow].quantitymenu[j+1]);
                swap(day2[countnow].totalpricemenu[j],day2[countnow].totalpricemenu[j+1]);
            }

        }
    }
}

void minimumorder(customer day1[],menucustomer day2[],int countnow,int order)
{
    float minimum;
        int minindex;

   minimum=day2[countnow].pricemenu[0] * day2[countnow].quantitymenu[0];


    for (int i=0;i<order;i++)
    {
        if (minimum < (day2[countnow].pricemenu[i] * day2[countnow].quantitymenu[i]))
            {
                minimum = day2[countnow].pricemenu[i] * day2[countnow].quantitymenu[i];
                minindex= i;
            }
    }
    strcpy(day1[countnow].minimenu, day2[countnow].allmenu[minindex]);
    day1[countnow].minmenu=minimum;
    day1[countnow].minquantmenu=day2[countnow].quantitymenu[minindex];
}

void maximumorder(customer day1[],menucustomer day2[],int countnow,int order)
{
    float maximum;
    int maxindex;

    maximum=day2[countnow].pricemenu[0] * day2[countnow].quantitymenu[0];


    for (int i=0;i<order;i++)
    {
        if (maximum > (day2[countnow].pricemenu[i] * day2[countnow].quantitymenu[i]))
            {
                maximum = day2[countnow].pricemenu[i] * day2[countnow].quantitymenu[i];
                maxindex= i;
            }
    }
    strcpy(day1[countnow].maximumenu,day2[countnow].allmenu[maxindex]);
    day1[countnow].maxmenu=maximum;
    day1[countnow].maxquantmenu=day2[countnow].quantitymenu[maxindex];

}

float totaleverything(menucustomer day2[],int countnow,int order)
{
    float total=0;

    for(int i=0;i<(order+1);i++)
        {
            total+=day2[countnow].totalpricemenu[i];
        }

    total+= (total*10/100);
    return total;

}

void receipt(customer day1[],menucustomer day2[],timing customertime,int countnow,int order)
{


        cout<<'\n';
        cout<<"||----------------------WELCOME TO THE BURGER SHOP--------------------||"<<endl
            <<"   MENU ORDER RECEIPT:                                                  "<<endl
            <<"   NAME            :"<<day1[countnow].customname                         <<endl;
        cout<<"   CUSTOMER NNUMBER:"<<day1[countnow].customcount                        <<endl
            <<"------------------------------------------------------------------------"<<endl
            <<"NO.     DESCRIPTION                     QTY    PRICE         TOTAL      "<<endl;

   for(int i=0;i<order;i++)
    {

        cout<<i+1                             <<"     ";

        cout<<setw(30)<<day2[countnow].allmenu[i]                               <<"  "
            <<setw(4) <<fixed<<setprecision(0)<<day2[countnow].quantitymenu[i]  <<"     "
            <<"RM"    <<fixed<<setprecision(2)<<day2[countnow].pricemenu[i]     <<"     "
            <<"RM"    <<fixed<<setprecision(2)<<day2[countnow].totalpricemenu[i]<<endl;
    }
        cout<<"------------------------------------------------------------------------"                      <<endl
            <<"THE TOTAL PRICE(INCLUDE TAX):RM"<<fixed<<setprecision(2)<<day2[countnow].totalprice            <<endl
            <<"THE ORDER(S) THAT BEEN TAKEN:"  <<fixed<<setprecision(2)<<day2[countnow].ordertaken            <<endl
            <<"MAXIMUM			          :RM" <<day1[countnow].maximumenu<<"("<<day1[countnow].maxmenu<<")"  <<endl
            <<"MINIMUM			          :RM" <<day1[countnow].minimenu  <<"("<<day1[countnow].minmenu<<")"  <<endl;

        cout<<"Date: "<<dayString[customertime.weekDay]
            <<", "    <<customertime.day
            << " "    <<monthString[customertime.month]
            <<" "     <<customertime.year<<endl;


        cout<<"Time: "<<setfill( '0' )<<setw(2)<<customertime.hour
            << ":"    <<setfill( '0' )<<setw(2)<<customertime.mins
            << "."    <<setfill( '0' )<<setw(2)<<customertime.secs

            <<"\n||---------------------------------END--------------------------------||"                 <<endl;

}

void engagingdata(customer day1[],menucustomer day2[],record day3[],int countnow,int order) //engaging the data for i/o files
{

    strcpy(day3[countnow].customname,day1[countnow].customname);

    day3[countnow].thecustomercount=day1[countnow].customcount ;

    strcpy( day3[countnow].minmenu , day1[countnow].minimenu   );
    strcpy( day3[countnow].maxmenu , day1[countnow].maximumenu );

    day3[countnow].theminmenu = day1[countnow].minmenu;
    day3[countnow].themaxmenu = day1[countnow].maxmenu;

    day3[countnow].minquantmenu = day1[countnow].minquantmenu;
    day3[countnow].maxquantmenu = day1[countnow].maxquantmenu;

    for(int i=0;i<(order+1);i++)
    {
        strcpy(   day3[countnow].allmenu[i] , day2[countnow].allmenu[i]   );

        day3[countnow].quantitymenu[i]  = day2[countnow].quantitymenu[i]   ;
        day3[countnow].pricemenu   [i]  = day2[countnow].totalpricemenu[i] ;

    }

    day3[countnow].totalprice=day2[countnow].totalprice;
    day3[countnow].ordertaken=day2[countnow].ordertaken;

}//tak perlu

void repeat(char decision) //looping for wrong decision//
{
    cin>>decision;

    while((decision=='Y'||decision=='y'||decision=='N'||decision=='n')==0)
    {
            cout<<"\nWrong Decision!!\n"<<"Do you want to edit?(Y/N)\nInput:";
            cin>>decision;
    }

}


//......SPECIAL THINGS.......//
timing getTm() //fetching the current time from system//
{
    timing customertime;
    time_t tt;
    time( &tt );
    tm TM = *localtime( &tt );

    customertime.year= TM.tm_year + 1900;
    customertime.month= TM.tm_mon       ;
    customertime.day= TM.tm_mday        ;
    customertime.hour= TM.tm_hour       ;
    customertime.mins= TM.tm_min        ;
    customertime.secs= TM.tm_sec        ;
    customertime.weekDay= TM.tm_wday    ;

   return customertime;
}

/*
void clrscrn() //clear the screen//
{//cout << "\033[2J\033[1;1H";
  printf("\033c");
}
*/

