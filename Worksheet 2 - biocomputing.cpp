#include <iostream>

#include <time.h>
#include <stdlib.h>

#define N 10
#define P 5



int square (int x){
	
	return (x*x);
}



using namespace std;
int main(){
	
srand(time(NULL));
	
	typedef struct{
		int gene[N];
		int fitness;
	}individual;
	

	
	
	individual population[P];
	int i,j;
	for (i=0;i<P;i++){
		for (j=0;j<N;j++){
			
			population[i].gene[j]=rand()%2;
			cout <<population[i].gene[j] ;
		}
		cout << endl;
		population[i].fitness=0;
	}


cout << endl;

int population_fitness_total =0;

cout << "fitness"<<endl;
for (int i=0;i<P;i++){
	
	for(int j=0;j<N;j++){
		
		if(population[i].gene[j]){
			
			population[i].fitness++;
			
		}
		
		
	}
	
	cout << population[i].fitness <<endl;
	population_fitness_total = population_fitness_total + population[i].fitness;
}


cout << "-------------------------------------------"<<endl;
cout << "total population fitness: "<<population_fitness_total<<endl;


 individual offspring[P];
cout << endl;

for (int i=0;i<P;i++){
	int selection_point = rand()%population_fitness_total;
	int running_total=0;
	int j=0;
	
	while(running_total<= selection_point){
		running_total = running_total+population[j].fitness;
		j++;
	}
	offspring[i] = population[j-1];
	
}

int sum = 0;

cout << " NEW POPULATION INDIVIDUAL FITNESS" <<endl;
for (int i =0; i<P;i++){
	cout << (offspring[i].fitness)<<endl;
	
	sum += offspring[i].fitness;
}

cout << "new population fitness is : "<< sum <<endl;


cout << " function x2 " << endl;



for (int i =0; i<P;i++){
	
	cout << (square(offspring[i].fitness))<<endl;
	
	
}

	
	
	return 0;
}
