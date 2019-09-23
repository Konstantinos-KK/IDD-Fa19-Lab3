
#include <EEPROM.h>

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int button=6;
int b_state=0;
int s_state=0;
int led =7;
int sensor=A0;
int pos=0;
int v_read=0;
void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led,LOW);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Study Time");
  lcd.setCursor(0,1);
  lcd.print("Press button");
  while(b_state==0){b_state=digitalRead(button);}
  lcd.clear();
  lcd.print("Position sensor");
  while(s_state<500){s_state = analogRead(sensor);}
  
}

void loop() {
  b_state=0;
  lcd.clear();
  lcd.print("Studying");
  lcd.setCursor(0,1);
  lcd.print("Good Job");
  while(s_state>500){s_state=analogRead(sensor);}
  
  lcd.clear();
  lcd.print("You are wasting");
  lcd.setCursor(5,1);
  lcd.print("time!!");
  int init_time = (millis() / 1000);
  while(s_state<=500){digitalWrite(led,HIGH); delay(1000);s_state=analogRead(sensor);};
  digitalWrite(led,LOW);
  lcd.clear();
  int delay_time = (millis() / 1000);
  EEPROM.write(pos, (delay_time-init_time));
  lcd.print("Distraction Time:");
  lcd.setCursor(0,1);
  lcd.print((delay_time-init_time));
  while(b_state==0){b_state=digitalRead(button);}
  delay(1000);
  b_state=0;
  s_state=0;
  lcd.clear();
  lcd.print("Restart->sensor");
  lcd.setCursor(0,1);
  lcd.print("Results->button");
  while(1){b_state=digitalRead(button);s_state=analogRead(sensor);
    if (b_state==1){lcd.clear();lcd.print("Results: ");
    Serial.print(pos);
    for(int j = pos; j>-1 ; j-- ){
      v_read = EEPROM.read(j);
      Serial.print(v_read);
      lcd.print(v_read);
      lcd.print(" ");
      }
      b_state=0;
    }
    if (s_state>500){break;}
  }
  lcd.clear();lcd.print("Restart");
  pos++;
}
