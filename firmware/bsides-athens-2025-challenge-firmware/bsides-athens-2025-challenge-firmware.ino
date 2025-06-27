#define LED_0 2
#define LED_1 3
#define LED_2 4

/* HARDWARE HACKING BOARD */
#define BTN_DOT 5
#define BTN_DASH 6
#define BTN_SPACE 8
#define BTN_OK 7

#define SPEED 250

const char SECRET[] = "- .-- ...-- .-.. ...- . ..... ...-- -.-."; // TW3LVE53C

const char HELP[] = ".... . .-.. .--."; // HELP

const char USAGE[] = "..- ... .- --. . / .-.. . -.. / --- -. / --- .-. / --- ..-. ..-. / -. ..- -- -... . .-."; // USAGE LED ON OR OFF NUMBER
const char ERROR[] = ". .-. .-. --- .-."; // ERROR

const char LED_ON_1[] = ".-.. . -.. --- -. .----"; // LED ON 1
const char LED_ON_2[] = ".-.. . -.. --- -. ..---"; // LED ON 2
const char LED_ON_3[] = ".-.. . -.. --- -. ...--"; // LED ON 3

const char LED_OFF_1[] = ".-.. . -.. --- ..-. ..-. .----" ; // LED OFF 1
const char LED_OFF_2[] = ".-.. . -.. --- ..-. ..-. ..---" ; // LED OFF 2
const char LED_OFF_3[] = ".-.. . -.. --- ..-. ..-. ...--" ; // LED OFF 3

int LED_0_STATE = 1;
int LED_1_STATE = 1;
int LED_2_STATE = 1;

char MorseInput[40] = {'\0'};
int morse_index = 0;

bool flag = true;
  
  
void morseMessager(String morse, int speed);
  


void setup()
{
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  
  pinMode(BTN_DOT, INPUT);
  pinMode(BTN_DASH, INPUT);
  pinMode(BTN_OK, INPUT);
  pinMode(BTN_SPACE, INPUT);

  digitalWrite(LED_0, LED_0_STATE);
  digitalWrite(LED_1, LED_1_STATE);
  digitalWrite(LED_2, LED_2_STATE);
  
  Serial.begin(9600);
}

void loop()
{

  digitalWrite(LED_0, LED_0_STATE);
  delay(10);
  digitalWrite(LED_1, LED_1_STATE);
  delay(10);
  digitalWrite(LED_2, LED_2_STATE);
  delay(10);

  if (digitalRead(BTN_DOT) == HIGH){
    MorseInput[morse_index] = '.';
    morse_index++;
    if(morse_index == 40){
      morse_index = 0;
    }
    delay(300);
  }
  
  if (digitalRead(BTN_DASH) == HIGH){
    MorseInput[morse_index] = '-';
    morse_index++;
    if(morse_index == 40){
      morse_index = 0;
    }
    delay(300);
  }
  
    
  if (digitalRead(BTN_SPACE) == HIGH){
    MorseInput[morse_index] = ' ';
    morse_index++;
    if(morse_index == 40){
      morse_index = 0;
    }
    delay(300);
  }
    
  if (digitalRead(BTN_OK) == HIGH){
    delay(10);
    if (strcmp(MorseInput , SECRET) == 0){
      Serial.println("SECRET MODE UNLOCKED");  
      while(true){
        digitalWrite(LED_0, HIGH);
        delay(100);
        digitalWrite(LED_0, LOW);
        delay(100);
        digitalWrite(LED_1, HIGH);
        delay(100);
        digitalWrite(LED_1, LOW);
        delay(100);
        digitalWrite(LED_2, HIGH);
        delay(100);
        digitalWrite(LED_2, LOW);
        delay(100);
      }
    }
    else
    {
      
      if (strcmp(MorseInput , HELP) == 0)
      {
        morseMessager(USAGE, SPEED);
      }
      else if (strcmp(MorseInput , LED_ON_1) == 0)
      {
        LED_0_STATE = 1;
      }
      else if (strcmp(MorseInput , LED_ON_2) == 0)
      {
        LED_1_STATE = 1;
      }
      else if (strcmp(MorseInput , LED_ON_3) == 0)
      {
        LED_2_STATE = 1;
      }
      else if (strcmp(MorseInput , LED_OFF_1) == 0)
      {
        LED_0_STATE = 0;
      }
      else if (strcmp(MorseInput , LED_OFF_2) == 0)
      {
        LED_1_STATE = 0;
      }
      else if (strcmp(MorseInput , LED_OFF_3) == 0)
      {
        LED_2_STATE = 0;
      }
      else{
        morseMessager(ERROR, SPEED);
      }
    }
    delay(500);
    morse_index = 0;
    memset(MorseInput, '\0', sizeof(MorseInput));
  }
}

void morseMessager(String morse, int speed){

  digitalWrite(LED_0, LOW);
  delay(10);
  digitalWrite(LED_1, LOW);
  delay(10);
  digitalWrite(LED_2, LOW);
  delay(speed * 2);

  for (int i=0; i < morse.length(); i++){
    
    if (morse.charAt(i) == '.') {   
        delay(speed);    
        digitalWrite(LED_2, HIGH);
        delay(speed);
        digitalWrite(LED_2, LOW);
    }

    if (morse.charAt(i) == '-') {
        delay(speed);           
        digitalWrite(LED_0, HIGH);
        digitalWrite(LED_1, HIGH);
        delay(speed);
        digitalWrite(LED_0, LOW);
        digitalWrite(LED_1, LOW);
    }

    if (morse.charAt(i) == ' ') {
        delay(speed * 2);    
        digitalWrite(LED_0, LOW);
        digitalWrite(LED_1, LOW);   
        digitalWrite(LED_2, LOW);
        delay(speed * 2);
    }
  }

  delay(speed * 2);
  digitalWrite(LED_0, HIGH);
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH);
}
