 package processing.app.tools.jexplorer.utils;

import java.io.File;

import java.io.FileFilter;


public class AcceptAllFileFilter implements FileFilter {

    public boolean accept(File f) {
        return true;
    }

}
