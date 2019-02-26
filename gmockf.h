#ifndef GMOCK_FUNCTION_MOCK_H
#define GMOCK_FUNCTION_MOCK_H

#include <memory>
#include <gmock/gmock.h>

//
// Mock classes for different argument count definitions
//
#define FUNCTION_MOCK_DELETER_NAME3(x, y)     x##y
#define FUNCTION_MOCK_DELETER_NAME2(x, y)     FUNCTION_MOCK_DELETER_NAME3(x, y)
#define FUNCTION_MOCK_DELETER_NAME(x)         FUNCTION_MOCK_DELETER_NAME2(x, __COUNTER__)

#define FUNCTION_MOCK_TYPE(name)              gmock_function_mock_##name
#define FUNCTION_MOCK_INSTANCE(name)          gmock_function_mock_##name##_instance
//
// Mock class and macroses for 0 arguments function
//
#define _MOCK_FUNCTION_0(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method () constness {  \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 0), \
        this_method_does_not_take_0_arguments); \
    GMOCK_MOCKER_(0, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(0, constness, Method).Invoke(); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method() constness { \
    GMOCK_MOCKER_(0, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(0, constness, Method).With(); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(0, constness, \
      Method); \
   }; \
   std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
   GMOCK_RESULT_(tn, __VA_ARGS__) ct Method() constness { \
         \
       return FUNCTION_MOCK_INSTANCE(Method)->Method();\
      }\

#define MOCK_FUNCTION0(m, ...) _MOCK_FUNCTION_0(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION0_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_0(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 1 arguments function
//
#define _MOCK_FUNCTION_1(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1) constness {  \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 1), \
        this_method_does_not_take_1_arguments); \
    GMOCK_MOCKER_(1, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(1, constness, Method).Invoke(gmock_a1); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1) constness { \
    GMOCK_MOCKER_(1, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(1, constness, Method).With(gmock_a1); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(1, constness, \
      Method); \
  }; \
  std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1) constness { \
       return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1);\
  }\

#define MOCK_FUNCTION1(m, ...) _MOCK_FUNCTION_1(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION1_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_1(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 2 arguments function
//
#define _MOCK_FUNCTION_2(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 2), \
        this_method_does_not_take_2_arguments); \
    GMOCK_MOCKER_(2, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(2, constness, Method).Invoke(gmock_a1, gmock_a2); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2) constness { \
    GMOCK_MOCKER_(2, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(2, constness, Method).With(gmock_a1, gmock_a2); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(2, constness, \
      Method); \
  }; \
  std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2) constness { \
       return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2);\
  }\


#define MOCK_FUNCTION2(m, ...) _MOCK_FUNCTION_2(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION2_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_2(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 3 arguments function
//
#define _MOCK_FUNCTION_3(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 3), \
        this_method_does_not_take_3_arguments); \
    GMOCK_MOCKER_(3, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(3, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3) constness { \
    GMOCK_MOCKER_(3, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(3, constness, Method).With(gmock_a1, gmock_a2, gmock_a3); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(3, constness, \
      Method); \
  }; \
  std::unique_ptr< FUNCTION_MOCK_TYPE(Method)> FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3) constness { \
         \
       return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3);\
   }\

#define MOCK_FUNCTION3(m, ...) _MOCK_FUNCTION_3(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION3_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_3(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 4 arguments function
//
#define _MOCK_FUNCTION_4(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 4), \
        this_method_does_not_take_4_arguments); \
    GMOCK_MOCKER_(4, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(4, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3, gmock_a4); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4) constness { \
    GMOCK_MOCKER_(4, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(4, constness, Method).With(gmock_a1, gmock_a2, gmock_a3, gmock_a4); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(4, constness, \
      Method); \
  }; \
  std::unique_ptr< FUNCTION_MOCK_TYPE(Method)> FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4 ) constness { \
         \
       return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3, gmock_a4);\
   }\

#define MOCK_FUNCTION4(m, ...) _MOCK_FUNCTION_4(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION4_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_4(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 5 arguments function
//
#define _MOCK_FUNCTION_5(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 5), \
        this_method_does_not_take_5_arguments); \
    GMOCK_MOCKER_(5, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(5, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5) constness { \
    GMOCK_MOCKER_(5, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(5, constness, Method).With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(5, constness, \
      Method); \
  }; \
  std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5) constness { \
      return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5);\
  }\

#define MOCK_FUNCTION5(m, ...) _MOCK_FUNCTION_5(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION5_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_5(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 6 arguments function
//
#define _MOCK_FUNCTION_6(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 6), \
        this_method_does_not_take_6_arguments); \
    GMOCK_MOCKER_(6, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(6, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6); \
  } \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method( \
      GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6) constness { \
          GMOCK_MOCKER_(6, constness, Method).RegisterOwner(this); \
          return GMOCK_MOCKER_(6, constness, Method).With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(6, constness, \
      Method); \
  }; \
  std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6) constness { \
      return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6);\
  }\

