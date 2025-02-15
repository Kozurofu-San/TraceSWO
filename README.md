# TraceSWO
Simple example that shows how ITM SWO tracing works on STM32F103 using VSCode 
Project uses _Cortex-Debug_ and _swoparser.py_
  
## How to use
Copy folder _swoTrace_ to root of your project  
In root _CMakeLists.txt_ write  
```
add_subdirectory(swoTrace)
target_link_libraries(${CMAKE_PROJECT_NAME} swoTrace)
```
In _swoTrace.h_ specify your MCU  
Add _swoTrace.h_ to your C file when trace is needed