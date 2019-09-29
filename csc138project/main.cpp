#include "main.h"
#include "functions.h"


timing getTm();

int main()
{
    timing customertime;
    customer day1[countday];    //initialize for struct 'customer'
    menucustomer day2[countday];//initialize for struct 'menucustomer'
    record day3[countday];


    char decision='y',maindecision='y';
    int countnow=0;
    cout<<"What do you want me to do?\nY-Record File\nN-Taking Customer's Order";
    repeat(maindecision);//clrscrn();

    if(maindecision=='y')
    {
    do
    {
        int order=0; //Initialize the struct member of menucustomer.


        do
        {
            day1[countnow]=custdetail1(countnow); //getting customer's detail

            cout<<"Do you want to edit?(Y/N)\nInput:";
            repeat(decision);//clrscrn(); //clearscreen

        }while(decision=='n'||decision=='N');

        customertime=getTm();  //getting current time

        do
        {
            int a=0,b=0,c=0;    //declaring for food menu decision...

            //clrscrn();

            cout<<"TAKING ORDER:\n(1=Burger 2=Beverage 3=Nugget 4=French Fries)\nInput:";
            cin>>a;

            if(a==1)
            {displaymenu1(b,c);}
            else
            {displaymenu2(a);cin>>b;}


            if(a==1)
            {menutype1(day2,countnow,order,b,c);}

            else
            {menutype2(day2,countnow,order,a,b);}

            day2[countnow].totalpricemenu[order]=totalpricemenu(day2,countnow,order);

            //clrscrn();  //clearscreen
            cout<<"Do you want to edit?(Y/N\nInput";    //editing order
            repeat(decision);//clrscrn();

            while((decision=='y'||decision=='Y')==0)
            {
                displayorder(day2,countnow,order);

                if(a==1)
                {displaymenu1(b,c);}
                else
                {displaymenu2(a);cin>>b;}


                if(a==1)
                {menutype1(day2,countnow,order,b,c);}

                else
                {menutype2(day2,countnow,order,a,b);}

                day2[countnow].totalpricemenu[order]=totalpricemenu(day2,countnow,order);

                repeat(decision);
            }
            cout<<"\nDo to add more the order?(Y/N)\nInput:";   //adding an order
            repeat(decision);//clrscrn();

            day2[countnow].ordertaken=order+1;
            order++;

        }while((decision=='y'||decision=='Y')==0);

        maximumorder(day1,day2,countnow,order); //to find the maximum order that been ordered by customer
        minimumorder(day1,day2,countnow,order); //to find the minimum order that been ordered by customer

        day2[countnow].totalprice=totaleverything(day2,countnow,order);

        if(order>0)
        {sortingorder(day2,countnow,order);} //sorting the order

        receipt(day1,day2,customertime,countnow,order);   //showing the receipt
        engagingdata(day1,day2,day3,countnow,order);

        countnow++;
        cout<<"\nDo you want to continue? Y/N\nInput:";
        repeat(decision);//clrscrn();


    }while(decision=='n'||decision=='N');
    }//maindecision if closed

    return 0;
};

