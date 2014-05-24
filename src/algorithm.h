#ifndef ALGORITHM
#define ALGORITHM

/* =========== struct Particle ===========
	nArgs    - number of values contained
	solution - contains values for equation-solution
	velocity - rate of change for each solution-value 
	pBest    - best fitness achieved so far */
typedef struct
{
	int nArgs;
	float* solution;
	float* velocity;
	float pBest;
} Particle;

/* ================ run ==================
	p_particles - pointer to an array containing possible solutions
	fitness	    - function for calculating fitness */
Particle run(Particle* p_particles, float (*fitness)(Particle, float));

#endif
