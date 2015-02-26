#include <Energia.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/BIOS.h>

class Button {
  private:
    Event_Handle _event;
    uint8_t _pin;
    int buttonState;
    int lastButtonState;
    long lastDebounceTime;
    long debounceDelay;

  public:
    Button(uint8_t pin);
    void begin();
    void waitForPress();
    void waitForRelease();
    bool read();
};
