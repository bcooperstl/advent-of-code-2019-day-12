#ifndef __FUNCS_H__
#define __FUNCS_H__

#define DIM_COUNT 3
#define MOON_COUNT 4

extern int position[DIM_COUNT][MOON_COUNT];
extern int velocity[DIM_COUNT][MOON_COUNT];

void apply_gravity();
void apply_velocity();
int calculate_total_energy();
void dump(int step_number);
void run_steps(int num_steps);

#endif
