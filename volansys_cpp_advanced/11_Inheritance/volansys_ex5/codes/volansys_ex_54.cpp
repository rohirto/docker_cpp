/**
 * @file volansys_ex_54.cpp
 * @author rohit S
 * @brief Extra Challenges for Inheritance Lesson C++ Advance
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Extra Challenge 4
 * We want to store the information of different vehicles. Create a class named Vehicle with two data member named mileage and price. 
 * Create its two subclasses
 * Car with data members to store ownership cost, warranty (by years), seating capacity and fuel type (diesel or petrol).
 * 
 * Bike with data members to store the number of cylinders, number of gears, cooling type(air, liquid or oil), wheel type(alloys or spokes) and 
 * fuel tank size(in inches)
 * 
 * Make another two subclasses Audi and Ford of Car, each having a data member to store the model type. 
 * 
 * Next, make two subclasses Bajaj and TVS, each having a data member to store the make-type.
 * 
 * Now, store and print the information of an Audi and a Ford car (i.e. model type, ownership cost, warranty, seating capacity, fuel type, mileage 
 * and price.) 
 * 
 * Do the same for a Bajaj and a TVS bike.
 * 
 */

#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

class Vehicle{
protected:
    double mileage;
    double price;

public:
    Vehicle(double m, double p): mileage(m), price(p){}

    void display_decorator()
    {
        cout << "=========================================================\n";
    }

    void display()
    {
        cout << fixed<< "Vehicle Params:\tMileage: "<< setprecision(2) << mileage << "\tPrice: " << price << endl; 
    }

};

class Car: public Vehicle{
protected:
    double ownership_cost;
    int warranty_years;
    int seating_capacity;
    char fuel_type; //Petrol 'p', Diesel 'd'

public:
    Car(double m, double p, double oc, int wy, int sc, char ft):Vehicle(m,p),ownership_cost(oc),warranty_years(wy),seating_capacity(sc),fuel_type(ft){}

    void display()
    {
        
        cout << fixed<< "Car Params:\tOwnership Cost: "<< setprecision(2) << ownership_cost << "\tWarranty Years: " << warranty_years << "\nSeating Capacity: " << seating_capacity 
                << "\tFuel Type (p - Petrol, d Diesel): " << fuel_type<< endl;
        Vehicle::display();
    }
};

class Bike: public Vehicle{
protected:
    int no_of_cylinders;
    int no_of_gears;
    char cooling_type; //Air 'a', Liquid 'l', Oil 'o'
    char wheel_type; //Alloy 'a', Spoked 's'
    double fuel_tank_size; //In inches

public:
    Bike(double m, double p, int noc, int nog, char ct, char wt, double fts):Vehicle(m,p),no_of_cylinders(noc),no_of_gears(nog),cooling_type(ct),wheel_type(wt),fuel_tank_size(fts){}
    
    void display()
    {
        cout << fixed<< "Bike Params:\tNo of Cylinders: " << no_of_cylinders << "\tNo of Gears: " << no_of_gears << "\nCooling Type (Air cooled 'a', Liquid Cooled 'l, Oil cooled 'o): "
         << cooling_type << "\nWheel Type (Spoked 's', Alloy 'a'): " << wheel_type << "\tFuel Tank size in inches: "<< fuel_tank_size << endl;
        Vehicle::display();
    }
};

class Audi: public Car{
protected:
    string model_type;

public:
    Audi(double m, double p, double oc, int wy, int sc, char ft, string mt):Car(m,p,oc,wy,sc,ft),model_type(move(mt)){}
    void display()
    {
        Car::Vehicle::display_decorator();
        cout << "Audi Model Type: " << model_type << endl;
        Car::display();
        Car::Vehicle::display_decorator();
        
    }
};

class Ford: public Car{
protected:
    string model_type;

public:
    Ford(double m, double p, double oc, int wy, int sc, char ft, string mt):Car(m,p,oc,wy,sc,ft),model_type(move(mt)){}

    void display()
    {
        Car::Vehicle::display_decorator();
        cout << "Ford Model Type: " << model_type;
        Car::display();
        Car::Vehicle::display_decorator();
        
    }
};

class Bajaj: public Bike{
protected:
    string model_make;

public:
    Bajaj(double m, double p, int noc, int nog, char ct, char wt, double fts, string mm):Bike(m,p,noc,nog,ct,wt,fts),model_make(move(mm)){}

    void display()
    {
        Bike::Vehicle::display_decorator();
        cout << "Bajaj Model Make: " << model_make << endl;
        Bike::display();
        Bike::Vehicle::display_decorator();
        
    }
};

class TVS: public Bike{
protected:
    string model_make;

public:
    TVS(double m, double p, int noc, int nog, char ct, char wt, double fts, string mm):Bike(m,p,noc,nog,ct,wt,fts),model_make(move(mm)){}
    void display()
    {
        Bike::Vehicle::display_decorator();
        cout << "TVS Model Make: " << model_make << endl;
        Bike::display();
        Bike::Vehicle::display_decorator();
        
        
    }

};


int main()
{
    Audi A4(18,5300000,4771808,10,5,'d',"Audi A4");
    Ford Mustang(7.9,7461000,180000,10,4,'d',"Mustang GT");

    Bajaj Pulsar(35,125000,2,5,'l','a',12,"Pulsar 220F");
    TVS Apache(36,130000,2,5,'a','s',10,"Apache 180");

    A4.display();
    Mustang.display();
    Pulsar.display();
    Apache.display();


    return 0;
}