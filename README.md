# TraceSWO
Simple example that shows how ITM SWO tracing works on STM32F103 using VSCode.  
Project uses [Cortex-Debug](https://github.com/Marus/cortex-debug) and [swo_parser.py](https://github.com/robertlong13/SWO-Parser).
This example runs in Blue Pill and STM32_smart boards. You need to connect SWO and RST pins of your programmer. Trace speed is 8 us per symbol.  

## How to use
Clone repo as submodele or copy _swoTrace_ and _.vscode_ folders to root of your project  
```py
git submodule add https://github.com/Kozurofu-San/TraceSWO.git submodules/swoTrace
```
In root _CMakeLists.txt_ write  
```c
add_subdirectory(submodules/swoTrace)   # For submodule
add_subdirectory(swoTrace)   # For copied falder

target_link_libraries(${CMAKE_PROJECT_NAME} swoTrace)
```
In _swoTrace.h_ specify your MCU  
Add to your C file when trace is needed
```c
#include "swoTrace.h"
```
Call init function
```c
swoInit (0xFFFFFFFF, SystemCoreClock , SWO_STLINK_V2_MAX_SPEED);
```
And call print function
```c
    cnt = 0;
    LOGI("Count %d\r\n", ++cnt);            // LOGI is info level
    LOGW("Sample warning %d\r\n", ++cnt);   // LOGW is warning level
    LOGE("Sample error %d\r\n", ++cnt);     // LOGE is error level
    
    LOGV(3, ++cnt);     // Print value to 3-rd ITM channel
    LOGV(4, ++cnt);     // Print value to 4-th ITM channel
    LOGV(5, ++cnt);     // Print value to 5-th ITM channel

```
