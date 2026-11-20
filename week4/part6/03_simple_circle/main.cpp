#include<iostream>
#include<cmath>
using namespace std;
class SimpleCircle{
private:
    double *itsRadius;
public:
    SimpleCircle(double radius);
    ~SimpleCircle();
    void setradius(double r);
    double getradius() const;
    double getarea() const;
};
SimpleCircle::SimpleCircle(double radius){itsRadius = new double(radius) ;}
SimpleCircle::~SimpleCircle(){delete itsRadius;}
void SimpleCircle::setradius(double r){*itsRadius=r;}
double SimpleCircle::getradius()const{return *itsRadius;}
double SimpleCircle::getarea()const{return pow(*itsRadius,2)*3.1415926;}
int main(){
    double r;
    cout<<"please input the radious: ";
    cin >>r;
    SimpleCircle c(r);
    c.setradius(r);
    cout<<"radius is: "<<c.getradius();
    cout<<"\narea is "<<c.getarea();
    return 0;
}