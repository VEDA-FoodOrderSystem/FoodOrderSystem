if(EXISTS "/Users/yunhyegyeong/Documents/FoodOrderSystem/foodOrderProgram/cmake-build-debug/test[1]_tests.cmake")
  include("/Users/yunhyegyeong/Documents/FoodOrderSystem/foodOrderProgram/cmake-build-debug/test[1]_tests.cmake")
else()
  add_test(test_NOT_BUILT test_NOT_BUILT)
endif()
