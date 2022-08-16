#include <stdio.h>
#include <strings.h>

#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>


int main() 
{
    char devicePath[] = "/dev/tty.usbserial-110";
    int serial_port = open(devicePath, O_RDONLY | O_NONBLOCK);

    struct termios tty;

    if(tcgetattr(serial_port, &tty) != 0)
    {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
        return 1;
    }

    //Set control modes
    tty.c_cflag &= ~PARENB;         //parity disable 
    tty.c_cflag &= ~CSTOPB;         //send one stopbit
    tty.c_cflag &= ~CSIZE;          //character size reset
    tty.c_cflag |= CS8;             //8-bit length of data
    tty.c_cflag &= ~CRTSCTS;         //disable cts/rts
    tty.c_cflag |= CREAD | CLOCAL;  //reciever enable & ignore status lines

    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO; // Disable echo
    tty.c_lflag &= ~ECHOE; // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes



    //Configure read & timeout behaviour --> configured so that read() always directly returns what is aviable
    tty.c_cc[VTIME] = 10;
    tty.c_cc[VMIN] = 0;

    //Configure baud rate
    cfsetispeed(&tty, B9600);

    //save settings 
    if(tcsetattr(serial_port, TCSANOW, &tty) != 0)
    {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }

    int arr[256];

    while(1)
    {
        size_t nrOfBytes = read(serial_port, &arr, sizeof(arr));
        printf("%zu %i\n", nrOfBytes, arr[0]);
    }

}