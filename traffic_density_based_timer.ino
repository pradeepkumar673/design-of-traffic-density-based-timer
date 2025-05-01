#include <TM1637Display.h>

#define CLK A0  
#define DIO A1  

#define TRIG1 6   
#define ECHO1 7
#define TRIG2 8   
#define ECHO2 9


#define RED 3
#define YELLOW 4 
#define GREEN 5 

TM1637Display display(CLK, DIO);


const uint8_t flippedDigits[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

int countdown = 30;

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(GREEN, OUTPUT);

    pinMode(TRIG1, OUTPUT);
    pinMode(ECHO1, INPUT);
    pinMode(TRIG2, OUTPUT);
    pinMode(ECHO2, INPUT);

    display.setBrightness(7);
    
    
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
}

long long getDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    return pulseIn(echoPin, HIGH) * 0.034 / 2;
}


void showFlippedNumber(int num) {
    uint8_t displayData[4];
    
    displayData[0] = flippedDigits[num / 1000];       // Thousands place
    displayData[1] = flippedDigits[(num / 100) % 10]; // Hundreds place
    displayData[2] = flippedDigits[(num / 10) % 10];  // Tens place
    displayData[3] = flippedDigits[num % 10];         // Ones place
    
    display.setSegments(displayData);
}
void runCountdown() {
    while (countdown > 0) {
        long dist1 = getDistance(TRIG1, ECHO1);
        long dist2 = getDistance(TRIG2, ECHO2); 

        bool closeBlocked = (dist1 < 10);
        bool farBlocked = (dist2 < 10);

    
        if (closeBlocked && farBlocked) {
            countdown -= 2;  
        } else {
            countdown -= 1; 
        }

      
        if (countdown > 5) {
            digitalWrite(RED, HIGH);
            digitalWrite(YELLOW, LOW);
            digitalWrite(GREEN, LOW);
        } else {
            digitalWrite(RED, LOW);
            digitalWrite(YELLOW, LOW);
            digitalWrite(GREEN, HIGH);
        }

        showFlippedNumber(countdown);
        delay(1000);
    }
}

void loop() {
    countdown = 30;
    
    runCountdown(); 

    
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);

    for (int i = 20; i > 0; i--) {
        showFlippedNumber(i);
        delay(1000);
    }

    
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
}