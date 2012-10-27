
#ifndef TwoWire_h
#define TwoWire_h

#include <inttypes.h>
#include "Stream.h"

#define BUFFER_LENGTH     16


class TwoWire : public Stream
{

	private:
		static uint8_t rxBuffer[];
		static uint8_t rxBufferIndex;
		static uint8_t rxBufferLength;

		static uint8_t txAddress;
		static uint8_t txBuffer[];
		static uint8_t txBufferIndex;
		static uint8_t txBufferLength;

		static unsigned long i2cModule;
		static uint8_t slaveAddress;

		static uint8_t transmitting;
		static void (*user_onRequest)(void);
		static void (*user_onReceive)(int);
		static void onRequestService(void);
		static void onReceiveService(uint8_t*, int);
		
    public:
		TwoWire(void);
        TwoWire(unsigned long _i2cModule);
		void begin();
		void begin(uint8_t);
		void begin(int);
		void selectModule(unsigned long);
		void beginTransmission(uint8_t);
		void beginTransmission(int);
		uint8_t endTransmission(void);
		uint8_t endTransmission(uint8_t);
		uint8_t requestFrom(uint8_t, uint8_t);
		uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
		uint8_t requestFrom(int, int);
		uint8_t requestFrom(int, int, int);
		virtual size_t write(uint8_t);
		virtual size_t write(const uint8_t *, size_t);
		virtual int available(void);
		virtual int read(void);
		virtual int peek(void);
		virtual void flush(void);
        void I2CIntHandler(void);
		void onReceive( void (*)(int) );
		void onRequest( void (*)(void) );
	  
	    inline size_t write(unsigned long n) { return write((uint8_t)n); }
	    inline size_t write(long n) { return write((uint8_t)n); }
	    inline size_t write(unsigned int n) { return write((uint8_t)n); }
	    inline size_t write(int n) { return write((uint8_t)n); }
	    using Print::write;
        
};

extern TwoWire Wire;
extern "C" void I2CIntHandler(void);
#endif
