; ---------------------------------------------------------------------------
;
; Rockwell AIM-65 definitions
;
; ---------------------------------------------------------------------------

RAMSTART := $0200     ; Entry point

; Monitor variables
UIN     := $0108   ; 2 bytes, Vector to User Input Handler
UOUT    := $010A   ; 2 bytes, Vector to User Output Handler
KEYF1   := $010C   ; 3 bytes, JMP to User Function 1
KEYF2   := $010C   ; 3 bytes, JMP to User Function 2
KEYF3   := $010C   ; 3 bytes, JMP to User Function 3
IRQV4   := $A400   ; 2 bytes, Vector to IRQ after Monitor
                                ;          Interrupt Routine
NMIV2   := $A402   ; 2 bytes, Vector to NMI Interrupt Routine
IRQV2   := $A404   ; 2 bytes, Vector to IRQ Interrupt Routine
DILINK  := $A406   ; 2 bytes, Vector to Display Routine
TSPEED  := $A408   ; 1 byte, Audio Tape Speed
                   ;         Default = $C7 (AIM 65)
                   ;         Options = $5A (KIM-1 x 1)
                   ;         Options = $5B (KIM-1 x 3)
GAP     := $A409   ; 1 byte, Audio Tape Gap
                   ;         Default = $08 (32 SYN characters)
                   ;         Option  = $80 (for Assembler input & Editor update)
INFLG   := $A412   ; 1 byte, Active Input Device
                   ;         $0D (ASCII Return) Read from keyboad or TTY
                   ;         'T' Read from tape
                   ;         'K' Read from tape in KIM-1 format
                   ;         'M' Read from editor buffer in memory
                   ;         'U' Read from user defined routine
                   ;         'L' Read from PPR tape (punched tape)
OUTFLG  := $A413   ; 1 byte, Active Output Device
                   ;         $0D (ASCII Return) Write to display or TTY
                   ;         'T' Write to tape
                   ;         'K' Write to tape in KIM-1 format
                   ;         'P' Write to printer
                   ;         'U' Write to user defined routine
                   ;         'X' Write to nothing (discard chars)
S1      := $A41A   ; Start Address
ADDR    := $A41C   ; End Address
CKSUM   := $A41E   ; Checksum
NAME    := $A42E   ; Tape File Name
TAPOUT  := $A435   ; Tape unit selected
DRB     := $A800   ; 6522 Data Register B

; Monitor routines
; Legend:
;        AID = Active Input Device
;        AOD = Active Output Device
;        D/P = Display / Printer
;        CR  = Carriage Return ASCII control code
;        LF  = Line Feed ASCII control code
;        NUL = Null ASCII control code
;        KB  = Keyboard

BLANK   := $E83E   ; Outputs one SP to D/P
BLANK2  := $E83B   ; Outputs two SP's to D/P
CLR     := $EB44   ; Clears D/P pointers
CRCK    := $EA24   ; Outputs print buffer to Printer
CRLF    := $E9F0   ; Outputs CR, LF & NUL to AOD
CRLOW   := $EA13   ; Outputs CR & LF to D/P
COMIN   := $E1A1   ;
CUREAD  := $FE83   ; Inputs one ASCII char from KB to A, display
                   ; cursor
DISASM  := $F46C   ; Outputs disassembled instruction
DU11    := $E50A   ; Close tape block if active
DUMPTA  := $E56F   ; Opens a Audio Tape output file by setting the tape buffer
                   ; pointer and moving the file name from NAME ($A42E) to the
                   ; tape buffer. The rest of the tape buffer can be loaded
                   ; with output data using OUTALL. The recorder 1 or 2
                   ; control will turn on automatically depending on the state
                   ; of TAPOUT ($A435).
DU11    := $E50A   ; Closes a tape block if the audio tape output is active.
                   ; Turns both recorder controls on. Stores CR ($0D) in INFLG
                   ; ($A412) and OUTFLG ($A714) to indicate input from
                   ; keyboard and output to the display/printer. 
