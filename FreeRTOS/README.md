

# See also

1. https://github.com/ElectricRCAircraftGuy/eRCaGuy_hello_world/tree/master/FreeRTOS


# Main links

1. FreeRTOS Kernel Developer Docs: https://www.freertos.org/features.html
1. API Reference: https://www.freertos.org/a00106.html
1. Official FreeRTOS source code: https://github.com/FreeRTOS
    1. Official FreeRTOS kernel source code: https://github.com/FreeRTOS/FreeRTOS-Kernel
        1. Example `FreeRTOSConfig.h` file: https://github.com/FreeRTOS/FreeRTOS-Kernel/blob/main/examples/template_configuration/FreeRTOSConfig.h
        1. My modifications to the above file: [`eRCaGuy_hello_world/FreeRTOS/FreeRTOSConfig_GS_customizations.h`](https://github.com/ElectricRCAircraftGuy/eRCaGuy_hello_world/blob/master/FreeRTOS/FreeRTOSConfig_GS_customizations.h)
        1. Compare to see my modifications:
            ```bash
            meld FreeRTOSConfig.h FreeRTOSConfig_GS_customizations.h
            ```
1. Official FreeRTOS Kernel Book: 
    1. Main link: https://freertos.org/Documentation/02-Kernel/07-Books-and-manual/01-RTOS_book
    1. Mastering the FreeRTOS Real Time Kernel - A Hands On Tutorial Guide
        1. Main link: https://freertos.org/Documentation/02-Kernel/07-Books-and-manual/01-RTOS_book
        1. On GitHub: 
            1. https://github.com/FreeRTOS/FreeRTOS-Kernel-Book
            1. Table of Contents: https://github.com/FreeRTOS/FreeRTOS-Kernel-Book/blob/main/toc.md
        1. Downloadable PDF: https://github.com/FreeRTOS/FreeRTOS-Kernel-Book/releases/download/V1.1.0/Mastering-the-FreeRTOS-Real-Time-Kernel.v1.1.0.pdf
            1. Companion Example Source Code: https://freertos.org/media/2024/source-code-for-book-examples.20240207.zip
    1. The FreeRTOS Reference Manual: https://freertos.org/media/2018/FreeRTOS_Reference_Manual_V10.0.0.pdf


# FreeRTOS undefined behavior and crashes at startup


# AI: Which FreeRTOS API calls are and are not allowed prior to calling `vTaskStartScheduler()`?


## My own research

For example:  

Only try to take or give a mutex if the FreeRTOS scheduler is running. Otherwise, it is undefined behavior to try to do so while the scheduler is not running.

(Emphasis added):

> ### 13.5.6 Symptom: The application crashes even before the scheduler is started
>
> An interrupt service routine **that could potentially cause a context switch must not be permitted to execute before the scheduler has been started.** The same applies to any interrupt service routine that attempts to send to or receive from a FreeRTOS object, such as a **queue or semaphore.** A context switch cannot occur until after the scheduler has started.
> 
> Many API functions cannot be called until after the scheduler has been started. It is best to restrict API usage to the creation of objects such as tasks, queues, and semaphores, rather than the use of these objects, **until after `vTaskStartScheduler()` has been called.**

Source: https://github.com/FreeRTOS/FreeRTOS-Kernel-Book/blob/main/ch13.md#1356-symptom-the-application-crashes-even-before-the-scheduler-is-started


## Prompt to GitHub Copilot

> Which FreeRTOS API calls are and are not allowed prior to calling vTaskStartScheduler()?

Answer:

Before calling `vTaskStartScheduler()`, you can use the following FreeRTOS API calls:

### Allowed API Calls:
1. **Task Creation**:
   - `xTaskCreate()`
   - `xTaskCreateStatic()`

2. **Queue Creation**:
   - `xQueueCreate()`
   - `xQueueCreateStatic()`

3. **Semaphore Creation**:
   - `xSemaphoreCreateBinary()`
   - `xSemaphoreCreateBinaryStatic()`
   - `xSemaphoreCreateCounting()`
   - `xSemaphoreCreateCountingStatic()`
   - `xSemaphoreCreateMutex()`
   - `xSemaphoreCreateMutexStatic()`
   - `xSemaphoreCreateRecursiveMutex()`
   - `xSemaphoreCreateRecursiveMutexStatic()`

4. **Event Group Creation**:
   - `xEventGroupCreate()`
   - `xEventGroupCreateStatic()`

5. **Timer Creation**:
   - `xTimerCreate()`
   - `xTimerCreateStatic()`

6. **Stream Buffer Creation**:
   - `xStreamBufferCreate()`
   - `xStreamBufferCreateStatic()`

7. **Message Buffer Creation**:
   - `xMessageBufferCreate()`
   - `xMessageBufferCreateStatic()`

### Not Allowed API Calls:
1. **Task Management**:
   - `vTaskDelete()`
   - `vTaskDelay()`
   - `vTaskDelayUntil()`
   - `vTaskSuspend()`
   - `vTaskResume()`
   - `vTaskResumeFromISR()`
   - `vTaskPrioritySet()`
   - `vTaskGetInfo()`
   - `vTaskList()`
   - `vTaskGetRunTimeStats()`

2. **Queue Management**:
   - `xQueueSend()`
   - `xQueueReceive()`
   - `xQueuePeek()`
   - `xQueueSendFromISR()`
   - `xQueueReceiveFromISR()`
   - `xQueuePeekFromISR()`

3. **Semaphore Management**:
   - `xSemaphoreTake()`
   - `xSemaphoreGive()`
   - `xSemaphoreTakeFromISR()`
   - `xSemaphoreGiveFromISR()`

4. **Event Group Management**:
   - `xEventGroupSetBits()`
   - `xEventGroupClearBits()`
   - `xEventGroupWaitBits()`
   - `xEventGroupSync()`

5. **Timer Management**:
   - `xTimerStart()`
   - `xTimerStop()`
   - `xTimerChangePeriod()`
   - `xTimerReset()`
   - `xTimerStartFromISR()`
   - `xTimerStopFromISR()`
   - `xTimerChangePeriodFromISR()`
   - `xTimerResetFromISR()`

6. **Stream Buffer Management**:
   - `xStreamBufferSend()`
   - `xStreamBufferReceive()`
   - `xStreamBufferSendFromISR()`
   - `xStreamBufferReceiveFromISR()`

7. **Message Buffer Management**:
   - `xMessageBufferSend()`
   - `xMessageBufferReceive()`
   - `xMessageBufferSendFromISR()`
   - `xMessageBufferReceiveFromISR()`

In summary, you can create tasks, queues, semaphores, event groups, timers, stream buffers, and message buffers before starting the scheduler, but you cannot perform operations that require the scheduler to be running.


<a id="freertos-critical-section-calls"></a>
# AI: Which FreeRTOS API calls are and are not allowed to be called within a critical section specified by `taskENTER_CRITICAL()` and `taskEXIT_CRITICAL()`?


## My own research

Important! (emphasis added): 

> ### 13.5.7 Symptom: Calling API functions while the scheduler is suspended, or from inside a critical section, causes the application to crash
>
> The scheduler is suspended by calling `vTaskSuspendAll()` and resumed (unsuspended) by calling `xTaskResumeAll()`. A critical section is entered by calling `taskENTER_CRITICAL()`, and exited by calling `taskEXIT_CRITICAL()`.
> 
> **Do not call API functions while the scheduler is suspended, or from inside a critical section.**

Source: https://github.com/FreeRTOS/FreeRTOS-Kernel-Book/blob/main/ch13.md#1357-symptom-calling-api-functions-while-the-scheduler-is-suspended-or-from-inside-a-critical-section-causes-the-application-to-crash

And:

> FreeRTOS API functions must not be called from within a critical section.

Source: https://www.freertos.org/Documentation/02-Kernel/04-API-references/04-RTOS-kernel-control/01-taskENTER_CRITICAL_taskEXIT_CRITICAL

---


## Prompt to GitHub Copilot

I prompted this question to GitHub Copilot. 

Answer: 

Within a critical section specified by `taskENTER_CRITICAL()` and `taskEXIT_CRITICAL()`, you should avoid calling FreeRTOS API functions that might block or cause the scheduler to switch context. Here is a breakdown of what is allowed and not allowed:

### Allowed API Calls:
1. **Task Management**:
   - `vTaskSuspendAll()`
   - `xTaskResumeAll()`
   - `vTaskGetTickCount()`
   - `vTaskGetTickCountFromISR()`
   - `uxTaskGetNumberOfTasks()`
   - `pcTaskGetName()`
   - `uxTaskPriorityGet()`
   - `vTaskPrioritySet()`
   - `vTaskDelayUntil()`
   - `vTaskDelay()`
   - `vTaskSuspend()`
   - `vTaskResume()`
   - `vTaskResumeFromISR()`

2. **Queue Management**:
   - `xQueueCreate()`
   - `xQueueCreateStatic()`
   - `xQueueSendFromISR()`
   - `xQueueReceiveFromISR()`
   - `xQueuePeekFromISR()`
   - `uxQueueMessagesWaiting()`
   - `uxQueueSpacesAvailable()`
   - `vQueueDelete()`

3. **Semaphore Management**:
   - `xSemaphoreCreateBinary()`
   - `xSemaphoreCreateBinaryStatic()`
   - `xSemaphoreCreateCounting()`
   - `xSemaphoreCreateCountingStatic()`
   - `xSemaphoreCreateMutex()`
   - `xSemaphoreCreateMutexStatic()`
   - `xSemaphoreCreateRecursiveMutex()`
   - `xSemaphoreCreateRecursiveMutexStatic()`
   - `xSemaphoreGiveFromISR()`
   - `xSemaphoreTakeFromISR()`
   - `uxSemaphoreGetCount()`
   - `vSemaphoreDelete()`

4. **Event Group Management**:
   - `xEventGroupCreate()`
   - `xEventGroupCreateStatic()`
   - `xEventGroupSetBitsFromISR()`
   - `xEventGroupClearBitsFromISR()`
   - `xEventGroupGetBits()`
   - `xEventGroupGetBitsFromISR()`
   - `vEventGroupDelete()`

5. **Timer Management**:
   - `xTimerCreate()`
   - `xTimerCreateStatic()`
   - `xTimerStartFromISR()`
   - `xTimerStopFromISR()`
   - `xTimerChangePeriodFromISR()`
   - `xTimerResetFromISR()`
   - `pvTimerGetTimerID()`
   - `vTimerSetTimerID()`
   - `vTimerDelete()`

6. **Stream Buffer Management**:
   - `xStreamBufferCreate()`
   - `xStreamBufferCreateStatic()`
   - `xStreamBufferSendFromISR()`
   - `xStreamBufferReceiveFromISR()`
   - `xStreamBufferReset()`
   - `xStreamBufferSpacesAvailable()`
   - `xStreamBufferBytesAvailable()`
   - `vStreamBufferDelete()`

7. **Message Buffer Management**:
   - `xMessageBufferCreate()`
   - `xMessageBufferCreateStatic()`
   - `xMessageBufferSendFromISR()`
   - `xMessageBufferReceiveFromISR()`
   - `xMessageBufferReset()`
   - `xMessageBufferSpacesAvailable()`
   - `xMessageBufferBytesAvailable()`
   - `vMessageBufferDelete()`

### Not Allowed API Calls:
1. **Task Management**:
   - `vTaskDelay()`
   - `vTaskDelayUntil()`
   - `vTaskSuspend()`
   - `vTaskResume()`
   - `vTaskResumeFromISR()`
   - `vTaskDelete()`
   - `vTaskPrioritySet()`
   - `vTaskGetInfo()`
   - `vTaskList()`
   - `vTaskGetRunTimeStats()`

2. **Queue Management**:
   - `xQueueSend()`
   - `xQueueReceive()`
   - `xQueuePeek()`
   - `xQueueSendToFront()`
   - `xQueueSendToBack()`
   - `xQueueOverwrite()`
   - `xQueueSendToFrontFromISR()`
   - `xQueueSendToBackFromISR()`
   - `xQueueOverwriteFromISR()`

3. **Semaphore Management**:
   - `xSemaphoreTake()`
   - `xSemaphoreGive()`
   - `xSemaphoreTakeRecursive()`
   - `xSemaphoreGiveRecursive()`

4. **Event Group Management**:
   - `xEventGroupSetBits()`
   - `xEventGroupClearBits()`
   - `xEventGroupWaitBits()`
   - `xEventGroupSync()`

5. **Timer Management**:
   - `xTimerStart()`
   - `xTimerStop()`
   - `xTimerChangePeriod()`
   - `xTimerReset()`

6. **Stream Buffer Management**:
   - `xStreamBufferSend()`
   - `xStreamBufferReceive()`

7. **Message Buffer Management**:
   - `xMessageBufferSend()`
   - `xMessageBufferReceive()`

In summary, avoid calling any FreeRTOS API functions that might block or cause the scheduler to switch context within a critical section. Functions that are safe to call are typically those that do not block and do not interact with the scheduler.

