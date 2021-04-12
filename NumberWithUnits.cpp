#include "NumberWithUnits.hpp"
using namespace std;
namespace ariel{
    NumberWithUnits n(1.0,"Pickles") ;
    void NumberWithUnits::read_units(ifstream& units_file){

    }
    int convert (const NumberWithUnits& a,const NumberWithUnits& b){
        return 0;
    }
    NumberWithUnits operator+(const NumberWithUnits& a,const NumberWithUnits& b){
        return n ;
    }
    NumberWithUnits operator+(const NumberWithUnits& a,const double b){
        return n ;
    }
    NumberWithUnits operator+(const double a,const NumberWithUnits& b){
        return n ;
    }
    NumberWithUnits operator+=(const NumberWithUnits& a,const NumberWithUnits& b){
        return n ;
    }
    NumberWithUnits operator-(const NumberWithUnits& a,const NumberWithUnits& b){
        return n ;
    }
    NumberWithUnits operator-(const NumberWithUnits& a,const double b){
        return n ;
    }
    NumberWithUnits operator-(const double a,const NumberWithUnits& b){
        return n ;
    }
    NumberWithUnits operator-(const NumberWithUnits& a){
        return n ;
    }
    NumberWithUnits operator-=(const NumberWithUnits& a,const NumberWithUnits& b){
        return n ;
    }
    bool operator<(const NumberWithUnits& a,const NumberWithUnits& b){
        return true;
    }
    bool operator<=(const NumberWithUnits& a,const NumberWithUnits& b){
        return true;
    }
    bool operator>(const NumberWithUnits& a,const NumberWithUnits& b){
        return true;
    }
    bool operator>=(const NumberWithUnits& a,const NumberWithUnits& b){
        return true;
    }
    bool operator==(const NumberWithUnits& a,const NumberWithUnits& b){
        return true;
    }
    bool operator!=(const NumberWithUnits& a,const NumberWithUnits& b){
        return true;
    }
    NumberWithUnits operator++(const NumberWithUnits& a){
        return n ;
    }
    NumberWithUnits operator++(const NumberWithUnits& a,int){
        return n ;
    }
    NumberWithUnits operator--(const NumberWithUnits& a){
        return n ;
    }
    NumberWithUnits operator--(const NumberWithUnits& a,int){
        return n ;
    }
    NumberWithUnits operator*(const NumberWithUnits& a,const double b){
        return n ;
    }
    NumberWithUnits operator*(const double a,const NumberWithUnits& b){
        return n ;
    }
    ostream& operator<<(ostream& os, const NumberWithUnits& a){
        return os;
    }
    istream& operator>>(istream& is, NumberWithUnits& a){
        return is;
    }        
}
