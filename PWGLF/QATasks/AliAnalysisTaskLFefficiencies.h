#ifndef __AliAnalysisTaskLFefficiencies__
#define __AliAnalysisTaskLFefficiencies__

#include "AliAnalysisTaskSE.h"

#include <string>

#include <AliEventCuts.h>
#include <AliPID.h>

class TF1;
class TH2F;
class TH3D;
class AliFlowTrackCuts;
class AliAODTrack;
class AliVVertex;
class AliPIDResponse;
class TList;

class AliAnalysisTaskLFefficiencies : public AliAnalysisTaskSE {
public:
  AliAnalysisTaskLFefficiencies(TString taskname = "LFefficienciesTask");
  virtual ~AliAnalysisTaskLFefficiencies();

  static bool  HasTOF(AliVTrack *t);

  virtual void   UserCreateOutputObjects();
  virtual void   UserExec(Option_t *);
  virtual void   Terminate(Option_t *);

  AliEventCuts  fEventCut;

  bool fUseMCtruthParams;
  static const std::string fPosNeg[2];
  static const int fNcuts;
  static const std::string fCutNames[5];
private:
  AliAnalysisTaskLFefficiencies (const AliAnalysisTaskLFefficiencies &source);
  AliAnalysisTaskLFefficiencies &operator=(const AliAnalysisTaskLFefficiencies &source);

  TList* fOutputList;                                    //!<! Output list
  TH3D* fGeneratedYPhiPt[AliPID::kSPECIESC][2];          //!<! Generated particles
  TH3D* fReconstructedYPhiPt[AliPID::kSPECIESC][2][5];   //!<! Reconstructed particles vs y, Phi and pT, {FB4,FB5,FB5+PID TPC, FB5 + TOF matching, FB8 + PID TOF}
  TH3D* fGeneratedEtaPhiPt[AliPID::kSPECIESC][2];        //!<! Generated particles in the eta
  TH3D* fReconstructedEtaPhiPt[AliPID::kSPECIESC][2][5]; //!<! Reconstructed particles vs eta, Phi and pT, {FB4,FB5,FB5+PID TPC, FB5 + TOF matching, FB8 + PID TOF}

  /// \cond CLASSDEF
  ClassDef(AliAnalysisTaskLFefficiencies, 1);
  /// \endcond
};


#endif /* defined(__AliAnalysisTaskLFefficiencies__) */
