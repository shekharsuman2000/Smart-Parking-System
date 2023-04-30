    #include <Wire.h>
    #include <LiquidCrystal_I2C.h>
    #include <Adafruit_LiquidCrystal.h>
    LiquidCrystal_I2C lcd(0x20,16,2);
    #include <Servo.h>
    Servo myservo1;
    Adafruit_LiquidCrystal lcd_1(0);
    int IR1 = 2;
    int IR2 = 4;
    int Slot = 4;
    int flag1 = 0;
    int flag2 = 0;
    void setup() 
    {
        //lcd.begin();
        lcd_1.begin(16, 2);
        //lcd_1.setBacklight(56);
        pinMode(IR1, INPUT);
        pinMode(IR2, INPUT);

        myservo1.attach(3);
        myservo1.write(100);
        lcd_1.setCursor (0,0);
        lcd_1.print(" WELCOME ");
        lcd_1.setCursor (0,1);
        lcd_1.print(" SMART PARKING SYSTEM ");
        delay (2000);
        //lcd_1.clear();
    }
    void loop()
    {
        if(digitalRead (IR1) == LOW && flag1==0)
        {
            if(Slot>0)
            {
                flag1=1;
                if(flag2==0)
                {
                    myservo1.write(0); Slot = Slot-1;
                }
            }
            else
            {
                lcd_1.setCursor (0,0);
                lcd_1.print(" SORRY :( ");
                lcd_1.setCursor (0,1);
                lcd_1.print(" Parking Full ");
                delay (3000);
                lcd.clear();
            }
        }
        if(digitalRead (IR2) == LOW && flag2==0)
        {
            flag2=1;
            if(flag1==0)
            {
                myservo1.write(0); Slot = Slot+1;
            }
        }
        if(flag1==1 && flag2==1)
        {
            delay (1000);
            myservo1.write(100);
            flag1=0, flag2=0;
        }
    }