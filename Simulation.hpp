
#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <vector>
//#include "Generation.cpp"
#include "Generation.hpp"
#include "Allele.hpp"



/*! \class Simulation
 * 
 * structure from which the program will turn and will display 
 * the frequencies of each alleles for different populations
 * 
 */
 
 
class Simulation
{
	private: 
	
		std::vector<Generation*> evolution_pop_; 
	
	
	public: 
	
		/** \fn simulation constructor 
		 *
		 * */ 
		Simulation(); 
		
		/** simulation destructor 
		 * 
		 * defined by default  
		 * 
		 * */  
		virtual ~Simulation() = default; 
		
		/**getter of attribut evolution_pop
		 */
		std::vector<Generation*> getEvolutionPop();	//pas sûr de l'utilité de cette méthode, on n'appellera probablement pas un ensemble de générations depuis une autre classe que Simlation #Lululafripouille
		
		std::vector<std::string> readFromFile(std::vector<int> NuclPositions, std::ifstream inputFile);
		
		void createNewGeneration();

};

#endif

