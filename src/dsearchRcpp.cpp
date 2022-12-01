#include <Rcpp.h>
using namespace Rcpp;

//' Find pairs of points within fixed cutoff
//'
//' @param dim The number of spatial dimensions
//' @param pts A list of coordinate vectors (of length dim).
//' @param r The cutoff distance criteria between points (<=r).
//'
//' @return A list of length 2 vectors.
//' @export
//'
//' @examples
//' pts <- list(c(1,1), c(2,1), c(2,2), c(1,2))
//' pairs <- dsearchRcpp(2, pts, 1.1)
//' @useDynLib dsearchR
//' @importFrom Rcpp evalCpp sourceCpp
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
        prs.push_back(IntegerVector::create(i+1,j+1));
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

