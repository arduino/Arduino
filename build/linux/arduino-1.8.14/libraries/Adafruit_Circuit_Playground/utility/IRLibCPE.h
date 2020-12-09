/* IRLibCPE.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * Combines all of the necessary libraries for implementing IR transmit and receive
 *  on the Adafruit Circuit Playground Express. Similar to the IRLibAll.h in the
 *  regular IRLib2.xx.
 */

#ifndef IRLIB_CPE_H
#define IRLIB_CPE_H
#include "IRLibDecodeBase.h"
#include "IRLibSendBase.h"
#include "IRLib_P01_NEC.h"
#include "IRLib_P02_Sony.h"
#include "IRLib_P03_RC5.h"
#include "IRLib_P04_RC6.h"
#include "IRLib_P05_Panasonic_Old.h"
#include "IRLib_P06_JVC.h"
#include "IRLib_P07_NECx.h"
#include "IRLib_P08_Samsung36.h"
#include "IRLib_P09_GICable.h"
#include "IRLib_P10_DirecTV.h"
#include "IRLib_P11_RCMM.h"
#include "IRLib_P12_CYKM.h"
//include additional protocols here
#include "IRLibCombo.h"
#include "IRLibRecvPCI.h"
#endif //IRLIB_CPE_H
