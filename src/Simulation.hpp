#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "Generation.hpp"
#include "Allele.hpp"
#include <iostream>



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
		std::vector<Generation*> getEvolutionPop();
		
		std::vector<std::string> readFromFile(std::vector<int> NuclPositions);


};

#endif
