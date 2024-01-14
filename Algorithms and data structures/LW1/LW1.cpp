#include <iostream>
#include <fstream>
#include <sstream>
#include <codecvt>
#include <vector>
#include <chrono>
#include <map>

using namespace std;

//функция getFilename принимает с консоли название файла
string getFilename() {
	string fileName;
	cout << "Введите название файла: " << endl;
	cin >> fileName;
	return fileName;
}


//функция readFile принимает в себя название файла, составляет путь к нему, открывает его и настраивает кодировку с помощью метода 
// imbue, считывает содержимое файла из wif и записывает в переменную wss с помощью rdbuf, возвращает значение wss (исходный текст)
wstring readFile(string& fileName) {
	string folderName = "tests/input/";
	string originalFilename = folderName + fileName;
	wifstream wif(originalFilename);
	wif.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	wstringstream wss;
	wss << wif.rdbuf();
	if (!wif.is_open()) {
		cerr << "Ошибка при открытии файла!" << endl;
	}
	wstring text = wss.str();
	wif.close();
	return text;
}

//функция toLowerCase переводит все символы в нижний кейс
wstring toLowerCase(wstring& text) {
	wstring result = text;
	for (wchar_t& ch : result) {
		ch = towlower(ch);
	}
	return result;
}

//функция isCyrillicLetter проверяет, является ли символ кириллической буквой
bool isCyrillicLetter(wchar_t ch) {
	wstring cyrillicLetters = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	return cyrillicLetters.find(ch) != wstring::npos;
}

//функция findWords проходит по строке и определяет, является ли символ кириллической буквой; если да, то она 
// добавляется в переменную word, если нет, то, если word не пуста, добавляет текущее значение этой переменной 
// в вектор words и очищает переменную word
vector<wstring> findWords(wstring& text) {
	wstring word;
	vector<wstring> words;
	for (wchar_t ch : text) {
		if (isCyrillicLetter(ch)) {
			word += ch;
		}
		else {
			if (!word.empty()) {
				words.push_back(word);
				word.clear();
			}
		}
	}
	if (!word.empty()) {
		words.push_back(word);
	}
	return words;
}

//функция compareWords сравнивает, какое из слов идет раньше по алфавиту
bool compareWords(wstring& a, wstring& b) {
	return a < b;
}

//функция outputResult сохраняет содержимое отсортированного массива в файл с таким же названием, как и оригинал, но в папку result
void outputResult(vector<wstring>& words, string fileName) {
	string folderName = "tests/result/";
	string originalFilename = folderName + fileName;
	wofstream outputFile(originalFilename);
	outputFile.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (outputFile.is_open()) {
		for (wstring& words : words) {
			outputFile << words << endl;
		}
		outputFile.close();
	}
	else {
		wcerr << L"Ошибка сохранения результата" << endl;
	}
	return;
}

//функция shellSort выполняет сортировку Шелла, подсчитывает и возвращает время её выполнения, вызывает функцию outputResult
auto shellSort(vector<wstring>& arr, string fileName) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t d = arr.size() / 2; d > 0; d /= 2) {
		for (size_t i = d; i < arr.size(); i++) {
			for (int j = i - d; j >= 0 && compareWords(arr[j + d], arr[j]); j -= d) {
				swap(arr[j + d], arr[j]);
			}
		}
	}
	outputResult(arr, fileName);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	return duration;
}

//функция countWordsByLetters подсчитывает количество слов, начинающихся с каждой буквы кириллицы
map<wchar_t, int> countWordsByLetters(vector<wstring>& words) {
	map<wchar_t, int> wordCountByLetter;
	for (wstring& word : words) {
		if (!word.empty() && isCyrillicLetter(word[0])) {
			wordCountByLetter[word[0]]++;
			}
		}
	return wordCountByLetter;
	}

//
void outputAnalysis(string fileName, vector<wstring> words, int durationTime, wstring text, map<wchar_t, int> wordCountByLetter) {
	string folderName = "tests/analysis/";
	string originalFilename = folderName + fileName;
	wofstream analysisFile(originalFilename);
	analysisFile.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (analysisFile.is_open()) {
		analysisFile << endl << L"Вариант 10. Кириллица, сортировка по алфавиту, по возрастанию, игнорировать числа, сортировка Шелла." << endl;
		analysisFile << L"Количество слов в исходном тексте: " << words.size() << endl;
		analysisFile << L"Время выполнения сортировки: " << durationTime << L"мкс" << endl;
		analysisFile << endl << L"Исходный текст:" << endl << text << endl << endl;
		for (auto& entry : wordCountByLetter) {
			analysisFile << entry.first << L" - " << entry.second << L", ";
		}
		analysisFile.close();
	}
	else {
		wcerr << L"Ошибка сохранения результата" << endl;
	}
	return;
}

//функция exec последовательно вызывает все функции, необходимые для работы программы
void exec() {
	string fileName = getFilename();
	wstring text = readFile(fileName);
	wstring low_text = toLowerCase(text);
	vector<wstring> words = findWords(low_text);
	auto duration = shellSort(words, fileName);
	int durationTime = duration.count();
	map<wchar_t, int> wordCountByLetter = countWordsByLetters(words);
	outputAnalysis(fileName, words, durationTime, text, wordCountByLetter);

	//выводим анализ на консоль
	cout << "Отсортированный массив уже в файле !" << endl;
	cout << endl << "Вариант 10. Кириллица, сортировка по алфавиту, по возрастанию, игнорировать числа, сортировка Шелла." << endl;
	cout << "Количество слов в исходном тексте: " << words.size() << endl;
	cout << "Время выполнения сортировки: " << duration.count() << "мкс" << endl;
	wcout << endl << L"Исходный текст:" << endl << text << endl << endl;
	for (auto& entry : wordCountByLetter) {
		wcout << entry.first << L" - " << entry.second << L", ";
	}
}

//функция main является точкой входа в программу, устанавливает кодировку UTF-8 и вызывает функцию exec
int main() {
	setlocale(LC_ALL, ".UTF-8");
	exec();
	return 0;
}