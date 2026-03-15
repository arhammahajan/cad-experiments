# Bresenham's Line Drawing Algorithm
This is a better algorithm over DDA as it improves upon many of the shortcomings of the DDA algorithm. 
- Uses strictly integer arithmetic. It tracks a "decision parameter" (error term) that is always a whole number, removing the need for a Floating Point Unit (FPU).
- Operates using only addition, subtraction, and bit-shifting. These are the fastest operations a CPU or GPU can perform.
- Does not require rounding. The decision parameter logic inherently selects the integer coordinate closest to the mathematical line, eliminating the overhead of rounding functions.
- Is mathematically exact within the pixel grid. Since it uses integers to track the remainder (error), there is no "drift" regardless of line length.

There are four possible cases that can arise in this in the four quadrants.