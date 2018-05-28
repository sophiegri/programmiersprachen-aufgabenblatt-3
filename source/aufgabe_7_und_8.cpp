#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"
#include <iostream>
#include <algorithm> 
#include <vector> 
#include <functional>
using namespace std; 

//Aufgabe 3.7 Lambda

Circle c_1 {370.0f, Vec2 (400.0f, 400.0f), Color (0.0f, 0.6f, 0.0f), "Kreis_1"};
Circle c_2 {290.0f, Vec2 (200.0f, 200.0f), Color (0.5f, 0.4f, 0.3f), "Kreis_2"};
Circle c_3 {30.0f, Vec2 (140.0f, 239.0f), Color (0.3f, 0.2f, 0.8f), "Kreis_3"};
vector <Circle> sorted_circles{c_1,c_2,c_3}; //Die Kreise werden in einen Vector eingefügt 
vector <Circle> sorted_circles_2{c_1,c_2,c_3};

auto l = [] //Definition des Lambda l
      (Circle const& lhs, Circle const& rhs) -> 
      bool {return ( lhs.get_radius() < rhs.get_radius() ? true :
                   ( lhs.get_radius() == rhs.get_radius() ? true :
                     lhs.get_radius() < rhs.get_radius() )
                   ); 
      };
//lambda lieber direkt in die SORT ohne die vergleichsoperatoren ganz kurz

//Aufgabe 3.8 Funktor

class sort_it { //neue Klasse für Funktor
  public: 
  bool operator() (Circle const& lhs, Circle const& rhs) {
    return ( lhs.get_radius() > rhs.get_radius() ? true : 
             lhs.get_radius() == rhs.get_radius() ? true : 
             lhs.get_radius() > rhs.get_radius() );
  }
}; 
      
 

TEST_CASE ("Sortierung-Test") //Test 3.7 Aufsteigende Sortierung
{
REQUIRE(is_sorted(sorted_circles.begin(), sorted_circles.end(), l ));
} 

TEST_CASE ("Sortierung-Test-2") //Test 3.8 Absteigende Sortierung
{
REQUIRE(is_sorted(sorted_circles_2.begin(), sorted_circles_2.end(), sort_it{} ));
} 


int main(int argc, char *argv[])
{

//Aufgabe 3.7 

  sort(sorted_circles.begin(), sorted_circles.end(), l ); //hier dann direkt das lambda 

  std::cout << "aufsteigende Sortierung nach Radius: " << '\n';
  for (auto a : sorted_circles)
  {
      std::cout << a << '\n';
  }
  std::cout << '\n';


//Aufgabe 3.8 

  sort(sorted_circles_2.begin(), sorted_circles_2.end(), sort_it{});

  std::cout << "absteigende Sortierung nach Radius: " << '\n';
  for (auto b : sorted_circles_2)
  { 
      std::cout << b << '\n';
  }
  std::cout << '\n';


  return Catch::Session().run(argc, argv); //Für den Test Case
};



