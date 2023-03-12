# Styök language interpreter

Stack? No, **Styök**!

## Available instructions
* `PUSH` – push the value on **stack**
* `POP` – pop the value out of **stack**
* `SWAP` – swap the last two values
* `DUP` – duplicate the last value
* `IADD` – sum the last two values
* `ISUB` – sum the last two values
* `IMUL` – sum the last two values
* `IDIV` – sum the last two values
* `INEG` – negate the last value
* `IREAD` – read from the console input
* `IPRINT` – pop and print the last value
* `STOP` – must be the last command in each program

### Example (example.st)
```asm
PUSH 10 ;Push new value to the stack
DUP ;Duplicate the last value
POP ;Throw the last value
IREAD ;Read an input as integer
ISWAP ;Swap two last values, why not :)
IMUL ;Multiply two last values
IPRINT ;Pop and print the last value
STOP
```