EQUAL   := $E7D8   ; Outputs "=" to D/P
FROM    := $E7A3   ; Outputs "FROM=" to D/P and enters address
GETTAP  := $EE29   ; Inputs one character from Audio Tape into A. The tape
                   ; must be in sync to read the character properly.
HEX     := $EA7D   ; Converts a hex number in A from ASCII to
                   ; binary, and puts result in the LSD of A,
                   ; with zero in MSD of A
INALL   := $E993   ; Inputs one ASCII char from AID to A. The input device
                   ; code must be in INFLG ($A412) before calling.
INLOW   := $E8F8   ; Put CR ($0D) in INFLG to indicates Keyboard input.
LL      := $E8FE   ; Sets input from KB and output to D/P
LOADTA  := $E32F   ; Searches for audio tape file with file name as specified
                   ; in NAME ($A42E). Turns on recorder control 1 or 2
                   ; depending on the state of TAPIN ($A434). Loads only the
                   ; first block of the located file. Each byte of the loaded
                   ; block can then be read using INALL. Subsequent block
                   ; will be loaded automatically whenever the tape input
                   ; buffer is empty. Subroutine LOAD1 can be used after
                   ; LOADTA to load the remaining blocks. 
NOUT    := $EA51   ; Converts a hex number in LSD of A from
                   ; binary to ASCII, and outputs them to AOD
NUMA    := $EA46   ; Converts two hex numbers in A from binary
                   ; to ASCII, and outputs them to AOD, MSD first
OUTALL  := $E9BC   ; Outputs ASCII char in A to AOD
OUTCK1  := $E53B   ; Outputs A to AOD, converting to two ASCI chars, whithout updating checksum
OUTDIS  := $EF05   ; Output A to display
OUTDP   := $EEFC   ; Output A to D/P
OUTDP1  := $EF02   ; Output A to active display
OUTLOW  := $E901   ; Set output to terminal (D/P or TTY)
OUTPRI  := $F000   ; Output A to printer
OUTPUT  := $E97A   ; Outputs ASCII char in A to either TTY of D/P
OUTTAP  := $F24A   ; Outputs ASCII char in A to Audio Tape
                   ; after SYN
PACK    := $EA84   ; Converts a hex number in A from ASCII to
                   ; binary, and puts result in the LSD of A,
                   ; with the result of the last call to PACK
                   ; or HEX in the MSD of A
PHXY    := $EB9E   ; Push X and Y Registers onto Stack
PLXY    := $EBAC   ; Pull X and Y Registers from Stack
PSL1    := $E837   ; Outputs "/" to D/P
QM      := $E7D4   ; Outputs "?" to D/P
RBYTE   := $E3FD   ; Inputs two ASCII chars from AID, and
                   ; converts to binary with result in A
RCHEK   := $E907   ; Scans KB, returns to Monitor in ESC, to
                   ; caller on no entry, wait on SP
RDRUB   := $E95F   ; Inputs one ASCII char from KB to A, with
                   ; echo to D/P. Allows DEL, if Y != 0
READ    := $E93C   ; Inputs one ASCII char from KB to A
RED1    := $FE96   ; Inputs one char from KB, with echo to D/P
REDOUT  := $E973   ; Inputs one ASCII char from KB to A, with
                   ; echo to D/P, displays cursor
SEMI    := $E9BA   ; Outputs ";" to AOD
TAISET  := $EDEA   ; Sets up Audio Tape input, detects five SYN
                   ; chars
TAOSET  := $F21D   ; Sets up Audio Tape output, issues SYN
                   ; characters
TIBY1   := $ED53   ; Loads a block of 80 bytes from Audio Tape
TIBYTE  := $ED3B   ;
TO      := $E7A7   ; Outputs "TO" to D/P and enters address
TOBYTE  := $F18B   ;
TOGTA1  := $E6BD   ;
TOGTA2  := $E6CB   ;
TOPNO   := $F8BC   ;
WRAX    := $EA42   ;
WHEREI  := $E848   ; Sets up the AID and loads INFLG
WHEREO  := $E871   ; Sets up the AOD and loads OUTFLG

