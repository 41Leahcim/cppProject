#include <iostream>
#include <memory>
#include <list>

class Hond{};

class SintBernard : public Hond{
public:
    SintBernard(std::string _, int __){}
};

class Tekkel : public Hond{
public:
    Tekkel(std::string _){}
};

int main(){
    std::list<Hond> kennel;
    kennel.push_back(SintBernard("Boris", 100));
    kennel.push_back(Tekkel("Keffertje"));
    kennel.push_back(SintBernard("Donald", 100));
    for(const Hond& dog : kennel){
        // print de naam van de hond
    }
    double hoeveelheidVloeistof = 0;
    for(const Hond& dog : kennel){
        // tel de hoeveelheid vloeistof in de kennel op
    }
    std::cout << "Aanwezige vloeistof in de kennel is: " << hoeveelheidVloeistof << "\n";
    kennel.clear();
}
