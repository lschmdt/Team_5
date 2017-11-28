#include "Generation.hpp"
#include <cassert>
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<double> Generation::mus_ = {};
//double Generation::delta_ = 1/3.;
Model Generation::model_ = Nothing;
vector<double> Generation::deltaOrPis_ = {};



Generation::Generation(bool mutate, vector<double> mus, Model model, vector<double> deltaOrPis)
	//: mus_(mus)
{
	//for (size_t i(0); i < mus_.size(); ++i){}
	if (!mus.empty() and mus_.empty()) {
		mus_ = mus;
	}
	if (model_ == Nothing and model != Nothing){
		model_ = model;
	}
	if (!deltaOrPis.empty() and deltaOrPis_.empty()) {
		cout << "salut" << endl;
		deltaOrPis_ = deltaOrPis;
		if (deltaOrPis_.size() == 3) {
			double piT(1);
			for (size_t j (0); j < deltaOrPis_.size(); ++j) {
				piT -= deltaOrPis_[j];
			} 
			deltaOrPis_.push_back(piT);
			for (size_t j (0); j < deltaOrPis_.size(); ++j) {
				cout << "pi : " <<deltaOrPis_[j] << endl;
			}
			
		}
	}
	
		
	/*if (mus.empty()){ 
		initialiseMus();
		cout << "initialisemus()" << endl;
	}*/
}

Generation::Generation(vector<string> list, vector<double> mus, Model model, vector<double> deltaOrPis) 
	// : mus_(mus)
{
	//cout << "Constructeur list" << endl;

	assert (list.size() > 0);
	sort(list);
	nb_individuals_ = list.size();
	
	if (!mus.empty() and mus_.empty()) {
		mus_ = mus;
	}
	if (model_ == Nothing and model != Nothing){
		model_ = model;
	}
	if (!deltaOrPis.empty() and deltaOrPis_.empty()) {
		cout << "salut" << endl;
		deltaOrPis_ = deltaOrPis;
		if (deltaOrPis_.size() == 3) {
			double piT(1);
			for (size_t j (0); j < deltaOrPis_.size(); ++j) {
				piT -= deltaOrPis_[j];
			} 
			deltaOrPis_.push_back(piT);
			for (size_t j (0); j < deltaOrPis_.size(); ++j) {
				cout << "pi : " <<deltaOrPis_[j] << endl;
			}
			
		}
	}
	/*if (mus.empty()){ 
		initialiseMus();
		//cout << "initialisemus()" << endl;
	}*/
	/*for (auto mu:mus_) {
		cout << mu << endl;}*/

}

Generation::Generation(vector<double> frequencies, vector<double> mus, Model model, vector<double> deltaOrPis)
	 //: mus_(mus)
{
	
	for(size_t i(0); i<frequencies.size(); ++i){
		allelesPushBack(new Allele(intToString(i), frequencies[i]));
	}
	nb_individuals_ = 100;
	
	if (!mus.empty() and mus_.empty()) {
		mus_ = mus;
	}
	if (model_ == Nothing and model != Nothing){
		model_ = model;
	}
	if (!deltaOrPis.empty() and deltaOrPis_.empty()) {
		cout << "salut" << endl;
		deltaOrPis_ = deltaOrPis;
		if (deltaOrPis_.size() == 3) {
			double piT(1);
			for (size_t j (0); j < deltaOrPis_.size(); ++j) {
				piT -= deltaOrPis_[j];
			} 
			deltaOrPis_.push_back(piT);
			for (size_t j (0); j < deltaOrPis_.size(); ++j) {
				cout << "pi : " <<deltaOrPis_[j] << endl;
			}
		}
	}
	/*if (mus.empty()){ 
		initialiseMus();
	}*/
	
		/*for (auto mu:mus_) {
		cout << "Constructeur frequencies" << endl;
		cout << mu << endl;}*/
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

/*
bool Generation::compare(string s1, string s2) const{
	return s1==s2;
}
*/

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
			//cout << "Création allele : " << all[i] << endl;
		}
		different = true;
	}
}

