test_that("dsearchRcpp() finds the correct pairs", {
  expect_equal(dsearchRcpp(2, list(c(1,1), c(2,1), c(2,2), c(1,2)), 1.1), list(c(1,2), c(1,4), c(2,3), c(3,4)))
})
