#ifndef GaspardTrackerModule_h
#define GaspardTrackerModule_h 1

// C++ headers
#include <string>

// G4 headers
#include "G4LogicalVolume.hh"
#include "G4Event.hh"
#include "G4MultiFunctionalDetector.hh"

// NPTool - ROOT headers
#include "TInteractionCoordinates.h"
#include "TGaspardTrackerData.h"

using namespace std;



class GaspardTrackerModule
{
public:
   GaspardTrackerModule();
   virtual ~GaspardTrackerModule();

public:
   // Read stream at Configfile to pick-up parameters of detector (Position,...)
   virtual void ReadConfiguration(string Path) = 0;

   // Construct detector and inialise sensitive part.
   virtual void ConstructDetector(G4LogicalVolume* world) = 0;

   // Read sensitive part of a the GaspardTrackerModule detector and fill the Root tree.
   virtual void ReadSensitive(const G4Event* event) = 0;

   // Add Detector branch to the ROOT output tree
   virtual void InitializeRootOutput();

   // Initialize all scorers necessary for each detector
   virtual void InitializeScorers() = 0;

   // Give the static TInteractionCoordinates from VDetector to the classes
   // deriving from GaspardTrackerModule
   // This is mandatory since the GaspardTracker*** does not derive from VDetector
   virtual void SetInterCoordPointer(TInteractionCoordinates* interCoord) = 0;
   virtual TInteractionCoordinates* GetInterCoordPointer() = 0;

public:
   TGaspardTrackerData*		GetEventPointer() 	{return ms_Event;};

protected:
   // Class to store the result of simulation
   static TGaspardTrackerData*		ms_Event;

   // Set to true if you want this stage on you telescope
   vector<bool>      m_wFirstStage;
   vector<bool>      m_wSecondStage;
   vector<bool>      m_wThirdStage;

   // Set to true if you want to see Telescope Frame in your visualisation
   bool              m_non_sensitive_part_visiualisation;

protected:
   // First stage Associate Scorer
   G4MultiFunctionalDetector* m_FirstStageScorer;

   // Second stage Associate Scorer
   G4MultiFunctionalDetector* m_SecondStageScorer;

   // Third stage Associate Scorer 
   G4MultiFunctionalDetector* m_ThirdStageScorer;
};

#endif
