/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

/// \ingroup base
/// \class AliDrawStyle
/// \brief AliDrawStyle
///  ### AliDrawStyle - Class to access drawing styles
///  * Several drawing styles can be regeistered and used in the same moment
///    * Styles are identified using strings as identifiets
///      * TStyle
///      * MarkerStyle[]  AliDrawStyle::GetMarkerStyle(const char *style, Int_t index);
///      * MarkerColors[] AliDrawStyle::GetMarkerColor(const char *style, Int_t index);
///      * FillColors[]   AliDrawStyle::GetFillColor(const char *style, Int_t index); 
///  * Default styles are created  AliDrawStyle::SetDefaults()
///    * default style is based on the fig template -  https://twiki.cern.ch/twiki/pub/ALICE/ALICERecommendationsResultPresentationText/figTemplate.C
///    * users should be able to regiester their oun styles (e.g in macros)
///  * Usage (work in progress)
///    * performance reports -  with styles as a parameter 
///    * QA reports
///    * AliTreePlayer, and TStatToolkit  
/// \author marian  Ivanov marian.ivanov@cen.ch


#include "TObject.h"
#include <map>
#include <vector>
#include <string>
#include "TString.h"
class TPRegexp; 
class TStyle;

class AliDrawStyle : public TObject{
public:
  static void ApplyStyle(const char* styleName);
  static void SetDefaults();
  static TString GetLatexAlice(const char * symbol);
  static void AddLatexSymbol(const char * symbolName, const char * symbolTitle);
  static Int_t GetMarkerStyle(const char *style, Int_t index);
  static Int_t GetMarkerColor(const char *style, Int_t index);
  static Int_t GetFillColor(const char *style, Int_t index); 
  static void PrintLatexSymbols(Option_t *option,TPRegexp& regExp);
  static void PrintStyles(Option_t *option, TPRegexp& regExp);
protected:
  static std::map<TString, TString> fLatexAlice;              // map of prefdefiend latex symbols - fomatted according ALICE rules
  static std::map<TString, TStyle*>  fStyleAlice;             // map of Alice predefined styles (+user defined) 
  static std::map<TString, std::vector<int>> fMarkerStyles;   // map of predefiend marker styles arrays
  static std::map<TString, std::vector<int>> fMarkerColors;   // map of predefiend colors  arrays
  static std::map<TString, std::vector<int>> fFillColors;     // map of predefiend fill colors arrays 
  //
  static void  RegisterDefaultLatexSymbols();                 // initialize default LatexSymbols
  static void  RegisterDefaultStyle();                        // initialize default TStyles
  static void  RegisterDefaultMarkers();                      // initialize default Markers/Colors

  ClassDef(AliDrawStyle,1);
};
