#ifndef CAR_H
#define CAR_H

class Car {
private:
    int year;
    string make;
    int speed;
public:
    Car();
    Car(int y, string m);
    void setyear(int r) { year = r; }
    int getspeed() { return speed; }
    void Accelerate();
    void brake();
};
#endif 


