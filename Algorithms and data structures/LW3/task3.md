EN: Write a program to simulate network packet processing. The processor is able to process packets that fit into the buffer, the size of which 
is defined by the size variable, the rest it discards and does not process further. We need to realize the input of the processor buffer size, 
the number of packets, their arrival time and duration. The output should contain the time of the beginning of processing of each packet or -1, 
if the buffer was filled at the moment of packet arrival and it has been discarded. There are input constraints: all numbers are integers, 
the processor buffer size is from 1 to 10⁵, the size of the number of packets is from 0 to 10⁵, the packet arrival times are in ascending order 
and fall within the range from 0 to 10⁶, the values of the duration of processing of each of the packets are in the range from 0 to 10³. 
The processor processes packets in the order in which they arrive. If the processor starts processing a packet, it is not interrupted during 
the whole processing time and does not stop until the end of processing. If there are no packets, then nothing needs to be output. The computer 
is idle only if all packets are processed and there are no packets in the buffer, otherwise it processes the the next packet as soon as the 
current packet is processed.  

RU: Написать программу для симуляции обработки сетевых пакетов. Процессор способен обрабатывать пакеты, помещающиеся в буфер, размер которого 
определяется переменной size, остальные он отбрасывает и не обрабатывает в дальнейшем. Нужно реализовать ввод размера буфера процессора, числа 
пакетов, их времени поступления и длительности обработки. На выходе необходимо вывести время начала обработки каждого из пакетов или -1, если 
буфер был заполнен в момент поступления пакета, и он был отброшен. Есть ограничения на ввод: все числа целые, размер буфера процессора от 1 до 
10⁵, размер числа пакетов от 0 до 10⁵, значения времени поступления пакетов идут в порядке возрастания и входят в диапазон от 0 до 10⁶, значения 
длительности обработки каждого из пакетов входят в диапазон от 0 до 10³. Процессор обрабатывает пакеты в порядке их поступления. Если процессор 
начинает обработку пакета, то он не прерывается все время обработки duration и не останавливается до окончания обработки. Если пакетов нет, то 
выводить ничего не нужно. Компьютер простаивает только если все пакеты обработаны и в буфере нет пакетов, в остальное время он обрабатывает 
следующий пакет сразу после окончания обработки текущего.