#define MOCK_FUNCTION6(m, ...) _MOCK_FUNCTION_6(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION6_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_6(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 7 arguments function
//
#define _MOCK_FUNCTION_7(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7) constness { \
      GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 7), \
        this_method_does_not_take_7_arguments); \
    GMOCK_MOCKER_(7, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(7, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7); \
  } \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method( \
      GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7) constness { \
    GMOCK_MOCKER_(7, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(7, constness, Method).With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(7, constness, \
      Method); \
  }; \
  std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
        GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
        GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
        GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
        GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
        GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
        GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
        GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7) constness { \
     return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7);\
      }\

#define MOCK_FUNCTION7(m, ...) _MOCK_FUNCTION_7(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION7_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_7(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 8 arguments function
//
#define _MOCK_FUNCTION_8(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 8), \
        this_method_does_not_take_8_arguments); \
    GMOCK_MOCKER_(8, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(8, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8) constness { \
    GMOCK_MOCKER_(8, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(8, constness, Method).With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(8, constness, \
      Method); \
   }; \
   std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
   GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8) constness { \
         \
       return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8);\
      }\

#define MOCK_FUNCTION8(m, ...) _MOCK_FUNCTION_8(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION8_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_8(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 9 arguments function
//
#define _MOCK_FUNCTION_9(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 9), \
        this_method_does_not_take_9_arguments); \
    GMOCK_MOCKER_(9, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(9, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9) constness { \
    GMOCK_MOCKER_(9, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(9, constness, Method).With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(9, constness, \
      Method); \
   }; \
   std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
   GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9) constness { \
         \
       return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9);\
      }\

#define MOCK_FUNCTION9(m, ...) _MOCK_FUNCTION_9(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION9_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_9(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 10 arguments function
//
#define _MOCK_FUNCTION_10(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 10), \
        this_method_does_not_take_10_arguments); \
    GMOCK_MOCKER_(10, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(10, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10, __VA_ARGS__) gmock_a10 ) constness { \
    GMOCK_MOCKER_(10, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(10, constness, Method).With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(10, constness, \
      Method); \
   }; \
   std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
   GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10) constness { \
         \
       return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10);\
      }\

#define MOCK_FUNCTION10(m, ...) _MOCK_FUNCTION_10(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION10_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_10(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 11 arguments function
//
#define _MOCK_FUNCTION_11(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, \
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 11), \
        this_method_does_not_take_11_arguments); \
    GMOCK_MOCKER_(11, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(11, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10, __VA_ARGS__) gmock_a10, \
                     GMOCK_MATCHER_(tn, 11, __VA_ARGS__) gmock_a11 ) constness { \
    GMOCK_MOCKER_(11, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(11, constness, Method).With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(11, constness, \
      Method); \
   }; \
   std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
   GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, \
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11) constness { \
         \
       return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11);\
      }\

#define MOCK_FUNCTION11(m, ...) _MOCK_FUNCTION_11(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION11_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_11(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 12 arguments function
//
#define _MOCK_FUNCTION_12(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, \
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
      GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 12), \
        this_method_does_not_take_12_arguments); \
    GMOCK_MOCKER_(12, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(12, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11, gmock_a12); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10, __VA_ARGS__) gmock_a10, \
                     GMOCK_MATCHER_(tn, 11, __VA_ARGS__) gmock_a11, \
                     GMOCK_MATCHER_(tn, 12, __VA_ARGS__) gmock_a12 ) constness { \
    GMOCK_MOCKER_(12, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(12, constness, Method).With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11, gmock_a12); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(12, constness, \
      Method); \
   }; \
   std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
   GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, \
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
      GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12) constness { \
         \
       return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11, gmock_a12);\
      }\

#define MOCK_FUNCTION12(m, ...) _MOCK_FUNCTION_12(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION12_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_12(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 13 arguments function
//
#define _MOCK_FUNCTION_13(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, \
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
      GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12, \
      GMOCK_ARG_(tn, 13, __VA_ARGS__) gmock_a13) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 13), \
        this_method_does_not_take_13_arguments); \
    GMOCK_MOCKER_(13, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(13, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11, gmock_a12, gmock_a13); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10, __VA_ARGS__) gmock_a10, \
                     GMOCK_MATCHER_(tn, 11, __VA_ARGS__) gmock_a11, \
                     GMOCK_MATCHER_(tn, 12, __VA_ARGS__) gmock_a12, \
                     GMOCK_MATCHER_(tn, 13, __VA_ARGS__) gmock_a13 ) constness { \
    GMOCK_MOCKER_(13, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(13, constness, Method).With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11, gmock_a12, gmock_a13); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(13, constness, \
      Method); \
   }; \
   std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
   GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, \
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
      GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12, \
      GMOCK_ARG_(tn, 13, __VA_ARGS__) gmock_a13) constness { \
         \
       return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11, gmock_a12, gmock_a13);\
      }\

