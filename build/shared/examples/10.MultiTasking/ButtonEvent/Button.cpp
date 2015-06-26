#include "Button.h"

Button::Button(uint8_t pin)
{
  _pin = pin;
  lastButtonState = HIGH;
  buttonState = HIGH;
  lastDebounceTime = 0;
  debounceDelay = 50;  
}

void Button::begin()
{
  pinMode(_pin, INPUT_PULLUP);
  
  Error_Block eb;
  Error_init(&eb);
  /* Default instance configuration params */
  _event = Event_create(NULL, &eb);
}

bool Button::read()
{
  int reading = digitalRead(_pin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
        buttonState = reading;

      if (buttonState == HIGH) {
        Event_post(_event, Event_Id_00);
      }
    }
  }
  lastButtonState = reading;
}

void Button::waitForPress()
{
  xdc_UInt events;
  events = Event_pend(_event, Event_Id_NONE,
    Event_Id_00, BIOS_WAIT_FOREVER);    
}
