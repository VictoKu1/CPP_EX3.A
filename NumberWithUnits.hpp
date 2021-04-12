#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;
namespace ariel{
    class NumberWithUnits{
        private:
            double number;
            string unit;
        public:
            NumberWithUnits(double number,string unit){
                (*this).number=number;
                (*this).unit=unit;
            }
            static void read_units(ifstream& units_file);
            friend int convert (const NumberWithUnits& a,const NumberWithUnits& b);
            friend NumberWithUnits operator+(const NumberWithUnits& a,const NumberWithUnits& b);
            friend NumberWithUnits operator+(const NumberWithUnits& a,const double b);
            friend NumberWithUnits operator+(const double a,const NumberWithUnits& b);
            friend NumberWithUnits operator+=(const NumberWithUnits& a,const NumberWithUnits& b);
            friend NumberWithUnits operator-(const NumberWithUnits& a,const NumberWithUnits& b);
            friend NumberWithUnits operator-(const NumberWithUnits& a,const double b);
            friend NumberWithUnits operator-(const double a,const NumberWithUnits& b);
            friend NumberWithUnits operator-(const NumberWithUnits& a);
            friend NumberWithUnits operator-=(const NumberWithUnits& a,const NumberWithUnits& b);
            friend bool operator<(const NumberWithUnits& a,const NumberWithUnits& b);
            friend bool operator<=(const NumberWithUnits& a,const NumberWithUnits& b);
            friend bool operator>(const NumberWithUnits& a,const NumberWithUnits& b);
            friend bool operator>=(const NumberWithUnits& a,const NumberWithUnits& b);
            friend bool operator==(const NumberWithUnits& a,const NumberWithUnits& b);
            friend bool operator!=(const NumberWithUnits& a,const NumberWithUnits& b);
            friend NumberWithUnits operator++(const NumberWithUnits& a);
            friend NumberWithUnits operator++(const NumberWithUnits& a,int);
            friend NumberWithUnits operator--(const NumberWithUnits& a);
            friend NumberWithUnits operator--(const NumberWithUnits& a,int);
            friend NumberWithUnits operator*(const NumberWithUnits& a,const double b);
            friend NumberWithUnits operator*(const double a,const NumberWithUnits& b);
            friend ostream& operator<<(ostream& os, const NumberWithUnits& a);
            friend istream& operator>>(istream& is, NumberWithUnits& a);
    };
}

