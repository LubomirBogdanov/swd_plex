Description  
===================================================================   
The project aims at flashing multiple ARM-based microcontrollers  
over a single SWD interface.  
  
SWCLK and RST of each target can be paralleled, while each SWDIO  
should have a separate line. Connect each line at the swd_plex  
hardware tool, whose circuit diagram is given in this project as  
well as the firmware for the microcontroller it uses.  

Send commands over the UART (or RS232) as a number between 0 and 9  
in ASCII (0x30 - 0x39 in raw format). Do not append newline or a  
carriage return. If the command is accepted, the red LED will  
continue to be turned on. If the command is rejected, the LED will  
turn off until a valid command is sent.  
Every command will be echoed back. Ensure that the sent and the  
received commands match. If they don't - there's an problem with  
the communication over the UART (or RS232).  

!!! NOTE: the default UART settings are 2400-8-E-1 !!!  


INSTALL  
===================================================================
If you want to modify the firmware of the multiplexer, either  
import it in Texas Instruments' Code Composer Studio or build it  
from the command line. In either case, use GCC (msp430-elf-gcc) with  
mspdebug (set in ./swd_muliplexer_src/Makefile).  

Take a look at the top-level Makefile (./Makefile) of this project -  
it is an example Makefile for Linux (tested on Ubuntu 18.04) to flash  
NXP's LPC810 microcontrollers (tested on 8-pin DIP package, 10 targets).  
You can flash and debug (with MCUXpresso) only one target at a time!  
  
Example usage  
===================================================================
Build the circuit shown in ./swd_muliplexer_src/sch.  
Flash the code of the MSP430G2101 (./swd_muliplexer_src/gcc/main.elfgcc/main.elf  
or ./swd_muliplexer_src/gcc/main.a43) with the help of the MSP430G2 LaunchPad  
or any other debugger that supports the Texas Instruments' SBW interface. The  
SBW connector is J3.  
Build a system with up to 10 ARM Cortex targets (any ARM-based microcontroller  
should work).
Modify the multi-target Makefile (in the top-level directory of this project) to  
suit your needs. From a command line the following invokations are available  
(N = 0 - 9).  
  
- To build target firmware for microcontroller N:  

<b>make MCU_INDEX=N</b>  

- To flash microcontroller number N:  

<b>make flash MCU_INDEX=N</b>  

- To flash all the microcontrollers in range 0 - 9:  

<b>make flash_all</b>  

- To switch the multiplexer to target N but without flashing it:  

<b>make multiplex MCU_INDEX=N</b>  

- To build and flash microcontrollers in range ${PROC_LIST} with an  
empty main file with an endless loop:  

<b>make empty PROC_LIST=”0 1 2 3 4 5 6 7 8 9”</b>  

- To delete the target directory, here named gcc:  

<b>make clean</b>  

 - To show the size of the current object file of microcontroller N:  

<b>make size MCU_INDEX=N</b>  

<i>Note: the makefile uses "echo" and "stty" to configure the serial port. You must  
ensure that they are installed before invoking any flash command.</i> 


