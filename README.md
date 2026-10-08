# 💡 Dự Án Điều Khiển LED Bằng OneButton Trên ESP32

> Một dự án thực hành ứng dụng vi điều khiển **ESP32** kết hợp với thư viện `OneButton` để xử lý mượt mà các thao tác nút nhấn và điều khiển trạng thái đèn LED theo thời gian thực.

---

## 🚀 1. Các Chức Năng Chính

Hệ thống nhận diện các thao tác khác nhau trên cùng một nút nhấn:

- 🔘 **Single Click (Nhấn 1 lần):** Chức năng ON/OFF, dùng để Bật hoặc Tắt đèn LED ngay lập tức.
- ⚡ **Double Click (Nhấn đúp 2 lần):** Chuyển đèn LED sang chế độ nhấp nháy liên tục (Blink Mode).

---

## 🛠️ 2. Cấu Hình Phần Cứng

Dự án tận dụng các linh kiện có sẵn trên bo mạch để tối giản việc đi dây:

| Thiết bị / Linh kiện | Chi tiết sử dụng | Chân kết nối (GPIO) |
| :--- | :--- | :---: |
| 📟 **Bo mạch** | DOIT ESP32 DevKit V1 | N/A |
| 🔘 **Nút nhấn** | Nút BOOT tích hợp sẵn trên mạch | `GPIO 0` |
| 💡 **Đèn LED** | Đèn LED xanh dương tích hợp trên mạch | `GPIO 2` |

---

## 🧠 3. Kỹ Thuật Lập Trình Áp Dụng

Dự án áp dụng các kỹ thuật lập trình tối ưu, mang lại độ ổn định cao cho vi điều khiển:

*   🛡️ **Xử lý sự kiện & Chống nhiễu (Debounce):** Tự động loại bỏ các xung nhiễu vật lý khi thao tác phím nhờ các thuật toán cốt lõi của thư viện `OneButton`.
*   ⏱️ **Lập trình đa nhiệm cơ bản (Non-blocking):** 
    *   Loại bỏ hoàn toàn sự phụ thuộc vào hàm `delay()`.
    *   Sử dụng bộ đếm thời gian `millis()` để kiểm soát chu kỳ nhấp nháy của đèn LED. 
    *   **Lợi ích:** Đảm bảo vòng lặp `loop()` không bao giờ bị "treo", giúp hệ thống luôn quét và nhận tín hiệu nút nhấn mượt mà ngay cả khi LED đang trong chu kỳ chớp tắt.