package cc.arduino.packages.autocomplete;

import br.com.criativasoft.cpluslibparser.metadata.TAttribute;

/**
 * Simple collections filter 
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 */
public class TAttributeFilter extends TElementFilter<TAttribute> {

  public TAttributeFilter(String text, int mathType) {
    super(text, mathType);
  }

}
