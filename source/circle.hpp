#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include <iostream> 
#include <string> // std::string 


class Circle 
{
    private: //Attribute sind immer privat
    float radius; 
    Vec2 center;
    Color color; 

//Aufgabe 3.4
    std::string name_; 

    
    public: //Methoden und Konstruktor sind öffentlich
    Circle (); 
    Circle (float _radius, Vec2 const& _center, Color const& _color,
            std::string const& _name);
   

    Vec2 get_center() const;
    float get_radius() const; 
    Color get_color() const;  
    float get_circumference () const; 

//Aufgabe 2.11    
    bool is_inside (Vec2 const& point) const;
    

//Aufgabe 3.4 
    std::ostream& print (std::ostream& os) const;

};

    std::ostream& operator<< (std::ostream& os, const Circle& c); 


#endif