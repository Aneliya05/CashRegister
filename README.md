# КАСОВ АПАРАТ
ПРОЕКТ ПО МОДУЛ 8 
ВГРАДЕНИ СИСТЕМИ

Име на проект: Касов апарат

 

Екип: 
Анелия Лявова,
Веселин Пискачев,
Стоян Димитров


Дата на представяне: 14.05.2023

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




Свързване
За да стартира устройството и програма, включваме Ардуино платката към компютър чрез USB. Реалната клавиатурата, която е 4x3, сме свързали към пинове от 9 до 3, а в Tinkercad – от 9 до 2, тъй като там единствената налична е 4x4 . Дисплеят е I2C и има 4 пина. Решихме да използваме този вид дисплей, защото е много по-удобен за свързване от класическия. Дисплеят има пинове VCC, Ground, SDA и SCL, които се свързват съответно към 5V, Ground, SDA и SCL от Ардуино платката.


Списък съставни части

	Arduino Uno R3
	Keypad 3*4
	LCD I2C display
	11 джъмпера



Заключение

Проектът ни за касов апарат е нова стъпка в нашето развитие като програмисти, защото видяхме, че освен да пишем код на компютър, ние можем да го приложим и практически, като накараме машина да работи според нашите команди.

Предизвикателствата бяха доста, докато изпълнявахме проекта, като бяха предимно свързани с хардуерната част, но всичко беше решено след като разбрахме грешките си.

Този проект ще има развитие в бъдеще, защото е актуален в настоящето и може да постигне голям успех. Ще се подобри неговата хардуерна част, както и софтуерната.



Tinkercad: https://www.tinkercad.com/things/8h7zmGDrerJ-cash-register/editel \n
Notion: https://www.notion.so/5df67a0ef1cf4cdb820df446adfc7413?v=ba2ed34f180e431bad86fb2a23613352&pvs=4

