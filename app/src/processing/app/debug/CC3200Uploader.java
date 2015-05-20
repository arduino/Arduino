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

public class CC3200Uploader extends Uploader{
	public CC3200Uploader() {
	}
	public boolean uploadUsingPreferences(String buildPath, String className, boolean usingProgrammer)
	throws RunnerException, SerialException {
		this.verbose = verbose;
		Map<String, String> boardPreferences = Base.getBoardPreferences();
		Target target = Base.getTarget();
		Collection params = new ArrayList();

		String uploadPort = Preferences.get("serial.port");
		String variant = boardPreferences.get("build.variant");
		
		if (Base.isMacOS() || Base.isLinux()) {
			params.add(uploadPort);
			if ( Base.isLinux()) {
				params.add(buildPath + File.separator + className + ".bin");
			}
			else { 
				params.add(buildPath + File.separator + className + ".bin");
			}
		} else {
			params.add(uploadPort.substring(3));
			params.add(buildPath + File.separator + className + ".bin");
		}

		if(variant.contains("RedBearLab"))
			params.add("h");

		return cc3200prog(params);
	}

	public boolean burnBootloader() throws RunnerException {
		//nothing do do for MSP430
		return false;
	}

	public boolean cc3200prog(Collection params) throws RunnerException {
		List commandDownloader = new ArrayList();

		if ( Base.isLinux()) {
			commandDownloader.add(Base.getLM4FBasePath() + "cc3200prog");
		} 
		else if (Base.isMacOS()) {
			commandDownloader.add(Base.getLM4FBasePath() + "cc3200prog");
		}
		else {
			commandDownloader.add(Base.getLM4FBasePath() + "cc3200prog");
		}
		commandDownloader.addAll(params);
		
		return executeUploadCommand(commandDownloader);
	}
}

