#include<vector>

class european{
    public:
    //constructor
    european(
    double S0_ = 140,
    double k_ = 150,
    double volatility_ = 0.24,
    double interest_rate_ = 0.07,
    double time_to_maturity_ = 0.75,
    double barrier_level_ = 120
    );
    //destructor
    ~european(){};

    //methods
    double simulation();
    double monte_carlo(int n);

    //members
    std::vector<double> thisPath;
    double S0;
    double k;
    double volatility;
    double interest_rate;
    double time_to_maturity;
    double barrier_level;
};
