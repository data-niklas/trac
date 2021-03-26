#include "../lib/argparse.hpp"
#include "./trac.h"

#include "./parser/TracReader.h"
#include "./logger.h"
#include "./eventqueue.h"
#include <unistd.h>
#include <chrono>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

static fs::path get_default_config_dir()
{
    const char *homedir;

    if ((homedir = getenv("HOME")) == NULL)
    {
        homedir = getpwuid(getuid())->pw_dir;
    }
    return fs::path(homedir) / ".config" / "trac";
}

void start(Logger *logger, fs::path config_file)
{
    parser::TracReader reader;
    auto start = chrono::system_clock::now();
    TracResult result = reader.parseFromFile(config_file.u8string());
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start);
    logger->debug("Loaded " + to_string(result.value.size()) + " Trac(s) in " + to_string(duration.count()) + " milliseconds");

    Logger::getLogger()->info("Loaded all Tracs");
    EventQueue::getInstance()->runLoop();
}

int main(int argc, char *argv[])
{

    Logger *logger = Logger::getLogger();
    argparse::ArgumentParser program("program name");

    fs::path default_config_dir = get_default_config_dir();
    fs::path default_config_file = default_config_dir / "tracrc";

    program.add_argument("config file")
        .default_value(default_config_file.u8string())
        .help("sets the config file")
        .action([](const std::string &value) { return value; });

    program.add_argument("-ll", "--loglevel")
        .default_value(string("warning"))
        .help("sets the log level")
        .action([](const std::string &value) { return value; });

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err)
    {
        cout << err.what() << endl;
        cout << program;
        exit(0);
    }

    auto loglevel = program.get<string>("-ll");
    if (loglevel == "debug")
        logger->loglevel = LogLevel::Debug;
    else if (loglevel == "info")
        logger->loglevel = LogLevel::Info;
    else if (loglevel == "warning")
        logger->loglevel = LogLevel::Warning;
    else if (loglevel == "error")
        logger->loglevel = LogLevel::Error;
    else if (loglevel == "off")
        logger->loglevel = LogLevel::Off;
    else
        logger->warning("Unrecognized log level '" + loglevel + "'.\nTry [debug|info|warning|error|off]");
    

    fs::path config_file = fs::path(program.get<string>("config file"));
    if (!fs::exists(config_file))
    {
        if (config_file == default_config_file)
        {
            if (!fs::exists(default_config_dir)){
                fs::create_directories(default_config_dir);
            }
            {
                std::ofstream output(default_config_file);
            }
            logger->info("Default config file is " + default_config_file.u8string() + ", which has now been created");
        }
        else
        {
            logger->error("The config file " + config_file.u8string() + " does not exist");
            exit(1);
        }
    }
    start(logger, config_file);
    return 0;
}