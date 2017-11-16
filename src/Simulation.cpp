#include <iostream>
#include <random>

#include "Simulation.hpp"

using namespace std;

Simulation::Simulation(Generation* firstGen){
	random_device rd;
  	gen=mt19937(rd());
	evolution_pop_.push_back(firstGen);
}
Simulation::Simulation(std::vector<int> marker_positions)
{
    input_file_.open("../res/test.fa");
    assert(!input_file_.fail());
    random_device rd;
    gen=mt19937(rd());

    evolution_pop_.push_back(new Generation(readFromFile(marker_positions, input_file_)));
}
Simulation::~Simulation()
{	input_file_.close();
  
 for(auto& gen: evolution_pop_)
 {	gen=nullptr;
  	delete gen;
 }
 evolution_pop_.clear();
}
std::vector<Generation*> Simulation::getEvolutionPop(){
	return evolution_pop_;
}


vector<string> Simulation::readFromFile(vector<int> NuclPositions, std::ifstream& inputFile)
{
	vector<string> nuclMarkerSite; 
	string line;
	string sequence;
	if (inputFile.is_open()){
		
		while (getline(inputFile, line)){								//Parcours chaque ligne du fichier
			
			if (line[0]== '>'){ continue; }								//Ignore les lignes commencant par >
			for (size_t j(0); j< NuclPositions.size(); ++j){			//Parcours tableau des markers positions
				sequence +=(line[NuclPositions[j]]);					//Ajoute le nucléotide marqué à la séquence
				}
			nuclMarkerSite.push_back(sequence);							//Crée la case de l'individu, elle contient la séquence résultante
			sequence.clear();											//Efface séquence pour le prochain individu
			}
		}
	
	for (auto n: nuclMarkerSite){cout << n << endl;}					//afficher la séquence de chaque individu
	return nuclMarkerSite;
		
}



void Simulation::createNewGeneration() {
	
	Generation* nextGen (new Generation());
	
	Generation* lastGen (evolution_pop_[evolution_pop_.size()-1]);
	int sampleSize (lastGen->getNbIndividuals());
	double proba (0);
	for (size_t i(0); i < lastGen->getAlleles().size(); ++i) {
		if (lastGen != nullptr) {
			proba = lastGen->getAlleles()[i]->getFrequency(); 
			std::binomial_distribution<> bin_dis (sampleSize, proba);
			int a(bin_dis(gen));
			if (i == lastGen->getAlleles().size()-1) {
				a = sampleSize;											//dernier allèle qui complète
			}
			if (!(i > lastGen->getAlleles().size())){
				nextGen->allelesPushBack(new Allele(lastGen->getAlleles()[i]->getSequence(), a/double(lastGen->getNbIndividuals())));
			}
			if (sampleSize <= 0) {
				i = lastGen->getAlleles().size() + 1;					//sortie de la boucle
			}
			sampleSize -= a;
		}
	}
	nextGen->setGenerationLength(lastGen->getNbIndividuals());
	evolution_pop_.push_back(nextGen);
}

void Simulation::printTerminal() {
	for (auto gen : getEvolutionPop()) {
		for (auto all : gen->getAlleles()) {
			std::cout << "séquence de l'allèle : "<< all->getSequence() << " fréquence : " << all->getFrequency() << std::endl;
		}
	}
}


