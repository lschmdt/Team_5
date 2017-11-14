#include "Generation.hpp"
#include <cassert>

Generation::Generation(){}

Generation::Generation(std::vector<std::string> list) {
	sort(list);
}

Generation::~Generation(){}
	
void Generation::update(){}

std::vector<Allele*> Generation::getAlleles(){
	return alleles_;
}

int Generation::getNbIndividuals() {
	return nb_individuals_;
}

void Generation::allelesPushBack(Allele* allele) {
	alleles_.push_back(allele);
}
		
/*void Generation::setAlleleFrequency(int i, double frequency) {
	assert(frequency <= 1 and frequency >= 0);
	alleles_[i]->(setFrequency(frequency));
}*/

void Generation::setGenerationLength(int i) {
	nb_individuals_ = i;
}

bool Generation::compare(std::string s1, std::string s2) {
	return s1==s2;
}

void Generation::sort (std::vector<std::string> all){ 
	std::map<std::string, int> sort; 
	if (alleles_.size() == 0) { 
		sort[all[0]] = 1;
	} 
	for (auto allele: all) { 
		std::map<std::string, int> n(sort); 
		for (auto& elm : n) {
			if ( compare (elm.first, allele) ){ 
				++elm.second;
			} else {
				sort[elm.first] = 1;
			}
		}
	}
	for(auto elm : sort) {
		alleles_.push_back(new Allele(elm.first, elm.second/all.size()));
	}
}



