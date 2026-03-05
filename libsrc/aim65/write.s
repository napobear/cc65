;
; Wayne Parham (wayne@parhamdata.com)
;
; int __fastcall__ write (int fd, const void* buf, int count);
;

.include        "aim65.inc"

.export         _write

.proc           _write

        jsr     OUTDIS
        rts                     ; Return count

.endproc
