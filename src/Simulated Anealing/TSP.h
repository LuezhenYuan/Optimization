#ifndef TSP_H_INCLUDED
#define TSP_H_INCLUDED
#include "Simulated_Annealing.h"
#include <fstream>
#include <string>
#include <random>
#include "string_process_two.h"
using namespace std;
class TSP:public Simulated_Annealing_Problem<int*>{
double* m_distance;
double max_length;
public:

int m_size;
TSP(string data_file="TSPdata.txt");//Input file. The coordinate of each city.
int* initial_state();
double energy(int* state);//[0 1]
int* neighbour(int* state);
double& distance(int i, int j);//A[i][j]=distance[(2*m_size-i)(i-1)/2+j-i];

};

inline double& TSP::distance(int i, int j){//A[i][j]=distance[(2*m_size-i)*(i-1)/2+j-i];
    int tmp;
    if(i>j){
        tmp=i;i=j;j=tmp;
    }
    //else if(i==j){ return 0;}
    return m_distance[(2*m_size-i)*(i-1)/2+j-i];//i,j>=1
}

#endif // TSP_H_INCLUDED
