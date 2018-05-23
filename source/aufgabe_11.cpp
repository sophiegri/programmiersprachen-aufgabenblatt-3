#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm> // remove und remove_if
#include <vector> // std::vector <>
#include <iostream>


bool is_not_multiple_of_3 (int i)
{
 return (i % 3) != 0 ; //Ist nicht durch 3 teilbar und return true 
}

bool is_multiple_of_3 (int x) 
{
  return ! is_not_multiple_of_3(x); //Variante Funktionsaufruf, natürlich möglich mit neu schreiben (x % 3) == 0
}

void print(std::vector<unsigned int> const& vec) //Print Funktion 
{
  ///Ohne Referenz weil Vektor von elementar-Datentyp, wenn von Circle oder String 
  //dann mit Referenz weil kopieren von nicht-elementar-Datentypen teurer ist als eine Referenz
  for (unsigned int m: vec) 
  {
      std::cout << m << ' '; 
  }
  std::cout << std::endl << std::endl;
}


TEST_CASE ("filter alle vielfache von drei", "[erase]")
{
    std::vector <unsigned int> v (100);
    std::cout << "Vector: " << "\n"; //Vektor mit 100 Zufallszahlen von 0-100 erstellt und ausgegeben
    //range-based for-loop
    for (auto& x : v) 
    {
        x = std::rand() % 100 +1;         
    }   
    print(v);


    v.erase (std::remove_if (v.begin(), v.end(), is_not_multiple_of_3), v.end() ); //löscht alle Werte die nicht durch 3 teilbar sind
    std::cout << "Vector with values multiple of 3: " << "\n";
    print(v);

    REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3)); //Test ob nur noch Vielfache von 3 im Vektor
}



int main(int argc, char* argv[])
{    

    return Catch::Session().run(argc, argv);
}