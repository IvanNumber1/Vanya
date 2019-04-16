const int buttonPin=10;// вывод кнопки 0 нажата 1 нет
uint32_t last_millis; // переменные: последний  millis
int i;
uint8_t botton(){
  if (digitalRead(buttonPin) == 1){ // кнопка не нажата     
     last_millis = millis();
     return 0;}
   delay(30);
   while (digitalRead(buttonPin) == 0);
   delay(30);
   if (last_millis+65 > millis()){ // ложное срабатывание
     //Serial.println(millis()-last_millis);
     last_millis = millis();
     return 0;}
   if (last_millis+500 > millis()){ // короткое нажатие меньше 0.30 сек
     //Serial.println(millis()-last_millis);
     last_millis = millis();
     return 1;}
   //Serial.println(millis()-last_millis);
   last_millis = millis(); // длинное нажатие больше 0.30 сек
   return 2;
}


void setup() 
{  
  Serial.begin(9600); // Запускаем последовательный порт
  pinMode(buttonPin, INPUT_PULLUP); // вывод на ввод с подтягивающим резистром 
  last_millis = millis();  
}
void loop()
 {
   switch (botton()) {
      case 1:  i++;
      Serial.println(i);
         break;
     case 2:  Serial.println("LONG");
         break;
   } 
 }
