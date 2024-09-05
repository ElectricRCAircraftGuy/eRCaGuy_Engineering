

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


# AI: Which FreeRTOS API calls are and are not allowed prior to calling `vTaskStartScheduler()`?

Prompt to GitHub Copilot:

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

