#define Gas A3 // аналоговый выход MQ135 подключен к пину A0 Arduino

int ZnacheniyaGasa; // для аналогового значения
void setup() {

Serial.begin(9600); // инициализация последовательного порта
pinMode(Gas, INPUT); // режим работы аналогового пина
}

void loop() {

  ZnacheniyaGasa = analogRead(Gas); // чтение аналогового значения
  Serial.print("Current value: "); // вывод аналогового значения в последовательный порт
  Serial.println(ZnacheniyaGasa);

 delay(500); // задержка, чтобы не мельтешило перед глазами

}
