#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"

int main (int argc, char * argv[])
{
    FILE * infile=NULL;
    char buffer[1024];
    int num_steps=0;
    
    memset(&buffer, '\0', sizeof(buffer));
    
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s filename steps\n", argv[0]);
        exit(1);
    }
    
    num_steps=atoi(argv[2]);
    
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
    
    run_steps(num_steps);
    
    return 0;
}
