#include "./logger.h"

Logger *Logger::getLogger()
{
    static Logger *logger = new Logger();
    return logger;
}

string Logger::style(string text, string styles[], int count)
{
    string styleprefix = "\x1b[";
    if (count == 0)
        return text;
    for (int i = 0; i < count; i++)
    {
        string style = styles[i];
        if (Logger::styles.count(style) != 0)
        {
            styleprefix += Logger::styles.at(style) + ";";
        }
    }
    styleprefix.pop_back();
    return styleprefix + "m" + text + "\x1b[0m";
}

Logger::Logger()
{
    this->loglevel = LogLevel::Warning;
}

map<string, string> Logger::styles = map<string, string>{
    {"bold", "1"},
    {"black", "30"},
    {"red", "31"},
    {"green", "32"},
    {"yellow", "33"},
    {"blue", "34"},
    {"magenta", "35"},
    {"cyan", "36"},
    {"white", "37"}};

void Logger::info(string text)
{
    if (this->loglevel > LogLevel::All)return;
    string headstyles[] = {"white", "bold"};
    string styles[] = {"white"};
    cout << this->style("Info: ", headstyles, 2) << this->style(text, styles, 1) << '\n';
}

void Logger::warning(string text)
{
    if (this->loglevel > LogLevel::Warning)return;
    string headstyles[] = {"yellow", "bold"};
    string styles[] = {"yellow"};
    cout << this->style("Warning: ", headstyles, 2) << this->style(text, styles, 1) << '\n';
}

void Logger::error(string text)
{
    if (this->loglevel > LogLevel::Error)return;
    string headstyles[] = {"red", "bold"};
    string styles[] = {"red"};
    cout << this->style("Error: ", headstyles, 2) << this->style(text, styles, 1) << '\n';
}