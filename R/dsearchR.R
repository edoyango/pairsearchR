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
