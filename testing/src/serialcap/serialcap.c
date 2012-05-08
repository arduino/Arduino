#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/param.h>

#define TIMEOUT 60
#define BAUDRATE B9600
  
#define _POSIX_SOURCE 1 /* POSIX compliant source */
#define FALSE 0
#define TRUE 1
  
volatile int STOP=FALSE; 
  
void signal_handler_IO (int status);   /* definition of signal handler */
speed_t convert_baud (char *baudstring);    /* convert string baud rate to bit pattern */
int wait_flag=TRUE;                    /* TRUE while no signal received */
  
int main(int argc, char** argv)
{
  int fd, c, res;
  char *ctl;
  struct termios oldtio,newtio;
  struct sigaction saio;           /* definition of signal action */
  char buf[255];
  char device[MAXPATHLEN];
  int errno = 0;
  speed_t baud;

  /* if first command line arg exists then it is the serial device to use */
  if ( argv[1] != NULL ) {
    strncpy(device, argv[1], MAXPATHLEN - 1);
  } else {
    fprintf(stderr,"usage: serialcap <device> [baud]\n");
    exit(-1);
  }

  /* second command line arg is baud (if it exists) */
  argv[2] != NULL ? (baud = convert_baud(argv[2])) : (baud = BAUDRATE);

  /* open the device to be non-blocking (read will return immediatly) */
  fd = open(device, O_RDONLY | O_NOCTTY | O_NONBLOCK);
  if (fd <0) {perror(device); exit(-1); }
  
  /* install the signal handler before making the device asynchronous */
  saio.sa_handler = signal_handler_IO;
  sigemptyset(&saio.sa_mask);
  saio.sa_flags = 0;
  saio.sa_restorer = NULL;
  sigaction(SIGIO,&saio,NULL);
    
  /* allow the process to receive SIGIO */
  fcntl(fd, F_SETOWN, getpid());

  /* Make the file descriptor asynchronous (the manual page says only 
     O_APPEND and O_NONBLOCK, will work with F_SETFL...) */
  fcntl(fd, F_SETFL, FASYNC);
  
  tcgetattr(fd,&oldtio); /* save current port settings */
  /* set new port settings for non-canonical input processing */
  newtio.c_cflag = baud | CS8 | CLOCAL | CREAD;
  newtio.c_iflag = IGNPAR | ICRNL;
  newtio.c_oflag = 0;
  newtio.c_lflag &= ~(ICANON|ECHO);
  newtio.c_cc[VMIN]=1;
  newtio.c_cc[VTIME]=0;
  tcflush(fd, TCIFLUSH);
  tcsetattr(fd,TCSANOW,&newtio);

  // No buffering on output
  setvbuf(stdout, NULL, _IONBF, 0);
   
  /* loop while waiting for input. normally we would do something
     useful here */ 
  while (STOP==FALSE) {
    /* wait until TIMEOUT seconds for new input, SIGIO will interupt this */
    sleep(TIMEOUT);
    /* after receiving SIGIO, wait_flag = FALSE, input is available
       and can be read */
    if (wait_flag==FALSE) { 
      res = read(fd,buf,255);
      buf[res]=0;

      /* check for ^d and ^z, replace 1st with null, let it print, then exit; */
      if (ctl = strchr(buf, 0x04)) {
	*ctl = 0;
        STOP=TRUE;
      }
      if (ctl = strchr(buf, 0x1A)) {
	*ctl = 0;
        STOP=TRUE;
      }

      printf("%s", buf);
      wait_flag = TRUE;      /* wait for new input */
    } else {
      STOP=TRUE;
      errno = 1;
    }
  }
  /* restore old port settings */
  tcsetattr(fd,TCSANOW,&oldtio);
  exit(errno);
}
  
/***************************************************************************
* signal handler. sets wait_flag to FALSE, to indicate above loop that     *
* characters have been received.                                           *
***************************************************************************/
  
void signal_handler_IO (int status)
{
  wait_flag = FALSE;
}

// setbaud(char* baudstring)
// convert string baud to proper bit pattern

speed_t convert_baud(char *baudstring)
{
  fprintf(stderr, "convert_ baud not finished\n");
  return BAUDRATE;
}
