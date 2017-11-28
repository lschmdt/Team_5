#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "Allele.hpp"
#include <random>
#include <array>

enum Model {JukesKantor, Kimura, Felsenstein, Nothing};

/*const double delta_ (0.5);
const double piA(0.1);
const double piC(0.3);
const double piG(0.4);
const double piT(1-piA-piC-piG);
const Model model (Felsenstein);*/



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
		static std::vector<double> mus_;
		//static double delta_;
		static Model model_;
		static std::vector<double> deltaOrPis_;
		

		
	public: 
	
		/** \fn generation constructors 
		 *
		 * */ 
		Generation(bool mutate, std::vector<double> mus = {}, Model model = Nothing, std::vector<double> deltaOrPis = {});

		Generation(std::vector<std::string> list, std::vector<double> mus = {}, Model model = Nothing, std::vector<double> deltaOrPis = {}); 
		
		
		Generation(std::vector<double> frequencies, std::vector<double> mus = {}, Model model = Nothing, std::vector<double> deltaOrPis = {});
		

		
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
		void initialiseMus();
		std::vector<double> getMus();
		 
		void sizeEvolution();
		
		/*static double mutationParameter(Model model, Nucleotide ancientNucl = N, Nucleotide newNucl = N);
		
		static double jukesKantor();
		
		static double kimura(Nucleotide ancientNucl, Nucleotide newNucl);
		
		static double felsenstein(Nucleotide ancientNucl, Nucleotide newNucll);*/
		
};

std::string intToString(int i);

#endif
