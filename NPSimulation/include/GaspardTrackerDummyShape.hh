/*****************************************************************************
 * Copyright (C) 2009   this file is part of the NPTool Project              *
 *                                                                           *
 * For the licensing terms see $NPTOOL/Licence/NPTool_Licence                *
 * For the list of contributors see $NPTOOL/Licence/Contributors             *
 *****************************************************************************/

/*****************************************************************************
 * Original Author: N. de Sereville  contact address: deserevi@ipno.in2p3.fr *
 *                                                                           *
 * Creation Date  : 03/09/09                                                 *
 * Last update    :                                                          *
 *---------------------------------------------------------------------------*
 * Decription: Define a dummy module for the Gaspard tracker                 *
 *             The goal of this class is to be a starting point to create a  *
 *             new shape to be added to the Gaspard tracker.                 *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *
 *                                                                           *
 *****************************************************************************/

#ifndef GaspardTrackerDummyShape_h
#define GaspardTrackerDummyShape_h 1

// C++ headers
#include <vector>

// NPTool header
#include "GaspardTrackerModule.hh"
#include "TInteractionCoordinates.h"

using namespace std;

#define	INDEX	1000


class GaspardTrackerDummyShape : public GaspardTrackerModule
{
   ////////////////////////////////////////////////////
   /////// Default Constructor and Destructor /////////
   ////////////////////////////////////////////////////
public:
   GaspardTrackerDummyShape();
   virtual ~GaspardTrackerDummyShape();

   ////////////////////////////////////////////////////
   //////// Specific Function of this Class ///////////
   ////////////////////////////////////////////////////
public:
   // By Position Method
   void AddModule(G4ThreeVector TL           ,
                  G4ThreeVector BL           ,
                  G4ThreeVector BR           ,
                  G4ThreeVector CT           ,
                  bool          wFirstStage  ,
                  bool          wSecondStage ,
                  bool          wThirdStage);

   // By Angle Method
   void AddModule(G4double R            ,
                  G4double Theta        ,
                  G4double Phi          ,
                  G4double beta_u       ,
                  G4double beta_v       ,
                  G4double beta_w       ,
                  bool     wFirstStage  ,
                  bool     wSecondStage ,
                  bool     wThirdStage);

   // Effectively construct Volume
   // Avoid to have two time same code for Angle and Point definition
   void VolumeMaker(G4int TelescopeNumber          ,
                    G4ThreeVector     MMpos        ,
                    G4RotationMatrix* MMrot        ,
                    bool              wFirstStage  ,
                    bool              wSecondStage ,
                    bool              wThirdStage  ,
                    G4LogicalVolume*  world);


   ////////////////////////////////////////////////////
   ////  Inherite from GaspardTrackerModule class /////
   ////////////////////////////////////////////////////
public:
   // Read stream at Configfile to pick-up parameters of detector (Position,...)
   // Called in DetecorConstruction::ReadDetextorConfiguration Method
   void ReadConfiguration(string Path);

   // Construct detector and inialise sensitive part.
   // Called After DetecorConstruction::AddDetector Method
   void ConstructDetector(G4LogicalVolume* world);

   // Add Detector branch to the EventTree.
   // Called After DetecorConstruction::AddDetector Method
   void InitializeRootOutput();

   // Initialize all scorers necessary for the detector
   void InitializeScorers();

   // Read sensitive part and fill the Root tree.
   // Called at in the EventAction::EndOfEventAvtion
   void ReadSensitive(const G4Event* event);

   // Give the static TInteractionCoordinates from VDetector to the classes
   // deriving from GaspardTrackerModule
   // This is mandatory since the GaspardTracker*** does not derive from VDetector
   void SetInterCoordPointer(TInteractionCoordinates* interCoord);
   TInteractionCoordinates* GetInterCoordPointer()	{return ms_InterCoord;};


   ////////////////////////////////////////////////////
   ///////////////Private intern Data//////////////////
   ////////////////////////////////////////////////////
private:
   // Interaction Coordinates coming from VDetector through the 
   // SetInteractionCoordinatesPointer method
   TInteractionCoordinates* ms_InterCoord;

   // True if Define by Position, False is Define by angle
   vector<bool>   m_DefinitionType  ;

   // Used for "By Point Definition"
   vector<G4ThreeVector>   m_X1_Y1     ; // Top Left Corner Position Vector
   vector<G4ThreeVector>   m_X1_Y128   ; // Bottom Left Corner Position Vector
   vector<G4ThreeVector>   m_X128_Y1   ; // Bottom Right Corner Position Vector
   vector<G4ThreeVector>   m_X128_Y128 ; // Center Corner Position Vector

   // Used for "By Angle Definition"
   vector<G4double>  m_R      ; //  |
   vector<G4double>  m_Theta  ; //  > Spherical coordinate of Strips Silicium Plate
   vector<G4double>  m_Phi    ; //  |

   vector<G4double>  m_beta_u ; //  |
   vector<G4double>  m_beta_v ; //  > Tilt angle of the Telescope
   vector<G4double>  m_beta_w ; //  |
};



namespace GPDDUMMYSHAPE
{
   // Resolution
//   const G4double ResoFirstStage  = 0              ;// = 52keV of Resolution   //   Unit is MeV/2.35
   const G4double ResoFirstStage  = 0.022          ;// = 52keV of Resolution   //   Unit is MeV/2.35
   const G4double ResoSecondStage = 0          ;// = 130 keV of resolution //   Unit is MeV/2.35
//   const G4double ResoSecondStage = 0.055          ;// = 130 keV of resolution //   Unit is MeV/2.35
   const G4double ResoThirdStage  = 0              ;// = 100 keV of resolution //   Unit is MeV/2.35
//   const G4double ResoThirdStage  = 0.043          ;// = 100 kev of resolution //   Unit is MeV/2.35
   const G4double ResoTimeGpd     = 0.212765957    ;// = 500ps                 //   Unit is  ns/2.35

   // Geometry for the mother volume containing the different layers of your dummy shape module
   const G4double FaceFront          = 5.1*cm;
   const G4double FaceBack           = 5.1*cm;
//   const G4double Length             = 1.5*cm;
//   const G4double InterStageDistance = 5*mm;
   // for testing the excitation energy reconstruction
   const G4double Length             = 4*cm;
   const G4double InterStageDistance = 15*mm;

   // First stage
   const G4double FirstStageFace       = 5.0*cm;
//   const G4double FirstStageThickness  = 300*micrometer ;
   // for testing the excitation energy reconstruction
   const G4double FirstStageThickness  = 1.3*cm;
//   const G4int NumberOfStrips	       = 128;
   const G4int NumberOfStrips	       = 25;

   // Second stage
   const G4double SecondStageFace      = FirstStageFace;
   const G4double SecondStageThickness = 1*mm;

   // Third stage
   const G4double ThirdStageFace      = FirstStageFace;
   const G4double ThirdStageThickness = 1*mm;

   // Starting at the front of the first stage and going to the third stage 
   const G4double FirstStage_PosZ  = Length* -0.5 + 0.5*FirstStageThickness;
   const G4double SecondStage_PosZ = Length* -0.5 + 0.5*SecondStageThickness + 1*InterStageDistance;
   const G4double ThirdStage_PosZ  = Length* -0.5 + 0.5*ThirdStageThickness  + 2*InterStageDistance;
}

#endif
