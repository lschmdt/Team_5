#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>



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
		
		vector<string> readFromFile(vector<int> NuclPositions);


};

#endif
