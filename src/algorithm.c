#include "algorithm.h"
#include <stdio.h>

Particle run(Particle* p_particles, float (*fitness)(Particle, float))
{
	printf("%f",p_particles[0].pBest);
}
