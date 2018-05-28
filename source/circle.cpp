#include "circle.hpp"
#include <iostream>
#include <cmath>

//Aufgabe 2.8 

Circle::Circle ():
  radius{1.0f},
  center{0.0f,0.0f},
  color{0.0f,0.0f,0.0f},
  name{"default_name"}
  {} 
  
Circle::Circle (std::string const& _name):
  radius{1.0f},
  center{0.0f,0.0f},
  color{0.0f,0.0f,0.0f},
  name{_name}
  {}


Circle::Circle (float _radius, Vec2 const& _center, Color const& _color, std::string const& _name):
  radius{_radius},
  center{_center},
  color{_color},
  name{_name}
  {}

//Aufgabe 3.14

Circle::Circle (float const& _radius):
  radius{-radius},
  center{0.0f,0.0f},
  color{0.0f,0.0f,0.0f},
  name{"default_name"}
  {}


Vec2 Circle::get_center() const
{
  return center; 
}

float Circle::get_radius() const
{
  return radius;
}

Color Circle::get_color() const
{
  return color;
}

//Aufgabe 2.9 

float Circle::get_circumference () const
{
  float circumference = 2*(M_PI)*get_radius();
  return circumference;
}



//Aufgabe 2.13

bool Circle::is_inside (Vec2 const& point) const
{
  if (pow ((center.x - point.x) , 2) + pow ((center.y-point.y) , 2) <= pow (radius ,2))
  {
    return true;
  }
  else {
    return false;
  }
}

//Aufgabe 3.4 / 3.6
//anhand des radius kann nun der Circle sortiert werden

bool operator < (Circle const& lhs, Circle const& rhs) //hier wird der kleiner operator definiert
{  
  if (lhs.get_radius() < rhs.get_radius() ) 
  {
    return true; 
  }
  else 
  {
    return false;
  }
}

bool operator > (Circle const& lhs, Circle const& rhs)
{
  if (lhs.get_radius() > rhs.get_radius() )
  {
    return true; 
  }  
  else 
  {
    return false;
  }
}

bool operator == (Circle const& lhs, Circle const& rhs)
{
  if (lhs.get_radius() == rhs.get_radius())
  {
    return true;
  }
  else 
  {
    return false;
  }
} 


std::string Circle::get_name() const
{
  return name;
}


std::ostream& operator<<(std::ostream& os, const Circle& c) 
{  
  return c.print(os);
 
}

std::ostream& Circle::print (std::ostream& os) const 
{
  os << "Name: " << name  << "\n"
     << "Position: " << center.x << "," << center.y << "\n"
     << "Farbe: " << color.r << "," << color.g << "," << color.b  << "\n"
     << "Radius: " << radius << "\n"; 
  return os;
  
}


