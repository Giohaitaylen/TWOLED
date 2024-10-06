#include <Arduino.h>
#include <OneButton.h>
#include "C:\Users\quan8\OneDrive\Documents\PlatformIO\Projects\ESP32 CL\lib\LED.h"

#define BUTTON_PIN 4U        
#define LED2_PIN 21U         
#define LED_PIN 2U          

OneButton button(BUTTON_PIN, true); // Khởi tạo đối tượng OneButton

bool ledState = false;    // Trạng thái của LED
bool led2State = false;    // Trạng thái của LED2
bool blinkMode = false;    // Trạng thái chế độ nhấp nháy
bool controllingLED = true; // Đang điều khiển LED

unsigned long previousMillis = 0; // Biến thời gian cho nhấp nháy

void singleClick();
void doubleClick();
void longPressStart();
void toggleLED();

void setup() {
  // Cấu hình các chân LED
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  // Gán sự kiện cho nút nhấn
  button.attachClick(singleClick);
  button.attachDoubleClick(doubleClick);
  button.attachLongPressStart(longPressStart);

  // Tắt cả hai LED ban đầu
  digitalWrite(LED_PIN, ledState);
  digitalWrite(LED2_PIN, led2State);
}

void loop() {
  button.tick(); // Kiểm tra sự kiện nút nhấn

  // Nếu đang ở chế độ nhấp nháy
  if (blinkMode) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= 20) { // Nhấp nháy mỗi 200ms
      previousMillis = currentMillis;
      toggleLED();  // Chuyển trạng thái LED hiện tại
    }
  }
}

void singleClick() {
  // Bật/tắt LED hiện đang được điều khiển
  if (controllingLED) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  } else {
    led2State = !led2State;
    digitalWrite(LED2_PIN, led2State);
  }
}

void doubleClick() {
  // Chuyển chế độ điều khiển giữa LED1 và LED2
  controllingLED = !controllingLED;
  blinkMode = false;  // Thoát chế độ nhấp nháy khi chuyển chế độ
}

void longPressStart() {
  // Kích hoạt chế độ nhấp nháy LED hiện tại
  blinkMode = true;
  previousMillis = millis(); // Đặt lại thời gian để nhấp nháy ngay lập tức
}

void toggleLED() {
  if (controllingLED) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  } else {
    led2State = !led2State;
    digitalWrite(LED2_PIN, led2State);
  }
}