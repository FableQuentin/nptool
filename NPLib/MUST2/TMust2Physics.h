#ifndef TMUST2PHYSICS_H
#define TMUST2PHYSICS_H

#include <vector>
#include "TObject.h"
#include "TMust2Data.h"

using namespace std ;

class TMust2Physics : public TObject
{
	public:
		TMust2Physics()	;
		~TMust2Physics();

	public: 
	void Clear()									;	
	void BuildPhysicalEvent(TMust2Data* Data)		;
	void BuildSimplePhysicalEvent(TMust2Data* Data)	;
		
	public:
	//	Provide Physical Multiplicity
	Int_t			EventMultiplicity	;
				
	//	Provide a Classification of Event
	vector<int>		EventType			;
		
	// Telescope
	vector<int>		TelescopeNumber		;
	
	//	Si X
	vector<double>	Si_E				;
	vector<double>	Si_T				;
	vector<int>		Si_X				;
	vector<int>		Si_Y				;
	
	//	Si(Li)
	vector<double>	SiLi_E				;
	vector<double>	SiLi_T				;
	vector<int>		SiLi_N				;
	
	//	CsI
	vector<double>	CsI_E				;
	vector<double>	CsI_T				;
	vector<int>		CsI_N				;	
	
	// Physical Value  
	vector<double>	TotalEnergy			;
	
	ClassDef(TMust2Physics,1)  // Must2Data structure
};

#endif
