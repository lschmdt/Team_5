#include "Generation.hpp"
#include <cassert>
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

Generation::Generation(bool mutate, vector<double> mus)
	: mus_(mus)
{
}

Generation::Generation(vector<string> list, vector<double> mus) 
	 : mus_(mus)
{
	cout << "Constructeur list" << endl;

	assert (list.size() > 0);
	sort(list);
	nb_individuals_ = list.size();
	

}

Generation::Generation(vector<double> frequencies, vector<double> mus)
	 : mus_(mus)
{
	cout << "Constructeur génération frequence" << endl;

	for(size_t i(0); i<frequencies.size(); ++i){
		allelesPushBack(new Allele(intToString(i), frequencies[i]));
	}
	nb_individuals_ = 100;

}

Generation::~Generation(){
	for(auto& all: alleles_){
		delete all;
		all= nullptr;
	}
	alleles_.clear();
}

string intToString(int i){
	ostringstream oss;
	oss << i;
	return oss.str();
}

void Generation::update(){}

vector<Allele*> Generation::getAlleles() const{
	return alleles_;
}

int Generation::getNbIndividuals() const {
	return nb_individuals_;
}

void Generation::allelesPushBack(Allele* allele) {
	assert(allele != nullptr);
	alleles_.push_back(allele);
}
		
/*void Generation::setAlleleFrequency(int i, double frequency) {
	assert(frequency <= 1 and frequency >= 0);
	alleles_[i]->(setFrequency(frequency));
}*/

void Generation::setGenerationLength(int i) {
	nb_individuals_ = i;
}


void Generation::sort(vector<string> all){ 
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
			cout << "Création allele : " << all[i] << endl;
		}
		different = true;
	}
}

void Generation::sizeEvolution(){
	cout << "SIZE EVOLUTION --------------------------------------------------------------------------" << endl;
	std::default_random_engine generator; 
	std::bernoulli_distribution dist(0.8);
	std::uniform_int_distribution<> nbIndividus(/*nb_individuals_ - nb_individuals_/2*/ 0, nb_individuals_+ nb_individuals_/2);

	if(dist(generator)){
		//cout << "I'm here" << endl;
		setGenerationLength(nbIndividus(gen));
		cout << "individus : " << nb_individuals_ <<endl;
	}
}

void Generation::mute(){
	static std::random_device rd;
    static std::mt19937 gen(rd());
	
	for (size_t w(0); w < alleles_.size(); ++w) {
		cout << alleles_[w]->getSequence() << endl;
		if (alleles_[w] != nullptr){
			assert(alleles_[w] != nullptr);
			
			//if  (alleles_[w]->getFrequency() < 1e-8) {alleles_[w]->setFrequency(0.0);}
			if (alleles_[w]->getFrequency() > 0.0){
				
				for (size_t i(0); i < alleles_[w]->getSequenceNucl().size(); ++i) {
					cout << "i = " << i << endl;
					cout << "mu size = " << mus_.size() << endl;
					for (auto m:mus_) {
					cout << "mu " << m << endl;}
					
					assert(i<=mus_.size());
					double mu (mus_[i]);
					assert(i<=alleles_[w]->getSequence().size());
					cout << "mu du site i :" << mu<< endl;
					if (alleles_[w]->getNucleotide(i) == A) {
						double probaA(1/3. * mu);
						binomial_distribution<>binDis(int(alleles_[w]->getFrequency()*nb_individuals_),probaA);
						mutate(alleles_[w], i, C, binDis(gen));
						mutate(alleles_[w], i, G, binDis(gen));
						mutate(alleles_[w], i, T, binDis(gen));
					} else if (alleles_[w]->getNucleotide(i) == C) {
						double probaC(1/3. * mu);
						binomial_distribution<>binDis(int(alleles_[w]->getFrequency()*nb_individuals_),probaC);
						mutate(alleles_[w], i, A, binDis(gen));
						mutate(alleles_[w], i, G, binDis(gen));
						mutate(alleles_[w], i, T, binDis(gen));
					} else if (alleles_[w]->getNucleotide(i) == G) {
						double probaG(1/3. * mu);
						binomial_distribution<>binDis(int(alleles_[w]->getFrequency()*nb_individuals_),probaG);
						mutate(alleles_[w], i, A, binDis(gen));
						mutate(alleles_[w], i, C, binDis(gen));
						mutate(alleles_[w], i, T, binDis(gen));
					} else if (alleles_[w]->getNucleotide(i) == T) {
						double probaT(1/3. * mu);
						binomial_distribution<>binDis(int(alleles_[w]->getFrequency()*nb_individuals_),probaT);
						mutate(alleles_[w], i, A, binDis(gen));
						mutate(alleles_[w], i, C, binDis(gen));
						mutate(alleles_[w], i, G, binDis(gen));
					}
				}
			}
		} else {cout << "NULLPTR" << endl;}
	}
}

				


void Generation::mutate(Allele* allele,  int position, Nucleotide M, int nbToModify){
	if (nbToModify > 0) {
		if  (allele->getFrequency() < 1e-8) {allele->setFrequency(0.0);}
		assert (allele != nullptr);
		if (allele!= nullptr and allele->getFrequency() > 0.0){
		

			vector<Nucleotide> newSequence (allele->getSequenceNucl());
				
			newSequence[position] = M;
			
			
			
			bool different(true);
			bool sufficient (allele->getFrequency()>(nbToModify/double(nb_individuals_)));
			
			if (sufficient){ // evite que la fréquence passe en négatif
				allele->setFrequency((allele->getFrequency())-(nbToModify/double(nb_individuals_)));
			} else {

			}

			if (sufficient){
				for (auto all : alleles_){

					if (newSequence == all->getSequenceNucl()){
						if (all->getFrequency()+ (nbToModify/double(nb_individuals_)) <= 1.0){ //evite que la fréquence dépasse 1
							all->setFrequency(all->getFrequency()+ (nbToModify/double(nb_individuals_)));
							cout << "+++++nbToModify : " << nbToModify << endl;
						} else {
							allele->setFrequency((allele->getFrequency())+(nbToModify/double(nb_individuals_)));
						}
						different = false;
					}
				}
			} else {different = false;}
			if (different){

				std::unordered_map<int, char> nuc2char = {{A,'A'},{C,'C'},{G,'G'},{T,'T'},{N,'N'}};
				std::string sequenceString;
				for (auto c: newSequence){
					sequenceString+=nuc2char[c];
				}
				alleles_.push_back(new Allele(sequenceString, nbToModify/double(nb_individuals_), -0.5));
				cout << "+++++nbToModify : " << nbToModify << endl;
			}
		}
		cout << endl;
	}
}


vector<double> Generation::getMus() {
	return mus_;
}
