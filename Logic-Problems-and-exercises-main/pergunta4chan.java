#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ┌───┐
// │┌─┐│
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘


Anonymous 03/15/21(Mon)12:03:51 No.80660382▶>>80660478 >>80660696 >>80660769 >>80661165 >>80663266

    ok, op. time for an interview question:
    You are provided a random number generator that returns a single bit and has been rated as having a perfectly uniform probability distribution between its outputs (0 and 1 each have 50% chance of occuring). Using this provided function, please write a random number generator that:
    >1. returns one of seven values
    >2. maintains a perfectly uniform probability distribution across all its return values
    >3. is guaranteed to execute successfully (may not throw exceptions) in finite time

>>
Anonymous 03/15/21(Mon)12:11:22 No.80660478▶

    >>80660382
    once anybody tries to hit me up with a probability question i exit the interview. who the fuck wants to work in a place like that?

>>
Anonymous 03/15/21(Mon)12:17:58 No.80660563▶

    >>80660268
    > new features, bugfixing, planning, tackling tech debt, refactors, R&D
    If you work on an old code base that was shat on by generations of pajeets you end up doing constant fire fighting, maybe on a Friday afternoon you can do some refactoring if you're lucky. At least it pays well.

>>
Anonymous 03/15/21(Mon)12:28:05 No.80660696▶>>80660802

    >>80660382
    >1
    Run the rng 3 times. 8 unique combos. Discard 000.
    >2
    Ja
    >3
    Fuck you

>>
Anonymous 03/15/21(Mon)12:33:42 No.80660769▶>>80661074 >>80661165

    >>80660382
    >generate 7 random bits
    >add them all (i.e. count 1s)
    it can probably be done with fewer calls to the random function but this was my first instinct

>>
Anonymous 03/15/21(Mon)12:36:07 No.80660802▶>>80661074

    >>80660696
    how are you planning on discarding 000? generating a new set? it could theoretically keep going forever, only generating 000.

>>
Anonymous 03/15/21(Mon)12:38:03 No.80660823▶>>80661074 >>80662376

    >>80660221 (OP)
    Just apply for a job dumbass

>>
Anonymous 03/15/21(Mon)12:38:22 No.80660832▶>>80661074

    >>80660221 (OP)
    >tedious and boring
    Yes, that's most of what they do, not fly around like superman like you may have imagined

>>
Anonymous 03/15/21(Mon)12:57:16 No.80661074▶>>80661210 >>80665028

    >>80660802
    Yes th ts why I said fuck you

    >>80660769
    God Im retarded

    >>80660823
    With what degree? With what CV? Should I tell them I smoke weed and write scifi stories?

    >>80660832
    Then why the fuck are they getting paid hundreds of thousands of dollars to make the next shitty edition of some windows UI?

>>
Anonymous 03/15/21(Mon)13:03:14 No.80661165▶>>80661196 >>80661226 >>80661277
File: 1475716175614.jpg (50 KB, 478x443)
50 KB

    >>80660382
    We've had this one before.
    We had an entire thread on it.
    The answer was a bit of a damp squib.

    You use the 1-bit RNG to make an 8-bit random number.
    Seven of the values just return as normal (say 0-6).
    The eighth value (say 7) returns the next value of a state machine that just cyclicly iterates through 0-6.

    int getRandomBit();

    int counter = 0;

    int arr[] = {0, 1, 2, 3, 4, 5, 6};

    int getRandomSeven() {
        int r = (getRandomBit() << 2)
            + (getRandomBit() << 1)
            + getRandomBit();
        
        
        if(r == 7) {
            counter++;
            counter %= 7;
            
            return arr[counter];
        }
        else
            return r;
    }