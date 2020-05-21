package processing.app.helpers.filefilters;

import java.io.File;

public class ExamplesFilter extends OnlyDirs {

    
    @Override
    public boolean accept( File dir , String name ) {
        
        if(!super.accept(dir, name)) return false;
        
        return name.equalsIgnoreCase("example") || name.equalsIgnoreCase("examples")  ;
    }

}
