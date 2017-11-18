#ifndef ALLELE_H
#define ALLELE_H

#include <vector>
#include <fstream> 


/*! \class Allele
 * 
 * This class gathers the characteristics of each allele 
 * retrieved from the data base. They each have a specific sequence as well as a frequency. 
 * 
 */
 
 
class Allele
{
	private: 
	
		std::string sequence_; 		/**<	Sequence of allele.				*/
		double frequency_; 		/**<	Frequency of allele within a generation.	*/
				
	
	public: 
	
		/** \fn Allele constructor, initialized an Allele with a given sequence and frequency.
		 *
		 * */ 
		Allele(std::string sequence, double frequency); 
		
		/** Allele destructor 
		 *  
		 * 
		 * */  
		 ~Allele(); 
		 
		/**	Getter of the allele's sequence.
		*	@return string: Allele sequence.	*/
		 std::string getSequence() const;
		
		/**	Getter of the allele's frequency.
		*	@return double: Allele frequency.	*/
		 double getFrequency() const;
		 
		/**	Setter of the allele's frequency.
		*	@param freq: New frequency of the given allele.	*/
		 void setFrequency(double const& freq);

};

#endif
