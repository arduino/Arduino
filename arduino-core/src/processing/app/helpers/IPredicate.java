package processing.app.helpers;

/**
 * Interface to perform the filtering elements
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 */
public interface IPredicate<T> { boolean apply(T element); }