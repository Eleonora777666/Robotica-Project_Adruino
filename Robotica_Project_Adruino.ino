// =========================================================
// Robotica-Project_Adruino: Interactive Sound System Sketch
// =========================================================

// --- Pin Definitions ---
const int BUTTON_PIN = 2;   // Желтая кнопка подключена к цифровому пину D2
const int BUZZER_PIN = 8;   // Встроенный пьезоизлучатель (buzzer) подключен к пину 8

// --- State Variables ---
int soundState = 0;         // Счётчик состояния: 0, 1, 2
int lastButtonState = HIGH; // Последнее состояние кнопки (для обнаружения нажатия)

// --- Debounce Variables ---
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // Задержка устранения дребезга в миллисекундах

void setup() {
  // Настройка пина кнопки с внутренним подтягивающим резистором (INPUT_PULLUP)
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  // Настройка пина динамика как OUTPUT
  pinMode(BUZZER_PIN, OUTPUT);
  // Инициализация последовательного порта для отладки (необязательно)
  Serial.begin(9600);
}

// --- Function to play sound based on the current state ---
void playSound(int state) {
  noTone(BUZZER_PIN); // Остановить предыдущий звук

  switch (state) {
    case 0:
      // Sound 1: Simple Confirmation Tone (440 Hz / A4)
      tone(BUZZER_PIN, 440, 300); // 440 Hz for 300 ms
      break;
    case 1:
      // Sound 2: Alert/High Signal (660 Hz / E5)
      tone(BUZZER_PIN, 660, 500); // 660 Hz for 500 ms
      break;
    case 2:
      // Sound 3: Short Melody (C5 then G5)
      tone(BUZZER_PIN, 523, 150); // C5
      delay(150);
      tone(BUZZER_PIN, 783, 150); // G5
      delay(150);
      noTone(BUZZER_PIN);
      break;
  }
}

void loop() {
  // 1. Чтение текущего состояния кнопки
  int reading = digitalRead(BUTTON_PIN);

  // 2. Логика устранения дребезга
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // 3. Обнаружение нажатия (переход из HIGH в LOW)
    if (reading == LOW && lastButtonState == HIGH) {
      // Кнопка нажата!
      
      // Инкрементируем состояние
      soundState++;

      // Сбрасываем счетчик, если он превышает максимальное значение (2)
      if (soundState > 2) {
        soundState = 0;
      }

      // Воспроизводим звук
      playSound(soundState);
    }
  }

  // 4. Сохранение текущего состояния для следующей итерации
  lastButtonState = reading;
}
