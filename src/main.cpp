#include <iostream>
#include <clocale>

#ifdef _WIN32
#include <windows.h>
#endif

#include "wrapper.h"
#include "engine.h"
#include "text_processor.h"

int main() {
	setlocale(LC_ALL, "");

#ifdef _WIN32
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
#endif

	const std::string base_text = "здравствуй мир. это проверка программы! добро пожаловать в c++.";

	std::cout << "1. Замена слов:" << "\n";
	{
		TextProcessor doc("привет мир. это проверка программы! добро пожаловать в c++.");
		Wrapper replace(&doc, &TextProcessor::replace_words, { {"old_word", "привет"}, {"new_word", "здравствуй"} });
		std::cout << replace.execute() << "\n\n";
	}

	std::cout << "2. Поиск словосочетания:" << "\n";
	{
		TextProcessor doc(base_text);
		Wrapper find(&doc, &TextProcessor::find_phrase, { {"phrase", "проверка программы"} });
		std::cout << find.execute() << "\n\n";
	}

	std::cout << "3. Заглавные буквы слов:" << "\n";
	{
		TextProcessor doc(base_text);
		Wrapper words(&doc, &TextProcessor::capitalize_words, {});
		std::cout << words.execute() << "\n\n";
	}

	std::cout << "4. Заглавные буквы предложений:" << "\n";
	{
		TextProcessor doc(base_text);
		Wrapper sentences(&doc, &TextProcessor::capitalize_sentences, {});
		std::cout << sentences.execute() << "\n\n";
	}

	std::cout << "5. Нумерация предложений:" << "\n";
	{
		TextProcessor doc(base_text);
		Wrapper numbering(&doc, &TextProcessor::number_sentences, {});
		std::cout << numbering.execute() << "\n";
	}

	return 0;
}