#include <Arduino.h>

#if defined(__SAMD21G18A__)
#ifndef ADAFRUIT_FREETOUCH_H
#define ADAFRUIT_FREETOUCH_H


/*************** CONTROL A register ***************/
#define PTC_REG_CONTROLA   0x42004C00
#define PTC_BIT_ENABLE     0x02
#define PTC_BIT_RUNINSTBY  0x04


typedef union {
  struct {
    uint8_t   SWRESET:1;
    uint8_t   ENABLE:1;
    uint8_t   RUNINSTANDBY:1;
    uint8_t   __pad0__:5;
  } bit;
  uint8_t reg;
} PTC_REG_CONTROLA_Type;

/*************** CONTROL B register ***************/

#define PTC_REG_CONTROLB 0x42004C01
#define PTC_BIT_SYNCFLAG 0x80

typedef union {
  struct {
    uint8_t   __pad0__:7;
    uint8_t   SYNCFLAG:1;
  } bit;
  uint8_t reg;
} PTC_REG_CONTROLB_Type;

/*************** UNK4C04 register ***************/

#define PTC_REG_UNK4C04 0x42004C04

typedef union {
  uint8_t reg;
} PTC_REG_UNK4C04_Type;


/*************** CONTROL C register ***************/

#define PTC_REG_CONTROLC 0x42004C05
#define PTC_BIT_INIT 0x01

typedef union {
  struct {
    uint8_t   INIT:1;
    uint8_t   __pad0__:7;
  } bit;
  uint8_t reg;
} PTC_REG_CONTROLC_Type;



/*************** INT registers ***************/

typedef union {
  struct {
    uint8_t   EOC:1;
    uint8_t   WCO:1;
    uint8_t   __pad0__:6;
  } bit;
  uint8_t reg;
} PTC_REG_INT_Type;


#define PTC_REG_INTDISABLE 0x42004C08
#define PTC_REG_INTENABLE 0x42004C09
#define PTC_BIT_EOCINTEN  0x01
#define PTC_BIT_WCOINTEN  0x02

#define PTC_REG_INTFLAGS 0x42004C0A
#define PTC_BIT_EOCINTFLAG 0x01
#define PTC_BIT_WCOINTFLAG 0x02


/*************** FREQ CONTROL reg ***************/

typedef union {
  struct {
    uint8_t   SAMPLEDELAY:4;
    uint8_t   FREQSPREADEN:1;
    uint8_t   __pad0__:3;
  } bit;
  uint8_t reg;
} PTC_REG_FREQCONTROL_Type;

#define PTC_REG_FREQCONTROL 0x42004C0C
#define PTC_BIT_FREQSPREADEN 0x10
#define PTC_REG_SAMPLEDELAY_MASK 0x0F

/*************** CONVERT CONTROL reg ***************/

typedef union {
  struct {
    uint8_t   ADCACCUM:3;
    uint8_t   __pad0__:4;
    uint8_t   CONVERT:1;
  } bit;
  uint8_t reg;
} __attribute__ ((packed)) PTC_REG_CONVCONTROL_Type;


#define PTC_REG_CONVCONTROL 0x42004C0D
#define PTC_BIT_CONVSTARTED 0x80
#define PTC_REG_ADCACC_MASK 0x07


/*************** Y SELECT L+H reg ***************/

typedef union {
  struct {
    uint8_t   Y0:1;
    uint8_t   Y1:1;
    uint8_t   Y2:1;
    uint8_t   Y3:1;
    uint8_t   Y4:1;
    uint8_t   Y5:1;
    uint8_t   Y6:1;
    uint8_t   Y7:1;
  } bit;
  uint8_t reg;
} __attribute__ ((packed)) PTC_REG_YSELECTL_Type;

typedef union {
  struct {
    uint8_t   Y8:1;
    uint8_t   Y9:1;
    uint8_t   Y10:1;
    uint8_t   Y11:1;
    uint8_t   Y12:1;
    uint8_t   Y13:1;
    uint8_t   Y14:1;
    uint8_t   Y15:1;
  } bit;
  uint8_t reg;
} __attribute__ ((packed)) PTC_REG_YSELECTH_Type;

#define PTC_REG_YSELECT_L 0x42004C10
#define PTC_REG_YSELECT_H 0x42004C11

#define PTC_REG_YENABLE_L 0x42004C14
#define PTC_REG_YENABLE_H 0x42004C15


/*************** X SELECT L+H reg ***************/

typedef union {
  struct {
    uint8_t   X0:1;
    uint8_t   X1:1;
    uint8_t   X2:1;
    uint8_t   X3:1;
    uint8_t   X4:1;
    uint8_t   X5:1;
    uint8_t   X6:1;
    uint8_t   X7:1;
  } bit;
  uint8_t reg;
} __attribute__ ((packed)) PTC_REG_XSELECTL_Type;

