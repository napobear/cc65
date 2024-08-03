; ---------------------------------------------------------------------------
;
; Rockwell AIM-65 definitions
;
; ---------------------------------------------------------------------------

RAMSTART := $0200     ; Entry point

; Monitor routines
; Legend:
;        AID = Active Input Device
;        AOD = Active Output Device
;        D/P = Display / Printer
;        CR  = Carriage Return ASCII control code
;        LF  = Line Feed ASCII control code
;        NUL = Null ASCII control code
;        KB  = Keyboard

        .define BLANK   $E83E   ; Outputs one SP to D/P
        .define BLANK2  $E83B   ; Outputs two SP's to D/P
        .define CLR     $EB44   ; Clears D/P pointers
        .define CRCK    $EA24   ; Outputs print buffer to Printer
        .define CRLF    $E9F0   ; Outputs CR, LF & NUL to AOD
        .define CRLOW   $EA13   ; Outputs CR & LF to D/P
        .define COMIN   $E1A1   ;
        .define CUREAD  $FE83   ; Inputs one ASCII char from KB to A, display
                                ; cursor
        .define DISASM  $F46C   ; Outputs disassembled instruction
        .define DU11    $E50A   ; Close tape block if active
        .define DUMPTA  $E56F   ; Opens Audio Tape output file
        .define EQUAL   $E7D8   ; Outputs "=" to D/P
        .define FROM    $E7A3   ; Outputs "FROM=" to D/P and enters address
        .define GETTAP  $EE29   ; Inputs one character from Audio Tape
        .define HEX     $EA7D   ; Converts a hex number in A from ASCII to
                                ; binary, and puts result in the LSD of A,
                                ; with zero in MSD of A
        .define INALL   $E993   ; Inputs one ASCII char from AID to A
        .define INLOW   $E8F8   ; Indicates KB input in INFLG
        .define LL      $E8FE   ; Sets input from KB and output to D/P
        .define LOADTA  $E32F   ; Searches for audio input file
        .define NOUT    $EA51   ; Converts a hex number in LSD of A from
                                ; binary to ASCII, and outputs them to AOD
        .define NUMA    $EA46   ; Converts two hex numbers in A from binary
                                ; to ASCII, and outputs them to AOD, MSD first
        .define OUTALL  $E9BC   ; Outputs ASCII char in A to AOD
        .define OUTCK1  $E53B   ; Outputs A to AOD, converting to two ASCI chars, whithout updating checksum
        .define OUTDIS  $EF05   ; Output A to display
        .define OUTDP   $EEFC   ; Output A to D/P
        .define OUTDP1  $EF02   ; Output A to active display
        .define OUTLOW  $E901   ; Set output to terminal (D/P or TTY)
        .define OUTPRI  $F000   ; Output A to printer
        .define OUTPUT  $E97A   ; Outputs ASCII char in A to either TTY of D/P
        .define OUTTAP  $F24A   ; Outputs ASCII char in A to Audo Tape
                                ; after SYN
        .define PACK    $EA84   ; Converts a hex number in A from ASCII to
                                ; binary, and puts result in the LSD of A,
                                ; with the result of the last call to PACK
                                ; or HEX in the MSD of A
        .define PHXY    $EB9E   ; Push X and Y Registers onto Stack
        .define PLXY    $EBAC   ; Pull X and Y Registers from Stack
        .define PSL1    $E837   ; Outputs "/" to D/P
        .define QM      $E7D4   ; Outputs "?" to D/P
        .define RBYTE   $E3FD   ; Inputs two ASCII chars from AID, and
                                ; converts to binary with result in A
        .define RCHEK   $E907   ; Scans KB, returns to Monitor in ESC, to
                                ; caller on no entry, wait on SP
        .define RDRUB   $E95F   ; Inputs one ASCII char from KB to A, with
                                ; echo to D/P. Allows DEL, if Y != 0
        .define READ    $E93C   ; Inputs one ASCII char from KB to A
        .define RED1    $FE96   ; Inputs one char from KB, with echo to D/P
        .define REDOUT  $E973   ; Inputs one ASCII char from KB to A, with
                                ; echo to D/P, displays cursor
        .define SEMI    $E9BA   ; Outputs ";" to AOD
        .define TAISET  $EDEA   ; Sets up Audio Tape input, detects five SYN
                                ; chars
        .define TAOSET  $F21D   ; Sets up Audio Tape output, issues SYN
                                ; characters
        .define TIBY1   $ED53   ; Loads a block of 80 bytes from Audio Tape
        .define TIBYTE  $ED3B   ;
        .define TO      $E7A7   ; Outputs "TO" to D/P and enters address
        .define TOBYTE  $F18B   ;
        .define TOGTA1  $E6BD   ;
        .define TOGTA2  $E6CB   ;
        .define TOPNO   $F8BC   ;
        .define WRAX    $EA42   ;
        .define WHEREI  $E848   ; Sets up the AID and loads INFLG
        .define WHEREO  $E871   ; Sets up the AOD and loads OUTFLG








