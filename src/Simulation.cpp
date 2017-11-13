#include "Simulation.hpp"

Simulation::Simulation()
{}

std::vector<Generation*> Simulation::getEvolutionPop(){
	return evolution_pop_;
}

vector<string> Simulation:: readFromFile(vector<int> NuclPositions)
{
	vector<string> nuclMarkerSite; 
	string line;
	string sequence;
	ifstream genomes("test.fa");
	if (genomes.is_open()){
		
		while (getline(genomes, line)){									//Parcours chaque ligne du fichier
			
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
