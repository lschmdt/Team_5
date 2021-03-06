#ifndef ALLELE_H
#define ALLELE_H

#include <vector>
#include <fstream> 
#include <random>
#include <string>

enum Nucleotide{A,C,G,T,N};

/*! \class Allele
 * 
 * This class gathers the characteristics of each allele 
 * retrieved from the data base. They each have a specific sequence as well as a frequency. 
 * 
 */
 
 
class Allele
{
	private: 

		std::vector<Nucleotide> sequence_; 		/**<	Sequence of allele.				*/
		double frequency_; 		/**<	Frequency of allele within a generation.	*/
		double fitness_;		/**<	Fitness coefficient of allele.	*/
		std::mt19937 generator;
		std::uniform_real_distribution<double> distribution;
		
	public: 
	
		/** \fn Allele constructor, initialized an Allele with a given sequence and frequency.
		 *
		 * */ 
		Allele(std::string sequence, double frequency, double fit=0.0); 
		
		/** \Allele copy constructor
		 *
		 * */ 
		Allele(const Allele& other);
		/** Allele destructor 
		 *  
		 * 
		 * */  
		 ~Allele(); 
		 
		 /**	Getter of allele's fitness coefficient.
		  * 	@return double: Fitness coefficient.	*/
		double getFitness() const;
		/**	Getter of the allele's sequence.
		*	@return string: Allele sequence.	*/
		std::string getSequence() const;
		 
		std::vector<Nucleotide> getSequenceNucl() const;
		 
		Nucleotide getNucleotide(int i) const;

		 
		/**	Getter of the allele's frequency.
		*	@return double: Allele frequency.	*/
		 double getFrequency() const;
		 
		 /** Setter of allele's fitness coefficient.
		 *  @param fit: New fitness coefficient.	*/
		 void setFitness(double const& fit);
		 
		/**	Setter of the allele's frequency.
		*	@param freq: New frequency of the given allele.	*/
		 void setFrequency(double const& freq);
		 
		 double getMu(int i) const;
};

#endif
