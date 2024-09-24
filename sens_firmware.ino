

#define CLK_PIN   12
#define LATCH_PIN 14
#define LED_PIN   2

bool clk_state = false; 
bool clk_state_high = false;

bool latch_state = false;
bool latch_state_high = false;

long time_since_boot = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(CLK_PIN, INPUT_PULLDOWN);
  pinMode(LATCH_PIN, INPUT_PULLDOWN);
  time_since_boot = esp_timer_get_time();

}

void loop() {
  // put your main code here, to run repeatedly:

  clk_state = digitalRead(CLK_PIN);
  latch_state = digitalRead(LATCH_PIN);
  
  

  if (clk_state == HIGH && !clk_state_high) {
    // turn LED on:
//    digitalWrite(LED_PIN, HIGH);
//    Serial.println(esp_timer_get_t/ime() - time_since_boot);
//    time_since_boot = esp_timer_get_t/ime();
    clk_state_high = true;
  } 
  else if(clk_state == LOW) {
    // turn LED off:
//    digitalWrite(LED_PIN, LOW);/
    clk_state_high = false;
  }

  if (latch_state == HIGH && !latch_state_high) {
    // turn LED on:
    digitalWrite(LED_PIN, HIGH);
    Serial.println(esp_timer_get_time() - time_since_boot);
    time_since_boot = esp_timer_get_time();
    latch_state_high = true;
  } 
  else if(latch_state == LOW) {
    // turn LED off:
    digitalWrite(LED_PIN, LOW);
    latch_state_high = false;
  }

  

}