typedef union {
  struct {
    uint8_t   X8:1;
    uint8_t   X9:1;
    uint8_t   X10:1;
    uint8_t   X11:1;
    uint8_t   X12:1;
    uint8_t   X13:1;
    uint8_t   X14:1;
    uint8_t   X15:1;
  } bit;
  uint8_t reg;
} __attribute__ ((packed)) PTC_REG_XSELECTH_Type;


#define PTC_REG_XSELECT_L 0x42004C12
#define PTC_REG_XSELECT_H 0x42004C13

#define PTC_REG_XENABLE_L 0x42004C16
#define PTC_REG_XENABLE_H 0x42004C17

/*************** Compensation Cap reg ***************/

typedef union {
  struct {
    uint8_t   VALUE:8;
  } bit;
  uint8_t reg;
} __attribute__ ((packed)) PTC_REG_COMPCAPL_Type;

typedef union {
  struct {
    uint8_t   VALUE:6;
    uint8_t   __pad0__:2;
  } bit;
  uint8_t reg;
} __attribute__ ((packed)) PTC_REG_COMPCAPH_Type;

#define PTC_REG_COMPCAPL    0x42004C18
#define PTC_REG_COMPCAPH    0x42004C19

/*************** Int Cap reg ***************/

typedef union {
  struct {
    uint8_t   VALUE:6;
    uint8_t   __pad0__:2;
  } bit;
  uint8_t reg;
} __attribute__ ((packed)) PTC_REG_INTCAP_Type;


#define PTC_REG_INTCAP    0x42004C1A

/*************** Series resistor reg ***************/

typedef union {
  struct {
    uint8_t   RESISTOR:2;
    uint8_t   __pad0__:6;
  } bit;
  uint8_t reg;
} __attribute__ ((packed)) PTC_REG_SERRES_Type;

#define PTC_REG_SERIESRES    0x42004C1B

/*************** conversion result reg ***************/

typedef union {
  struct {
    uint8_t   LOWBYTE;
    uint8_t   HIGHBYTE;
  } byte;
  uint16_t reg;
} __attribute__ ((packed)) PTC_REG_CONVRESULT_Type;

#define PTC_REG_CONVRESULT_L 0x42004C1C
#define PTC_REG_CONVRESULT_H 0x42004C1D

/*************** burst mode reg ***************/

typedef union {
  struct {
    uint8_t   __pad0__:2;
    uint8_t   CTSLOWPOWER:1;
    uint8_t   __pad1__:1;
    uint8_t   BURSTMODE:4;
  } bit;
  uint8_t reg;
} __attribute__ ((packed)) PTC_REG_BURSTMODE_Type;


#define PTC_REG_BURSTMODE     0x42004C20
#define PTC_REG_BURSTMODE_MASK   0xF0
#define PTC_BIT_CTSLOWPOWER   0x04

/*************** etc unused reg ***************/

#define PTC_REG_XYENABLE     0x42004C16
#define PTC_BIT_XYENABLE     0x02

#define PTC_REG_WCO_MODE     0x42004C21
#define PTC_REG_WCO_MODE_MASK   0x07

#define PTC_SET_WCO_THRESHHOLD_A_L 0x42004C24
#define PTC_SET_WCO_THRESHHOLD_A_H 0x42004C25
#define PTC_SET_WCO_THRESHHOLD_B_L 0x42004C26
#define PTC_SET_WCO_THRESHHOLD_B_H 0x42004C27



typedef struct {
  __IO PTC_REG_CONTROLA_Type CONTROLA;    // 0x42004C00
  __IO PTC_REG_CONTROLB_Type CONTROLB;    // 0x42004C01
  uint8_t   __pad4c02__;                // 0x42004C02 unknown
  uint8_t   __pad4c03__;                // 0x42004C03 unknown
  __IO PTC_REG_UNK4C04_Type  UNK4C04;   // 0x42004C04 unknown
  __IO PTC_REG_CONTROLC_Type CONTROLC;    // 0x42004C05
  uint8_t   __pad4c06__;                // 0x42004C06 unknown
  uint8_t   __pad4c07__;                // 0x42004C07 unknown
  __IO PTC_REG_INT_Type      INTDISABLE;  // 0x42004C08
  __IO PTC_REG_INT_Type      INTENABLE;   // 0x42004C09
  __I  PTC_REG_INT_Type      INTFLAGS;    // 0x42004C0A
  uint8_t   __pad4c0b__;                // 0x42004C0B unknown
  __IO PTC_REG_FREQCONTROL_Type FREQCONTROL;  //0x42004C0C
  __IO PTC_REG_CONVCONTROL_Type CONVCONTROL;  // 0x42004C0D
  uint8_t   __pad4c0e__;                // 0x42004C0E unknown
  uint8_t   __pad4c0f__;                // 0x42004C0F unknown
  __IO PTC_REG_YSELECTL_Type YSELECTL;  // 0x42004C10
  __IO PTC_REG_YSELECTL_Type YSELECTH;  // 0x42004C11
  __IO PTC_REG_XSELECTL_Type XSELECTL;  // 0x42004C12
  __IO PTC_REG_XSELECTL_Type XSELECTH;  // 0x42004C13
  __IO PTC_REG_YSELECTL_Type YENABLEL;  // 0x42004C14
  __IO PTC_REG_YSELECTL_Type YENABLEH;  // 0x42004C15
  __IO PTC_REG_XSELECTL_Type XENABLEL;  // 0x42004C16
  __IO PTC_REG_XSELECTL_Type XENABLEH;  // 0x42004C17

  __IO PTC_REG_COMPCAPL_Type COMPCAPL;  // 0x42004C18
  __IO PTC_REG_COMPCAPH_Type COMPCAPH;  // 0x42004C19
  __IO PTC_REG_INTCAP_Type   INTCAP;    // 0x42004C1A
  __IO PTC_REG_SERRES_Type   SERRES;    // 0x42004C1B

  __IO PTC_REG_CONVRESULT_Type RESULT;  // 0x42004C1C + 0x42004C1D
  uint8_t   __pad4c1e__;                // 0x42004C1E unknown
  uint8_t   __pad4c1f__;                // 0x42004C1F unknown
  __IO PTC_REG_BURSTMODE_Type BURSTMODE; // 0x42004C20
} Qtouch_Ptc;

