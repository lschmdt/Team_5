#ifndef ALLELE_H
#define ALLELE_H

#include <vector>
#include <fstream> 


/*! \class Allele
 * 
 * this class gathers the characteristics of each allele 
 * retrieved from the data base
 * 
 */
 
 
class Allele
{
	private: 
	
		std::string sequence_;
		double frequency_; 
				
		/** retrieves the DNA sequence of the alleles contained 
		 * in the genotype-database and initialises the attribut sequences_
		 *   
		 * */ 
		void readFromFile(ostream& Data);
	
	public: 
	
		/** \fn allele constructor 
		 *
		 * */ 
		Allele(std::string sequence, double frequency); 
		
		/** allele destructor 
		 *  
		 * 
		 * */  
		 ~Allele(); 
		 
		 std::string getSequence();

		 double getFrequency();

};

