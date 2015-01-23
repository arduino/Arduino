package cc.arduino.packages.autocomplete;

import processing.app.helpers.IPredicate;
import br.com.criativasoft.cpluslibparser.metadata.TElement;

/**
 * Simple collections filter 
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 */
public class TElementFilter<T extends TElement> implements IPredicate<T> {
  
  public static final int MATCH_START = 1;
  public static final int MATCH_CONTAINS = 2;
  public static final int MATCH_END = 3;
  
  private String text;
  
  private int mathType = MATCH_START;
  

  public TElementFilter(String text, int mathType) {
    super();
    this.text = text;
    this.mathType = mathType;
  }


  @Override
  public boolean apply(TElement node) {
    String name = node.name().toLowerCase();
    
    if(mathType == MATCH_START){
        return name.startsWith(text);
    }
    if(mathType == MATCH_CONTAINS){
      return name.contains(text);
    }
    if(mathType == MATCH_END){
      return name.endsWith(text);
    }
    
    return false;
  }
  

}
