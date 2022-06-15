# Data-Structures-Project
Project: Data Compression
Data Structure Spring 2022

Introduction
This project's purpose is to build a data compression method. That is, we want to convey the same
information in a smaller amount of space given particular data. We'll be concentrating on
compressing text files for this project, so we'll need to first learn how computers internally
represent text.
Computers save information as a series of bytes. A byte is an eight-bit value that ranges from 0 to
255. We need a technique to assign each English letter, punctuation symbol, special character,
and other characters to an eight-bit(a value from 0 to 255) sequence in order to represent English
text. The ASCII encoding, as stated in the table below, is responsible for this mapping. Notice
that ASCII only uses 128 out of the 256 possible values that a byte can store.

For instance, consider the text “A b ????”. Using the table above, we can see that this is
represented as the following sequence of bytes: “65 32 98 32 63 63 63 63”. Note that the space
counts as a character, and its value in the ASCII encoding is 32.If we write out the binary string
for each character according to the table above and concatenate them together, we
get “0100000100100000011000100010000000111111001111110011111100111111”. Storing
our original string with the ASCII encoding requires 8*8 = 64 bits. There are 8 characters in the
text “A b ????” and each character is represented by a byte that is 8 bits long.
Now, imagine if we weren’t forced to use eight bits for every character, and we could instead use
the binary encoding “? = 0, [space] = 10, A = 110, b = 111”. Then our string “A b ????” would
become “11010111100000”. This is only 14 bits, significantly smaller than the 64 bits that ASCII
requires. Also notice that none of these codes are a prefix of any others, so there is no ambiguity
when decoding. Here, we compressed our string by finding a different encoding for the characters
that minimized the number of bits we needed to use.

One of the most important lossless data compression algorithms is called Huffman coding. A
Huffman code is defined by a tree, whose leaves are the symbols in the alphabet. For example,
the tree

If we indicate going left by 0 and going right by 1, then the Huffman code for the above tree is:

a 0
b 100
c 101
d 11

A string of symbols aadbaaca would be encoded as 0011100001010. This would yield
compression considering the original requires 8 bits per symbol. So 64 bits have been reduced to
13 bits. The reason we get compression is that the symbol “a” occurs quite frequently in the
original and the Huffman code uses just one bit to encode it. There is a simple process to
decoding a Huffman code. Start at the root of the tree. If you are at a leaf output the symbol.
Otherwise read a bit and go left if is 0 and go right if is 1 and continue in that manner until
reaching a leaf. An optimal Huffman code is one that produces the shortest code given
frequencies for the symbols.
It turns out there is an elegant algorithm for generating an optimal Huffman code. The algorithm
uses a priority queue. First you need to calculate the frequency of each symbol in the input.
Make a leaf node for each symbol and store its frequency in the node. Repeatedly do the
following, find the two trees with the smallest frequencies. Make them the left and right children
of a new node whose frequency the sum of the two frequencies. When one tree remains we are
done. In the example above the frequencies are a:5, b:1, c:1, d:1.
d
b c
a

5 1 1 1
a b c d

In one more step we are done. The average bit rate of the code can be computed as
ABR = (F1L1 + F2L2 + ... + FmLm)/N
where Fi is the frequency of the i’th symbol, Li is the length of the code for the i’th symbol and N
is the length of the file. Without actually compressing the file the compression ratio for a text file
can be computed as 8/ABR. This is because the uncompressed tex file is stored with 8 bits per
symbol.
Task No. 1:
Build simple Tree based Huffman coding scheme and show the results.
Task No. 2:
The second task in this project is to use predefined priority queues to build an optimal Huffman
tree. Your priority queue will maintain the current set of trees ordered by their frequencies. One
challenge is to efficiently traverse the optimal Huffman tree to generate the code to be printed
out.

The User Interface
Again we are not too concerned with the user interface because we are working with the data
structures. The program requests a text file name, then computes the optimal Huffman code and
prints it. The compression ratio is then printed.
> Please enter a text file name:
foo.txt
> The optimal Huffman code is:
> a 0
> b 100
> c 101
> d 11
> The compression ratio is:
> 4.92
Your program should check for invalid inputs.
5 2 1
a d
b c
5 3
a

d
b c
5 2 1
a d
b c

Tree drawing
To debug your program you may want to use Graphviz which draws trees and other graphs. The
Graphviz information page is available at
http://www.research.att.com/sw/tools/graphviz/.
The Graphviz program "dot" generates output in Postscript format. There are many viewers
available for Postscript. I recommend GSview with Ghostscript on Windows machines. The
home page for GSview is http://www.cs.wisc.edu/~ghost/gsview/ where you will find the latest
revision information for both GSview and Ghostscript.
Project Groups
This project can be done within a group of two (2) students. There is no restriction on the
selection of group members. Students can make groups according to their preferences. The group
members must belong to the same section.
Report
You must write a report(pdf) about your project that explains how your code works and how it is
structured.
How to Turn in your Program
All submissions MUST be uploaded on Google classroom. Solutions sent to the emails will not
be graded. To avoid last minute problems (unavailability of Internet, load shedding etc.), you are
strongly advised to start working on the project from day one. You are required to use Visual
Studio for the project. Combine all your work (solution folder) in one .zip file after performing
“Clean Solution”. Submit zip file on GCR within given deadline. If only .cpp file is submitted, it
will not be considered for evaluation.
Plagiarism
Zero marks in the project for all members if any significant part of project is found plagiarized. A
code is considered plagiarized if more than 20% code is not your own work.

Good Luck!
