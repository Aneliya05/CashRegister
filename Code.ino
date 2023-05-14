#include <Key.h>
#include <Keypad.h>
#include <LCD_I2C.h>
#include <Wire.h>

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
LCD_I2C lcd(0x3F, 16, 2);

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

void setup() {
  
  Serial.begin(9600);
  Serial.print("WELCOME TO OUR RESTAURANT! \n");
  Serial.println();
}

void loop()
{
  char key = keypad.getKey();
  if(key == '*'){
    lcd.begin();
    lcd.backlight();
    lcd.print("Hello :)");
    delay(5000);
    lcd.setCursor(0,0);
    lcd.print("NEW RECEIPT");
    lcd.setCursor(0,1);
   	lcd.print("Add product: ");
  }
  shop();
  
  if(key == '#'){
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
      lcd.noDisplay();

      sum = 0;
  }
  
}
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

    case '2':
        lcd.clear();
   	  lcd.setCursor(0, 0);
      lcd.print("# ");
      lcd.print(productKey);
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("Hamburger");
      lcd.setCursor(0, 1);
      lcd.print(hamburgerPrice);
      lcd.print(" lv.");
      
      Serial.print("Hamburger                        ");
        Serial.println(hamburgerPrice);

      sum += hamburgerPrice;
      break;

    case '3':
      lcd.clear();
   	  lcd.setCursor(0, 0);
      lcd.print("# ");
      lcd.print(productKey);
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("BBQ Burger");
      lcd.setCursor(0, 1);
      lcd.print(bbqBurgerPrice);
      lcd.print(" lv.");

      Serial.print("BBQ Burger                       ");
        Serial.println(bbqBurgerPrice);

      sum += bbqBurgerPrice;
      break;
    
    case '4':
      lcd.clear();
   	  lcd.setCursor(0, 0);
      lcd.print("# ");
      lcd.print(productKey);
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("Veggie Burger");
      lcd.setCursor(0, 1);
      lcd.print(veggieBurgerPrice);
      lcd.print(" lv.");

      Serial.print("Veggie Burger                    ");
        Serial.println(veggieBurgerPrice);

      sum += veggieBurgerPrice;
      break;

      case '5':
      lcd.clear();
   	  lcd.setCursor(0, 0);
      lcd.print("# ");
      lcd.print(productKey);
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("Pizza Pepperoni");
      lcd.setCursor(0, 1);
      lcd.print(pizzaPepperoniPrice);
      lcd.print(" lv.");

      Serial.print("Pizza Pepperoni                  ");
        Serial.println(pizzaPepperoniPrice);

      sum += pizzaPepperoniPrice;
      break;
  
      case '6':
      lcd.clear();
   	  lcd.setCursor(0, 0);
      lcd.print("# ");
      lcd.print(productKey);
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("Pizza Margarita");
      lcd.setCursor(0, 1);
      lcd.print(pizzaMargaritaPrice);
      lcd.print(" lv.");

      Serial.print("Pizza Margarita                  ");
        Serial.println(pizzaMargaritaPrice);

      sum += pizzaMargaritaPrice;
      break;

      case '7':
      lcd.clear();
   	  lcd.setCursor(0, 0);
      lcd.print("# ");
      lcd.print(productKey);
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("Fried Chicken");
      lcd.setCursor(0, 1);
      lcd.print(friedChickenPrice);
      lcd.print(" lv.");

      Serial.print("Fried Chicken                    ");
        Serial.println(friedChickenPrice);

      sum += friedChickenPrice;
      break;

      case '8':
      lcd.clear();
   	  lcd.setCursor(0, 0);
      lcd.print("# ");
      lcd.print(productKey);
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("Hot Dog");
      lcd.setCursor(0, 1);
      lcd.print(hotDogPrice);
      lcd.print(" lv.");

      Serial.print("Hot Dog                          ");
        Serial.println(hotDogPrice);

      sum += hotDogPrice;
      break;
      
      case '9':
      lcd.clear();
   	  lcd.setCursor(0, 0);
      lcd.print("# ");
      lcd.print(productKey);
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("Juice");
      lcd.setCursor(0, 1);
      lcd.print(juicePrice);
      lcd.print(" lv.");

      Serial.print("Juice                            ");
        Serial.println(juicePrice);

      sum += juicePrice;
      break;

      case '0':
      lcd.clear();
   	  lcd.setCursor(0, 0);
      lcd.print("# ");
      lcd.print(productKey);
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("Cola");
      lcd.setCursor(0, 1);
      lcd.print(colaPrice);
      lcd.print(" lv.");

      Serial.print("Cola                             ");
        Serial.println(colaPrice);

      sum += colaPrice;
      break;
  }
} 


