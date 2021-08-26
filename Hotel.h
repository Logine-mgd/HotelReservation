#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>

using namespace std;
class Hotel
{
    public:
        Hotel();
    int MonsterRooms=15;
    int HumanRooms=5;
    int occupiedMonsterRooms=0;
    int occupiedHumanRooms=0;
    int countN_occupiedroomsH(int n)
    {
        if((occupiedHumanRooms+n)<=HumanRooms)
       {
         occupiedHumanRooms+=n;
         return true;
       }
        else{
        cout<<"There isn't available rooms" <<endl;
        return false;}
    }

    int countN_occupiedroomsM(int n)
    {
        if((occupiedMonsterRooms+n)<=MonsterRooms)
        {occupiedMonsterRooms+=n;

          return true;}
        else {
        cout<<"There isn't available rooms" << endl;
        return false;
    }}
};

#endif // HOTEL_H
