//This file implement the "Simulated Annealing" using generic programming approach.
//The template function "my_Acceptance" is the core of the algorithm.
/////////

/////////
//"class Simulated_Annealing_Problem"
//This is a virtual base class. All the problem you want to solve using
//  the template function "my_Acceptance", should design a class that inherit
//  from the "class Simulated_Annealing_Problem".
//The three pure virtual functions in the "class Simulated_Annealing_Problem" should
//  be defined in your class.
////////

////////
//Template function:
//State Simulated_Annealing(Simulated_Annealing_Problem<State>* pSAP,int iteration=100000,
//  double downratio=0.999, string file_name="Simulated_Path.txt",void m_free(State pst)=my_free,
//  double m_next(double current_temperature,double downratio)=my_next,
//  double Acceptance(Simulated_Annealing_Problem<State>* pSAP,State st1,
//  State st2, double temperature)=my_Acceptance )
//
//Simulated_Annealing_Problem<State>* pSAP: your problem need to solve. You should implement in class
//int iteration=100000: The max iteration
//double downratio=0.999: The annealing plan(temprature decrease rate)
//string file_name="Simulated_Path.txt": Output file name
//void m_free(State pst)=my_free: Your free function. free a state
//double Acceptance(Simulated_Annealing_Problem<State>* pSAP,State st1,
//  State st2, double temperature)=my_Acceptance ): Implement how to accept a neighbour state
////////

#ifndef SIMULATED_ANNEALING_H_INCLUDED
#define SIMULATED_ANNEALING_H_INCLUDED
#include <random>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
template <class State>
class Simulated_Annealing_Problem{
public:
virtual State initial_state()=0;
virtual double energy(State state)=0;//[0 1]
virtual State neighbour(State state)=0;
};

double my_next(double current_temperature,double downratio);//the annealing schedule


template <class State>
void my_free(State pst){
    free(pst);
}

template <class State>
double my_Acceptance(Simulated_Annealing_Problem<State>* pSAP,State st1, State st2, double temperature){
    //return 1/(1+1/exp(-(pSAP->energy(st1)-pSAP->energy(st2))/temperature));
    return exp(-(pSAP->energy(st1)-pSAP->energy(st2))/temperature);
}

template <class State>
State Simulated_Annealing(Simulated_Annealing_Problem<State>* pSAP,int iteration=100000,double downratio=0.999, string file_name="Simulated_Path.txt",void m_free(State pst)=my_free, double m_next(double current_temperature,double downratio)=my_next,double Acceptance(Simulated_Annealing_Problem<State>* pSAP,State st1, State st2, double temperature)=my_Acceptance ){
    State pst;State pst_tmp;
    pst = pSAP->initial_state();
    double temperature=100;
    double energy,last_energy=-1;
    int last_stage_length;
    std::random_device rd;
    std::mt19937_64 rseed(rd());
    std::uniform_int_distribution<int> dr(0,1);
    ofstream out;
    if(file_name!="null")
        out.open(file_name,ios::app);
    out<<"Distance\n";
    last_stage_length=0;
    for(int i=0;i<iteration;i++){
        energy=pSAP->energy(pst);
        out<<energy<<endl;
        pst_tmp=pSAP->neighbour(pst);
        if(dr(rseed)<Acceptance(pSAP,pst_tmp,pst,temperature)){//drop current pst, accept pst_tmp
            m_free(pst);
            pst=pst_tmp;
        }
        else{//drop pst_tmp
            m_free(pst_tmp);

        }
        if(last_energy!=energy){
            last_stage_length=0;
        }
        else{
            last_stage_length++;
        }
        if(last_stage_length>iteration/5) break;//Prevent useless iteration. When this code run, it likely that the final stage in just here.
        temperature=m_next(temperature,downratio);
        last_energy=energy;
    }
    //cout<<"last_stage_length"<<last_stage_length<<endl;
    out<<"\n\n";
    out.close();out.clear();
    return pst;
}


#endif // SIMULATED_ANNEALING_H_INCLUDED
