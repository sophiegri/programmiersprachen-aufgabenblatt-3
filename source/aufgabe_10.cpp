#include <list> // std::list <>
#include <cstdlib> // std::rand ()
#include <iostream> // std::cout 
#include <vector> // std::vector <>
#include <iterator> // std::ostream_iterator <>


int main ()
{

//Aufgabe 3.10

std::list <unsigned int> L (100); //Liste aus Aufgabe 3.2 
for (auto& l : L) 
{ 
    l = std::rand() % 100 + 1;
}

std::vector <int> v_0 (100); //Es wird ein neuer Vektor angelegt 
 

std::copy (L.begin() , L.end(), v_0.begin() ); //Die Elemente aus der Liste werden in den Vektor eingefügt
std::cout << "My vector contains: \n";
    for (std::vector<int>::iterator it = v_0.begin(); it!=v_0.end(); ++it) //Ausgabe mit Iterator it 
    {
        std::cout << ' ' << *it;  //Dereferenzierungsoperator: Gib mir Element unter dem Iterator
        std::cout << '\n'; 
    }

return 0;

}

