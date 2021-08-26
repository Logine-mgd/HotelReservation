#include <iostream>
#include "Human.h"
#include "Monster.h"
#include "Guest.h"
#include "Hotel.h"

using namespace std;

int main()
{
    Human h[20];
    Monster m[40];
    Hotel hotel;
    int num,i,x,l,mm,ss,jj;
    i=0;
    x=0;
    bool flag=false;
    string username;
    while(true)
    {
        cout<< "           ******Welcome!*******"<< endl;
        cout<< "press 1 :If this is the first time in our hotel"<< endl;
        cout<< "press 2 :If you have visited us previously"<< endl;
        //when the user inputs a letter the code will handle it
         while(!(cin>>num))
        {
            cout <<"Enter valid number"<< endl;
            cin.clear();
            cin.ignore(123,'\n');
        }
        switch(num)
        {
        case 1:
            cout<< "Creating account"<< endl;
            cout<< "Please write 1 if you are Monster and 2 if you are Human "<< endl;
              while(!(cin>>num))
        {
            cout <<"Enter valid number"<< endl;
            cin.clear();
            cin.ignore(123,'\n');
        }

            cout<< "Please enter your username"<< endl;
            cin>>username;
            //if the guest is a human then we will add him to the list of Human guests and his ID will be an even number
            if(num==2)
            {
                h[i].setName(username);
                x=2*i;
                h[i].setID(x);
                cout<< "Your account is created "<< endl;
                cout<< "Your id is "<<x<< endl;
                i++;
            }
            //if the guest is a monster then we will add it to the list of monster guests and its ID will be an odd number
            else if(num==1)
            {
                m[i].setName(username);
                x=2*i+1;
                m[i].setID(x);
                cout<< "Your account is created "<< endl;
                cout<< "Your id is "<<x<< endl;
                i++;
            }

            break;


        case 2:
            cout<< "Please enter your ID"<< endl;
              while(!(cin>>num))
        {
            cout <<"Enter valid number"<< endl;
            cin.clear();
            cin.ignore(123,'\n');
        }
             for(ss=0;ss<i;ss++)
                    {
                        if(num%2==0)  jj=h[ss].getID();
                        else          jj=m[ss].getID();
                        if(jj==num)
                    {
                        jj=ss;
                cout<< "press 1 :If you want a new reservation"<< endl;
                cout<< "press 2 :If you want to extend your reservation"<< endl;
                cout<< "press 3 :If you want any additional service"<< endl;
                cout<< "press 4 :If you want to Cancel your reservation"<< endl;
                  while(!(cin>>ss))
        {
            cout <<"Enter valid number"<< endl;
            cin.clear();
            cin.ignore(123,'\n');
        }
                switch(ss)
                {
            case 1:
                cout<< "How many rooms do you want to reserve?"<< endl;
                 while(!(cin>>l))
        {
            cout <<"Enter valid number"<< endl;
            cin.clear();
            cin.ignore(123,'\n');
        }

                cout<< "Please write the number of nights you want to stay"<< endl;
                  while(!(cin>>mm))
        {
            cout <<"Enter valid number"<< endl;
            cin.clear();
            cin.ignore(123,'\n');
        }

                if(num%2==0)
                {
                    flag= hotel.countN_occupiedroomsH(l);
                    //If there is available rooms then the total cost will be shown
                    if(flag)
                        cout<<  h[jj].getTotalCost(l,mm,0,0)<< endl;
                     h[jj].inc_decReservedRooms(l,mm);
                }
                else
                {
                    flag=hotel.countN_occupiedroomsM(l);

                    //If there is available rooms then the total cost will be shown
                    if(flag)
                        cout<<"Total cost is "<<m[jj].getTotalCost(l,mm,0,0)<< endl;
                    m[jj].inc_decReservedRooms(l,mm);
                }
                break;

            case 2:
                cout<< "How many extra nights do you want to reserve?"<< endl;
                 while(!(cin>>x))
        {
            cout <<"Enter valid number"<< endl;
            cin.clear();
            cin.ignore(123,'\n');
        }
                int r;
                 if(num%2==0)
                {
    //Function increaseReservedRooms is called to return the number of rooms that was reserved before so that we can count the totCost
                r=h[jj].inc_decReservedRooms(0,0);
                cout<< "cost of additional nights" <<h[jj].getTotalCost(r,x,0,0)<< endl;}
                else {
                     r=m[jj].inc_decReservedRooms(0,0);
                     cout<< "cost of additional nights"<< m[jj].getTotalCost(r,x,0,0)<< endl;}

                  break;
            case 3:
                int numnight;
                 if(num%2==0)
                {
    //Function increaseReservedRooms is called to return the number of rooms that was reserved before so that we can count the totCost
                r=h[jj].inc_decReservedRooms(0,0);
                numnight=h[jj].numberofnights();
                }
                else {
                     r=m[jj].inc_decReservedRooms(0,0);
                     numnight=m[jj].numberofnights();
                }
                cout<< "press 1 :If you want to take a spa"<< endl;
                cout<< "press 2 :If you want Dry cleaning"<< endl;
                cout<< "press 3 :If you want both"<< endl;
                  while(!(cin>>ss))
        {
            cout <<"Enter valid number"<< endl;
            cin.clear();
            cin.ignore(123,'\n');
        }
            cout<<numnight<<endl;
                if(ss==1)
                {
                     if(num%2==0) {cout<< h[jj].getTotalCost(r,numnight,1,0)<<endl;}
                     else {cout<<m[jj].getTotalCost(r,numnight,1,0)<<endl;}
                }
                else if(ss==2)
                {
                    if(num%2==0) {cout<<h[jj].getTotalCost(r,numnight,0,1)<<endl;}
                     else {cout<<m[jj].getTotalCost(r,numnight,0,1)<<endl;}

                } else if(ss==3)
                {
                  if(num%2==0) cout<<h[jj].getTotalCost(r,numnight,1,1)<<endl;
                     else {cout<<m[jj].getTotalCost(r,numnight,0,1)<<endl;}

                }
                 else{}
               break;
            case 4:
                cout<< " Press 1 if you want to cancel all the reservation"<< endl;
                cin>>ss;
                if(ss==1)
                {
                    r=m[jj].inc_decReservedRooms(0,0);
                     int p= m[jj].numberofnights();

                    m[jj].inc_decReservedRooms(-r,p);
                }
               break;
            }
                    //Flag to say if the ID is found or not
                    flag=true;
                    break;
                    }}
                    if(!flag) cout<<" There isn't such ID "<<endl;
            break;

        default:
            cout<< "Invalid number"<< endl;

        }
    }
    return 0;
}
