#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"

long gcd(long a, long b)
{
    long temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}

int main (int argc, char * argv[])
{
    FILE * infile=NULL;
    char buffer[1024];
    
    memset(&buffer, '\0', sizeof(buffer));
    
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }
    
    fprintf(stderr, "Opening file %s\n", argv[1]);
    
    infile=fopen(argv[1], "r");
    if (infile == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(1);
    }
    
    for (int i=0; i<4; i++)
    {
        fgets(buffer, sizeof(buffer), infile);

        char * xPos = strchr(buffer, '=')+1;
        char * yPos = strchr(xPos, '=')+1;
        char * zPos = strchr(yPos, '=')+1;
        
        position[0][i]=atoi(xPos);
        position[1][i]=atoi(yPos);
        position[2][i]=atoi(zPos);
        velocity[0][i]=0;
        velocity[1][i]=0;
        velocity[2][i]=0;        
    }
    
    fclose(infile);
    
    int steps[DIM_COUNT];
    for (int i=0; i<DIM_COUNT; i++)
    {
        steps[i]=steps_to_repeat(i);
    }
    
    long gcdXY=gcd(steps[0],steps[1]);
    long lcmXY=(long)(steps[0])*(long)(steps[1])/(long)gcdXY;
    long gcdXYZ=gcd(lcmXY, steps[2]);
    long lcm=(lcmXY*(long)(steps[2]))/(long)gcdXYZ;
    
    printf("minimum steps for the cycle is %ld\n", lcm);
    
    return 0;
}
