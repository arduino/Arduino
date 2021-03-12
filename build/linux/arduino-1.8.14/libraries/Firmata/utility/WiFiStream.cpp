/*
 * Implementation is in WiFiStream.h to avoid linker issues. Legacy WiFi and modern WiFi101 both define WiFiClass which
 * will cause linker errors whenever Firmata.h is included.
 */
