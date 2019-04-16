const int buttonPin=10;// вывод кнопки 0 нажата 1 нет
uint32_t last_millis; // переменные: последний  millis

uint8_t botton(){
  if (digitalRead(buttonPin) == 1){ // кнопка не нажата     
     last_millis = millis();
     return 0;}
   delay(5);
   while (digitalRead(buttonPin) == 0);
   delay(5);
   if (last_millis+15 > millis()){ // ложное срабатывание
     //Serial.println(millis()-last_millis);
     last_millis = millis();
     return 0;}
   if (last_millis+600 > millis()){ // короткое нажатие меньше 0.30 сек
     //Serial.println(millis()-last_millis);
     last_millis = millis();
     return 1;}
   //Serial.println(millis()-last_millis);
   last_millis = millis(); // длинное нажатие больше 0.30 сек
   return 2;
};


void setup() 
{  
  Serial.begin(9600); // Запускаем последовательный порт
  pinMode(buttonPin, INPUT_PULLUP); // вывод на ввод с подтягивающим резистром 
  last_millis = millis();  
}
void loop()
 {
   switch (botton()) {
      case 1:  Serial.println("Short press");
         break;
     case 2:  Serial.println("Long press");
         break;
   } 
 }
