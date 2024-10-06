Điều khiển Hai LED bằng Nút Nhấn Sử dụng OneButton

## Mô tả

Dự án này sử dụng một nút nhấn để điều khiển hai LED (một LED tích hợp trên bo mạch và một LED ngoài) với các chức năng sau:

- Single Click: Bật hoặc tắt LED hiện đang được điều khiển (LED hoặc LED2).
- Double Click: Chuyển đổi chế độ điều khiển giữa LED (tích hợp) và LED2 (LED ngoài).
- Long Press: Kích hoạt chế độ nhấp nháy 200ms cho LED hiện đang được điều khiển.

## Phần cứng

- LED: LED tích hợp trên bo mạch 
- LED2: LED ngoài được kết nối với chân D21
- Nút nhấn: Kết nối với chân D4, chân còn lại nối GND

## Phần mềm

- Ngôn ngữ lập trình: C++ (Arduino Framework)
- Thư viện sử dụng: + [OneButton](https://github.com/mathertel/OneButton)
                    + LED.h

## Chức năng điều khiển

- Single Click:
  - Bật/tắt LED hiện đang được điều khiển.
- Double Click:
  - Chuyển đổi giữa điều khiển LED và LED2.
  - Khi chuyển đổi, chế độ nhấp nháy sẽ bị tắt.
- Long Press:
  - Kích hoạt chế độ nhấp nháy 200ms cho LED hiện tại.

## Cài đặt

- Phần mềm:
   - Clone mã nguồn của dự án.
   - Mở dự án trong Visual Studio Code.
   - Kiểm tra file `platformio.ini` để đảm bảo cấu hình đúng board và thư viện.
   - Nạp chương trình vào bo mạch phát triển.

## Sử dụng

  - Nhấn nút một lần để bật hoặc tắt LED đang được điều khiển.
  - Nhấn nút hai lần liên tiếp (double click) để chuyển đổi giữa LED và LED2.
  - Nhấn và giữ nút để kích hoạt chế độ nhấp nháy cho LED hiện tại.