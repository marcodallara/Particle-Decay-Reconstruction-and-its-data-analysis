#include "AnalysisFramework/EventSource.h"


EventSource::EventSource() {
}


EventSource::~EventSource() {
}

void EventSource::run() {
  // loop over events
  const Event* ev;
  while ( ( ev = get() ) != nullptr ) {
    //notify the distapatcher 
    Dispatcher<Event>::notify( *ev );
     delete ev;
  }
  return;
}

