#ifndef HUMAN_H
#define HUMAN_H
#include "Hotel.h"
#include "Guest.h"
using namespace std;

class Human :public Guest
{
    public:
        Human();
        int Dryclean=70;
        int night=500;
        int Spa=100;
        int reservedRooms=0;
        int numnight=0;
        int price;
        Hotel hotel;

    //increase or decrease number of reserved rooms of each guest by a certain number
    int inc_decReservedRooms(int n,int k)
    {
        hotel.countN_occupiedroomsH(n);
        reservedRooms+=n;
        numnight+=k;
        return reservedRooms;
    }
    int numberofnights()
    {
        return numnight;
    }
   int getTotalCost(int l, int m,int s,int D)
    {
        price=l*m*night+m*s*Spa+m*D*Dryclean;
        return price;
    }

};

#endif // HUMAN_H
