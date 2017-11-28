#include "Allele.hpp"
#include <unordered_map>

using namespace std;

Allele::Allele(string sequence, double frequency, double fit)
: frequency_(frequency), fitness_(fit) {
	if(fit==0.0)
	{	random_device rd;
		generator=mt19937(rd());
		distribution=uniform_real_distribution<double>(-1.0,1.0);
		setFitness(distribution(generator));
		
	}
	
	
	std::unordered_map<char, Nucleotide> char2nuc = {{'A', A},{'a', A},{'C', C},{'c', C},{'G', G},{'g', G},{'T', T},{'t', T},{'N', N},{'n', N}, {'-', N},{'.', N}};
	for (auto c: sequence){
		sequence_.push_back(char2nuc[c]);
	}
}
	 
Allele::~Allele(){}
    
double Allele::getFitness() const{
	return fitness_;
}

double Allele::getFrequency() const{
	return frequency_;
} 

void Allele::setFitness(double const& fit){
	fitness_=fit;
}

void Allele::setFrequency(double const& freq) {
	frequency_ = freq;
}

std::vector<Nucleotide> Allele::getSequenceNucl() const{
	return sequence_;
}

Nucleotide Allele::getNucleotide(int i) const{
	return sequence_[i];
}

std::string Allele::getSequence() const{
	
	std::unordered_map<int, char> nuc2char={{A,'A'},{C,'C'},{G,'G'},{T,'T'},{N,'N'}};
	std::string sequenceString;
	for (auto c: sequence_){
		sequenceString+=nuc2char[c];
	}
	return sequenceString;
}
