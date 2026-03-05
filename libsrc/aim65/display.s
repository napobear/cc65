;
; Wayne Parham (wayne@parhamdata.com)
;
; void fdisp (void);
;

.include        "aim65.inc"

.export         _fdisp

.segment        "CODE"

.proc _fdisp:   near

        jmp     SCAND           ;  Flash Display

.endproc
