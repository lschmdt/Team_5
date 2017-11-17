#include "Experiment.hpp"
#include <cassert>
#include <vector>


Experiment::Experiment(vector<Simulation*> sim)
	:	simulations_(sim)
	{
		output_file_.open("../res/frequencies.txt");
		assert(!output_file_.fail());
	}

Experiment::~Experiment()
{	for(auto& sim: simulations_)
	{	sim=nullptr;
		delete sim;
	}
	simulations_.clear();
	output_file_.close();
}


void Experiment::runall(size_t time)
{	size_t time_step(0);
	while(time_step<=time)
	{	output_file_<<time_step<<"\t";
		for(auto& sim: simulations_)
		{	sim->createNewGeneration();
			writeFrequencies(output_file_, sim);
		}
		++time_step;
		output_file_<<endl;
	}
	writeGenotypes(output_file_);
	
}
void Experiment::writeFrequencies(ofstream& Output, Simulation* sim){
 
		vector<Allele*> alleles=vector<Allele*>(sim->getEvolutionPop().back()->getAlleles());	//Recovery of overall allele vector simplifies code

		for(size_t i(0);i<alleles.size();++i)
		{	Output<<alleles[i]->getFrequency();
			if(i!=alleles.size()-1)
			{	Output<<"|";
			}
		}
    Output<<"\t";
}
void Experiment::writeGenotypes(ofstream& Output)
{   Output<<"\t\t";
	for(auto const& sim: simulations_)
	{
		vector<Allele*> alleles=vector<Allele*>(sim->getEvolutionPop().back()->getAlleles());
		for(size_t i(0);i<alleles.size();++i)
		{
			Output<<alleles[i]->getSequence();
			if(i!=alleles.size()-1)
			{	Output<<"|";
			}
		}
		Output<<"\t\t";
	}
}
