#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "Allele.hpp"
#include <random>

/*! \class Generation
 * 
 * represents the state of all the alleles (at this point just the 
 * frequency ) after at a certain time in the simulation.
 * 
 */
 
 
class Generation
{
	private: 
	
		std::vector<Allele*> alleles_;
		int nb_individuals_;
		std::mt19937 gen;
		std::vector<double> mus_;

		
	public: 
	
		/** \fn generation constructors 
		 *
		 * */ 
		Generation(bool mutate= false, std::vector<double> mus = {});

		Generation(std::vector<std::string> list, std::vector<double> mus = {}); 
		
		
		Generation(std::vector<double> frequencies, std::vector<double> mus = {});
		

		
		/** generation destructor 
		 * 
		 * */  
		~Generation();
		
		/** updates every step until the generation lenght is reached
		*@param duration of one step //could be defined as a cst somewhere else (remarque au groupe)
		*/
		void update();
		
		/**getter of all types of Alleles
		 */
		std::vector<Allele*> getAlleles() const;
		
		int getNbIndividuals() const;
		
		void allelesPushBack(Allele*);
		
		void setAlleleFrequency(int const& i, double const& frequency);
		
		void setGenerationLength(int i);
		
		/** \fn compare
		 */
		bool compare(std::string s1, std::string s2) const;
		 
		 /** This function sorts the alleles given by the file and calculates
		  * their frequencies. 
		  * //a completer(remarque au groupe)
		  * @param all : the vector of string to sort to find all the possibly alleles
		  */
		void sort(std::vector<std::string> all);
		 
		void mute();
		void mutate(Allele* allele, int position, Nucleotide M, int nbToModify);
		std::vector<double> getMus();
		 
		void sizeEvolution();


};

std::string intToString(int i);

#endif
