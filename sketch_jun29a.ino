//пины
#define UP_RIGHT 10//вперёд правый мотор
#define DOWN_RIGHT 9//назад правй мотор
#define UP_LEFT 6//вперёд левый мотор
#define DOWN_LEFT 5//назад левый мотор

#define LEFT_ENCODER 2//левый энкодер
#define RIGHT_ENCODER 3//правый энкодер
//----------------------------------------------------------------------------------------------

//скорость двигателей
#define SPD_NULL 0
#define SPD_MIN 100
#define SPD_MAX 255
//----------------------------------------------------------------------------------------------

////коды кнопок
//#define KEY_UP "F"
//#define KEY_DOWN "B"
//#define KEY_LEFT "L"
//#define KEY_RIGHT "R"
//----------------------------------------------------------------------------------------------

//прерывания


//скорость работы ардуино
#define SERIAL_BOAD 115200
//----------------------------------------------------------------------------------------------


//переменная хранящая код с геймпада на телефоне
char res;




void parser()//ф-ия парсер для движения робота(коды задаются в приложении на телефоне)
{
  
}




void setup() {
  Serial.begin(SERIAL_BOAD);
  pinMode(UP_RIGHT, OUTPUT);
  pinMode(UP_LEFT, OUTPUT);
  pinMode(DOWN_RIGHT, OUTPUT);
  pinMode(DOWN_LEFT, OUTPUT);
}

void loop() {
  if (Serial.available())
    res = Serial.read();
   switch (res)
   {
    case 'F':
      analogWrite(UP_RIGHT, SPD_MAX);
      analogWrite(UP_LEFT, SPD_MAX);
      break;
    case 'B':
      analogWrite(DOWN_RIGHT, SPD_MAX);
      analogWrite(DOWN_LEFT, SPD_MAX);
      break;
    case 'G':
      analogWrite(UP_LEFT, SPD_MIN);
      analogWrite(UP_RIGHT, SPD_MAX);
      break;
    case 'I':
      analogWrite(UP_LEFT, SPD_MAX);
      analogWrite(UP_RIGHT, SPD_MIN);
      break;
    case 'H':
      analogWrite(DOWN_LEFT, SPD_MIN);
      analogWrite(DOWN_RIGHT, SPD_MAX);
      break;
    case 'J':
      analogWrite(DOWN_LEFT, SPD_MAX);
      analogWrite(DOWN_RIGHT, SPD_MIN);
      break;  
    case 'L':
      analogWrite(DOWN_LEFT, SPD_MAX);
      analogWrite(UP_RIGHT, SPD_MAX);
      break;
    case 'R':
      analogWrite(DOWN_RIGHT, SPD_MAX);
      analogWrite(UP_LEFT, SPD_MAX);
      break;
    default:
      analogWrite(DOWN_RIGHT, 0);
      analogWrite(DOWN_LEFT, 0);
      analogWrite(UP_RIGHT, 0);
      analogWrite(UP_LEFT, 0);
      break;
   } 
}
