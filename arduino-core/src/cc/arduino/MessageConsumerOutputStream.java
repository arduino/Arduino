package cc.arduino;

import processing.app.debug.MessageConsumer;

import java.io.ByteArrayOutputStream;

public class MessageConsumerOutputStream extends ByteArrayOutputStream {

  private final MessageConsumer consumer;
  private final String lineSeparator;

  public MessageConsumerOutputStream(MessageConsumer consumer) {
    this(consumer, System.getProperty("line.separator"));
  }

  public MessageConsumerOutputStream(MessageConsumer consumer, String lineSeparator) {
    this.consumer = consumer;
    this.lineSeparator = lineSeparator;
  }

  @Override
  public void write(byte[] b, int off, int len) {
    super.write(b, off, len);

    flush();
  }

  @Override
  public void flush() {
    String asString = toString();
    if (!asString.contains(lineSeparator)) {
      return;
    }

    while (asString.contains(lineSeparator)) {
      String line = asString.substring(0, asString.indexOf(lineSeparator));
      reset();
      byte[] bytes = asString.substring(asString.indexOf(lineSeparator) + lineSeparator.length()).getBytes();
      super.write(bytes, 0, bytes.length);
      asString = toString();

      consumer.message(line);
    }

  }
}
