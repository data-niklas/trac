

## Language Specification

<program> ::= <item>
            | <item> <divider> <program>

<divider> ::= '\n'
            | '\n' <divider>

<item>    ::= <definition>
            | <trac>

<definition> ::= 


<trac>    ::= <call> ':' <varnames> '?' <calls> '!' <calls> ';'


<calls>   ::= 
            | <call>
            | <call> <calls>

<call>    ::= <ident>'(' <vars> ')


<varnames>::=
            | <ident>
            | <ident> <varnames>

<vars>    ::=
            | <var>
            | <var> <vars>

<var>     ::= <ident>
            | <string>
            | <int>
            | <boolean>
            | <call>


timed(1, 2, 4) : time
?   true()
    eq(systime(time), 5)
!   print(formatted_time(time, "fuck you"))
    print("Whaaaat")

on_print() :


every(5) : time ? eq(mod(time,5),0) ! shell(notify-send("stop"))


active_window() : window_id
? 
! ;
