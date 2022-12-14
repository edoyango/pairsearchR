#' Find pairs of points within fixed cutoff
#'
#' @param pts A list of coordinate vectors (of any dimension).
#' @param r The cutoff distance criteria between points (<=r).
#'
#' @return A list of length 2 vectors.
#' @export
#'
#' @examples
#' pts <- list(c(1,1), c(2,1), c(2,2), c(1,2))
#' pairs <- dsearchR(pts, 1.1)
dsearchR <- function(pts, r) {
  npts = length(pts)
  nprs = 0
  prs = list()
  for (i in 1:(npts-1)) {
    for (j in (i+1):npts) {
      if (norm(pts[[i]]-pts[[j]], type="2") <= r) {
        nprs <- nprs + 1
        prs[[nprs]] <- c(i, j)
      }
    }
  }
  return(prs)
}
