# include <cstdlib> // std::rand()
# include <vector> // std::vector<>
# include <list> // std::list<>
# include <iostream> // std::cout
# include <iterator> // std::ostream_iterator<>
# include <algorithm> //std::reverse, std::generate


int main ()
{

    std::vector<int> v_0(10); //Hier wird ein Vektor mit 10 int Elementen angelegt. Den Elementen wird durch die 
                              // for-Schleife Zufallszahlen zugeteilt  

    for (auto& v : v_0) { 
    v = std::rand();
}
std::copy (std::cbegin(v_0), std::cend(v_0), //Die Inputinteratoren sind cbegin und cend, alle Elemente zwischen diesen Iteratoren
std::ostream_iterator<int>(std::cout, "\n")); //werden in den Outputinterator kopiert und ausgegeben 

std::list<int> l_0 (std::cbegin(v_0), std::cend(v_0)); //neue Liste L0 mit Elementen des Vectors
std::list<int> l_1 (std::cbegin(l_0), std::cend(l_0)); //neue Liste L1 mit Elemeten der ersten Liste 
std::reverse(std::begin(l_1), std::end(l_1)); //kehrt die Reihenfolge der Elemente in L1 um 
std::copy (std::cbegin(l_1), std::cend(l_1), //c steht für const
std::ostream_iterator<int>(std::cout, "\n")); //Die Elemente dieser "umgekehrten" Liste werden in den neuen Ostream  
                                              // Iterator kopiert und direkt ausgegeben 
l_1.sort(); //Die Liste L1 wird sortiert 
std::copy(l_1.cbegin(), l_1.cend(),
std::ostream_iterator<int>(std::cout, "\n")); //Diese sortierte Liste wird mit einem ostream Iterator ausgegeben 

std::generate(std::begin(v_0), std::end(v_0), std::rand); //Die Elemente des Vektors werden mit zufälligen Werten generiert 
std::copy(v_0.crbegin(), v_0.crend(), //cr steht für const reversed (??)
std::ostream_iterator<int>(std::cout, "\n")); //Diese neuen Werte werden mit dem ostream Iterator kopiert und direkt ausgegeben

return 0;
}
 