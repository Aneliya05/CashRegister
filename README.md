# CashRegister
ПРОЕКТ ПО МОДУЛ 8 
ВГРАДЕНИ СИСТЕМИ

Име на проект: Касов апарат

 

Екип: 
Анелия Лявова
Веселин Пискачев
Стоян Димитров


Дата на представяне: 14.05.2023
Ръководител: Янислав Картелов
GIT HUB: https://github.com/Aneliya05/CashRegister.git


СЪДЪРЖАНИЕ

1.	Описание на проекта
2.	Блокова схема
3.	Електрическа схема
4.	Списък съставни части
5.	Сорс код – описание на функционалността
6.	Заключение



























Описание на проекта

Поставихме си за цел да създадем устройство, което да е лесно достъпно за масова употреба, без да е необходима допълнителна квалификация на работниците в търговски вериги. Затова решихме да създадем касов апарат с малко на брой бутони, който да извършва най-важните функции за едно пресмятащо стоки устройство. Устройството е в началния етап на своето развитие, така че предстои добавянето на много нови функции и дори взаимодействие с бази данни.

Специално за представянето решихме да покажем нашия продукт, като го използваме в сферата на ресторантьорството. Като за начало потребителят ще получи дружелюбен поздрав, след което ще има възможността да добави каквито продукти желае и колкото желае, а после ще се отпечата крайната сума. С цел улесняване на работниците, използващи устройството, вече се обмисля функция за връщане на ресто и отваряне на касата с пари. 

Проектът ни има два интерфейса, единият от които е физически, като сме използвали Arduino, LCD дисплей и Keypad, а другият интерфейс е виртуален (конзолен). Може да бъде достъпен чрез Serial Monitor прозорците в Tinkercad и Arduino IDE.
















Електрическа схема
  














За да стартира устройството и програма, включваме Ардуино платката към компютър чрез USB. Реалната клавиатурата, която е 4x3, сме свързали към пинове от 9 до 3, а в Tinkercad – от 9 до 2, тъй като там единствената налична е 4x4 . Дисплеят е I2C и има 4 пина. Решихме да използваме този вид дисплей, защото е много по-удобен за свързване от класическия. Дисплеят има пинове VCC, Ground, SDA и SCL, които се свързват съответно към 5V, Ground, SDA и SCL от Ардуино платката.


Списък съставни части

	Arduino Uno R3
	Keypad 3*4
	LCD I2C display
	11 джъмпера







Сорс код – описание на функционалността

1)	 Използвани библиотеки
 #include <Key.h>
 #include <Keypad.h>
 #include <LCD_I2C.h>
 #include <Wire.h>
  
2)	Инициализация на компонентите 
-	Клавиатура:
//keypad
const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
  {'#','*','0'},
  {'3','2','1'},
  {'6','5','4'},
  {'9','8','7'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

-	Дисплей:
LCD_I2C lcd(0x3F, 16, 2);

3)	 Данни, които ще използва приложението
//data
double sum;
double cheeseburgerPrice = 4.90;
double hamburgerPrice = 5.20;
double bbqBurgerPrice = 4.80;
double veggieBurgerPrice = 5.50;
double pizzaPepperoniPrice = 4.20;
double pizzaMargaritaPrice = 3.60;
double friedChickenPrice = 5.20;
double hotDogPrice = 1.30;
double juicePrice = 1.80;
double colaPrice = 2.20;
4)	Setup

void setup() {
  Serial.begin(9600);
  Serial.print("WELCOME TO OUR RESTAURANT! \n");
  Serial.println();
}

5)	Loop
void loop()
{
  char key = keypad.getKey(); //взимаме число от keypad-а
  if(key == '*'){     //ако натиснатият бутон е “*”, дисплеят се включва
    lcd.begin();
    lcd.backlight();
    lcd.print("Hello :)");
    delay(5000);
       lcd.setCursor(0,0);
       lcd.print("NEW RECEIPT");
    lcd.setCursor(0,1);
    lcd.print("Add product: ");
  }
  shop(); //метод, чрез който можем да избираме какво да си купим
  
  if(key == '#'){   //метод за приключване на пазаруването
         Serial.println();
      Serial.print("TOTAL:                           ");
      Serial.println(sum);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Total: ");
      lcd.print(sum);
      lcd.print(" lv.");
      lcd.setCursor(0,1);
         lcd.print("Come again :)");
         delay(5000);
         lcd.clear();
      lcd.print("New Receipt:");
      lcd.setCursor(0, 1);
      lcd.print("Press *");
      lcd.noDisplay(); //изключване на дисплея

      sum = 0;
  }
  
}
6)	Shop() методът- 
Направен е да работи, чрез switch-case, който изглежда по този начин. Има добавени още case-ове, аналогични на показания тук. Всяко число от 1 до 9 е код на продукт.

void shop(){
  char productKey = keypad.getKey();
  switch(productKey){
    case '1':
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("# ");
             lcd.print(productKey);
        delay(1000);
        lcd.setCursor(0, 0);
          lcd.print("Cheeseburger");
        lcd.setCursor(0, 1);
        lcd.print(cheeseburgerPrice);
        lcd.print(" lv.");

        Serial.print("Cheeseburger                     ");
        Serial.println(cheeseburgerPrice);

      sum += cheeseburgerPrice;
      break;
...




Заключение

Проектът ни за касов апарат е нова стъпка в нашето развитие като програмисти, защото видяхме, че освен да пишем код на компютър, ние можем да го приложим и практически, като накараме машина да работи според нашите команди.

Предизвикателствата бяха доста, докато изпълнявахме проекта, като бяха предимно свързани с хардуерната част, но всичко беше решено след като разбрахме грешките си.

Този проект ще има развитие в бъдеще, защото е актуален в настоящето и може да постигне голям успех. Ще се подобри неговата хардуерна част, както и софтуерната.


