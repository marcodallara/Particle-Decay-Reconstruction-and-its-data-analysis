#include <iostream>
#include <fstream>
#include <string>

struct Event;
struct Partcile;

void dump(const Event& e);
const Event* read(std:: ifstream& in );
void clear(const Event* e);

int main( int argc, char* argv[] ){
  
  const char* name = argv[1];
  std::ifstream file( name ); //open input file
  const Event* e;
  while( ( e = read( file))  != nullptr ){ //looping file
      dump( *e );
      clear( e );
  }
    return 0;
}