void Generation::sizeEvolution(){
	
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
		//cout << alleles_[w]->getSequence() << endl;
		if (alleles_[w] != nullptr){
			assert(alleles_[w] != nullptr);
			
			if  (alleles_[w]->getFrequency() < 1e-8) {alleles_[w]->setFrequency(0.0);}
			if (alleles_[w]->getFrequency() > 0.0){
				
				for (size_t i(0); i < alleles_[w]->getSequenceNucl().size(); ++i) {
					//cout << "i = " << i << endl;
					//cout << "mu size = " << mus_.size() << endl;
					//for (auto m:mus_) {
					//cout << "mu " << m << endl;}
					
					assert(i<=mus_.size());
					double mu (mus_[i]);
					assert(i<=alleles_[w]->getSequence().size());
					//cout << "mu du site i :" << mu<< endl;
					if (model_ == JukesKantor) {
						double proba(1/3. * mu);
						binomial_distribution<>binDis(int(alleles_[w]->getFrequency()*nb_individuals_),proba);
						if (alleles_[w]->getNucleotide(i) == A) {
							mutate(alleles_[w], i, C, binDis(gen));
							mutate(alleles_[w], i, G, binDis(gen));
							mutate(alleles_[w], i, T, binDis(gen));
						} else if (alleles_[w]->getNucleotide(i) == C) {
							mutate(alleles_[w], i, A, binDis(gen));
							mutate(alleles_[w], i, G, binDis(gen));
							mutate(alleles_[w], i, T, binDis(gen));
						} else if (alleles_[w]->getNucleotide(i) == G) {
							mutate(alleles_[w], i, A, binDis(gen));
							mutate(alleles_[w], i, C, binDis(gen));
							mutate(alleles_[w], i, T, binDis(gen));
						} else if (alleles_[w]->getNucleotide(i) == T) {
							mutate(alleles_[w], i, A, binDis(gen));
							mutate(alleles_[w], i, C, binDis(gen));
							mutate(alleles_[w], i, G, binDis(gen));
						}
					} else if (model_ == Kimura) {
						double proba1(deltaOrPis_[0] * mu);
						binomial_distribution<>binDis1(int(alleles_[w]->getFrequency()*nb_individuals_),proba1);
						
						double proba2((1-deltaOrPis_[0])/2 * mu);
						binomial_distribution<>binDis2(int(alleles_[w]->getFrequency()*nb_individuals_),proba2);
						
						if (alleles_[w]->getNucleotide(i) == A) {
							mutate(alleles_[w], i, C, binDis1(gen));
							mutate(alleles_[w], i, G, binDis2(gen));
							mutate(alleles_[w], i, T, binDis1(gen));
						} else if (alleles_[w]->getNucleotide(i) == C) {
							mutate(alleles_[w], i, A, binDis1(gen));
							mutate(alleles_[w], i, G, binDis1(gen));
							mutate(alleles_[w], i, T, binDis2(gen));
						} else if (alleles_[w]->getNucleotide(i) == G) {
							mutate(alleles_[w], i, A, binDis2(gen));
							mutate(alleles_[w], i, C, binDis1(gen));
							mutate(alleles_[w], i, T, binDis1(gen));
						} else if (alleles_[w]->getNucleotide(i) == T) {
							mutate(alleles_[w], i, A, binDis1(gen));
							mutate(alleles_[w], i, C, binDis2(gen));
							mutate(alleles_[w], i, G, binDis1(gen));
						}
					} else if (model_ == Felsenstein) {
						if (alleles_[w]->getNucleotide(i) == A) {
							double probaA(deltaOrPis_[0]/(1-deltaOrPis_[0]) * mu);
							binomial_distribution<>binDis(int(alleles_[w]->getFrequency()*nb_individuals_),probaA);
							mutate(alleles_[w], i, C, binDis(gen));
							mutate(alleles_[w], i, G, binDis(gen));
							mutate(alleles_[w], i, T, binDis(gen));
						} else if (alleles_[w]->getNucleotide(i) == C) {
							double probaC(deltaOrPis_[1]/(1-deltaOrPis_[1]) * mu);
							binomial_distribution<>binDis(int(alleles_[w]->getFrequency()*nb_individuals_),probaC);
							mutate(alleles_[w], i, A, binDis(gen));
							mutate(alleles_[w], i, G, binDis(gen));
							mutate(alleles_[w], i, T, binDis(gen));
						} else if (alleles_[w]->getNucleotide(i) == G) {
							double probaG(deltaOrPis_[2]/(1-deltaOrPis_[2]) * mu);
							binomial_distribution<>binDis(int(alleles_[w]->getFrequency()*nb_individuals_),probaG);
							mutate(alleles_[w], i, A, binDis(gen));
							mutate(alleles_[w], i, C, binDis(gen));
							mutate(alleles_[w], i, T, binDis(gen));
						} else if (alleles_[w]->getNucleotide(i) == T) {
							double probaT(deltaOrPis_[3]/(1-deltaOrPis_[3]) * mu);
							binomial_distribution<>binDis(int(alleles_[w]->getFrequency()*nb_individuals_),probaT);
							mutate(alleles_[w], i, A, binDis(gen));
							mutate(alleles_[w], i, C, binDis(gen));
							mutate(alleles_[w], i, G, binDis(gen));
						}
					}
					
				}
			}
		} else {cout << "NULLPTR" << endl;}
	}
}


				

