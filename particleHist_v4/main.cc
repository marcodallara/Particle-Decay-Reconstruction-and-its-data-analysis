#include <vector>
#include <string>

#include "EventSource.h"
#include "AnalysisSteering.h"
#include "AnalysisInfo.h"
#include "SourceFactory.h"
#include "AnalysisFactory.h"



using namespace std;

int main( int argc, char* argv[] ) {


  // store command line parameters
  AnalysisInfo* info = new AnalysisInfo( argc, argv );

  // create data source
  EventSource* es = SourceFactory::create( info );

  // create a list of analyzers
  vector<AnalysisSteering*> aList = AnalysisFactory::create( info );
  
  // initialize all analyzers
  for ( auto as: aList ) as->beginJob();

  //loop over events and for each one notify the dispatcher
  es->run();
  
  // finalize all analyzers
  for ( auto as: aList ) as->endJob();
  
  delete es;

  return 0;
 

}

