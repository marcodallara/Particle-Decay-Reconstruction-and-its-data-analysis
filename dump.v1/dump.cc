#include <iostream>
#include <fstream>

using namespace std;

//dump 
void dump(int event_num, int particle_num, float x, float y, float z, int* charge, float* p_x, float* p_y, float* p_z ){
    //dump event number
    cout<<event_num<<endl;
    //dump number of particle, cooedinates and caratheristics for each one
    cout<<particle_num<<endl;
    cout<<x<<" "<<y<<" "<<z<<endl;
    for(int i=0;i<particle_num;i++)
    cout<<*(charge+i)<<" "<<*(p_x+i)<<" "<<*(p_y+i)<<" "<<*(p_z+i)<<endl;
    
}

