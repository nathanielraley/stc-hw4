#include <stdio.h>
#include <mpi.h>
#include <math.h>

const int NNN=1000000;

double f(double x);

int main(int argc, char *argv[])
{
        int myrank, size;
	int localstart=0, localend;
	double localsum=0.0;
	double sum=0.0;
        double h,x;
	int i;

	// Initilize Mpi and local rank and size
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);

        if(myrank==0)
  printf("\n");	
	//Different MPI Tasks are doing different jobs!!!
        localstart=NNN/size * myrank +1; 
	localend=NNN/size * (myrank +1 );

h=1.0/(double)NNN;

//printf("h=%f",h);

for (i=localstart-1; i<localend; i++){
x=h*(double)i;
localsum+=h*(double)0.5*(f(x)+f(x+h));
}
//printf("localsum=%f",localsum);
 
	MPI_Reduce(&localsum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if(myrank==0)

		printf("\nThe value of pi is approximately %.15f\n", sum );

        MPI_Finalize();
        return 0;
}



double f(double x){ 
return (4.0 / (1.0 + x*x)); }

