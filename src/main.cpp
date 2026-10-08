#include <Arduino.h>
#include <OneButton.h>

#define LED_PIN 2 
#define BTN_PIN 0 

OneButton button(BTN_PIN, true); 

bool isBlinking = false; // Cờ theo dõi trạng thái nháy
bool ledState = false;   // Trạng thái hiện tại của LED sáng/tối
unsigned long lastBlinkTime = 0; 
const long blinkInterval = 300;  // Tốc độ nháy (300ms)

// Hàm xử lý khi click 1 lần (Single Click)
void singleClick() {
  isBlinking = false;   
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState);
}

// Hàm xử lý khi click đúp 2 lần (Double Click)
void doubleClick() {
  isBlinking = !isBlinking; // Bật/Tắt cờ nháy LED
}

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // Gắn sự kiện nút nhấn vào các hàm xử lý
  button.attachClick(singleClick);
  button.attachDoubleClick(doubleClick);
}

void loop() {
  // Quét trạng thái nút nhấn liên tục
  button.tick();

  // Chức năng nháy LED không dùng delay() (Non-blocking)
  if (isBlinking) {
    unsigned long currentMillis = millis();
    if (currentMillis - lastBlinkTime >= blinkInterval) {
      lastBlinkTime = currentMillis;
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }
  }
}