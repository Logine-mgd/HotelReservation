#ifndef MONSTER_H
#define MONSTER_H
#include "Guest.h"
#include "Hotel.h"
using namespace std;

class Monster :public Guest
{
    public:
        Monster();
        int Dryclean=30;
        int night=200;
        int Spa=50;
        int price=0;
        int reservedRooms=0;
        int numnight=0;
        Hotel hotel;
        //increase number of reserved rooms of each guest by a certain number
    int inc_decReservedRooms(int n,int k)
    {
        hotel.countN_occupiedroomsM(n);
        reservedRooms+=n;
        numnight+=k;
        return reservedRooms;
    }
    int numberofnights()
    {
        return numnight;
    }

    int getTotalCost(int l, int m,int s,int D)
    //where m is number of nights,s and D are to say if the customer wants a spa or Drycleaning
    {
        price= l*m*night+m*s*Spa+m*D*Dryclean;
        return price;
    }
};

#endif // MONSTER_H
