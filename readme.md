# Computer Science I
## Lab 14.0 - Generative AI
[School of Computing](https://computing.unl.edu)  
[College of Engineering](https://engineering.unl.edu/)  
[University of Nebraska-Lincoln](https://unl.edu)  

This lab introduces you using generative artificial intelligence to
help you code, test, and debug code and demonstrates its pitfalls and
limitations.

## Prior to Lab

* Read and familiarize yourself with this handout.

## Peer Programming Pair-Up

***For students in the online section:*** you may complete
the lab on your own if you wish or you may team up with a partner
of your choosing, or, you may consult with a lab instructor to get
teamed up online (via Zoom).

***For students in the on campus section:*** your lab instructor
will team you up with a partner.  

To encourage collaboration and a team environment, labs are be
structured in a *peer programming* setup.  At the start of
each lab, you will be randomly paired up with another student
(conflicts such as absences will be dealt with by the lab instructor).
One of you will be designated the *driver* and the other
the *navigator*.  

The navigator will be responsible for reading the instructions and
telling the driver what to do next.  The driver will be in charge of the
keyboard and workstation.  Both driver and navigator are responsible
for suggesting fixes and solutions together.  Neither the navigator
nor the driver is "in charge."  Beyond your immediate pairing, you
are encouraged to help and interact and with other pairs in the lab.

Each week you should alternate: if you were a driver last week,
be a navigator next, etc.  Resolve any issues (you were both drivers
last week) within your pair.  Ask the lab instructor to resolve issues
only when you cannot come to a consensus.  

Because of the peer programming setup of labs, it is absolutely
essential that you complete any pre-lab activities and familiarize
yourself with the handouts prior to coming to lab.  Failure to do
so will negatively impact your ability to collaborate and work with
others which may mean that you will not be able to complete the
lab.  

# Using Generative AI

First and foremost: though you will be using generative AI in this particular
module, you should adhere to any policies that this and other courses establish
regarding the use of AI.  

Generative AI can be a very useful tool, but it does have a lot of risks.  
It is not always correct (even though it can be *confidently* incorrect),
it can [hallucinate](https://en.wikipedia.org/wiki/Hallucination_(artificial_intelligence),
or it may just not have been trained on the relevant information to give
an answer.  When using AI, the following guidelines are recommended.

1. Be intentional with your AI use. Ask yourself: Is AI enhancing my
   understanding or replacing my effort? If AI is doing all (or most) of
   the intellectual work, you're not learning.
2. Treat your prompt like a question to a (human) tutor. Give background,
   explain your goals, and clearly say what you want or don't want. A
   detailed prompt leads to a better, more useful response.
3. Scrutinize: Think critically about the output. Does it align with what
   you've learned? Are there logical gaps, factual errors, or unfamiliar
   terms? Remember, AI can sound confident but still be wrong.
4. Follow-up: Use follow-up questions to deepen your understanding. Ask
   AI to explain, rephrase, give examples, or recommend additional
   resources. Engage with it like you would in a conversation with a
   teacher or mentor.
5. Verify: Fact check AI responses with textbooks, scholarly articles,
   and official course materials. AI is a tool, not a source of truth.

AI can’t reason like a human, understand nuance, or access real-time data
unless explicitly designed to. Know what it can and can't do.  Don't let
AI flatten your style or critical thinking. Use it to inform, not to
replace, your own voice, reasoning, and creativity--these are the skills
college is meant to develop.

Occasionally AI will get stuck or go down the wrong path
and needs to be refreshed.  You can refresh your session by prompting:
`Forget all previous messages and let’s begin anew.`

# Activities

In the following activities you'll use AI to fix and debug code that determines
if a number is a *Kaprekar number*.  A Kaprekar number is a non-negative
integer $n$ whose square can be split into two positive integers
whose sum is equal to the original number.  For example, 45 is a Kaprekar
number, because
  $$45^2 = 2025$$
which can be split up as $20 + 25 = 45$.  The split doesn't have to be
*exactly* in the middle.  For more information see [wikipedia](https://en.wikipedia.org/wiki/Kaprekar_number)
and for a full reference see <https://oeis.org/A006886>

We have provided code that implements an algorithm to determine whether or not a number
is a Kaprekar number by trying all possible splits.  For example, for $n = 297$,
$n^2 = 88209$, it will try:

$8 + 8209 = 8217 \neq 297$

$88 + 209 = 297 = 297$

and would continue with $882 + 9$ and $8820+9$ if it didn't find the equality
first.  For a *non-Kaprekar* number such as $n= 42$ it would use $n^2 = 1764$
and try

$1 + 764 = 765 \neq 42$

$17 + 64 =  81 \neq 42$

$176 + 4 = 180 \neq 42$

before concluding it is *not* a Kaprekar number.

For this lab, we'll assume that you're using ChatGPT.  If you prefer using
another AI/LLM you may do so, otherwise, open a browser to <https://chatgpt.com/>.
You don't need to create an account.

## Troubleshooting With AI

### Inference

Can AI understand the intent of code with little to no knowledge?

Below is a version of the `isKaprekar` function (in `kaprekar_utils.c`) with
no documentation and no "hints" as to what the code is trying to do.  Prompt
the AI to ask it what the code does.

```c
bool function(int n) {

  if(n < 1) {
    return false;
  }

  long s = n * (long) n;
  int d = (int) log10(n) + 1;
  long m = 1;
  long a, b;

  for(int i=1; i<=d; i++) {
    m *= 10;

    a = s / m;
    b = s % m;

    if(b > 0 && n == a + b) {
      return 1;
    }
  }
  return 0;

}
```

How good was the AI at inferring what the code was supposed to do?  Did it
provide a helpful walkthough of the code and how it operates?  

### Compiling

Is the AI better at helping to diagnose compiler errors than the compiler?

Try building the project in the `code` directory using `make all`.  You'll
find that there are several compiler errors.  Read the errors and see if you
understand them and how you would go about fixing them.  Before you do, prompt
your AI with:

`The following C code is not compiling, why and how do I fix it?`

followed by the relevant code snippet.  Were the suggestions by the AI better
than your own?  Update the code either using your fixes or the AI's until
it compiles.

### Debugging

We have provided several ways to test the code.  You can run a single number:

`./kaprekarDemo 45`

or a full ad-hoc test suite:

`./kaprekarTest`

or a formal `cmocka` test suite:

`./kaprekarTestCmocka`

Run all 3 (the first on several values) and observe the results.  The code is
still incorrect.  Prompt ChatGPT for why: `Below is a C function to determine
if a number is a Kaprekar number or not.  However, it is wrong for n = 4879.  
Why?` (then copy-paste your corrected code).  Did the AI provide a reasonable
fix and reasoning for it? (note: when we tried this, ChatGPT went through
several mistaken iterations but caught itself: `Wait, actually there's
confusion-let's redo this carefully.` or `Wait — there’s a mistake. Let’s reference known data.`)

### Testing

Now that you have a version that passes all of our tests, use your AI to
add tests *for* you.  Prompt your AI to `Add more tests to this cmocka
test suite` and copy/paste the main from `kaprekar_test_cmocka.c` file.

* Are the suggestions that the AI gives you correct?  Verify using the following
  reference: <https://oeis.org/A006886>
* When we tested this, ChatGPT gave several incorrect tests (it claimed 1,000,000
  and 999,000 were Kaprekar numbers).
* If incorrect, tell the AI what its errors are and ask it to fix them.  Where
  you able to get the AI to give you a 100% correct version?
* Clear the history and try again, but this time tell the AI which values to
  add: `Add code to test the following Kaprekar numbers to the following
  cmocka test suite: 142857, 148149, 181819, 187110, 208495, 318682, 329967,
  351352, 356643, 390313, 461539, 466830, 499500, 500500, 533170`
* Inspect the code for correctness and incorporate it into your tests.  Verify
  everything works.

### Limitations

Your interactions with AI can vary because it is a *stochastic* process which
involves randomization.  In addition, the language models are continuously being
updated with new training data.  The answers the AI gives may not be the same as your
fellow students and may not even be the same tomorrow as it is today.  To
illustrate this, consider the following interaction we had when developing this
lab (try the prompts yourself to see if you can reproduce the results, we were
using GPT-4o, July 2025).

1. Prompt: `Prove that 533170 is a Kaprekar number by showing me the split`

The AI gave a non-standard definition that the number of digits in the
split had to be the same as the original number.  As a consequence, it gave
the wrong information and concluded that `533170 is not a Kaprekar number
based on the standard definition (with splitting equal to the number of
digits of n).`  The AI was not even consistent with its own (incorrect)
definition: in the split `284270 + 248900 = 533170` that demonstrates that
it is a Kaprekar number, both numbers have 6 digits (note: when we investigated
this, it was apparent that ChatGPT even got basic math wrong, it claimed
that $533170^2 = 284,273,728,900$ but its 284,270,248,900!).

2. Prompt: `That is not the definition of a Kaprekar number.  The number
of digits in n is irrelevant.`

Once again, even though the AI accepted our revised definition it was
not able to demonstrate it, concluding `No split
sums to 533170 using the standard Kaprekar number splitting.`

3. Prompt: `Sequence A006886 says that 533170 is a Kaprekar number: https://oeis.org/A006886, verify`

When we provided an external source confirming that 533170 is a Kaprekar
number it finally was able to demonstrate the correct split and conclude
that `533170 is a Kaprekar number`

# Handin/Grader Instructions

1.  Hand in your completed files:

    -   `kaprekar_utils.c`

    -   `kaprekar_test_cmocka.c`

    through the online handin system.  Be sure your program
    passes all tests to get credit.

2.  Even if you worked with a partner, you *both* should turn in all
    files.
