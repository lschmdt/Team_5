#include "Generation.hpp"
#include <cassert>
#include <iostream>

using namespace std;

Generation::Generation(){}

Generation::Generation(std::vector<std::string> list) {
	assert (list.size() > 0);
	sort(list);
	nb_individuals_ = list.size();
}

Generation::~Generation(){}
	
void Generation::update(){}

std::vector<Allele*> Generation::getAlleles() const{
	return alleles_;
}

int Generation::getNbIndividuals() const {
	return nb_individuals_;
}

void Generation::allelesPushBack(Allele* allele) {
	alleles_.push_back(allele);
}
		
/*void Generation::setAlleleFrequency(int i, double frequency) {
	assert(frequency <= 1 and frequency >= 0);
	alleles_[i]->(setFrequency(frequency));
}*/

void Generation::setGenerationLength(int const& i) {
	nb_individuals_ = i;
}

/*
bool Generation::compare(std::string s1, std::string s2) {
	return s1==s2;
}
*/

void Generation::sort(std::vector<std::string> all){ 
	/*std::map<std::string, int> sort; 
	if (alleles_.size() == 0) { 
		sort[all[0]] = 1;
	}
	for (auto allele: all) { 
		std::map<std::string, int> n(sort); 
		for (auto elm : n) {
			if (compare(elm.first, allele)){ 
				++elm.second;
			} else {
				sort[elm.first] = 1;
			}
		}
	}
	for(auto elm : sort) {
		cout << elm.first << " " << elm.second << endl;
		alleles_.push_back(new Allele(elm.first, elm.second/double(all.size())));
	}
	
	cout << "fin" << endl;
	
	//____________________________________
	*/
	bool different (true);
	for (size_t i (0); i < all.size(); ++i) {
		for (size_t j(0); j < i ; ++j) {
			if (all[j] == all[i]) {
				different = false;
			}
		}
		if (different) {
			int compteur (0);
			for (size_t j(i); j < all.size(); ++j) {
				if (all[i] == all[j]) {
					compteur+=1;
				}
			}
			alleles_.push_back(new Allele(all[i], compteur/double(all.size())));
		}
		different = true;
	}
}
