if(EXISTS "/Users/yunhyegyeong/Documents/FoodOrderSystem/foodOrderProgram/cmake-build-debug/RunTests[1]_tests.cmake")
  include("/Users/yunhyegyeong/Documents/FoodOrderSystem/foodOrderProgram/cmake-build-debug/RunTests[1]_tests.cmake")
else()
  add_test(RunTests_NOT_BUILT RunTests_NOT_BUILT)
endif()
