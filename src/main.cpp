#include<Rcpp.h>
#include<vector>
#include<ctime>
#include<cstdlib>
#include"AsianOption.h"
#include"getVecMean.h"
#include"getVecStdDev.h"
#include"european.h"

using namespace Rcpp;
using std::vector;

// [[Rcpp::export]]
double monte_carlo(
  double S0 = 140,
    double k = 150,
    double volatility = 0.24,
    double interest_rate = 0.07,
    double time_to_maturity = 0.75,
    double barrier_level = 120,
	  int nReps = 10000){

	srand( time(NULL) );

	european european_instance(S0, k, volatility, interest_rate, time_to_maturity, barrier_level);

	// monte carlo 
	double sum = 0.0;
	for (int i = 1; i < nReps; i++){
	  double pom = european_instance.simulation();
	  sum += pom;
	  //std::cout << "Iteration:" << i << "\nPom:" << pom << "\nSum:" << sum << std::endl;
	}
	double outcome = sum/nReps;
	return outcome;
}
