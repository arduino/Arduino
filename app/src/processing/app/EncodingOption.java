package processing.app;

import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

/**
 * Represents the encoding option for decoding or encoding bytes that are
 * read from or written to a stream.
 */
public enum EncodingOption {

  /**
   * The system default character set as returned by
   * {@link Charset#defaultCharset()}.
   */
  SYSTEM_DEFAULT(Charset.defaultCharset()),
  
  /**
   * Comma separated unsigned byte representation.
   */
  BYTES(null),
  
  UTF_8(StandardCharsets.UTF_8),
  UTF_16(StandardCharsets.UTF_16),
  UTF_16BE(StandardCharsets.UTF_16BE),
  UTF_16LE(StandardCharsets.UTF_16LE),
  ISO_8859_1(StandardCharsets.ISO_8859_1),
  US_ASCII(StandardCharsets.US_ASCII);

  private final Charset charset;

  private EncodingOption(Charset charset) {
    this.charset = charset;
  }

  public Charset getCharset() {
    return this.charset;
  }

  @Override
  public String toString() {
    switch (this) {
      case SYSTEM_DEFAULT:
      case BYTES:
        return this.name().replace('_', ' ').toLowerCase();
      default:
        return this.charset.name();
    }
  }

  /**
   * Gets the {@link EncodingOption} with the given name.
   * The name match is case-insensitive and
   * whitespaces/dashes are interpreted as '_'.
   * @param name - The name of the {@link EncodingOption}.
   * @return The matching {@link EncodingOption}
   * or null when no such option exists.
   */
  public static EncodingOption forName(String name) {
    if (name == null) {
      return null;
    }
    try {
      return EncodingOption.valueOf(
          name.replace(' ', '_').replace('-', '_').toUpperCase());
    } catch (IllegalArgumentException e) {
      return null;
    }
//    name = name.replace(' ', '_').replace('-', '_');
//    for (EncodingOption option : EncodingOption.values()) {
//      if (option.name().equalsIgnoreCase(name)) {
//        return option;
//      }
//    }
//    return null;
  }
}