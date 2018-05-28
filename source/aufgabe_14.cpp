#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"
#include "aufgabe_4.cpp"
#include <iostream>
#include <algorithm> 
#include <vector> 


//Aufgabe 3.14


 
TEST_CASE ("Lambda-Test größer 4.0f")
{
std::vector<Circle> circles{{5.0f}, {3.0f}, {8.0f}, {1.0f}, {5.0f}};
std::cout << "Radien: " << circles << "\n"; 
//REQUIRE();
} 


int main(int argc, char *argv[])
{ 

  return Catch::Session().run(argc, argv); //Für den Test Case
}

