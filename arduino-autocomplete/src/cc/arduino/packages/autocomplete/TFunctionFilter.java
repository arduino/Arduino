package cc.arduino.packages.autocomplete;

import br.com.criativasoft.cpluslibparser.metadata.TFunction;

/**
 * Simple collections filter 
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 */
public class TFunctionFilter extends TElementFilter<TFunction>{

  public TFunctionFilter(String text, int mathType) {
    super(text, mathType);
  }

}
