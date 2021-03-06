#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include <iostream> 
#include <string> // string 
using namespace std; 

class Circle 
{
    private: //Attribute sind immer privat
    float radius; 
    Vec2 center;
    Color color; 

//Aufgabe 3.4
    string name; 

    
    public: //Methoden und Konstruktor sind öffentlich
    Circle (); 
    Circle (string const& _name);
    Circle (float _radius, Vec2 const& _center, Color const& _color,
            string const& _name);
    Circle (float const& _radius);
   

    Vec2 get_center() const;
    float get_radius() const; 
    Color get_color() const;  
    float get_circumference () const; 
    string get_name () const; 

//Aufgabe 2.11    
    bool is_inside (Vec2 const& point) const;


//Aufgabe 3.4 
    
    ostream& print (ostream& os) const;
};

    bool operator < (Circle const& lhs, Circle const& rhs); //left hand side und right hand side, logisch wegen links und rechts Vergleich
    bool operator > (Circle const& lhs, Circle const& rhs);
    bool operator == (Circle const& lhs, Circle const& rhs); 

    ostream& operator<< (ostream& os, const Circle& c);    


#endif