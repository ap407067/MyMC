This are all the necessary files needed to run R package created with RCPP using OOP in C++.
The package allows user to run Monte Carlo simulation of European style down-and-out call option with a barrier active between the moment of pricing and the option expiry.
Funcion can calculate the price of the option for any values of its characteristics, with following values set as default:

 - price of the underyling at the moment of option pricing: S0 = 140
  - strike price K = 150
  - annualized volatility rate σ = 0.24
  - annualized risk-free rate r = 0.07
  - time to maturity t = 0.75
