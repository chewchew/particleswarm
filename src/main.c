// main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "algorithm.h"

float equation(float x, float y)
{
	return x * x - y;
}

float fitness(Particle p, float goal)
{
	float x = p.solution[0];
	float y = p.solution[1];
	return abs(goal - equation(x,y));
}

// === random(float max) ===
// returns a random number 0 +/- [max]
float random(float max)
{
	float random_number = rand() / (float)RAND_MAX;
	float rand_neg      = rand() / (float)RAND_MAX;
	if (rand_neg < 0.5)
		return random_number * max;
	else
		return random_number * max * (-1);
}

// === get_rand_vector(int size, float max) ===
// size - size of array
// max  - maximum value of random values
// returns a float-array with random values
float* get_rand_vector(int size, float max)
{
	float* random_vector = (float*)(malloc(size * sizeof(float)));
	for (int i = 0; i < size; i++)
		random_vector[i] = random(max);
	return random_vector;
}

int main()
{	
	// seed rand
	srand(time(NULL));
	
	// setup globals
	float goal = 4.7;
	int number_of_arguments = 2;
	int number_of_particles = 10;
	int max = 10;
	float max_velocity = 5.0;

	// set-up particles
	Particle particles[number_of_particles];
	for (int i = 0; i < number_of_particles; i++)
	{	
		Particle p;

		// init nArgs
		p.nArgs = number_of_arguments;

		// init solution
		p.solution = get_rand_vector(number_of_particles,max);

		// init velocity
		p.velocity = get_rand_vector(number_of_particles,max_velocity);

		// init pBest
		p.pBest = fitness(p,goal);

		particles[i] = p;
	}

	// === DEBUG ===
	printf("==\n");
	for (int i = 0; i < number_of_particles; i++)
	{
		Particle p = particles[i];
		printf("Particle :\n");
		printf("%f,%f\n", p.solution[0], p.solution[1]);
		printf("%f,%f\n", p.velocity[0], p.velocity[1]);
		printf("%f\n",p.pBest);
		printf("\n");
	}
	
	// free space
	for (int i = 0; i < number_of_particles; i++)
	{
		Particle p = particles[i];
		free(p.solution);
		free(p.velocity);
	}
}
