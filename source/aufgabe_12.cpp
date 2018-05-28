#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <vector> // std::vector <>
#include <iostream> 
#include <cmath>
#include <algorithm>

std::vector<int> v_1 {1,2,3,4,5,6,7,8,9};
std::vector<int> v_2 {9,8,7,6,5,4,3,2,1};
std::vector<int> v_3(9);

bool is_10 (int i) //Funktion ob es gleich 10 ist 
{
  return i == 10 ; 
}

TEST_CASE ("pruefe ob alles 10 ist." "[transform]")
{
    REQUIRE(std::all_of(v_3.begin(), v_3.end(), is_10));
}

int main(int argc, char* argv[])
{  
  //Möglichkeit 1 mit Definition von Lambda aber nicht sinnvoll, lieber in Funktion:
  //auto addition = [] (int x, int y) -> int {return x + y;}; 
  //auto wichtig, Bindung weist auf Lambda hin
  
  std::transform (v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(), [] (int x, int y) -> int {return x + y;}); //Lambda direkt in der Funktion
  
  for(auto& i : v_3) 
  {
    std::cout << i << "\n";
  }

  return Catch::Session().run(argc, argv);
} 