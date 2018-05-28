#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"
#include <iostream>
#include <algorithm> 
#include <vector> 
using namespace std;

//Aufgabe 3.6 

Circle c_1 {370.0f, Vec2 (400.0f, 400.0f), Color (0.0f, 0.6f, 0.0f), "Kreis_1"};
Circle c_2 {290.0f, Vec2 (200.0f, 200.0f), Color (0.5f, 0.4f, 0.3f), "Kreis_2"};
Circle c_3 {30.0f, Vec2 (140.0f, 239.0f), Color (0.3f, 0.2f, 0.8f), "Kreis_3"};
vector <Circle> sorted_circles{c_1,c_2,c_3}; //Die Kreise werden in einen Vector eingefügt 

 
TEST_CASE ("Sortierung-Test")
{
REQUIRE(is_sorted(sorted_circles.begin(), sorted_circles.end()));
} 


int main(int argc, char *argv[])
{
  

  sort(sorted_circles.begin(), sorted_circles.end());

  for (auto x : sorted_circles)
  {
      std::cout << x << '\n';
  }
  std::cout << '\n';
  

  return Catch::Session().run(argc, argv); //Für den Test Case
}