#define QTOUCH_PTC  (( Qtouch_Ptc *)0x42004C00U)


#define PTC_REG_INTDISABLE 0x42004C08
#define PTC_REG_INTENABLE 0x42004C09
#define PTC_BIT_EOCINTEN  0x01
#define PTC_BIT_WCOINTEN  0x02

#define PTC_REG_INTFLAGS 0x42004C0A



/* Touch library oversampling (filter) setting */
typedef enum tag_oversample_level_t {
	OVERSAMPLE_1,
	OVERSAMPLE_2,
	OVERSAMPLE_4,
	OVERSAMPLE_8,
	OVERSAMPLE_16,
	OVERSAMPLE_32,
	OVERSAMPLE_64
}
oversample_t;

/* Touch library series resistor setting */
typedef enum tag_series_resistor_t {
	RESISTOR_0,
	RESISTOR_20K,
	RESISTOR_50K,
	RESISTOR_100K,
}
series_resistor_t;

typedef enum tag_freq_mode_t {
	FREQ_MODE_NONE,
	FREQ_MODE_HOP,
	FREQ_MODE_SPREAD,
	FREQ_MODE_SPREAD_MEDIAN
}
freq_mode_t;

typedef enum tag_freq_hop_t {
	FREQ_HOP_1,
	FREQ_HOP_2,
	FREQ_HOP_3,
	FREQ_HOP_4,
	FREQ_HOP_5,
	FREQ_HOP_6,
	FREQ_HOP_7,
	FREQ_HOP_8,
	FREQ_HOP_9,
	FREQ_HOP_10,
	FREQ_HOP_11,
	FREQ_HOP_12,
	FREQ_HOP_13,
	FREQ_HOP_14,
	FREQ_HOP_15,
	FREQ_HOP_16
}
freq_hop_t;



class Adafruit_CPlay_FreeTouch {
 public:
  Adafruit_CPlay_FreeTouch(int p = 0, oversample_t f = OVERSAMPLE_4, series_resistor_t r = RESISTOR_0, freq_mode_t fh = FREQ_MODE_NONE);
  bool begin(void);

  uint16_t measure(void);
  uint16_t measureRaw(void);

 private:
  void ptcInitSettings(void);
  void ptcConfigIOpin(void);
  uint16_t startPtcAcquire(void);

  void setupClock(void);
  int  getYLine(void);
  void selectYLine(void);
  void setOversampling(oversample_t lvl);
  void setSeriesResistor(series_resistor_t res);
  void setFreqHopping(freq_mode_t fh, freq_hop_t hops = FREQ_HOP_1);
  void setCompCap(uint16_t cc);
  void setIntCap(uint8_t ic);

  void runInStandby(boolean en);
  void enablePTC(boolean en);
  void enableWCOint(boolean en);
  void enableEOCint(boolean en);
  void clearWCOintFlag(void);
  void clearEOCintFlag(void);
  void ptcAcquire(void);
  void sync_config(void);

  // debugging helper!
  void snapshotRegsAndPrint(uint32_t base, uint8_t numregs);
  void printPTCregs(uint32_t base, uint8_t *regs, uint8_t num);
  void printHex(uint8_t h, boolean newline);


  int pin;           // arduino pin #
  int8_t yline;      // the Y select line (see datasheet)
  oversample_t oversample;
  series_resistor_t seriesres;
  freq_mode_t freqhop;
  freq_hop_t hops;
  uint16_t compcap;
  uint8_t  intcap;
};


#endif
#endif