void Generation::mutate(Allele* allele,  int position, Nucleotide M, int nbToModify){
	if (nbToModify > 0) {
		if  (allele->getFrequency() < 1e-8) {allele->setFrequency(0.0);}
		//std::cout << "mutate()" << std::endl;
		assert (allele != nullptr);
		if (allele!= nullptr and allele->getFrequency() > 0.0){
		

			vector<Nucleotide> newSequence (allele->getSequenceNucl());
				
			newSequence[position] = M;
			
			
			
			bool different(true);
			bool sufficient (allele->getFrequency()>(nbToModify/double(nb_individuals_)));
			//bool unsufficient()
			
			if (sufficient){ // evite que la fréquence passe en négatif
				allele->setFrequency((allele->getFrequency())-(nbToModify/double(nb_individuals_)));
				cout << "----nbToModify : " << nbToModify << endl;
			} else {
				//cout << "getFrequency : " << allele->getFrequency() << endl;
				//cout << "setFrequency : 0" << endl;
				//allele->setFrequency(0.0);	
			}

			if (sufficient){
				for (auto all : alleles_){

					if (newSequence == all->getSequenceNucl()){
						if (all->getFrequency()+ (nbToModify/double(nb_individuals_)) <= 1.0){ //evite que la fréquence dépasse 1
							all->setFrequency(all->getFrequency()+ (nbToModify/double(nb_individuals_)));
							//cout << "+++++nbToModify : " << nbToModify << endl;
						} else {
							//all->setFrequency(1.0);
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
				//cout << "+++++nbToModify : " << nbToModify << endl;
			}
		}
		//cout << endl;
	}
}



void Generation::initialiseMus() {

	assert(getAlleles()[0] != nullptr);

	for (size_t i(0); i < getAlleles()[0]->getSequence().size() ; ++i) {
		static std::random_device rd;									
		static std::mt19937 gen(rd());
		static std::uniform_real_distribution<> disMu (0.4, 0.8);
		mus_.push_back(disMu(gen));
	}
}



/*
void Generation::mutate(Allele* allele,  int position, Nucleotide M, int nbToModify){
	if (nbToModify > 0) {
		if  (allele->getFrequency() < 1e-8) {allele->setFrequency(0.0);}
		//std::cout << "mutate()" << std::endl;
		assert (allele != nullptr);
		if (allele!= nullptr and allele->getFrequency() > 0.0){
		

			vector<Nucleotide> newSequence (allele->getSequenceNucl());
				
			newSequence[position] = M;
			
			
			
			bool different(true);
			bool sufficient (allele->getFrequency()>(nbToModify/double(nb_individuals_)));
			//bool unsufficient()
			double reste (0);
			
			if (sufficient){ // evite que la fréquence passe en négatif
				//cout << "----nbToModify : " << nbToModify << endl;
				
				for (auto all : alleles_){

					if (newSequence == all->getSequenceNucl()){
						if (all->getFrequency()+ (nbToModify/double(nb_individuals_)) <= 1.0){ //evite que la fréquence dépasse 1
							allele->setFrequency((allele->getFrequency())-(nbToModify/double(nb_individuals_)));
							all->setFrequency(all->getFrequency()+ (nbToModify/double(nb_individuals_)));
							//cout << "+++++nbToModify : " << nbToModify << endl;
						} else {
							double difference (1.0 - all->getFrequency());
							all->setFrequency(1.0);
							allele->setFrequency((allele->getFrequency()) - difference);
						}
						different = false;
					}
				}
			} else {
				different = false;
				//cout << "getFrequency : " << allele->getFrequency() << endl;
				//cout << "setFrequency : 0" << endl;
				//allele->setFrequency(0.0);	
			}
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
}*/


vector<double> Generation::getMus() {
	return mus_;
}
/*
double jukesKantor(){
	//if (ancientNucl != newNucl) {
		return 1/3.;
	//} else return 0;
}
		
double kimura(Nucleotide ancientNucl, Nucleotide newNucl){
	//if (ancientNucl != newNucl) {
		if (ancientNucl == A and newNucl == G or ancientNucl == C and newNucl == T 
			or ancientNucl == G and newNucl == A or ancientNucl == T and newNucl == C){
			return gamma;
		} else {
			return (1-gamma)/2; 	
		}
	//} else return 0;		
}

double felsenstein(Nucleotide ancientNucl){
	//if (ancientNucl != newNucl) {
		if (ancientNucl == A) {
			return piA/(1-piA);
		} else if (ancientNucl == C) {
			return piC/(1-piC); 
		} else if (ancientNucl == G) {
			return piG/(1-piG); 
		} else if (ancientNucl == T) {
			return piT/(1-piT); 
		}
	//} else return 0;		
}

double mutationParameter(Model model, Nucleotide ancientNucl, Nucleotide newNucl) {
	if (model == JK){
		jukesKantor(ancientNucl, newNucl);
	} else if (model == KI) {
		kimura(ancientNucl, newNucl);
	} else if (model == FE) {
		felsenstein(ancientNucl, newNucl);
	}
}*/
		


