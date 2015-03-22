#include <Energia.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/BIOS.h>


class Event {
  private:
    Event_Handle eventHandle;
    static xdc_UInt eventId;
  public:
    Event();
    void begin();
    void send();
    void waitFor();
};
