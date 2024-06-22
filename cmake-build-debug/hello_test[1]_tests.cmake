add_test([=[SampleTest.AssertionTrue]=]  /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/cmake-build-debug/hello_test [==[--gtest_filter=SampleTest.AssertionTrue]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SampleTest.AssertionTrue]=]  PROPERTIES WORKING_DIRECTORY /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  hello_test_TESTS SampleTest.AssertionTrue)
