<b>EN:</b> Write a program that takes an array of numbers A[0...n-1], converts it to a heap in a linear number of exchanges, and outputs such permutations of array elements that the inequalities A[i] ≤ A[2i + 1] and A[i] ≤ A[2i + 2] for all i are satisfied.  
<b>Input format.</b> The first line contains the number n. The next line specifies an array of numbers A[0], ..., A[n-1].  
<b>Output format.</b> The first line of the output must contain the number of exchanges m, which must satisfy the inequality 0 ≤ m ≤ 4n. Each of the next m lines must specify the exchange of two elements of the array A. Each exchange is specified by a pair of different indices 0 ≤ i != j ≤ n-1. After applying all exchanges in the specified order, the array must become a min-heap, i.e., the following two conditions must be satisfied for all 0 ≤ i ≤ n-1:  
• if 2i + 1 ≤ n-1, then A[i] < A[2i + 1].  
• if 2i + 2 ≤ n-1, then A[i] < A[2i + 2].  
<b>Limitations.</b> 1 ≤ n ≤ 10⁵; 0 ≤ A[i] ≤ 10⁹ for all 0 ≤ i ≤ n-1; all A[i] are pairwise distinct; i != j.

<b>RU:</b> Написать программу, которая принимает в себя массив чисел A[0…n-1], преобразует его в кучу за линейное количество обменов и выводит такие перестановки элементов массива, чтобы выполнялись неравенства A[i] ≤ A[2i + 1] и A[i] ≤ A[2i + 2] для всех i.  
<b>Формат входа.</b> Первая строка содержит число n. Следующая строка задаёт массив чисел A[0], ..., A[n−1].  
<b>Формат выхода.</b> Первая строка выхода должна содержать число обменов m, которое должно удовлетворять неравенству 0 ≤ m ≤ 4n. Каждая из последующих m строк должна задавать обмен двух элементов массива A. Каждый обмен задаётся парой различных индексов 0 ≤ i != j ≤ n−1. После применения всех обменов в указанном порядке массив должен превратиться в min-кучу, то есть для всех 
0 ≤ i ≤ n−1 должны выполняться следующие два условия:  
• если 2i + 1 ≤ n−1, то A[i] < A[2i + 1].  
• если 2i + 2 ≤ n−1, то A[i] < A[2i + 2].  
<b>Ограничения.</b> 1 ≤ n ≤ 10⁵; 0 ≤ A[i] ≤ 10⁹ для всех 0 ≤ i ≤ n−1; все A[i] попарно различны; i != j.  
