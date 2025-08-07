#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

unsigned long startTime;
bool sweeping = true;

void setup() {
  servo1.attach(9);   // السيرفو الأول على البن رقم 9
  servo2.attach(10);  // السيرفو الثاني على البن رقم 10
  servo3.attach(11);  // السيرفو الثالث على البن رقم 11
  servo4.attach(12);  // السيرفو الرابع على البن رقم 12

  startTime = millis();  // بداية الوقت
}

void loop() {
  if (sweeping) {
    unsigned long currentTime = millis();

    // نعمل السويب لمدة ثانيتين
    if (currentTime - startTime < 2000) {
      for (int angle = 0; angle <= 180; angle += 5) {
        servo1.write(angle);
        servo2.write(angle);
        servo3.write(angle);
        servo4.write(angle);
        delay(15);
      }

      for (int angle = 180; angle >= 0; angle -= 5) {
        servo1.write(angle);
        servo2.write(angle);
        servo3.write(angle);
        servo4.write(angle);
        delay(15);
      }

    } else {
      // بعد ثانيتين نثبت الزاوية على 90
      servo1.write(90);
      servo2.write(90);
      servo3.write(90);
      servo4.write(90);
      sweeping = false;
    }
  }
}