#define MOCK_FUNCTION13(m, ...) _MOCK_FUNCTION_13(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION13_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_13(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 14 arguments function
//
#define _MOCK_FUNCTION_14(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, \
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
      GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12, \
      GMOCK_ARG_(tn, 13, __VA_ARGS__) gmock_a13, \
      GMOCK_ARG_(tn, 14, __VA_ARGS__) gmock_a14) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 14), \
        this_method_does_not_take_14_arguments); \
    GMOCK_MOCKER_(14, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(14, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11, gmock_a12, gmock_a13, gmock_a14); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10, __VA_ARGS__) gmock_a10, \
                     GMOCK_MATCHER_(tn, 11, __VA_ARGS__) gmock_a11, \
                     GMOCK_MATCHER_(tn, 12, __VA_ARGS__) gmock_a12, \
                     GMOCK_MATCHER_(tn, 13, __VA_ARGS__) gmock_a13, \
                     GMOCK_MATCHER_(tn, 14, __VA_ARGS__) gmock_a14 ) constness { \
    GMOCK_MOCKER_(14, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(14, constness, Method).With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11, gmock_a12, gmock_a13, gmock_a14); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(14, constness, \
      Method); \
   }; \
   std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
   GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, \
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
      GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12, \
      GMOCK_ARG_(tn, 13, __VA_ARGS__) gmock_a13, \
      GMOCK_ARG_(tn, 14, __VA_ARGS__) gmock_a14) constness { \
         \
       return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11, gmock_a12, gmock_a13, gmock_a14);\
      }\

#define MOCK_FUNCTION14(m, ...) _MOCK_FUNCTION_14(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION14_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_14(, , ct, m, __VA_ARGS__)

//
// Mock class and macroses for 15 arguments function
//
#define _MOCK_FUNCTION_15(tn, constness, ct, Method, ...) \
class FUNCTION_MOCK_TYPE(Method) { \
public:\
  FUNCTION_MOCK_TYPE(Method)(const char* tag) : m_tag(tag) {}  \
  const char* const m_tag; \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, \
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
      GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12, \
      GMOCK_ARG_(tn, 13, __VA_ARGS__) gmock_a13, \
      GMOCK_ARG_(tn, 14, __VA_ARGS__) gmock_a14, \
      GMOCK_ARG_(tn, 15, __VA_ARGS__) gmock_a15) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 15), \
        this_method_does_not_take_15_arguments); \
    GMOCK_MOCKER_(15, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(15, constness, Method).Invoke(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11, gmock_a12, gmock_a13, gmock_a14, gmock_a15); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10, __VA_ARGS__) gmock_a10, \
                     GMOCK_MATCHER_(tn, 11, __VA_ARGS__) gmock_a11, \
                     GMOCK_MATCHER_(tn, 12, __VA_ARGS__) gmock_a12, \
                     GMOCK_MATCHER_(tn, 13, __VA_ARGS__) gmock_a13, \
                     GMOCK_MATCHER_(tn, 14, __VA_ARGS__) gmock_a14, \
                     GMOCK_MATCHER_(tn, 15, __VA_ARGS__) gmock_a15 ) constness { \
    GMOCK_MOCKER_(15, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(15, constness, Method).With(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11, gmock_a12, gmock_a13, gmock_a14, gmock_a15); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(15, constness, \
      Method); \
   }; \
   std::unique_ptr< FUNCTION_MOCK_TYPE(Method) > FUNCTION_MOCK_INSTANCE(Method)(new FUNCTION_MOCK_TYPE(Method)("Uninterested"));\
   GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, \
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
      GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12, \
      GMOCK_ARG_(tn, 13, __VA_ARGS__) gmock_a13, \
      GMOCK_ARG_(tn, 14, __VA_ARGS__) gmock_a14, \
      GMOCK_ARG_(tn, 15, __VA_ARGS__) gmock_a15) constness { \
         \
       return FUNCTION_MOCK_INSTANCE(Method)->Method(gmock_a1, gmock_a2, gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, gmock_a10, gmock_a11, gmock_a12, gmock_a13, gmock_a14, gmock_a15);\
      }\

#define MOCK_FUNCTION15(m, ...) _MOCK_FUNCTION_15(, , , m, __VA_ARGS__)
#define MOCK_FUNCTION15_WITH_CALLTYPE(ct, m, ...) _MOCK_FUNCTION_15(, , ct, m, __VA_ARGS__)

//
// Code for deleting mock objects generated for function in the end of each test.
//

namespace testing {
    template<typename T>
    class FunctionMockDeleter {
    public:
        FunctionMockDeleter(std::unique_ptr<T> &ref) : m_mockReference(ref) {}

        ~FunctionMockDeleter() {
            m_mockReference.reset();
        }

    private:
        std::unique_ptr<T> &m_mockReference;
    };
}


#define EXPECT_FUNCTION_CALL(name, call) \
testing::FunctionMockDeleter<FUNCTION_MOCK_TYPE(name)> FUNCTION_MOCK_DELETER_NAME(mock_deleter)(FUNCTION_MOCK_INSTANCE(name));\
if (!FUNCTION_MOCK_INSTANCE(name) || 0 != strcmp(FUNCTION_MOCK_INSTANCE(name)->m_tag, __FUNCTION__)) FUNCTION_MOCK_INSTANCE(name).reset(new FUNCTION_MOCK_TYPE(name)(__FUNCTION__));\
EXPECT_CALL(*FUNCTION_MOCK_INSTANCE(name), call)


#endif //GMOCK_FUNCTION_MOCK