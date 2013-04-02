/* -*- mode: jde; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  ************************************************************************
  *	C2000Uploader.java
  *
  *	abstract uploading baseclass for c2000
  *		Copyright (c) 2012 Trey German. All right reserved.
  *
  *
  ***********************************************************************
  Derived from:
  Uploader - abstract uploading baseclass (common to both uisp and avrdude)
  Part of the Arduino project - http://www.arduino.cc/

  Copyright (c) 2004-05
  Hernando Barragan

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  
  $Id$
*/
package processing.app.debug;

import processing.app.Base;
import processing.app.Preferences;
import processing.app.Serial;
import processing.app.SerialException;

import java.io.*;
import java.util.*;
import java.util.zip.*;
import javax.swing.*;
import gnu.io.*;

public class C2000Uploader extends Uploader{
	public C2000Uploader() {
	}
	public boolean uploadUsingPreferences(String buildPath, String className, boolean usingProgrammer)
	throws RunnerException, SerialException {
		this.verbose = verbose;
		Map<String, String> boardPreferences = Base.getBoardPreferences();
		//No serial programming support (yet). 
		//Upload using programmer (MSP430Flasher for windows and mspdebug for Mac OS X and Linux).
		//added support for mspdebug for windows 

		Target target = Base.getTarget();
		Collection params = new ArrayList();

		if (Base.isMacOS() || Base.isLinux()) {
			params.add(boardPreferences.get("upload.protocol"));
			if(!Preferences.getBoolean("upload.verbose"))
				params.add("-q");
			params.add("--force-reset");
			if ( Base.isLinux()) {
				params.add("prog " + buildPath + File.separator + className + ".hex");
			}
			else { 
				params.add("prog " + buildPath + File.separator + className + ".hex");
			}
			return mspdebug(params);
		} else {
/*			// code to access via MSP430_Flasher	
			params.add("-n " + boardPreferences.get("build.mcu")); 
			params.add("-w");
			params.add(buildPath + File.separator + className + ".hex");
			params.add("-g");
			if(!Preferences.getBoolean("upload.verbose"))
					params.add("-q");
			
			params.add("-z[VCC]");
			return MSP430Flasher(params);
*/			
//			params.add(boardPreferences.get("upload.protocol"));
			params.add("tilib");       // always use the TI Lib on Windows, best integrate on this OS
			params.add("-d");
			params.add("USB");
			if(!Preferences.getBoolean("upload.verbose"))
				params.add("-q");
			params.add("--force-reset");
			params.add("\"prog " + buildPath + File.separator + className + ".hex\"");
			return mspdebug(params);
		}
	}

	public boolean burnBootloader() throws RunnerException {
		//nothing do do for MSP430
		return false;
	}

	public boolean mspdebug(Collection params) throws RunnerException {
		List commandDownloader = new ArrayList();

		if ( Base.isLinux()) {
			commandDownloader.add(Base.getMSP430BasePath() + "mspdebug"); // tools/msp430/bin or one from PATH
		} 
		else if (Base.isMacOS()) {
			commandDownloader.add(Base.getHardwarePath() + "/tools/msp430/mspdebug/mspdebug");
		}
		else {
			commandDownloader.add(Base.getHardwarePath() + "\\tools\\msp430\\mspdebug\\mspdebug");
		}
		commandDownloader.addAll(params);
		
		return executeUploadCommand(commandDownloader);
	}
	
	public boolean MSP430Flasher(Collection params) throws RunnerException {
		List commandDownloader = new ArrayList();

		commandDownloader.add(Base.toShortPath(Base.getHardwarePath()) + "\\tools\\msp430\\MSP430Flasher\\" + "MSP430Flasher.exe");
		commandDownloader.addAll(params);
		
		return executeUploadCommand(commandDownloader);
	}
}
