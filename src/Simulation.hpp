
#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <vector>
//#include "Generation.cpp"
#include "Generation.hpp"
#include "Allele.hpp"
#include <fstream>
#include <cassert>



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
        std::ifstream input_file_;  /**<	Opening of the file the simulation will read from.	*/
        std::ofstream output_file_; /**<	File in which time steps, individual allele frequencies and phenotypes will be written.	*/
	
	public: 
	
		/** \fn simulation constructor 
		 *
		 * */ 
		Simulation(Generation* firstGen); 
        /** Simulation constructor defining the generation by
               given marker positions. */
        Simulation(std::vector<int> marker_positions);
		/** simulation destructor 
		 * 
		 * defined by default  
		 * 
		 * */  
        //virtual ~Simulation() = default;
        ~Simulation();
		
		/**getter of attribut evolution_pop
		 */
		std::vector<Generation*> getEvolutionPop();
		
		std::vector<std::string> readFromFile(std::vector<int> NuclPositions, std::ifstream& inputFile);
		
		void createNewGeneration();
		
		void printTerminal();
        /**	A public function running the overall simulation of genetics during a given
         * 	time.
         * 	@param size_t time: The time of the simulation (in steps)	*/

        void run(size_t time);
        /**	A public function writing allele frequencies in an external file.
         * @param ofstream: External file.	*/
        void writeFrequencies(std::ofstream& Output);

        /**	A public function writing allele genotypes in a file.
         * 	@param ofstream: External file.	*/
        void writeGenotypes(std::ofstream& Output);
};

#endif

