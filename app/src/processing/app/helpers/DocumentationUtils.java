package processing.app.helpers;

import static processing.app.I18n._;

import java.io.File;
import java.io.IOException;
import java.net.URL;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.select.Elements;

import processing.app.Base;
import processing.app.I18n;
import processing.app.syntax.PdeKeywords;

public class DocumentationUtils {
  
  public static boolean useDefaultBigHtmlHelp = true; // TODO: remove latter ! 
  
  /**
   * 
   * @param Classname (optinal)
   * @param function (optinal)
   * @return
   */
  public static String getDocumentationURL(String Classname, String function){
    
    // get referencens indexed from keywords.txt
    String reference = PdeKeywords.getReference(Classname);
    if(reference == null) return null;
      
    reference = I18n.format(_("{0}.html"), reference);
    
    File referenceFolder = Base.getContentFile("reference");
    File referenceFile = new File(referenceFolder, reference);
    
    return referenceFile.getAbsolutePath();
  }
  
  public static String getDocumentation(String Classname, String function){
      String url = getDocumentationURL(Classname, function);
      
      if(url == null || url.trim().length() == 0) return null;
      
      Document doc;
      try {
        doc = Jsoup.parse(new File(url), "UTF-8");
        Elements docElemets = doc.select("#wikitext > table > tbody > tr > td:nth-child(1)");
        if(docElemets.isEmpty()) docElemets = doc.select("#wikitext");
        
        Elements styles =  doc.select("style");
        
        String html = docElemets.html();
        StringBuilder sb = new StringBuilder(html.length());
        
          // Load and display specified page.
        sb.append("<html><head>").append(styles.outerHtml()).append("</head>");
        sb.append("<body>").append(docElemets.html()).append("</body></html>");
        return sb.toString();
      } catch (IOException e) {
        e.printStackTrace();
      }

      
      return null;
      
  }


}
