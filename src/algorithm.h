#ifndef ALGORITHM
#define ALGORITHM

/* =========== struct Particle ===========
	nArgs    - number of values contained
	solution - contains values for equation-solution
	velocity - rate of change for each solution-value 
	pBest    - best fitness achieved so far */
typedef struct Particle
{
	int nArgs;
	float* solution;
	float* velocity;
	float pbest;
} Particle;

Particle run(int nParticles, Particle particles[nParticles]);

#endif
