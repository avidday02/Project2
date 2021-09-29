  #include <stdio.h>
  #include <stdarg.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  #include "ntuple.h"
  #include "unity.h"

void setUp(void) {}
void tearDown(void) {}

void test1(void){
  ntuple testTuple1 = newTuple(1, "print please");
  TEST_ASSERT_EQUAL_STRING("print please", get(0, testTuple1));
  put(0, "hi mom", testTuple1);
  TEST_ASSERT_EQUAL_STRING("hi mom", get(0, testTuple1));
  ntuple testTuple2 = newTuple(1, "hi mom");
  TEST_ASSERT_TRUE(equal(testTuple1, testTuple2));
  put(0, "hello mum", testTuple1);
  TEST_ASSERT_EQUAL_STRING("hello mum", get(0, testTuple1));
  ntuple testTuple3 = newTuple(1,"hello mum");
  TEST_ASSERT_TRUE(equal(testTuple1, testTuple3));
  //TEST_ASSERT_EQUAL_STRING("hello mum", ntupToString(testTuple1));
  printf("%s\n",ntupToString(testTuple1));
  ntuple testTuple4 = newTuple(2,"hello mum", "fuck");
  TEST_ASSERT_EQUAL_STRING("fuck", get(1, testTuple4));
  printf("%s\n",ntupToString(testTuple4));
  put(2, "asdf", testTuple4);
  printf("%s\n",ntupToString(testTuple4));
  ntuple zeroTuple = newTuple(0);
  printf("%s\n",ntupToString(zeroTuple));




  //TEST_ASSERT_EQUAL_STRING("");

}

void test2(void){
}

// test suites will go here - see class notes
int main(void){
  UNITY_BEGIN();
  RUN_TEST(test1);
  //will invoke test suites here - see class notes
  return UNITY_END();
}