WARM     := $8003     ; Monitor entry
SVNMI    := $809B     ; Save NMI entry
INBYTE   := $81D9     ; Get two HEX characters and pack
ASCNIB   := $8275     ; Test for carriage-return
INCCMP   := $82B2     ; Increment pointer
CHKSAD   := $82DD     ; Compute checksum
OUTPC    := $82EE     ; Display program counter
OUTBYT   := $82FA     ; Print byte as two ASCII characters
OUTS2    := $8319     ; Print pointer
INSTAT   := $8386     ; Determine if key is pressed
GETKEY   := $88AF     ; Get key (disregarding monitor login)
SCAND    := $8906     ; Flash LED display (once)
KEYQ     := $8923     ; Test for keypress
BEEP     := $8972     ; Make a beep
CONFIG   := $89A5     ; Configure I/O
OUTDSP   := $89C1     ; Output to on-board LED display
INCHR    := $8A1B     ; Input character and convert to uppercase
OUTCHR   := $8A47     ; Output character
INTCHR   := $8A58     ; Input character without case conversion
DLYF     := $8AE6     ; Delay 1 bit time
DLYH     := $8AE9     ; Delay 1/2 bit time
RESET    := $8B4A     ; Hard reset
ACCESS   := $8B86     ; Unlock lowest 4K memory
NACCES   := $8B9C     ; Lock lowest 4K memory
L8C78    := $8C78     ; Link to tape
DUMPT    := $8E87     ; Dump memory to tape
LOADT    := $8C78     ; Load memory from tape
TAPEMODE := $00FD     ; Top bit on for high-speed


; ---------------------------------------------------------------------------
; System Memory
; ---------------------------------------------------------------------------
DISBUF   := $A640     ; On-Board Display Buffer
DISBUF0  := $A640     ; Left-Most digit
DISBUF1  := $A641     ; Second digit
DISBUF2  := $A642     ; Third
DISBUF3  := $A643     ; Fourth
DISBUF4  := $A644     ; Fifth
DISBUF5  := $A645     ; Sixth and right-most digit
DISBUF6  := $A646     ; Not-used / right of display (shift buffer)
RDIG     := $A645     ; Right-most digit (same as DISBUF5)
P3L      := $A64A     ; Parameter 3 (low-byte)
P3H      := $A64B     ;             (high-byte)
P2L      := $A64C     ; Parameter 2
P2H      := $A64D     ;
P1L      := $A64E     ; Parameter 1
P1H      := $A64F
PARNR    := $A649     ; Number of Parameters Entered
PADBIT   := $A650     ; Pad Bits for Carriage Return
SDBYT    := $A651     ; Baud Rate for RS232 (01-4800,06-2400,10-1200,24-600,4C-300,D5-110)
ERCNT    := $A652     ; Error Count (Max FF)
TECHO    := $A653     ; Terminal Echo (bit-7=ECHO/NO, 6=CTL-O TOGGLE)
TOUTFL   := $A654     ; Output Flags (bit-7=CRT IN, 6=TTY IN, 5=TTY OUT, 4=CRT OUT)
KSHFL    := $A655     ; Keyboard Shift Flag
TV       := $A656     ; Trace Velocity (0=Single Step)
LSTCOM   := $A657     ; Last Monitor Command
MAXRC    := $A658     ; Maximum Record Length for Memory Dump


; ---------------------------------------------------------------------------
; Register Followers
; ---------------------------------------------------------------------------
PCLR     := $A659     ; Program Counter (low-byte)
PCHR     := $A65A     ;                 (high-byte)
SR       := $A65B     ; Stack Pointer
FR       := $A65C     ; Status Register Flags
AR       := $A65D     ; A Register
XR       := $A65E     ; X Register
YR       := $A65F     ; Y Register


