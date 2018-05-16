
#include <list> // std::list <>
#include <cstdlib> // std::rand ()
#include <iostream> // std::cout 
#include <set> // std::set <>
#include <map> // std::map <>

int main ()
{

//Aufgabe 3.2 

std::list <unsigned int> L (100); //Erstellen einer Liste L mit 100 positiven int's
for (auto& l : L) { //Schleife, die jedem Element eine zufällige Zahl von 0-100 zufügt
    l = std::rand() % 100 + 1;
}


std::set <unsigned int> Set_L1; //Erstellen eines Set's Set_L
for (auto l : L) { //Fügt die Elemente der Liste L ein 
    Set_L1.insert(l);
}
std::cout << "Anzahl der Elemente in der Liste: " << L.size() <<"\n" << "Anzahl der unterschiedlichen Zahlen in der Liste: " 
<< Set_L1.size() <<"\n"; //Ausgabe der Größe der Liste & des Sets 


std::set <unsigned int> Set_L2; //Set_L2 listet die Werte auf, die nicht enthalten sind 
for (int i=0; i<=100; ++i) {
    auto k = Set_L1.find(i); 
    //suche ob i enthalten ist und speicher die Position in der Variable k, find durchsucht das ganze Set
    //alle Elemente die nicht gefunden werden, da zeigt pointer auf das ende der Liste und dieses i 
    //(zahl zwischen 0 und 100) wird gespeichert in dem neuen Set

    if (k == Set_L1.end()) {
        Set_L2.insert(i);
    }
}

// DEBUG
/* for (auto o : Set_L2) { //Hier werden die Zahlen, die nicht in der Liste gelistet sind ausgegeben 
    std::cout << o << "\n";
} */


//Aufgabe 3.3

std::map <unsigned int,int> Haeufigkeit;

//Möglichkeit 1

for (auto x : L) {
    auto it = Haeufigkeit.find(x); //finde den wert x aus der Liste L und speicher die Position im iterator it 
    if (it == Haeufigkeit.end()) { //wenn der iterator am ende der Map ist und der wert x nicht gefunden ist
        Haeufigkeit[x] = 1; //speicher ihn in der map mit der häufigkeit 1 
    }
    else {
        //DEBUG
        //std::cout << it->second << std::endl; 
        //it->first ist der key, und it->second ist der value
        //hier wird der wert angezeigt wenn der key gefunden wird und es nicht am ende der map ist 

        //Möglichkeit 1
        //it->second += 1;

        //Möglichkeit 2
        Haeufigkeit[x] += 1; //erhöht die häufigkeit um 1 
    }
}

//Möglichkeit 2

/* for (auto x : L) { // x sind die Werte aus der Liste L 
    Haeufigkeit[x] = 0; // 0 ist der value zu jedem Schlüssel aus der Liste L (default Wert)
}

for (auto x : L) { //Es werden die Values definiert, wenn ein Schlüssel gefunden wird, erhört sich der Wert
    ++Haeufigkeit[x];
} */

for (auto& l : L) {
std::cout << "Zahl " << l << " : Häufigkeit " << Haeufigkeit[l] << std::endl;
}
//Für diese Aufgabe eignet sich die Map als Container, da hier zu jeder Zahl, die als key gesetzt wird, ein veränderbarer 
//value gespeichert werden kann. 
//Da die Häufigkeit variieren kann, die Zahl aber fest bleibt, ist dieser Container die richtige Lösung für das Problem



//Aufgabe 3.5 

/* std::map <string,int> matrikelnummern;
// Hinzufuegen von vielen Studenten
matrikelnummern ["Max Mustermann"] = 12345;
matrikelnummern ["Erika Mustermann"] = 23523;
// ...
exmatrikulation (matrikelnummern ["Fred Fuchs"]); //hier fehlte ein n */ 

}


