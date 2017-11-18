#include "Allele.hpp"

Allele::Allele(std::string sequence, double frequency)
: sequence_(sequence), frequency_(frequency) {}
	 
Allele::~Allele(){}
    

std::string Allele::getSequence() const{
	return sequence_;
}

double Allele::getFrequency() const{
	return frequency_;
} 

void Allele::setFrequency(double const& freq) {
	frequency_ = freq;
}


