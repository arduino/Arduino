#ifndef sci_isr_handler_h
#define sci_isr_handler_h



#ifdef __cplusplus
extern "C" {
#endif
void uart_tx_isr(void);
void uart_rx_isr(void);
void i2c_txrx_isr(void);
void i2c_state_isr(void);
void sci_isr_install(void);
#ifdef __cplusplus
}
#endif

#endif /* sci_isr_handler_h */
