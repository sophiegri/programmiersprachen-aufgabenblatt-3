#include "circle.hpp"
#include <iostream>
#include <string>
#include <set>
using namespace std; 


int main(int argc, char* argv[])
{ 
  string Eingabe_Name; 

  multiset <Circle> Kreise; //ein neues Multiset wird erstellt 
  int i=1; 
  while (i == 1) { //while Schleife um Nutzer Abfrage zu verwalten 

    cout << "Geben Sie einen neuen Namen ein:"; 
    cin >> Eingabe_Name;
    Circle _neu {Eingabe_Name}; //der neue Name wird mit dem Konstruktor (name) in dem Multiset gespeichert
    Kreise.insert(_neu);
   
    
    //for Schleife um die Namen miteinander zu vergleichen und auszugeben. 
     //die Namen dürfen im Multiset häufiger auftauchen 
     for (auto x : Kreise) { 
      if (x.get_name() == _neu.get_name()) {
        cout << x << "\n";
      }
     }

    cout << "Möchten Sie einen neuen Kreis erstellen? Ja:1 , Nein:0 ";
    cin >> i ;
    }
    
  
  //DEBUG ostream os
  /* Circle c_1 {370.0f, Vec2 (400.0f, 400.0f), Color (0.0f, 0.6f, 0.0f), "Kreis_1"};
     string Eingabe; 
     cout << c_1; */


}