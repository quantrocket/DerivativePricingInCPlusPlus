/*First GitHub Application to Computational Finance*/
/*BalckScoles Option Pricing Model*/
/* Edited by Ratanlal Mahanta */
/*www.twitter.com/mahantaratan*/

#include<iostream>
#include <cmath>              // mathematical C library
#include "normdist.hpp"         // the calculation of the cumularive normal distribution
using namespace std;
double option_price_call_black_scholes(const double& S,       // spot (underlying) price
				       const double& K,       // strike (exercise) price,
				       const double& r,       // interest rate
				       const double& sigma,   // volatility 
				       const double& time) {  // time to maturity 
    double time_sqrt = sqrt(time);
    double d1 = (log(S/K)+r*time)/(sigma*time_sqrt)+0.5*sigma*time_sqrt; 
    double d2 = d1-(sigma*time_sqrt);
    return S*N(d1) - K*exp(-r*time)*N(d2);
};
/*Black_Scholes_Put_Price*/            
double option_price_put_black_scholes(const double& S,      // spot price
				      const double& K,      // Strike (exercise) price,
				      const double& r,      // interest rate
				      const double& sigma,  // volatility
				      const double& time){
    double time_sqrt = sqrt(time);
    double d1 = (log(S/K)+r*time)/(sigma*time_sqrt) + 0.5*sigma*time_sqrt;
    double d2 = d1-(sigma*time_sqrt);
    return K*exp(-r*time)*N(-d2) - S*N(-d1);
};
/*Black_Scholes_delta_call*/
double option_price_delta_call_black_scholes(const double& S,     // spot price
                                             const double& K,     // Strike (exercise) price,
                                             const double& r,     // interest rate
                                             const double& sigma, // volatility
                                             const double& time){  // time to maturity
    double time_sqrt = sqrt(time);
    double d1 = (log(S/K)+r*time)/(sigma*time_sqrt) + 0.5*sigma*time_sqrt;
    double delta = N(d1);
    return delta;
};
double option_price_delta_put_black_scholes(const double& S, // spot price
                                            const double& K, // Strike (exercise) price,
                                            const double& r,  // interest rate
                                            const double& sigma,
                                            const double& time) {
    double time_sqrt = sqrt(time);
    double d1 = (log(S/K)+r*time)/(sigma*time_sqrt) + 0.5*sigma*time_sqrt;
    double delta = -N(-d1);
    return delta;
}
/*Option Price European call*/
double option_price_european_call_payout( const double& S, // spot price
                                          const double& X, // Strike (exercise) price,
                                          const double& r,  // interest rate
                                          const double& q,  // yield on underlying
                                          const double& sigma, // volatility
                                          const double& time) { // time to maturity
    double sigma_sqr = pow(sigma,2);
    double time_sqrt = sqrt(time);
    double d1 = (log(S/X) + (r-q + 0.5*sigma_sqr)*time)/(sigma*time_sqrt);
    double d2 = d1-(sigma*time_sqrt);
    double call_price = S * exp(-q*time)* N(d1) - X * exp(-r*time) * N(d2);
    return call_price;
};
/*Option Price European put*/

double option_price_european_put_payout( const double& S, // spot price
                                         const double& K, // Strike (exercise) price,
                                         const double& r,  // interest rate
                                         const double& q,  // yield on underlying
                                         const double& sigma,
                                         const double& time) {
    double sigma_sqr = pow(sigma,2);
    double time_sqrt = sqrt(time);
    double d1 = (log(S/K) + (r-q + 0.5*sigma_sqr)*time)/(sigma*time_sqrt);
    double d2 = d1-(sigma*time_sqrt);
    double put_price = K * exp(-r*time)*N(-d2)-S*exp(-q*time)*N(-d1);
    return put_price;
};
int main(){
  /*double S=100,K=100,r=0.09,sigma=0.20,time=0.5,X=100,q=0.00;
cout<<"Call_price="<<option_price_call_black_scholes(S,K,r,sigma,time)<<endl;
cout<<"Put_Price="<<option_price_put_black_scholes(S,K,r,sigma,time)<<endl;
cout<<"delta_call="<<option_price_delta_call_black_scholes(S,K,r,sigma,time)<<endl;
cout<<"delta_put="<<option_price_delta_put_black_scholes(S,K,r,sigma,time)<<endl;
cout<<"call_payout="<<option_price_european_call_payout(S,X,r,q,sigma,time)<<endl;
cout<<"Put_payout="<<option_price_european_put_payout(S,K,r,q,sigma,time)<<endl;
  */
  void test_option_price_call_black_scholes(){
    double S = 50; double K = 50; double r = 0.10;
    double sigma = 0.30; double time=0.50;
    cout << " Black Scholes call price = ";
    cout << option_price_call_black_scholes(S, K , r, sigma, time) << endl;
  };
  void test_black_scholes_partials_call(){
    cout  << " Black Scholes call partial derivatives " << endl;
    double S = 50; double K = 50; double r = 0.10;
    double sigma = 0.30; double time=0.50;
    double Delta, Gamma, Theta, Vega, Rho;
    option_price_partials_call_black_scholes(S,K,r,sigma, time,
                                             Delta, Gamma, Theta, Vega, Rho);
    cout << "  Delta = " << Delta << endl;
    cout << "  Gamma = " << Gamma << endl;
    cout << "  Theta = " << Theta << endl;
    cout << "  Vega  = " << Vega << endl;
    cout << "  Rho   = " << Rho << endl;
  };
}













