/* -*- mode: jde; c-basic-offset: 2; indent-tabs-mode: nil -*- */

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

public class LM4FUploader extends Uploader{
	public LM4FUploader() {
	}
	public boolean uploadUsingPreferences(String buildPath, String className, boolean usingProgrammer)
	throws RunnerException, SerialException {
		this.verbose = verbose;
		Map<String, String> boardPreferences = Base.getBoardPreferences();
		//No serial programming support (yet). 
		//Upload using programmer (LMFlasher for windows and openocd for Mac OS X and Linux).
		//added support for openocd for windows 

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
			//Standard cmd.exe call: lmflash -q ek-lm4f232 -v -r qs-rgb.bin
			// code to access via LM4F_Flasher
			params.add("-q" + boardPreferences.get("build.mcu"));
			params.add("-v");
			params.add("-r");
			//params.add("-w");
			params.add(buildPath + File.separator + className + ".hex");
			/*params.add("-g");
			if(!Preferences.getBoolean("upload.verbose"))
					params.add("-q");
			
			params.add("-z[VCC]");*/
			return LMFlasher(params);
			
//			params.add(boardPreferences.get("upload.protocol"));
/*			params.add("tilib");       // always use the TI Lib on Windows, best integrate on this OS
			params.add("-d");//specifies that the driver should connect via a tty device rather than USB
			params.add("USB");
			if(!Preferences.getBoolean("upload.verbose"))
				params.add("-q"); //quiet mode
			params.add("--force-reset");
			params.add("\"prog " + buildPath + File.separator + className + ".hex\"");
			return mspdebug(params);*/
		}
	}

	public boolean burnBootloader() throws RunnerException {
		//nothing do do for MSP430
		return false;
	}

	public boolean mspdebug(Collection params) throws RunnerException {
		List commandDownloader = new ArrayList();

		if ( Base.isLinux()) {
			commandDownloader.add(Base.getLM4FBasePath() + "lm4f"); // tools/msp430/bin or one from PATH
		} 
		else if (Base.isMacOS()) {
			commandDownloader.add(Base.getHardwarePath() + "/tools/lm4f/openocd/openocd");
		}
		else {
			commandDownloader.add(Base.getHardwarePath() + "\\tools\\lm4f\\openocd\\openocd");
		}
		commandDownloader.addAll(params);
		
		return executeUploadCommand(commandDownloader);
	}
	
	public boolean LMFlasher(Collection params) throws RunnerException {
		List commandDownloader = new ArrayList();

		commandDownloader.add(Base.toShortPath(Base.getHardwarePath()) + "\\tools\\lm4f\\LMFlasher\\" + "LMFlash.exe");
		commandDownloader.addAll(params);
		
		return executeUploadCommand(commandDownloader);
	}
}

