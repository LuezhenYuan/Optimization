#include "TSP.h"
#include <cstdlib>
#include <cmath>
TSP::TSP(string data_file){
    ifstream file_in(data_file);
    vector<string> item;
	std::string line;

	while(getline(file_in,line)){//The first city(index 1) is the starting and the end point in a TSP tour.
		line_splice_2(line,' ',item);
	}
	m_size = item.size()/2;//m_size 'cities'.
	m_distance=(double*)malloc(sizeof(double)*m_size*(m_size-1)/2);
	int i=0,j=0;
	max_length=0;
	for(i=1;i<=m_size;i++){//i,j>=1
		for(j=i+1;j<=m_size;j++){
            distance(i,j)=sqrt((stod(item[2*i-1])-stod(item[2*j-1]))*(stod(item[2*i-1])-stod(item[2*j-1])) + (stod(item[2*i-2])-stod(item[2*j-2]))*(stod(item[2*i-2])-stod(item[2*j-2]))) ;
            if(distance(i,j)>max_length) max_length=distance(i,j);
		}
	}
}


int* TSP::initial_state(){
    int* state;
    state=(int*) malloc(sizeof(int)*(m_size+1));//The last city is the same as the first city.
    for(int i=1;i<=m_size;i++){
        state[i-1]=i;
    }
    state[m_size]=1;//The last city is the same as the first city.
    return state;
}
double TSP::energy(int* state){
    double sum;
    sum=0;
    for(int i=0;i<m_size;i++){
        sum+=distance(state[i],state[i+1]);
    }
    return sum/m_size/max_length;//shrink the energy to (0,1)
}

int* TSP::neighbour(int* state){//The core of the simulated annealing
    std::random_device rd;
    std::mt19937_64 rseed(rd());
    std::uniform_int_distribution<int> dr(2,m_size);
    int u=dr(rseed),v=dr(rseed),tmp;
    while(u==v){
        v=dr(rseed);
    }
    if(u>v){
        tmp=u;u=v;v=tmp;
    }
    int* result;
    result=(int*)malloc(sizeof(int)*(m_size+1));
    int i=0;
    for(i=1;i<u;i++){
        result[i-1]=state[i-1];
    }
    for(i=u;i<=v;i++){
        result[i-1]=state[v-i+u-1];
    }
    for(i=v+1;i<=m_size+1;i++){
        result[i-1]=state[i-1];
    }
    return result;
}
