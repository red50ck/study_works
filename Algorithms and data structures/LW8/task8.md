<b>EN:</b> Implement a program that takes a binary tree as input, performs in-order, pre-order and post-order traversals and outputs all the vertices 
of the binary tree in three different orders (according to the traversals). The in-order traversal corresponds to the following recursive 
procedure, which receives as input the root v of the current subtree: make a recursive call to v.left, print v.key, make a recursive call 
to v.right. Pre-order traversal: print v.key, make a recursive call to v.left, make a recursive call to v.right. Post-order: make recursive 
call for v.left, make recursive call for v.right, print v.key.  
<b>Input format.</b> The first line contains the number of vertices n. The vertices of the tree are numbered with numbers from 0 to n-1. 
Vertex 0 is the root. Each of the next n lines contains information about vertices 0, 1, ..., n-1: the i-th line specifies the numbers keyᵢ, 
leftᵢ and rightᵢ, where keyᵢ is the key of the of vertex i, leftᵢ is the index of the left son of vertex i, and rightᵢ is the index of the 
right son of vertex i. If vertex i does not have one or both sons, the corresponding value is -1.  
<b>Output format.</b> Three lines: in-order, pre-order, and post-order traversals.  
<b>Limitations.</b> 1 ≤ n ≤ 10⁵; 0 ≤ keyᵢ ≤ 10⁹; -1 ≤ leftᵢ, rightᵢ ≤ n-1. It is guaranteed that the input specifies a valid binary tree: in particular, if leftᵢ != -1 and rightᵢ != -1, then leftᵢ != rightᵢ; no vertex is the son of two vertices; every vertex is the descendant of 
the root.

<b>RU:</b> Реализовать программу, принимающую на вход двоичное дерево, совершающую in-order, pre-order и post-order обходы и выдающую все 
вершины двоичного дерева в трех разных порядках (согласно обходам). In-order обход соответствует следующей рекурсивной процедуре, 
получающей на вход корень v текущего поддерева: произвести рекурсивный вызов для v.left, напечатать v.key, произвести рекурсивный вызов 
для v.right. Pre-order обход: напечатать v.key, произвести рекурсивный вызов для v.left, произвести рекурсивный вызов для v.right. 
Post-order: произвести рекурсивный вызов для v.left, произвести рекурсивный вызов для v.right, напечатать v.key.  
<b>Формат входа.</b> Первая строка содержит число вершин n. Вершины дерева пронумерованы числами от 0 до n−1. Вершина 0 является корнем. 
Каждая из следующих n строк содержит информацию о вершинах 0, 1, ..., n−1: i-я строка задаёт числа keyᵢ, leftᵢ и rightᵢ, где keyᵢ – ключ 
вершины i, leftᵢ – индекс левого сына вершины i, а rightᵢ – индекс правого сына вершины i. Если у вершины i нет одного или обоих сыновей, 
соответствующее значение равно −1.  
<b>Формат выхода.</b> Три строки: in-order, pre-order и post-order обходы.  
<b>Ограничения.</b> 1 ≤ n ≤ 10⁵; 0 ≤ keyᵢ ≤ 10⁹; −1 ≤ leftᵢ, rightᵢ ≤ n−1. Гарантируется, что вход задаёт корректное двоичное дерево: в частности, если leftᵢ != −1 и rightᵢ != −1, то leftᵢ != rightᵢ; никакая вершина не является сыном двух вершин; каждая вершина является потомком корня.
