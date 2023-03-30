**Ashar Khalil – 20k-1724  Musaab Imran – 20i-1794  08/06/2022** 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.001.png)

**Semester Project Submitted to:** 

Ma’am Mariam Hida 

**Submitted by:** 

Musaab Imran (20i-1794) Ashar Khalil (20k-1724) CS – A 

**Contents** 

[**TASK 01: Huffman Tree Implementation (without Priority Queue)............ 4** ](#_page2_x553.00_y458.92)

[**TASK 02: Huffman Tree Implementation (with Priority Queue) ................. 7** ](#_page6_x69.00_y395.92)[TASK 03: File Compression ............................................................................ 10** ](#_page9_x69.00_y72.92)[Calculations: ................................................................................................... 11** ](#_page10_x69.00_y72.92)

- The screenshot is showing the main menu of the project.

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.002.jpeg)
- Screenshot showing the contents of the string, unique characters, and their respective frequencies. As frequencies are of prime importance in HUFFMAN encoding. 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.003.jpeg)

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.004.jpeg)

- Basic structure/flow of the implemented code. 

**TASK 01: Huffman Tree Implementation (without Priority Queue)**  

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.005.jpeg)

- Screenshot showing the calling of the function of question 01. 

Firstly, vectors were used, and then the vectors were sorted using the operator overloading. The nodes are added, and then the vector is sorted. This way we have the vector which is sorted and then we apply the rest of the steps of Huffman coding. 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.006.jpeg)

- Inserting values in the vector which is node-based.  First, we pop the 2 nodes which the least frequency and make a new node using them and add them to the vector. 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.007.jpeg)

- Screenshot of printing the leaf nodes and assigning codes(bits) to the character nodes. 

In this function, we traverse the tree and assign bits based on the left and right positions of each node. Then we are printing the code when we check whether the node is a leaf or not. We are also printing the value of the root node. The last 2 lines of code show the calculation of the optimal number of bits for the compression ratio. 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.008.png)

- Overloading of vector (node type). 

As we wanted to sort our based on the frequency, so we did operator overloading and sorted the nodes based on their respective frequencies. 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.009.jpeg)

- Screenshot showing the output of question 01 based on character and their respective frequency information. 

<a name="_page6_x69.00_y395.92"></a>**TASK 02: Huffman Tree Implementation (with Priority Queue)** 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.010.png)

- Screenshot showing the calling of the function of question 02. 

Firstly, the object of the inbuilt priority queue was declared and we passed it in the function of **makeHuff** and then we made the tree in that function. 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.011.png)

Firstly, we make the list of all the characters and their respective frequencies and make a node of each value and then we insert the nodes in the priority queue and then apply sorting by operator overloading. 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.012.jpeg)

- Screenshot of printing the leaf nodes and assigning codes(bits) to the character nodes. 

In this function, we traverse the tree and assign bits based on the left and right positions of each node. Then we are printing the code when we check whether the node is a leaf or not. We are also printing the value of the root node. The last 2 lines of code show the calculation of the optimal number of bits of each character for the compression ratio. 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.013.png)

- Priority queue overloading for sorting the values based on frequencies. 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.014.jpeg)

- Screenshot showing the output of question 02 based on character and their respective frequency information. 

<a name="_page9_x69.00_y72.92"></a>**TASK 03: File Compression** 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.015.png)

- Calling of function from main for question 03 

The array length is the list of all the characters present in the file and by multiplying it by 8 we get the total number of bits that would be initially used without the Huffman encoding. 

Then we find the number of bits used after applying the Huffman encoding algorithm using the function **showcompression** by sending the root. 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.016.png)

The compression function adds the values of variable **comp** which is the number of bits of each character multiplied by their respective frequency. The **comp** has the total number of bits used by each character. Then we add all the values and return them. 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.017.png)

- The 2 lines of code show the calculation of the optimal number of bits of each character for the compression ratio. 

<a name="_page10_x69.00_y72.92"></a>**Calculations:**  

- **Calculation of original number of bits** 

Characters: abcd 

Frequency: 5111 

Total characters: 5+1+1+1= 8 

Bits for each character: 8 

**Original bits**: 8×8 =64 bits 

- **Calculation of optimal number of bits** 

a => 1 = 2 bits 

b =>100 = 3 bits 

c =>101 = 3 bits 

d =>01 = 2 bits 

**Optimal bits**: 2×5+3×1+3×1+2×1= 13 

- **Calculation of optimal number of bits** 

Compression ratio: Original bits / Optimal bits **Compression ratio**: 64/13 = **4.92** 

![](/Screenshots/Aspose.Words.275674a2-ce9d-488c-b937-8c3c0c97db52.018.jpeg)
12** 
