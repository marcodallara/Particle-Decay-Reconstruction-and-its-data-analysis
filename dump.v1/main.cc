#include <fstream>
#include <iostream>

//read data from file
int read(std::ifstream &file, float &x, float &y, float& z, int* charge, float* p_x, float* p_y, float* p_z );

//dump data
void dump(int event_num, int particle_num, float x, float y, float z, int* charge, float* p_x, float* p_y, float* p_z );

int main(int argc, char* argv[]){
    //take name of input file
    const char* name = argv[1];
    int event_num; //event id
    float x,y,z; //coordinates of the decay
    int charge[10]; //charges
    float p_x[10], p_y[10], p_z[10]; //momentums
    std::ifstream file( name ); //open input file
    //read and dump each event
    while(file>>event_num){
        int particle_num=read(file,x,y,z,charge,p_x,p_y,p_z);
        dump(event_num, particle_num, x, y, z, charge, p_x, p_y, p_z);

    }
    return 0;
}


