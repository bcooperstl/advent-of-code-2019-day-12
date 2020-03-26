#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "funcs.h"

int position[DIM_COUNT][MOON_COUNT];
int velocity[DIM_COUNT][MOON_COUNT];

void apply_gravity()
{
    for (int i=0; i<DIM_COUNT; i++) // loop for x, y, z
    {
        for (int j=0; j<MOON_COUNT; j++)
        {
            for (int k=j+1; k<MOON_COUNT; k++)
            {
                if (position[i][j] < position[i][k])
                {
                    velocity[i][j]++;
                    velocity[i][k]--;
                }
                else if (position[i][j] > position[i][k])
                {
                    velocity[i][j]--;
                    velocity[i][k]++;
                }
                // do nothing if they are on the same line
            }
        }
    }
}

void apply_velocity()
{
    for (int i=0; i<DIM_COUNT; i++) // loop for x, y, z
    {
        for (int j=0; j<MOON_COUNT; j++)
        {
            position[i][j]+=velocity[i][j];
        }
    }    
}

int calculate_total_energy()
{
    int total_energy=0;
    int kinetic_energy=0;
    int potential_energy=0;
    int moon_energy=0;
    
    for (int i=0; i<MOON_COUNT; i++)
    {
        potential_energy=abs(position[0][i])+abs(position[1][i])+abs(position[2][i]);
        kinetic_energy=abs(velocity[0][i])+abs(velocity[1][i])+abs(velocity[2][i]);        
        moon_energy=potential_energy*kinetic_energy;
        total_energy+=moon_energy;
    }
    
    return total_energy;
}

/*
After 0 steps:
pos=<x=-1, y=  0, z= 2>, vel=<x= 0, y= 0, z= 0>
pos=<x= 2, y=-10, z=-7>, vel=<x= 0, y= 0, z= 0>
pos=<x= 4, y= -8, z= 8>, vel=<x= 0, y= 0, z= 0>
pos=<x= 3, y=  5, z=-1>, vel=<x= 0, y= 0, z= 0>
*/
void dump(int step_number)
{
    printf("After %d steps:\n", step_number);
    printf("pos=<x=%d, y=%d, z=%d>, vel=<x=%d, y=%d, z=%d>\n", position[0][0], position[1][0], position[2][0], velocity[0][0], velocity[1][0], velocity[2][0]);
    printf("pos=<x=%d, y=%d, z=%d>, vel=<x=%d, y=%d, z=%d>\n", position[0][1], position[1][1], position[2][1], velocity[0][1], velocity[1][1], velocity[2][1]);
    printf("pos=<x=%d, y=%d, z=%d>, vel=<x=%d, y=%d, z=%d>\n", position[0][2], position[1][2], position[2][2], velocity[0][2], velocity[1][2], velocity[2][2]);
    printf("pos=<x=%d, y=%d, z=%d>, vel=<x=%d, y=%d, z=%d>\n", position[0][3], position[1][3], position[2][3], velocity[0][3], velocity[1][3], velocity[2][3]);
    printf("Total Energy is %d\n", calculate_total_energy());
    printf("\n");
}

void run_steps(int num_steps)
{
    dump(0);
    for (int i=1; i<=num_steps; i++)
    {
        apply_gravity();
        apply_velocity();
        dump(i);
    }
}

