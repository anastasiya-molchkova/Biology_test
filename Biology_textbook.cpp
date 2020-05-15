/* Контрольно-обучающая система. Напишите интерактивный учебник биологии. 
Он должен спрашивать у пользователя в случайном порядке 5 вопросов по биологии.
После опроса поставьте испытуемому оценку. */

#include <iostream>
#include <string>
#include <array>
#include <cstdlib>   // для функций выбора случайного числа srand() и rand()
#include <ctime>     // чтобы в randomize опираться на время запуска программы

struct Question
{
    std::string question;
    char correct_answer;
};

class Test
{
private:
    static const unsigned number_of_questions = 5;
    const std::array<Question, number_of_questions> questions_array
    { {
    {"Фенотип - это совокупность :\na. внешних и внутренних признаков организма\nb. всех генов организма\nc. внутренних признаков организма\nd. внешних признаков организма\n", 'a'},
    {"Преобладающий признак, проявляющийся в гомо- и гетерозиготном состоянии определяющего его гена :\na. гетерозиготный\nb. аллельный\nc. рецессивный\nd. доминантный\n", 'd'},
    {"Анализирующим называется скрещивание исследуемой особи с:\na. гомозиготной рецессивной особью\nb. особью с аналогичным генотипом\nc. гомозиготной доминантной особью\nd. гетерозиготной особью\n", 'a'},
    {"При скрещивании черной морской свинки (Аа) с черным самцом (Аа) в поколении FI получится:\na. 75 % черных и 25 % белых морских свинок\nb. 50 % белых и 50 % черных морских свинок\nc. 100 % черных морских свинок\nd. 25 % черных и 75 % белых морских свинок\n", 'a'},
    {"Для определения генотипа особи проводят скрещивание:\na. полигибридное\nb. промежуточное\nc. дигибридноe\nd. анализирующее\n", 'd'}
    } };
    std::array<bool, number_of_questions> used_questions = {false};
    unsigned number_of_correct_answers = 0;
    void work_with_random_question()
    {
        unsigned random_question = rand() % number_of_questions;
        while (used_questions[random_question] == true)
        {
            random_question = rand() % number_of_questions;
        }
        used_questions[random_question] = true;
        std::cout << questions_array[random_question].question;

        char user_answer;
        std::cin.get(user_answer);
        std::cin.ignore(1000, '\n');

        if (user_answer == questions_array[random_question].correct_answer)
        {
            std::cout << "Верно!\n";
            number_of_correct_answers++;
        }
        else
            std::cout << "Вы ошиблись. Правильный ответ: " << questions_array[random_question].correct_answer << std::endl;
    }
    void test_result()
    {
        std::cout << "Тест окончен. Вы ответили правильно на " << number_of_correct_answers << " из " << number_of_questions << " вопросов.\n";
        std::cout << "Ваша оценка: ";
        switch (number_of_correct_answers)
        {
        case 0:
        case 1:
        case 2:
            std::cout << "2 (плохо)\n";
            break;
        case 3:
            std::cout << "3 (удовлетворительно)\n";
            break;
        case 4:
            std::cout << "4 (хорошо)\n";
            break;
        default:
            std::cout << "5 (отлично)\n";
            break;
        }
    }
public:
    Test()
    {
        std::cout << "Предлагаем Вам пройти краткий тест по биологии (знания 9 класса).\nДля выбора ответа просто вводите его букву на клавиатуре и нажимайте enter\n\n";
        for (auto i = 0; i < number_of_questions; i++)
        { 
            std::cout << "Вопрос №" << i + 1 << " из " << number_of_questions << ": ";
            work_with_random_question();
        }
        test_result();
    }
};

int main()
{
    setlocale(LC_CTYPE, "rus");                // для кириллицы
    srand(static_cast<unsigned int>(time(0))); // аналог randomize с привязкой ко времени запуска:

    Test one_test;
    return 0;
}