int LedPin = 13;             // Подключаем светодиод к порту 13
int ButPin = 9;             // Подключаем кнопку к выходу 10
int flag = 0;                // флаг состояния
int flag2 = 0;
void setup()
{
  pinMode(LedPin, OUTPUT);   // Инициализируем порт "ledPin" как выходной
pinMode(9, INPUT);
pinMode(8, OUTPUT);
}  

void loop()
{
  if(digitalRead(ButPin) == HIGH && flag == 0)      
    {                                              
      digitalWrite(LedPin, !digitalRead(LedPin));
      flag = 1;
    }
  
  if(digitalRead(ButPin) == LOW && flag == 1)
    {
      flag = 0;
    } if(digitalRead(ButPin) == HIGH && flag2 == 0)      
    {                                              
      digitalWrite(9, !digitalRead(9));
      flag = 1;
    }
  
  if(digitalRead(ButPin) == LOW && flag2 == 1)
    {
      flag = 0;
    }  
 
}

