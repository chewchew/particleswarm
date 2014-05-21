// main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorithm.h"

float equation(float x, float y)
{
	return x * x - y;
}

int main()
{	
	// seed rand
	srand(time(NULL));
	
	// setup globals
	int number_of_arguments = 2;
	int number_of_particles = 10;
	int max = 100;

	// set-up particles
	Particle particles[number_of_particles];
	for (int i = 0; i < number_of_particles; i++)
	{	
		Particle p;

		// init nArgs
		p.nArgs = number_of_arguments;

		// init solution
		float random_solution[2];
		for (int j = 0; j < number_of_arguments; j++)
		{
			float random_number = rand() / (float)RAND_MAX;
			random_solution[j] = random_number * max;
		}
		p.solution = random_solution;

		// init velocity

		// init pBest

		particles[i] = p;
	}
}
