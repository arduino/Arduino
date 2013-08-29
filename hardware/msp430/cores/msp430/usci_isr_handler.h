#ifndef usci_isr_handler_h
#define usci_isr_handler_h

#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_A0__) || defined(__MSP430_HAS_USCI_A1__) \
 || defined(__MSP430_HAS_EUSCI_A0__)|| defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__) 

typedef void CHardwareSerial;
#ifdef __cplusplus
extern "C" {
#endif
void uart_tx_isr(uint8_t offset);
void uart_rx_isr(uint8_t offset);
void i2c_txrx_isr(void);
void i2c_state_isr(void);
void usci_isr_install(void);
#ifdef __cplusplus
}
#endif
#endif /* __MSP430_HAS_USCI__ */
#endif /* usci_isr_handler_h */
