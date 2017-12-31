# Turing Machine
Implementation of a Turing Machine in C++. A Turing Machine is a model of computation that defines an abstract machine which manipulates symbols on 
a tape according to the machine rules.

The machine operates on an infinite memory tape divided in cells. The steps are:
1. The machine positions its head over a cell.
2. The machine reads the symbol in that cell.
3. Depending on the state and the symbol read the turing machine write a symbol and changes its state.
4. The Turing Machine moves the tape one cell right or left.
5
## Author
Ángel Luis Igareta Herráiz

## Index
* [Usage](#usage)
* [License](#license)

## Usage
To start the Turing Machine first you have to compile the source with MakeFile. After that you can start it executing:

```
.bin/turing-machine test.tm test.tape
```
---
The first argument reffers to the Turing Machine Table. Its syntax is:
1. The first line is a the state number.
2. The second line is the initial state.
3. The thrid line are the final states separated by whitespace.
4. The fourth line is the number of t-uples that form the Machine.
5. The next lines are the t-uples, the syntax is:
```
input-state symbol-to-read symbol-to-write movement next-state
```
The second argument reffers to the Turing Machine's tape. Its syntax is a simple string.

---
Once the program is started it will show a menu with 6 options:

    ⬤ Option 0: Exit
    ⬤ Option 1: Change Turing Machine
    ⬤ Option 2: Change Tape
    ⬤ Option 3: Show Turing Machine
    ⬤ Option 4: Show Tape
    ⬤ Option 5: Check String and show process
    ⬤ Option 6: Check String and show process slowly
    ⬤ Option 7: Check String.
---
There are several Turing Machines and Tapes in the test folder.

## License
The Mit License.
