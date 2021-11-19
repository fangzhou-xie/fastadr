#include <Rcpp.h>
using namespace Rcpp;

#include <fastad.h>

//' test function for FastAD
//'
//' @examples
//' test_forward()
//' @export
// [[Rcpp::export]]
double test_forward() {
  using namespace ad;
  
  ForwardVar<double> w1(0.), w2(1.);
  w1.set_adjoint(1.); // differentiate w.r.t. w1
  ForwardVar<double> w3 = w1 * sin(w2);
  ForwardVar<double> w4 = w3 + w1 * w2;
  ForwardVar<double> w5 = exp(w4 * w3);
  
  return w5.get_adjoint();
}

// //' @export
// // [[Rcpp::export]]
// void test_reverse() {
//   using namespace ad;
//   
//   Var<double, scl> x(2);
//   Var<double, vec> v(5);
//   
//   // auto expr_bound = bind(sin(x) + cos(v));
//   auto expr = bind(sin(x) + cos(v));
//   
//   autodiff(expr);
//   
//   std::cout << x.get_adj() << std::endl;
//   std::cout << v.get_adj(2,0) << std::endl;
// }


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
test_forward()
# test_reverse()
*/
