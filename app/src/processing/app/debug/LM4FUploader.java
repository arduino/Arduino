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
		Target target = Base.getTarget();
		Collection params = new ArrayList();

		if (Base.isMacOS() || Base.isLinux()) {
			if ( Base.isLinux()) {
				params.add(buildPath + File.separator + className + ".bin");
			}
			else { 
				params.add(buildPath + File.separator + className + ".bin");
			}
			return mspdebug(params);
		} else {
			params.add(buildPath + File.separator + className + ".bin");
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
			commandDownloader.add(Base.getLM4FBasePath() + "lm4flash");
		} 
		else if (Base.isMacOS()) {
			commandDownloader.add(Base.getLM4FBasePath() + "lm4flash");
		}
		else {
			commandDownloader.add(Base.getLM4FBasePath() + "lm4flash");
		}
		commandDownloader.addAll(params);
		
		return executeUploadCommand(commandDownloader);
	}
}

