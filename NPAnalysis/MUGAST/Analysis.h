// You can use this file to declare your spectra, file, energy loss , ... and whatever you want.
// This way you can remove all unnecessary declaration in the main programm.
// In order to help debugging and organizing we use Name Space.

/////////////////////////////////////////////////////////////////////////////////////////////////
// -------------------------------------- VARIOUS INCLUDE ---------------------------------------

// NPL
#include "DetectorManager.h"
#include "NPOptionManager.h"
#include "NPReaction.h"
#include "RootInput.h"
#include "RootOutput.h"
#include "TMust2Physics.h"
#include "GaspardTracker.h"

#include "TInitialConditions.h"
#include "NPEnergyLoss.h"
using namespace NPL ;
// STL C++
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
// ROOT
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TVector3.h>
#include <TRandom3.h>
#include <TMath.h>
#include <TObject.h>

// ----------------------------------------------------------------------------------------------
void InitOutputBranch() ;
void InitInputBranch() ;
void ReInitValue() ;
/////////////////////////////////////////////////////////////////////////////////////////////////
// ----------------------------------- DOUBLE, INT, BOOL AND MORE -------------------------------
namespace VARIABLE{
  double Ex;
  double ELab;
  double ThetaLab;
  double ThetaCM;
  TInitialConditions* Init = new TInitialConditions();
}

using namespace VARIABLE ;
// ----------------------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////
// -----------------------------------ENERGY LOSS----------------------------------------------
namespace ENERGYLOSS{
  //	Energy loss table: the G4Table are generated by the simulation
  EnergyLoss LightCD2 = EnergyLoss("proton_CD2.G4table","G4Table",100 );
  EnergyLoss LightAl = EnergyLoss("proton_Al.G4table","G4Table",10);
  EnergyLoss LightSi = EnergyLoss("proton_Si.G4table","G4Table",10);
  EnergyLoss BeamCD2 = EnergyLoss("Kr74[0.0]_CD2.G4table","G4Table",100);
}

using namespace ENERGYLOSS ;
// ----------------------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////

