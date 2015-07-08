/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Ricardo JL Rufino (ricardo@criativasoft.com.br)
 * Copyright 2015 Arduino LLC
 *
 * Arduino is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As a special exception, you may use this file as part of a free software
 * library without restriction.  Specifically, if other files instantiate
 * templates or use macros or inline functions from this file, or you compile
 * this file and link it with other files to produce an executable, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU General Public License.  This exception does not however
 * invalidate any other reasons why the executable file might be covered by
 * the GNU General Public License.
 */
package cc.arduino.packages.autocomplete.template;

import java.io.File;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;

import org.fife.ui.autocomplete.BasicCompletion;
import org.fife.ui.autocomplete.Completion;
import org.fife.ui.autocomplete.CompletionProvider;

import br.com.criativasoft.cpluslibparser.LibraryIndex;
import br.com.criativasoft.cpluslibparser.metadata.TLibrary;
import processing.app.BaseNoGui;
import processing.app.helpers.filefilters.OnlyFilesWithExtension;
import processing.app.packages.LibraryList;
import processing.app.packages.UserLibrary;
import cc.arduino.packages.autocomplete.SketchCompletionProvider;
import cc.arduino.packages.autocomplete.TemplateChoicesCompletion;

public class IncludeTemplate extends TemplateChoicesCompletion {

  public IncludeTemplate(CompletionProvider provider) {
    super(provider, "#include", "#include <>", "#include ${<}");
  }

  @Override
  public List<Completion> getChoices(Parameter param) {
      List<Completion> completions = new LinkedList<Completion>();
      
      LibraryList libraries = BaseNoGui.getLibraries();
      for (UserLibrary library : libraries) {
        completions.add(new IncludeCompletion(getProvider(), library));
      }
      
      // Get files from Sketch folder.
      Collection<TLibrary> libs = LibraryIndex.getLibraries().values();
      for (TLibrary tLibrary : libs) {
    	 if(tLibrary.getName().startsWith(SketchCompletionProvider.SKETCH_LIB_PREFIX)){
    		 File folder = new File(tLibrary.getLocation().getPath());
    		 File[] listOfFiles = folder.listFiles(new OnlyFilesWithExtension(".h"));
    		 if (listOfFiles != null) {
    			 for (int i = 0; i < listOfFiles.length; i++) {
    				 completions.add(new BasicCompletion(getProvider(), "\""+listOfFiles[i].getName()+"\""));
				}
			}
    	 }
      }
      
      return completions;
  }
  
  private static class IncludeCompletion extends BasicCompletion{
	  
	private UserLibrary library;
	
	public IncludeCompletion(CompletionProvider provider, UserLibrary library) {
		super(provider, library.getInstalledFolder().getName());
		this.library = library;
	}

	@Override
	public String getSummary() {
		return library.getSentence();
	}
	
	@Override
	public String getShortDescription() {
		return library.getName();
	}
	
	@Override
	public String getReplacementText() {
		return "<"+library.getInstalledFolder().getName()+".h>";
	}
	  
  }

}
