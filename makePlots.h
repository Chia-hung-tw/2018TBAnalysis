/////////////////////////////////////////////////////////
// Arthor: Chia-hung Chien  chchien521@gmail.com       
// Just use the same class name as we used to.
// Date : 20-June-2018
/////////////////////////////////////////////////////////

#ifndef makePlots_h
#define makePlots_h

#include "TTree.h"
#include "TROOT.h"
#include "TH2Poly.h"
#include "TApplication.h"
#include "TChain.h"
#include <string>
#include <vector>

using namespace std;

const int kHGCalLayerHOffset = 19;
const int kHGCalLayerHMask   = 0x7F;
const int kHGCalCellHMask    = 0xFF;

class makePlots{
 public:
  makePlots();
  makePlots( TChain *c1,TChain *c2,TChain *c3,string filename );
  makePlots( TChain *c1,TChain *c2,string filename );
 
  ~makePlots();
  
  void Loop();
  void Event_Display();
  void NtupleMaker();
  
  //member
  bool Is_Data;
  int  beamE;
  int  runN; //0 for MC
  int  PID; // 0 for electron, 1 for pion, 2 for muon
  string beam_str; // "Ele","Pi","Mu"

 private:
  // Members
  string fname;
  //TApplication *app;
  
  TFile        *Inputfile;
  TTree        *T_Rechit;
  TTree        *T_DWC;
  TTree        *T_Meta;
  TTree        *T_MC;
  int          nevents;
  
  // Mainframe functions
  void Init();
  void Init_Runinfo();
  void GetData(int evt);
  void Getinfo(int nhit, int &layer,double &x, double &y,double &z,double &ene);    
  // Tool functions
  void InitTH2Poly(TH2Poly& poly); //Give frame to TH2Poly
  void root_logon();

  ///////////////////////////////
  // Declaration of leaf types //
  ///////////////////////////////
  /*Data*/
  //For Rechit
   UInt_t          event;
   UInt_t          run;
   Int_t           pdgID;
   Double_t        beamEnergy;
   Double_t        trueBeamEnergy;
   Int_t           NRechits;
   vector<unsigned int> *rechit_detid;
   vector<unsigned int> *rechit_module;
   vector<unsigned int> *rechit_layer;
   vector<unsigned int> *rechit_chip;
   vector<unsigned int> *rechit_channel;
   vector<unsigned int> *rechit_type;
   vector<float>   *rechit_x;
   vector<float>   *rechit_y;
   vector<float>   *rechit_z;
   vector<int>     *rechit_iu;
   vector<int>     *rechit_iv;
   vector<float>   *rechit_energy;
   vector<float>   *rechit_energy_noHG;
   vector<float>   *rechit_amplitudeHigh;
   vector<float>   *rechit_amplitudeLow;
   vector<int>     *rechit_hg_goodFit;
   vector<int>     *rechit_lg_goodFit;
   vector<int>     *rechit_hg_saturated;
   vector<int>     *rechit_lg_saturated;
   vector<int>     *rechit_fully_calibrated;
   vector<float>   *rechit_TS2High;
   vector<float>   *rechit_TS2Low;
   vector<float>   *rechit_TS3High;
   vector<float>   *rechit_TS3Low;
   vector<float>   *rechit_Tot;
   vector<float>   *rechit_time;   
   vector<float>   *rechit_timeMaxHG;
   vector<float>   *rechit_timeMaxLG;
   vector<float>   *rechit_toaRise;
   vector<float>   *rechit_toaFall;

   // For ImpactPoints (from Delayed wire chamber)
   Int_t           ntracks;
   // ignore the layers currently
   Float_t         trackChi2_X;
   Float_t         trackChi2_Y;
   Int_t           dwcReferenceType;
   Double_t        m_x;
   Double_t        m_y;
   Double_t        b_x;
   Double_t        b_y;

   // TBD

   // For metadata
   Int_t           configuration;
   Float_t         biasCurrentCh0;
   Float_t         biasCurrentCh1;
   Float_t         biasCurrentCh2;
   Float_t         biasCurrentCh3;
   Float_t         humidity_RHDP4;
   Float_t         TCassette07;
   Float_t         tablePositionY;
   Float_t         humidity_air;
   Float_t         temperature_air;
   
   /*MC*/
   // Declaration of leaf types
   vector<float>   *simHitLayEn1EE;
   vector<float>   *simHitLayEn2EE;
   vector<float>   *simHitLayEn1FH;
   vector<float>   *simHitLayEn2FH;
   vector<float>   *simHitLayEn1BH;
   vector<float>   *simHitLayEn2BH;
   Double_t        xBeam;
   Double_t        yBeam;
   Double_t        zBeam;
   Double_t        pBeam;
   vector<unsigned int> *simHitCellIdEE;
   vector<float>   *simHitCellEnEE;
   vector<unsigned int> *simHitCellIdFH;
   vector<float>   *simHitCellEnFH;
   vector<unsigned int> *simHitCellIdBH;
   vector<float>   *simHitCellEnBH;
   vector<unsigned int> *simHitCellIdBeam;
   vector<float>   *simHitCellEnBeam;

};

#endif
