using System;
using System.Text.RegularExpressions;

class Program
{
    static void Main()
    {
        string text = @"Мама мыла раму.
        Мир огромен и прекрасен.
        Мама любит мир.
        Море спокойно сегодня.";

        Console.WriteLine("Количество символов: " + text.Length);

        MatchCollection words = Regex.Matches(text, @"\b\w+\b");
        Console.WriteLine("Количество слов: " + words.Count);

        MatchCollection mamaCount = Regex.Matches(text, @"мама", RegexOptions.IgnoreCase);
        Console.WriteLine("Количество слова 'мама': " + mamaCount.Count);

        MatchCollection texts_f = Regex.Matches(text, @"\.");
        Console.WriteLine("Количество словосочетаний: " + texts_f.Count);

        Console.WriteLine("\nСтроки начинающиеся с 'Мама':");
        MatchCollection startLines = Regex.Matches(text, @"^\s*Мама.*$", RegexOptions.Multiline | RegexOptions.IgnoreCase);

        foreach (Match m in startLines)
        {
            Console.WriteLine(m.Value);
        }

        Console.WriteLine("\nСтроки заканчивающиеся на 'сегодня':");

        MatchCollection find_M = Regex.Matches(text, @"^\s*М.*$", RegexOptions.Multiline);

        foreach (Match m in find_M)
        {
            MatchCollection test_ = Regex.Matches(m.Value, @"сегодня\.");
            foreach (Match m_2 in test_)
            {
                Console.WriteLine(m.Value);
            }
        }

        string changedText = Regex.Replace(text, @"Мама", "Бабушка");

        Console.WriteLine("\nИзменённый текст:");
        Console.WriteLine(changedText);
    }
}