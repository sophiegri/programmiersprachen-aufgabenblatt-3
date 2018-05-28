#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <vector> // std::vector <>
#include <iostream> 
#include <cmath>
#include <algorithm> 


template <typename C, typename P> //Funktion zum filtern
C filter (C const& container , P praedikat) { //wir übergeben irgendeinen Container und Prädikat und bekommen einen Container zurück
    
    C container_2;     //neuer Container in dem später die Werte gespeichert werden
    for (auto x : container){ //für alle Elemente aus dem Container
        if (praedikat(x) == true) { //wird das Prädikat erfüllt, dann speicher in neuem Container
            container_2.push_back(x);
        }
    }
    return container_2; 
}

std::vector<int> v{1,2,3,4,5,6};
bool is_even (int n) {return n % 2 == 0;}


TEST_CASE ("filter alle geraden zahlen", "[filter]")
{
    std::vector<int> all_even = filter (v, is_even);
    REQUIRE(std::all_of(all_even.begin(), all_even.end(), is_even));
}

 

 int main(int argc, char* argv[])
{    
    std::vector<int> all_even = filter (v, is_even);
    return Catch::Session().run(argc, argv);
}    