#include "Allele.hpp"

Allele::Allele(std::string sequence, double frequency)
: sequence_(sequence), frequency_(frequency) {}
	 
Allele::~Allele(){}
    
void Allele::readFromFile(ostream& Data){}

std::string Allele::getSequence(){
	return sequence_;
}

double Allele::getFrequency(){
	return frequency_;
} 
