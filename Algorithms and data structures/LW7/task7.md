<b>EN:</b> Implement a simple phonebook that supports the following three types of queries:  
• add number name: add an entry with name and phone number number. If an entry with this phone number already exists, 
replace the name with name.  
• del number: delete an entry with the corresponding phone number. If there is no such record, do nothing.  
• find number: find the name of the record with the phone number number. If there is an entry with such a number, print the name. Otherwise
output "not found" (without quotes).  
<b>Input format.</b>The first line contains the number of requests n. Each of the next n lines specifies a query in one of the three formats
described above.  
<b>Output format.</b> For each find query, output either the name or "not found" on a separate line.  
<b>Limitations.</b> 1 ≤ n ≤ 10⁵ Phone numbers contain no more than seven digits and no leading zeros. Names contain only letters of the Latin
alphabet, are not empty strings, and are no more than 15 in length. It is guaranteed that there is no "not found" string among the names.

<b>RU:</b> Реализовать простую телефонную книгу, поддерживающую три следующих типа запросов:  
• add number name: добавить запись с именем name и телефонным номером number. Если запись с таким телефонным номером уже есть, 
нужно заменить в ней имя на name.  
• del number: удалить запись с соответствующим телефонным номером. Если такой записи нет, ничего не делать.  
• find number: найти имя записи с телефонным номером number. Если запись с таким номером есть, вывести имя. В противном случае 
вывести «not found» (без кавычек).  
<b>Формат входа.</b> Первая строка содержит число запросов n. Каждая из следующих n строк задаёт запрос в одном из трёх описанных выше форматов.  
<b>Формат выхода.</b> Для каждого запроса find выведите в отдельной строке либо имя, либо «not found».  
<b>Ограничения.</b> 1 ≤ n ≤ 10⁵ Телефонные номера содержат не более семи цифр и не содержат ведущих нулей. Имена содержат только буквы 
латинского алфавита, не являются пустыми строками и имеют длину не больше 15. Гарантируется, что среди имён не встречается строка «not found».
