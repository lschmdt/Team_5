#include "Generation.hpp"

Generation::Generation(std::vector<std::string> list)
{
	sort(list);
}
		
Generation::~Generation(){}
	
void Generation::update(){}

std::vector<Allele*> Generation::getAlleles()
{
	return alleles_;
}

bool Generation::compare(std::string s1, std::string s2)
{
	return s1==s2;
}
	
void Generation::sort (std::vector<std::string> all)
{ 
	std::map<std::string, int> sort; 
	
	if (alleles_.size() == 0) 
	{ 
		sort[all[0]] = 1;
	} 
	
	for (auto allele: all) 
	{ 
		std::map<std::string, int> n(sort); 
		for (auto& elm : n) 
		{
			if ( compare (elm.first, allele) )
			{ 
				++elm.second;
			} else {
				
				sort[elm.first] = 1;
			}
		}
	}
	
	for(auto elm : sort)
	{
		alleles_.push_back(new Allele(elm.first, elm.second/all.size()));
	}
}
		
		 
