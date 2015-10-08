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

public class DSLiteUploader extends Uploader{
	public DSLiteUploader() {
	}
	public boolean uploadUsingPreferences(String buildPath, String className, boolean usingProgrammer)
	throws RunnerException, SerialException {
		this.verbose = verbose;
		Map<String, String> boardPreferences = Base.getBoardPreferences();
		Target target = Base.getTarget();
		Collection params = new ArrayList();

		params.add("load");
		if(Base.getArch() == "msp432") {
			params.add(Base.getToolsPath() + File.separator + "common" + File.separator + "DSLite" + File.separator + "MSP432P401R.ccxml");
		} else if (Base.getArch() == "cc2600emt") {
			params.add(Base.getToolsPath() + File.separator + "common" + File.separator + "DSLite" + File.separator + "CC2650F128_TIXDS110_Connection.ccxml");
		}

		if (Base.isMacOS() || Base.isLinux()) {
			if ( Base.isLinux()) {
				params.add(buildPath + File.separator + className + ".elf");
			}
			else { 
				params.add(buildPath + File.separator + className + ".elf");
			}
			return dslite(params);
		} else {
			params.add(buildPath + File.separator + className + ".elf");
			return dslite(params);
		}
	}

	public boolean burnBootloader() throws RunnerException {
		//nothing do do for MSP430
		return false;
	}

	public boolean dslite(Collection params) throws RunnerException {
		List commandDownloader = new ArrayList();

		if ( Base.isLinux()) {
			commandDownloader.add(Base.getToolsPath() + File.separator + "common" + File.separator + "DSLite" + 
				File.separator + "DebugServer" + File.separator + "bin" +File.separator + "DSLite"	);
		} 
		else if (Base.isMacOS()) {
			commandDownloader.add(Base.getToolsPath() + File.separator + "common" + File.separator + "DSLite" + 
					File.separator + "DebugServer" + File.separator + "bin" +File.separator + "DSLite"	);
		}
		else {
			commandDownloader.add(Base.getToolsPath() + File.separator + "common" + File.separator + "DSLite" + 
					File.separator + "DebugServer" + File.separator + "bin" +File.separator + "DSLite"	);
		}
		commandDownloader.addAll(params);
		
		return executeUploadCommand(commandDownloader);
	}
}

