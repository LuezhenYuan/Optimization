# include "Simulated_Annealing.h"
double my_next(double current_temperature,double downratio=0.999){//the annealing schedule
    return current_temperature*downratio;
}
