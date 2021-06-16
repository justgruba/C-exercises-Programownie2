#include <iostream>
#include <vector>
using namespace std;
class Shape{
public:
   virtual void draw(){
        cout << "draw shape" << endl;
    }
};
class Circle: public virtual Shape{
public:
    void draw(){
        cout << "draw circle" << endl;
    }
};
class Square: public  virtual Shape{
public:
    void draw(){
        cout << "draw square" << endl;
    }
};
class Triangle: public virtual Shape{
public:
    void draw(){
        cout << "draw triangle";
    }
};
class Rodent{
public:
    virtual void name() =0;

    virtual ~Rodent()
    {
        cout << "deleted Rodent";
    }
};
class Mouse: public Rodent{
public:
    virtual void name(){
        cout << "Mouse" << endl;
    }
    ~Mouse()
    {
        cout << "deleted Mouse";
    }
};
class Gerbil: public Rodent{
public:
    virtual void name(){
        cout << "Gerbil" << endl;
    }
    ~Gerbil()
    {
        cout << "deleted Gerbil" << endl;
    }
};
class Hamster: public Rodent{
public:
    virtual void name(){
        cout << "Gerbil" << endl;
    }
    ~Hamster()
    {
        cout << "deleted Hamser" << endl;
    }
};
class BlueHamster: public Hamster{
public:
    virtual void name(){
        cout << "Blue Hamster" << endl;
    }
    ~BlueHamster()
    {
        cout << "deleted BlueHamster" << endl;
    }
};
class AirCraft{
public:
    virtual int getSpeed() = 0;
    virtual void  setSpeed(int n) = 0;
};
class Plane: public AirCraft{
private:
    int num;
    int speed;
public:
    Plane(int n){
        num =n;
        speed = 0;
    }
    int virtual getSpeed(){
       return speed;
    }
    void virtual setSpeed(int speed){
        this->speed = speed;
    }
    virtual ~Plane()
    {
        cout << "Plane deleted" << endl;
    }
};
class Helicopter: public  AirCraft{
private:
    int num;
    int speed;
public:
    Helicopter(int n){
        num =n;
        speed=0;

    }
   virtual int  getSpeed(){
        return speed;
    }
   virtual void  setSpeed(int speed){
        this->speed = speed;
    }
    virtual ~Helicopter()
    {
        cout << "Helicopter deleted" << endl;
    }
};
class AirBaloon: public  AirCraft{
private:
    int speed;
public:
    AirBaloon(int s){
        speed =s;
    }
    int virtual getSpeed(){
        return speed;
    }
    void virtual setSpeed(int speed){
        this->speed = speed;
    }
    virtual ~AirBaloon()
    {
        cout << "Helicopter deleted" << endl;
    }
};
class Tower{
    vector<AirCraft*> aircraft;
public:
    void add(AirCraft& aircrafts){
        aircraft.push_back(&aircrafts);
    }
    void addSpeed(){
        for(int i=0; i< aircraft.size(); i++){
            aircraft[i]->setSpeed(i);
        }
    }
    void getSpeed(){
        for(int i=0; i< aircraft.size(); i++){
           cout <<  aircraft[i]->getSpeed() << endl;
        }
    }
};
int main() {
 /*   Triangle t; t.draw();
    Square s; s.draw();

    vector<Rodent*> r;
    r.push_back(new Hamster);
    r.push_back(new Mouse);
    r.push_back(new Gerbil);
    r.push_back(new BlueHamster);

    Rodent* tmp;
    while(!r.empty()){
        tmp = r.back();
        tmp->name();
        r.pop_back();
        delete tmp;
    } */
    Tower tower;
    Helicopter h(399);
    Plane p(111);
    Plane p2(112);
    tower.add(p);
    tower.add(h);
    tower.add(p2);
    tower.addSpeed();
    tower.getSpeed();
    return 0;
}
