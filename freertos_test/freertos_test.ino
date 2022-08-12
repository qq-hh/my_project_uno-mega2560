#include <Arduino_FreeRTOS.h>

void TaskPrint1(void *param); //声明打印任务1
void TaskPrint2(void *param); //声明打印任务2

void setup() {

  Serial.begin(115200);
  while (!Serial);//等待串口连接后执行

  xTaskCreate(TaskPrint1, "Print1", 128, NULL, 1, NULL); //创建任务1
  xTaskCreate(TaskPrint2, "Print2", 128, NULL, 2, NULL); //创建任务2
  vTaskStartScheduler(); //启动任务调度
}

void TaskPrint1(void *param)
{
  while (1)
  {
    Serial.println("hello world !");
    vTaskDelay(1000 / portTICK_PERIOD_MS ); // 等待1秒,注意不能使用delay
  }
}


void TaskPrint2(void *param)
{
  while (1)
  {
    Serial.println("test");
    vTaskDelay(2000 / portTICK_PERIOD_MS ); // 等待2秒
  }
}

void loop() {

}
