#include "construction.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Box.hh"
MyDetectorConstruction::MyDetectorConstruction()
{}
MyDetectorConstruction::~MyDetectorConstruction()
{}
G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
  G4NistManager *nist = G4NistManager::Instance();
  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

  G4Box *solidWorld = new G4Box ("solidWorld", 0.5*m,0.5*m,0.5*m);
  G4LogicalVolume *logicalWorld = new G4LogicalVolume(solidWorld,worldMat,"logicWorld");
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),logicalWorld,"physWorld",0,false,0,true);


  return physWorld;
}


