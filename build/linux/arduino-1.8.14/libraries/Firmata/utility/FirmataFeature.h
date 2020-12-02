/*
  FirmataFeature.h
  Copyright (C) 2006-2008 Hans-Christoph Steiner.  All rights reserved.
  Copyright (C) 2010-2011 Paul Stoffregen.  All rights reserved.
  Copyright (C) 2009 Shigeru Kobayashi.  All rights reserved.
  Copyright (C) 2013 Norbert Truchsess. All rights reserved.
  Copyright (C) 2009-2016 Jeff Hoefs.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  Interface for Firmata feature classes.

  This version of FirmataFeature.h differs from the ConfigurableFirmata
  version in the following ways:

  - Imports Firmata.h rather than ConfigurableFirmata.h

  See file LICENSE.txt for further informations on licensing terms.
*/

#ifndef FirmataFeature_h
#define FirmataFeature_h

#include <Firmata.h>

class FirmataFeature
{
  public:
    virtual void handleCapability(byte pin) = 0;
    virtual boolean handlePinMode(byte pin, int mode) = 0;
    virtual boolean handleSysex(byte command, byte argc, byte* argv) = 0;
    virtual void reset() = 0;
};

#endif
