#include <Rcpp.h>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
List dsearchRcpp(int dim, List pts, double r) {

  int npts = pts.size();
  List prs;

  double rr {0.}, dx {0.};
  const double cutoff2 {r*r};
  IntegerVector ptsi(dim), ptsj(dim);
  for (int i {0}; i < npts-1; ++i)
  {
    ptsi = as<IntegerVector>(pts[i]);
    for (int j {i+1}; j < npts; ++j)
    {
      ptsj = as<IntegerVector>(pts[j]);
      dx = ptsi[0] - ptsj[0];
      rr = dx*dx;
      for (int d {1}; d < dim; ++d)
      {
        dx = ptsi[d] - ptsj[d];
        rr += dx*dx;
      }
      if (rr<=cutoff2)
      {
        prs.push_back(IntegerVector::create(i,j));
      }
    }
  }

  return prs;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//

/*** R
dsearchRcpp(2, list(c(1,1), c(2,1), c(2,2), c(1,2)), 1.1)
*/

