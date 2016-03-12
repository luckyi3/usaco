#Crafting Winning Solutions

A good way to get a competitive edge is to write down a game plan for what you're going to do in a contest round. This will help you script out your actions, in terms of what to do both when things go right and when things go wrong. This way you can spend your thinking time in the round figuring out programming problems and not trying to figure out what the heck you should do next... it's sort of like precomputing your reactions to most situations.

Mental preparation is also important.

###Game Plan For A Contest Round

Read through ALL the problems FIRST; sketch notes with algorithm, complexity, the numbers, data structs, tricky details, ...

* Brainstorm many possible algorithms - then pick the stupidest that works!
* DO THE MATH! (space & time complexity, and plug in actual expected and worst case numbers)
* Try to break the algorithm - use special (degenerate?) test cases
* Order the problems: shortest job first, in terms of your effort (shortest to longest: done it before, easy, unfamiliar, hard)

Coding a problem - For each, one at a time:

* Finalize algorithm
* Create test data for tricky cases
* Write data structures
* Code the input routine and test it (write extra output routines to show data?)
* Code the output routine and test it
* Stepwise refinement: write comments outlining the program logic
* Fill in code and debug one section at a time
* Get it working & verify correctness (use trivial test cases)
* Try to break the code - use special cases for code correctness
* Optimize progressively - only as much as needed, and keep all versions (use hard test cases to figure out actual runtime)

###Time management strategy and "damage control" scenarios

Have a plan for what to do when various (foreseeable!) things go wrong; imagine problems you might have and figure out how you want to react. The central question is: "When do you spend more time debugging a program, and when do you cut your losses and move on?". Consider these issues:

* How long have you spent debugging it already?
* What type of bug do you seem to have?
* Is your algorithm wrong?
* Do you data structures need to be changed?
* Do you have any clue about what's going wrong?
* A short amount (20 mins) of debugging is better than switching to anything else; but you might be able to solve another from scratch in 45 mins.
* When do you go back to a problem you've abandoned previously?
* When do you spend more time optimizing a program, and when do you switch?
* Consider from here out - forget prior effort, focus on the future: how can you get the most points in the next hour with what you have?

Have a checklist to use before turning in your solutions:

 Code freeze five minutes before end of contest?
* Turn asserts off.
* Turn off debugging output.


###Tips & Tricks

* Brute force it when you can
* KISS: Simple is smart!
* Hint: focus on limits (specified in problem statement)
* Waste memory when it makes your life easier (if you can get away with it)
* Don't delete your extra debugging output, comment it out
* Optimize progressively, and only as much as needed
* Keep all working versions!
* Code to debug:
	* whitespace is good,
	* use meaningful variable names,
	* don't reuse variables,
	* stepwise refinement,
	* COMMENT BEFORE CODE.
* Avoid pointers if you can
* Avoid dynamic memory like the plague: statically allocate everything.
* Try not to use floating point; if you have to, put tolerances in everywhere (never test equality)
* Comments on comments:
	* Not long prose, just brief notes
	* Explain high-level functionality: ++i; /* increase the value of i by */ is worse than useless
	* Explain code trickery
	* Delimit & document functional sections
	* As if to someone intelligent who knows the problem, but not the code
	* Anything you had to think about
	* Anything you looked at even once saying, "now what does that do again?"
	* Always comment order of array indices
* Keep a log of your performance in each contest: successes, mistakes, and what you could have done better; use this to rewrite and improve your game plan!

###Complexity

####Basics and order notation

The fundamental basis of complexity analysis revolves around the notion of ``big oh'' notation, for instance: O(N). This means that the algorithm's execution speed or memory usage will double when the problem size doubles. An algorithm of O(N 2) will run about four times slower (or use 4x more space) when the problem size doubles. Constant-time or space algorithms are denoted O(1). This concept applies to time and space both; here we will concentrate discussion on time.

One deduces the O() run time of a program by examining its loops. The most nested (and hence slowest) loop dominates the run time and is the only one mentioned when discussing O() notation. A program with a single loop and a nested loop (presumably loops that execute N times each) is O(N 2), even though there is also a O(N) loop present.

Of course, recursion also counts as a loop and recursive programs can have orders like O(b N), O(N!), or even O(N N).

###Rules of thumb

* When analyzing an algorithm to figure out how long it might run for a given dataset, the first rule of thumb is: modern (2004) computers can deal with 100M actions per second. In a five second time limit program, about 500M actions can be handled. Really well optimized programs might be able to double or even quadruple that number. Challenging algorithms might only be able to handle half that much. Current contests usually have a time limit of 1 second for large datasets.
* 16MB maximum memory use
* 2^10 ~approx~ 10^3
* If you have k nested loops running about N iterations each, the program has O(N k) complexity.
* If your program is recursive with b recursive calls per level and has l levels, the program O(b l) complexity.
* Bear in mind that there are N! permutations and 2 n subsets or combinations of N elements when dealing with those kinds of algorithms.
* The best times for sorting N elements are O(N log N).
* DO THE MATH! Plug in the numbers.




