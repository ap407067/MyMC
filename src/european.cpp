#include<iostream>
#include<cmath>
#include<ctime>
#include<random>
#include<chrono>
#include"european.h"

//definition of constructor

european::european(
    double S0_,
    double k_,
    double volatility_,
    double interest_rate_,
    double time_to_maturity_,
    double barrier_level_
    )
    {
        S0 = S0_;
        k = k_;
        volatility = volatility_;
        interest_rate = interest_rate_;
        time_to_maturity = time_to_maturity_;
        barrier_level = barrier_level_;
    }

//method definition

double european::simulation(){
    int time_steps = time_to_maturity*252;
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    double random_number;
    std::normal_distribution<double> distribution(0.0, 1.0);
    double prices[time_steps];
    prices[0] = S0;
    for (int i = 1; i <= time_steps; i++) {
    double random_number = distribution(generator);
    double pom = (((interest_rate - (volatility * volatility)/2) * (1.0 / time_steps))
                  + volatility * sqrt(1.0 / time_steps) * random_number);
    prices[i] = prices[i - 1] * exp(pom);
    if (prices[i] <= barrier_level ){
        return 0;
    }
  }
  double payoff = prices[time_steps] - k;
  if (payoff < 0){
    payoff = 0;
  }
  return payoff;
}


int main() {
    double S0 = 140;
    double k = 150;
    double volatility = 0.24;
    double interest_rate = 0.07;
    double time_to_maturity = 0.75;
    double barrier_level = 135;
    int num_simulations = 1000000;

    european european_instance(S0, k, volatility, interest_rate, time_to_maturity, barrier_level);

    // std::default_random_engine generator(std::time(0));
    // double simulation_result1 = european_instance.simulation();
    // std::cout << "Simulation 1 Result: " << simulation_result1 << std::endl;
    // double simulation_result2 = european_instance.simulation();
    // std::cout << "Simulation 2 Result: " << simulation_result2 << std::endl;

     double sum = 0.0;
     for (int i = 1; i < num_simulations; i++){
        double pom = european_instance.simulation();
         sum += pom;
         }
    return 0;
}


