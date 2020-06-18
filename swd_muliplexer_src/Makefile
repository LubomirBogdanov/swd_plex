#    Copyright (C) 2020 Lubomir Bogdanov
#    Contributor Lubomir Bogdanov <lbogdanov@tu-sofia.bg>
#    This file is part of swd_plex.
#    swd_plex is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#    swd_plex is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.
#    You should have received a copy of the GNU Lesser General Public License
#    along with swd_plex.  If not, see <http://www.gnu.org/licenses/>.

#The name of the top-level source file
PROJECT         = main
#Add additional files here. The ${PROJECT}.c should be at the end.
SRC		= ${PROJECT}.c
#The name of the directory with the output files
OUTDIR		= gcc
OBJ		= ${SRC:%.c=${OUTDIR}/%.o}
#Toolchain prefix
TOOLCHAIN	= msp430-elf
#Instruction sets:  430(msp430), 430x(mdsp430x), 430xv2(msp430xv2)
#CPU		= 430
#Target microcontroller
MCU             = msp430g2101
CC              = ${TOOLCHAIN}-gcc
LD		= ${TOOLCHAIN}-ld
OBJCOPY		= ${TOOLCHAIN}-objcopy
OBJDUMP		= ${TOOLCHAIN}-objdump
SIZE		= ${TOOLCHAIN}-size
IPATH		= /home/user/ti/msp430-gcc/include
OPTFLAGS	= -Os
DEBUGFLAGS	= -ggdb
CFLAGS          = -mmcu=${MCU} ${OPTFLAGS} ${DEBUGFLAGS} -std=gnu99 -Wall -ffunction-sections -fdata-sections -I${IPATH}
LDFLAGS		= -Wl,-gc-sections
OBJDUMPFLAGS	= -D -S
SIZEFLAGS	= -d
OBJCOPYFLAGS	= -O ihex
FLASHCMD	= mspdebug
FLASHCMDFLAGS	= rf2500 "prog ${OUTDIR}/${PROJECT}.elf" "verify ${OUTDIR}/${PROJECT}.elf" "reset"
RESETCMDFLAGS	= rf2500 "reset"

all: ${OUTDIR} ${OUTDIR}/${PROJECT}.elf ${OUTDIR}/${PROJECT}.lst size ${OUTDIR}/${PROJECT}.a43
flash_device: flash

${OUTDIR}:
	@mkdir -p ${OUTDIR}
	
${OUTDIR}/${PROJECT}.elf: ${SRC}
	${CC} ${CFLAGS} ${LDFLAGS} -o ${OUTDIR}/${PROJECT}.elf ${SRC}
	
${OUTDIR}/${PROJECT}.lst: 
	${OBJDUMP} ${OBJDUMPFLAGS} ${OUTDIR}/${PROJECT}.elf > ${OUTDIR}/${PROJECT}.lst

size:
	${SIZE} ${SIZEFLAGS} ${OUTDIR}/${PROJECT}.elf
	
${OUTDIR}/${PROJECT}.a43:
	${OBJCOPY} ${OBJCOPYFLAGS} ${OUTDIR}/${PROJECT}.elf ${OUTDIR}/${PROJECT}.a43

flash:
	${FLASHCMD} ${FLASHCMDFLAGS}
reset:
	${FLASHCMD} ${RESETCMDFLAGS}

clean:
	rm -r ${OUTDIR} 
