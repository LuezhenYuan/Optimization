//This program uses the Simulated Annealing method to solve the Travelling salesman problem(TSP) problem.
//In "Simulated_Annealing.h", I use the generic programming approach to implement a generic versioni of the Simulated Annealing.
//In TSP.cpp, I use the Object-oriented programming method to specify the TSP problem.
//  This problem can be solved using the "Simulated_Annealing" method in the "Simulated_Annealing.h".
///////////

#include <iostream>
#include <random>
#include "Simulated_Annealing.h"
#include "TSP.h"
#include <cmath>
using namespace std;

int main()
{
    cout << "Simulated Annealing For Travelling salesman problem(TSP) Problem." << endl;
    cout<<"TSP problem is an NP-complete problem(NP-hard problem) in combinatorial optimization.\nSimulated Annealing is a metaheuristic to approximate global optimization in a large search space.\n\n";
    TSP tsp("TSPdata.txt");
    int* result;
    int iteration;
    double downratio,t_low;
    cout<<"It's better to make the lowest temperature lower than 1e-20\n";
    cout<<"Lowest temperature [1e-20]:";cin>>t_low;
    cout<<"\nAnnealing plan r. (T=rT) [0.999]:";cin>>downratio;
    string file_name;
    cout<<"Output file name. null for drop energy message in each step. [null]:";cin>>file_name;
    cout<<"\n";
    iteration=log(t_low/100)/log(downratio);
    clock_t start,stop;//used in recording time
    double duration;//used in recording time
    start=clock();
    result=Simulated_Annealing(&tsp,iteration,downratio,file_name);
    stop=clock();
    duration=((double)(stop-start))/CLOCKS_PER_SEC;//calculate the real time

    for(int i=0;i<tsp.m_size+1;i++){
        cout<<result[i]<<endl;
    }
    double distance_sum=0;
    for(int i=0;i<tsp.m_size;i++){
        distance_sum+=tsp.distance(result[i],result[i-1]);
    }
    cout<<"Sum of distance: "<<distance_sum<<endl;
    printf("The waste of time:%fs\n",duration);
    cout<<"\n\n";
    return 0;
}







