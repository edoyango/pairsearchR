
<!-- README.md is generated from README.Rmd. Please edit that file -->

# dsearchR

<!-- badges: start -->
<!-- badges: end -->

The goal of dsearchR is to make a point-pair search algorithm available
in R.

## Installation

You can install the development version of dsearchR from
[GitHub](https://github.com/) with:

``` r
# install.packages("devtools")
devtools::install_github("edoyango/pairsearchR")
```

## Usage

The `dsearchR` function takes a list of vector coordinates (of any
dimension), and a cutoff distance, and finds the pairs whose distance
between is within the cutoff.

``` r
library(dsearchR)
(points <- list(c(1,1), c(2,1), c(2,2), c(1,2)))
#> [[1]]
#> [1] 1 1
#> 
#> [[2]]
#> [1] 2 1
#> 
#> [[3]]
#> [1] 2 2
#> 
#> [[4]]
#> [1] 1 2
(cutoff <- 1.1)
#> [1] 1.1
dsearchR(points, cutoff)
#> [[1]]
#> [1] 1 2
#> 
#> [[2]]
#> [1] 1 4
#> 
#> [[3]]
#> [1] 2 3
#> 
#> [[4]]
#> [1] 3 4
```

A C++ implementation is available:

``` r
dsearchRcpp(2, points, cutoff)
#> [[1]]
#> [1] 1 2
#> 
#> [[2]]
#> [1] 1 4
#> 
#> [[3]]
#> [1] 2 3
#> 
#> [[4]]
#> [1] 3 4
```

The difference in usage being that the number of spatial dimensions is
required as the first argument.
