# gmockf
### Function Mocking for Google Mock


Suppose you need to mock this C style function.
```c
int some_function(int value, char *msg);
```
You can do that by declaring this at the top of your test file:
```c++
MOCK_FUNCTION2(some_function, int(int, char*));
```
Then you can define the call expectations like so:
```c++
EXPECT_FUNCTION_CALL(some_function, some_function(3, "HelloWorld").WillOnce(Return(5));
```
