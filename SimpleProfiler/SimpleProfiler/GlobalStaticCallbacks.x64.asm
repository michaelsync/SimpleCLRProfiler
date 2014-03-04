extern EnterMethodStub:proc
extern LeaveMethodStub:proc
extern MethodTailcallStub:proc


_TEXT segment para 'CODE'


;typedef void MethodEntered3(
;         rcx = FunctionIDOrClientID function_id_or_client_id
;	      rdx = COR_PRF_ELT_INFO elt_info)

        align   16

        public  MethodEntered3

MethodEntered3     proc    frame

        ; save registers
        push    rax
        .allocstack 8

        push    r10
        .allocstack 8

        push    r11
        .allocstack 8

        sub     rsp, 20h
        .allocstack 20h

        .endprolog

        call    EnterMethodStub

        add     rsp, 20h

        ; restore registers
        pop     r11
        pop     r10
        pop     rax

        ; return
        ret

MethodEntered3     endp

;typedef void MethodLeft3(
;         rcx = FunctionIDOrClientID function_id_or_client_id
;	      rdx = COR_PRF_ELT_INFO elt_info)

        align   16

        public  MethodLeft3

MethodLeft3     proc    frame

        ; save integer return register
        push    rax
        .allocstack 8

        sub     rsp, 20h
        .allocstack 20h

        .endprolog

        call    LeaveMethodStub

        add     rsp, 20h

        ; restore integer return register
        pop     rax

        ; return
        ret

MethodLeft3     endp

;typedef void MethodTailcall3(
;         rcx = FunctionIDOrClientID function_id_or_client_id
;	      rdx = COR_PRF_ELT_INFO elt_info)

        align   16

        public  MethodTailcall3

MethodTailcall3  proc    frame

        ; save rax
        push    rax
        .allocstack 8

        sub     rsp, 20h
        .allocstack 20h

        .endprolog

        call    MethodTailcallStub

        add     rsp, 20h

        ; restore rax
        pop     rax

        ; return
        ret

MethodTailcall3  endp


_TEXT ends

end