; ---------------------------------------------------------------------------
; I/O Vectors (3 bytes each)
; ---------------------------------------------------------------------------
INVEC    := $A660     ; Input Character
OUTVEC   := $A663     ; Output Character
INSVEC   := $A666     ; Input Status
URSVEC   := $A669     ; Unrecognized Syntax
URCVEC   := $A66C     ; Unrecognized Command / Error
SCNVEC   := $A66F     ; Scan On-board Display


; ---------------------------------------------------------------------------
; Trace and Interrupt Vectors (2 bytes each)
; ---------------------------------------------------------------------------
EXEVEC   := $A672     ; Exec and Alternate InVec
TRCVEC   := $A674     ; Trace
UBRKVC   := $A676     ; User Break after Monitor
UIRQVC   := $A678     ; User non-break IRQ after Monitor
NMIVEC   := $A67A     ; Non-Maskable Interrupt
RSTVEC   := $A67C     ; Reset
IRQVEC   := $A67E     ; Interrupt Request


; ---------------------------------------------------------------------------
; I/O Registers
; ---------------------------------------------------------------------------
;
; 6532 (U27)
;
PADA     := $A400     ; Keyboard / Display
P3DA     := $A402     ; Serial I/O
DDPADA   := $A401     ; Data-Direction Register for PADA
DDP3DA   := $A403     ; Data-Direction Register for P3DA
WEDRTA   := $A404     ; Write-Edge Detect Read Timer A
WEDRFA   := $A405     ; Write-Edge Detect Read-Int Flags A
WEDRTB   := $A406     ; Write-Edge Detect Read Timer B
WEDRFB   := $A407     ; Write-Edge Detect Read-Int Flags B
TIM0001  := $A41C     ; Timer / 1
TIM0008  := $A41D     ; Timer / 8
TIM0064  := $A41E     ; Timer / 64
TIM1024  := $A41F     ; Timer / 1024
;
; 6522 (U25)
;
OR1A     := $A001     ; Input / Output Register for 1A
DDR1A    := $A003     ; Data-Direction Register for 1A
OR1B     := $A000     ; Input / Output Register for 1B
DDR1B    := $A002     ; Data-Direction Register for 1B
TIC1L    := $A004     ;
TIC1H    := $A005     ;
TIL1L    := $A006     ;
TIL1H    := $A007     ;
T2L1L    := $A008     ;
T2C1L    := $A008     ;
T2C1H    := $A009     ;
SR1      := $A00A     ;
ACR1     := $A00B     ;
PCR1     := $A00C     ;
IFR1     := $A00D     ;
IER1     := $A00E     ;
DR1A     := $A00F     ;
;
; 6522 (U28)
;
OR2A     := $A801     ; Input / Output Register for 2A
DDR2A    := $A803     ; Data-Direction Register for 2A
OR2B     := $A800     ; Input / Output Register for 2B
DDR2B    := $A802     ; Data-Direction Register for 2B
TIC2L    := $A804     ;
TIC2H    := $A805     ;
TIL2L    := $A806     ;
TIL2H    := $A807     ;
T2L2L    := $A808     ;
T2C2L    := $A808     ;
T2C2H    := $A809     ;
SR2      := $A80A     ;
ACR2     := $A80B     ;
PCR2     := $A80C     ;
IFR2     := $A80D     ;
IER2     := $A80E     ;
DR2A     := $A80F     ;
;
; 6522 (U29)
;
OR3A     := $AC01     ; Write-Protect RAM, Debug On/Off, I/O-3A
DDR3A    := $AC03     ; Data-Direction Register for 3A
OR3B     := $AC00     ; Input / Output Register for 3B
DDR3B    := $AC02     ; Data-Direction Register for 3B
TIC3L    := $AC04     ;
TIC3H    := $AC05     ;
TIL3L    := $AC06     ;
TIL3H    := $AC07     ;
T2L3L    := $AC08     ;
T2C3L    := $AC08     ;
T2C3H    := $AC09     ;
SR3      := $AC0A     ;
ACR3     := $AC0B     ;
PCR3     := $AC0C     ;
IFR3     := $AC0D     ;
IER3     := $AC0E     ;
DR3A     := $AC0F     ;






