# TraceSWO
Simple example that shows how ITM SWO tracing works on STM32F103 using VSCode.  
Project uses [Cortex-Debug](https://github.com/Marus/cortex-debug) and [swo_parser.py](https://github.com/robertlong13/SWO-Parser).
This example runs in Blue Pill and STM32_smart boards. You need to connect SWO and RST pins of your programmer.  

## How to use
Copy folder _swoTrace_ to root of your project  
In root _CMakeLists.txt_ write  
```c
add_subdirectory(swoTrace)
target_link_libraries(${CMAKE_PROJECT_NAME} swoTrace)
```
In _swoTrace.h_ specify your MCU  
Add to your C file when trace is needed
```c
#include "swoTrace.h"
```
