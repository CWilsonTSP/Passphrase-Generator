# Passphrase Generator
A passphrase generator written in c++.

### Build
Download or clone the repository and run make. Uses g++, but if there is another
compiler that you would rather use, just change it. 

You can also do `make run` which will recompile the program and generate a 
passphrase.
`make clean` will remove the binary and any .o files.

### Run
`./password`

### How does it work?
When it starts, the program will load two word lists-- one for adjectives, and
one for nouns. The user can append or remove any words they wish from these lists.

Two words are chosen at random from the adjectives list and one is chosen from 
the nouns. They are combined in the form "AdjectiveAdjectiveNoun" and "A/n" is
prepended.

### How many possible combinations are there?
A lot.

### Fun Examples
Note: I do not recommend you use these, as they are
1. Listed on the internet
2. Long and too tedious to memorize

- aDeconstructionistPolemoniaceousRappahannock
- AnImpetuousFerromagneticLonganimity
- aNonrenewableTicklingBastardization
- aNondenominationalUnrecognizedBattlesight


## TODO:
- Add random symbol replacement for extra entropy (l33tspeak)
- filter out words that don't play well
- A "static" version that doesn't rely on dynamically loading word lists
