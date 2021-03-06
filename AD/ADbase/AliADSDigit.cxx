/**************************************************************************
 * Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 *                                                                        *
 * Author: The ALICE Off-line Project.                                    *
 * Contributors are mentioned in the code where appropriate.              *
 *                                                                        *
 * Permission to use, copy, modify and distribute this software and its   *
 * documentation strictly for non-commercial purposes is hereby granted   *
 * without fee, provided that the above copyright notice appears in all   *
 * copies and that both the copyright notice and this permission notice   *
 * appear in the supporting documentation. The authors make no claims     *
 * about the suitability of this software for any purpose. It is          *
 * provided "as is" without express or implied warranty.                  *
 **************************************************************************/

#include "AliADSDigit.h"

ClassImp(AliADSDigit);

//__________________________________________________________________________
AliADSDigit::AliADSDigit()
  : AliDigit()
  , fPMNumber(0)
  , fNBins(0)
  , fCharges(NULL)
{
  // Standard default
  // constructor
}

//__________________________________________________________________________
AliADSDigit::AliADSDigit(Int_t    pmnumber,
                         Int_t    nbins,
                         Float_t *charges,
                         Int_t   *labels)
  : AliDigit()
  , fPMNumber(pmnumber)
  , fNBins(nbins)
  , fCharges(NULL)
{
  // Constructor
  // Used in the digitizer
  fCharges = new Float_t[fNBins];
  if (charges) {
    for(Int_t i = 0; i < fNBins; ++i)
      fCharges[i] = charges[i];
  } else {
    for(Int_t i = 0; i < fNBins; ++i)
      fCharges[i] = 0;
  }
  if (labels)
    for(Int_t iTrack = 0; iTrack < 3; ++iTrack) fTracks[iTrack] = labels[iTrack];
}

//__________________________________________________________________________
AliADSDigit::~AliADSDigit()
{
  // Destructor
  // Delete the charges array if it was allocated
  if (fCharges)
    delete [] fCharges;
  fCharges = NULL;
}

void AliADSDigit::Clear(Option_t* )
{
  if (fCharges)
    delete [] fCharges;
  fCharges = NULL;
}
//__________________________________________________________________________
void AliADSDigit::Print(Option_t*) const
{
  // Dumps digit object
  Dump();
}
