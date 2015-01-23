package processing.app.helpers;

import java.util.ArrayList;
import java.util.Collection;

/**
 * Utility to filter elements based on predicates
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 */
public class Predicate {
  
  public static <T> Collection<T> filter(Collection<? extends T> list, IPredicate<T> predicate) {
      Collection<T> result = new ArrayList<T>();
      return filter(list, predicate, result);
  }
  
  public static <T> Collection<T> filter(Collection<? extends T> list, IPredicate<T> predicate, Collection<T> target) {
    for (T element : list) {
        if (predicate.apply(element)) {
          target.add(element);
        }
    }
    return target;
}
  
  public static <T> T select(Collection<? extends T> target, IPredicate<T> predicate) {
      T result = null;
      for (T element : target) {
          if (!predicate.apply(element))
              continue;
          result = element;
          break;
      }
      return result;
  }
  
  public static <T> T select(Collection<? extends T> target, IPredicate<T> predicate, T defaultValue) {
      T result = defaultValue;
      for (T element : target) {
          if (!predicate.apply(element))
              continue;
          result = element;
          break;
      }
      return result;
  }
}
